/*
 * Logic.cpp
 *
 *  Created on: 16 lut 2017
 *      Author: tedlar
 */

#include <src/logic/Logic.h>
#include <QDebug>
#include <stdlib.h>


Logic::~Logic() {}

void Logic::create() {
	createController();
	createKeyManager();
	createObjects();
}

void Logic::configure(int& argc, char **argv) {
	configureController();
}

void Logic::initialize() {
	initializeController();
}

void Logic::start() {
	startController();
}

void Logic::receiveKeyGame(KeyType _key) {
	qDebug() << "Logic::receiveKeyGame - key: " << _key;
}

void Logic::onSendKeySignal(KeyType _key) {
	switch (_key) {
		case MOVE_UP:
		case MOVE_DOWN:
		case MOVE_LEFT:
		case MOVE_RIGHT:
		case MOVE_STAY:
			keyManager_->write(_key);
			break;
		default:
			receiveKeyGame(_key);
			break;
	}
}

void Logic::onConfigureGameSignal(uint8_t _n, uint8_t _sx, uint8_t _sy) {
	controller_->configureGame(_n, _sx, _sy);
}

void Logic::onStartGameSignal() {
	controller_->startGame();
}

void Logic::onStopGameSignal() {
	controller_->stopGame();
}

void Logic::createController() {
	controller_ = IController::produceController();
	controller_->create();
}

void Logic::createKeyManager() {
	keyManager_ = IKeyManager::createKeyManager();
}

void Logic::createObjects() {
	objectsMap_[0] = IObject::createPlayer();
	for (int i=1; i<= agentNumber_; ++i)
		objectsMap_[i] = IObject::createAgent();
	for(auto& pair : objectsMap_)
		pair.second->create();
}

void Logic::configureController() {
	controller_->configure();
}

void Logic::initializeController() {
	controller_->initialize();
}

void Logic::startController() {
	controller_->start();
}

