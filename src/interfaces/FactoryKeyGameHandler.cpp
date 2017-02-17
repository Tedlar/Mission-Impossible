/*
 * FactoryKeyManager.cpp
 *
 *  Created on: 17 lut 2017
 *      Author: Antoni Tomaszuk
 */

#include <src/interfaces/IKeyGameHandler.h>
#include <src/logic/keyboard/KeyGameHandler.h>


std::shared_ptr<IKeyGameHandler> IKeyGameHandler::createKeyGameHandler() {
	return std::make_shared<KeyGameHandler>();
}


