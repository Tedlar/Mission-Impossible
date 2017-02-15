/*
 * IUnit.cpp
 *
 *  Created on: 15 lut 2017
 *      Author: tedlar
 */

#include <src/interfaces/IObject.h>
#include <src/agent/ObjectAgent.h>
#include <src/player/ObjectPlayer.h>


std::shared_ptr<IObject> IObject::createAgent() {
	return std::make_shared<ObjectAgent>();
}

std::shared_ptr<IObject> IObject::createPlayer() {
	return std::make_shared<ObjectPlayer>();
}


