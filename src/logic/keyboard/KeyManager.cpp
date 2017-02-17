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
	switch (_type) {
		case MOVE_UP:
		case MOVE_DOWN:
		case MOVE_LEFT:
		case MOVE_RIGHT:
		case MOVE_STAY:
			keyMove_.write(_type);
			break;
		case GAME_RESTART:
		case GAME_RECONFIGURE:
		case GAME_QUIT:
			keyGame_.write(_type);
			break;
	}
}

void KeyManager::readKeyGame(KeyType& _type) {
	keyGame_.read(_type);
}

void KeyManager::readKeyMove(KeyType& _type) {
	keyMove_.read(_type);
}
