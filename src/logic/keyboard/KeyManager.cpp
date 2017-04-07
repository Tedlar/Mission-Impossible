/*
 * KeyManager.cpp
 *
 *  Created on: 17.02.2017
 *      Author: Antoni Tomaszuk
 */

#include <src/logic/keyboard/KeyManager.h>
#include <src/logic/keyboard/QueueData.h>
#include <QDebug>


KeyManager::KeyManager() {}
KeyManager::~KeyManager() {}

void KeyManager::write(const KeyType& _type) {
	keyQueue_.write(_type);
}

void KeyManager::readKey(KeyType& _type) {
	keyQueue_.read(_type);
}
