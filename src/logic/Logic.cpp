/*
 * Logic.cpp
 *
 *  Created on: 16 lut 2017
 *      Author: tedlar
 */

#include <src/logic/Logic.h>
#include <QDebug>


Logic::~Logic() {}

void Logic::create() {
	createController();
	createKeyState();
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

void Logic::onSendKeySignal(KeyType _type) {
	qDebug() << _type;
}

void Logic::createController() {
	controller_ = IController::produceController();
	controller_->create();
}

void Logic::createKeyState() {
	keyState_ = IKeyState::createKeyState();
	keyState_->create();
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

