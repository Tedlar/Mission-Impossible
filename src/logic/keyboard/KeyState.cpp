/*
 * KeyState.cpp
 *
 *  Created on: 16 lut 2017
 *      Author: Antoni Tomaszuk
 */

#include <src/logic/keyboard/KeyState.h>

#include <iostream>


KeyState::~KeyState() {}

void KeyState::create() {

}

void KeyState::setPressedKey(KeyType _key) {
	std::cout << "Grabbed key: " << (int)_key << std::endl;
	key_ = _key;
}

KeyType KeyState::getPresedKey() {
	return key_;
}

