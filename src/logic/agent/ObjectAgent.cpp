/*
 * ObjectAgent.cpp
 *
 *  Created on: 15 lut 2017
 *      Author: tedlar
 */

#include <src/logic/agent/ObjectAgent.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

int ObjectAgent::seed_ = 0;

ObjectAgent::ObjectAgent()
: algorithmType_(AlgorithmType::None), moveCounter_(0)
{
	speed_ = 1;
	selectAlgorithm();
	srand(++seed_);
}

void ObjectAgent::move(uint16_t& _posX, uint16_t& _posY, KeyType) {
	uint16_t targetX, targetY;
	MoveDirection direction;
	if (controller_->getPlayerPosition(targetX, targetY)) {
		switch (algorithmType_) {
			case AlgorithmType::Diagonally:
				direction = moveAlgorithmDiagonally(targetX, targetY);
				break;
			case AlgorithmType::FirstHorizontally:
				direction = moveAlgorithmFirstHorizontally(targetX, targetY);
				break;
			case AlgorithmType::FirstVertically:
				direction = moveAlgorithmFirstVertically(targetX, targetY);
				break;
			default:
				break;
		};
	} else
		direction = moveAlgorithmRandom();
	changePosition(targetX, targetY, direction);
	_posX = targetX;
	_posY = targetY;
	if (controller_->getPlayerPosition(targetX, targetY))
		if ( posX_ == targetX && posY_ == targetY) {
			std::cout << "Player position lost" << std::endl;
			controller_->setPlayerPositionLost();
		}
	++moveCounter_;
	if (moveCounter_ == 5) {
		selectAlgorithm();
		moveCounter_ = 0;
	}
}

void ObjectAgent::selectAlgorithm() {
	algorithmType_ = (AlgorithmType)(rand()%3+1);
	std::cout << "ObjectAgent::selectAlgorithm - " << (int)algorithmType_ << std::endl;
}

MoveDirection ObjectAgent::moveAlgorithmDiagonally(uint16_t _posX, uint16_t _posY) {
	std::cout << "ObjectAgent::moveAlgorithmDiagonally" << std::endl;
	int32_t deltaX = _posX - posX_;
	int32_t deltaY = _posY - posY_;
	if (deltaX == 0 && deltaY == 0) {
		return MoveDirection::MOVE_STAY;
	} else if ( abs(deltaX) >= abs(deltaY)) {
		return deltaX < 0 ? MoveDirection::MOVE_LEFT : MoveDirection::MOVE_RIGHT;
	} else {
		return deltaY < 0 ? MoveDirection::MOVE_DOWN : MoveDirection::MOVE_UP;
	}
}

MoveDirection ObjectAgent::moveAlgorithmFirstHorizontally(uint16_t _posX, uint16_t _posY) {
	std::cout << "ObjectAgent::moveAlgorithmFirstHorizontally" << std::endl;
	int32_t deltaX = _posX - posX_;
	int32_t deltaY = _posY - posY_;
	if (deltaX == 0 && deltaY == 0) {
		return MoveDirection::MOVE_STAY;
	} else if (deltaX != 0) {
		return deltaX < 0 ? MoveDirection::MOVE_LEFT : MoveDirection::MOVE_RIGHT;
	} else {
		return deltaY < 0 ? MoveDirection::MOVE_DOWN : MoveDirection::MOVE_UP;
	}
}

MoveDirection ObjectAgent::moveAlgorithmFirstVertically(uint16_t _posX, uint16_t _posY) {
	std::cout << "ObjectAgent::moveAlgorithmFirstVertically" << std::endl;
	int32_t deltaX = _posX - posX_;
	int32_t deltaY = _posY - posY_;
	if (deltaX == 0 && deltaY == 0) {
		return MoveDirection::MOVE_STAY;
	} else if (deltaY != 0) {
		return deltaY < 0 ? MoveDirection::MOVE_DOWN : MoveDirection::MOVE_UP;
	} else {
		return deltaX < 0 ? MoveDirection::MOVE_LEFT : MoveDirection::MOVE_RIGHT;
	}
}

MoveDirection ObjectAgent::moveAlgorithmRandom() {
	return (MoveDirection)(rand()%4);
}

void ObjectAgent::changePosition(uint16_t& _posX, uint16_t& _posY, MoveDirection _direction) {
	switch (_direction) {
		case MoveDirection::MOVE_UP:
			_posY = posY_ == (sizeY_-1) ? posY_ : ++posY_;
			_posX = posX_;
			break;
		case MoveDirection::MOVE_DOWN:
			_posY = posY_ == 0 ? posY_ : --posY_;
			_posX = posX_;
			break;
		case MoveDirection::MOVE_LEFT:
			_posX = posX_ == 0 ? posX_ : --posX_;
			_posY = posY_;
			break;
		case MoveDirection::MOVE_RIGHT:
			_posX = posX_ == (sizeX_-1) ? posX_ : ++posX_;
			_posY = posY_;
			break;
		case MoveDirection::MOVE_STAY:
			_posX = posX_;
			_posY = posY_;
			break;
	}
}
