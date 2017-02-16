/*
 * FactoryKeyState.cpp
 *
 *  Created on: 16 lut 2017
 *      Author: Antoni Tomaszuk
 */

#include <src/interfaces/IKeyState.h>
#include <src/logic/keyboard/KeyState.h>


std::shared_ptr<IKeyState> IKeyState::createKeyState() {
	return std::make_shared<KeyState>();
}


