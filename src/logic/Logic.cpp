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
	createKeyGameHandler();
	createKeyManager();
	createObjects();
}

void Logic::configure(int& argc, char **argv) {
	configureController();
	configureKeyGameHandler();
}

void Logic::initialize() {
	initializeController();
}

void Logic::start() {
	startController();
	startKeyGameHandler();
}

void Logic::onSendKeySignal(KeyType _type) {
	qDebug() << _type;
	keyManager_->write(_type);
}

void Logic::createController() {
	controller_ = IController::produceController();
	controller_->create();
}

void Logic::createKeyGameHandler() {
	keyGameHandler_ = IKeyGameHandler::createKeyGameHandler();
	keyGameHandler_->create();
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

void Logic::configureKeyGameHandler() {
	keyGameHandler_->configure(controller_, keyManager_);
}

void Logic::initializeController() {
	controller_->initialize();
}

void Logic::startController() {
	controller_->start();
}

void Logic::startKeyGameHandler() {
	keyGameHandler_->start(keyGameHandler_);
}

