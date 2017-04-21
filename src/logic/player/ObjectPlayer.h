/*
 * ObjectPlayer.h
 *
 *  Created on: 15 lut 2017
 *      Author: tedlar
 */

#ifndef PLAYER_OBJECTPLAYER_H_
#define PLAYER_OBJECTPLAYER_H_

#include <src/interfaces/IObject.h>

	//!  Player Object
	/*!

	*/
class ObjectPlayer : public IObject {
public:
	//! constructor
	/*!
	*/
	ObjectPlayer();

	//! constructor
	/*!
	*/
	ObjectPlayer(const ObjectPlayer&) = delete;

	//! move player
	/*!
	*/
	void move(uint16_t& _x, uint16_t& _y, KeyType _key = MOVE_STAY);
};

#endif // PLAYER_OBJECTPLAYER_H_
