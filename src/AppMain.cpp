/*
 * AppMain.cpp
 *
 *  Created on: 15 lut 2017
 *      Author: tedlar
 */

#include <src/AppMain.h>

AppMain::AppMain()
: agentNumber_(8) {}

AppMain::~AppMain() {}

void AppMain::create() {
	createController();
}

void AppMain::configure(int argc, char **argv) {
	configureController();
}

void AppMain::initialize() {
	initializeController();
}

void AppMain::start() {
	startController();
}

void AppMain::createController() {
	controller_ = IController::produceController();
	controller_->create();
}

void AppMain::createObjects() {
	objectsMap_[0] = IObject::createPlayer();
	for (int i=1; i<= agentNumber_; ++i)
		objectsMap_[i] = IObject::createAgent();
	for(auto& pair : objectsMap_)
		pair.second->create();
}

void AppMain::configureController() {
	controller_->configure();
}

void AppMain::initializeController() {
	controller_->initialize();
}

void AppMain::startController() {
	controller_->start();
}

