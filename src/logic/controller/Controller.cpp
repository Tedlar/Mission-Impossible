/*
 * Controller.cpp
 *
 *  Created on: 15 lut 2017
 *      Author: tedlar
 */

#include <src/logic/controller/Controller.h>
#include <iostream>


Controller::Controller()
: positionValid_(false), posX_(0), posY_(0) {}

void Controller::setPlayerPosition(uint16_t _posX, uint16_t _posY) {
	std::cout << "Controller::setPlayerPosition" << std::endl;
	posX_ = _posX;
	posY_ = _posY;
	positionValid_ = true;
}

void Controller::setPlayerPositionLost() {
	positionValid_ = false;
}

bool Controller::getPlayerPosition(uint16_t& _posX, uint16_t& _posY) {
	_posX = posX_;
	_posY = posY_;
	return positionValid_;
}

bool Controller::getPlayerPositionValid() {
	return positionValid_;
}



