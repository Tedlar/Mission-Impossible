/*
 * ObjectPlayer.cpp
 *
 *  Created on: 15 lut 2017
 *      Author: tedlar
 */

#include <src/logic/player/ObjectPlayer.h>
#include <iostream>


ObjectPlayer::ObjectPlayer() {
	speed_ = 2;
}

void ObjectPlayer::move(uint16_t& _x, uint16_t& _y, KeyType _key) {
	switch (_key) {
		case MOVE_UP:
			_y = posY_ == (sizeY_-1) ? posY_ : ++posY_;
			_x = posX_;
			break;
		case MOVE_DOWN:
			_y = posY_ == 0 ? posY_ : --posY_;
			_x = posX_;
			break;
		case MOVE_LEFT:
			_x = posX_ == 0 ? posX_ : --posX_;
			_y = posY_;
			break;
		case MOVE_RIGHT:
			_x = posX_ == (sizeX_-1) ? posX_ : ++posX_;
			_y = posY_;
			break;
		case MOVE_STAY:
			_x = posX_;
			_y = posY_;
			break;
		default:
			std::cerr << "Player - ERROR: Key not move type!" << std::endl;
			std::cerr << "Player - KeyType: " << _key << std::endl;
			exit(-1);
			break;
	}
}

