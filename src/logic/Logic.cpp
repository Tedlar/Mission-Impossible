/*
 * Logic.cpp
 *
 *  Created on: 16 lut 2017
 *      Author: tedlar
 */

#include <src/logic/Logic.h>
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <iostream>


Logic::Logic()
: gameConfigured_(false), gameStarted_(false),
  playerMove_(0), objectNumber_(0), sizeX_(0), sizeY_(0)
{
	qRegisterMetaType<uint8_t>();
	qRegisterMetaType<uint16_t>("uint16_t");
	createController();
	createKeyManager();
}

Logic::~Logic() {
	onStopGameSignal();
}


void Logic::onSendKeySignal(KeyType _key) {
	if (!gameStarted_) return;
	keyManager_->write(_key);
}

void Logic::onConfigureGameSignal(uint8_t _n, uint8_t _sizeX, uint8_t _sizeY) {
	objectNumber_ = _n+1;
	sizeX_ = _sizeX;
	sizeY_ = _sizeY;
	srand(time(NULL));
	gameClearLogic();
	qDebug()<<"onConfigureGameSignal enemies: "<<_n<<" x: "<<_sizeX<<" y:"<<_sizeY;
	for (int i=0; i<objectNumber_; ++i) {
		if (i == 0) {
			objects_.push_back(IObject::createPlayer());
			objects_.back()->setStartPosition((_sizeX-1)/2, (_sizeY-1)/2);
			controller_->setPlayerPosition((_sizeX-1)/2, (_sizeY-1)/2);
			qDebug()<<"start counter: "<<0<<"posX: "<<(_sizeX-1)/2<<"posY: "<<(_sizeY-1)/2;
			emit sendObjectPossitionSignal(0, (_sizeX-1)/2, (_sizeY-1)/2);
		} else {
			objects_.push_back(IObject::createAgent());
			uint16_t posX, posY, newX, newY;
			while(true) {
				posX = newX = rand()%_sizeX;
				posY = newY = rand()%_sizeY;
				if (!checkForObject(newX,newY, i, 4, false))
					break;
			}
			objects_.back()->setStartPosition(posX, posY);
			qDebug()<<"start counter: "<< objects_.size()+1 <<"posX: "<<posX<<"posY: "<<posY;
			emit sendObjectPossitionSignal(i, posX, posY);
		}
		objects_.back()->setMapSize(_sizeX, _sizeY);
		objects_.back()->setController(controller_);
	}
	gameConfigured_ = true;

	//Debug
	printPositions();
}

void Logic::onStartGameSignal() {
	if (!gameConfigured_) {
		std::cerr << "Cannot start new game. Game not configured" << std::endl;
		return;
	}
	if (gameStarted_) return;
	qDebug()<<"on Start Game Signal";
	gameStarted_ = true;
	if (logicThread_)
		logicThread_->join();
	logicThread_ = std::make_shared<std::thread>(&Logic::logicLoop, this);
	qDebug()<<"on Start Game Signal 2";
}

void Logic::onStopGameSignal() {
	if (!gameStarted_) {
		std::cerr << "Cannot stop game. Game not started" << std::endl;
		return;
	}
	gameStarted_ = false;
	keyManager_->write(GAME_QUIT);
	logicThread_->join();
	logicThread_ = nullptr;
	gameClearLogic();
}

void Logic::createController() {
	controller_ = IController::produceController();
}

void Logic::createKeyManager() {
	keyManager_ = IKeyManager::createKeyManager();
}

void Logic::logicLoop() {
	KeyType key;
	while (gameStarted_) {
		keyManager_->readKey(key);
		if (key == KeyType::GAME_QUIT) return;
		switch (key) {
			case MOVE_UP:
			case MOVE_DOWN:
			case MOVE_LEFT:
			case MOVE_RIGHT:
			case MOVE_STAY:
				if (!playerMove(key)) {
					std::cout << "%%%%%%%%%%%%%% END GAME" << std::endl;
					emit endGameSignal();
					gameStarted_ = false;
				}
				break;
			case GAME_QUIT:
			case GAME_RECONFIGURE:
			case GAME_RESTART:
				gameStarted_ = false;
				break;
		}
		//Debug
		printPositions();
	}
}

bool Logic::playerMove(KeyType _key) {
	uint16_t posX, posY, counter;
	counter = 0;
	for(auto& object : objects_) {
		object->move(posX, posY, _key);
		++playerMove_;
		qDebug()<<"counter: "<<counter<<"posX: "<<posX<<"posY: "<<posY;
		emit sendObjectPossitionSignal(counter, posX, posY);

		if (counter == 0 && checkForObject(posX,posY, counter, 1, false)) {
			return false;
		} else if (counter != 0 && checkForObject(posX,posY, counter, 1, true))
			return false;

		if (counter == 0 && playerMove_ < object->getSpeedValue()) {
			return true;
		} else
			playerMove_ = 0;

		if (counter != 0) {
			object->getPosition(posX, posY);
			if (checkForObject(posX, posY, counter, 3, true))
				controller_->setPlayerPosition(posX, posY);
		}
		++counter;
	}
	return true;
}

bool Logic::checkForObject(uint16_t& _posX, uint16_t& _posY, uint8_t _id, uint8_t _view, bool _checkForPlayer) {
	uint8_t currentID = 0;
	uint16_t objX, objY;
	int32_t deltaX, deltaY;
	double range, view;
	view = _view*_view;
	for (auto& object : objects_) {
		if (_checkForPlayer && currentID > 0) break;
		if (currentID == _id) {
			++currentID;
			continue;
		}
		object->getPosition(objX, objY);
		deltaX = objX-_posX;
		deltaY = objY-_posY;
		range = deltaX*deltaX + deltaY*deltaY;
		if (range <= view) {
			_posX = objX;
			_posY = objY;
			return true;
		}
		++currentID;
	}
	return false;
}

void Logic::gameClearLogic() {
	gameConfigured_ = gameStarted_ = false;
	for (auto& object : objects_)
		object.reset();
	objects_.clear();
}

void Logic::printPositions() {
	for (int i=sizeY_-1; i>=0; --i) {
		for (int j=0; j<sizeX_; ++j) {
			bool found = false;
			bool player = false;
			for(auto& obj : objects_) {
				uint16_t x,y;
				obj->getPosition(x,y);
				if (x == j && y == i) {
					found = true;
					if ((&obj - &objects_[0]) == 0)
						player = true;
				}
			}
			if (found && player)
				std::cout << "@";
			else if (found)
				std::cout << "*";
			else
				std::cout << "-";
		}
		std::cout << std::endl;
	}
}
