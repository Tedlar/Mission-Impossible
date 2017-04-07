/*
 * FactoryKeyManager.cpp
 *
 *  Created on: 17 lut 2017
 *      Author: Antoni Tomaszuk
 */

#include <src/interfaces/IKeyManager.h>
#include <src/logic/keyboard/KeyManager.h>


std::shared_ptr<IKeyManager> IKeyManager::createKeyManager() {
	return std::make_shared<KeyManager>();
}


