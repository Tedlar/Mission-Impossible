/*
 * ObjectPlayer.h
 *
 *  Created on: 15 lut 2017
 *      Author: tedlar
 */

#ifndef PLAYER_OBJECTPLAYER_H_
#define PLAYER_OBJECTPLAYER_H_

#include <src/interfaces/IObject.h>


class ObjectPlayer : public IObject {
public:
	ObjectPlayer();
	~ObjectPlayer();

	void create();
	void setPosition(uint8_t x, uint8_t y, uint16_t sizeX, uint16_t sizeY);
	void getPosition(uint8_t& x, uint8_t& y);
	uint8_t getSpeedValue();
};

#endif // PLAYER_OBJECTPLAYER_H_
