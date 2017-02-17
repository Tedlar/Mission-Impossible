/*
 * Controller.cpp
 *
 *  Created on: 15 lut 2017
 *      Author: tedlar
 */

#include <src/logic/controller/Controller.h>
#include <QDebug>

Controller::Controller() {}

Controller::~Controller() {}

void Controller::create() {}
void Controller::configure() {}
void Controller::initialize() {}
void Controller::start() {}

void Controller::receiveKeyGame(KeyType _key) {
	qDebug() << "Controller::receiveKeyGame - key: " << _key;
}
