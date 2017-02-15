/*
 * ObjectAgent.h
 *
 *  Created on: 15 lut 2017
 *      Author: tedlar
 */

#ifndef AGENT_OBJECTAGENT_H_
#define AGENT_OBJECTAGENT_H_

#include <src/interfaces/IObject.h>


class ObjectAgent : public IObject {
public:
	ObjectAgent();
	~ObjectAgent();

	void create();
	void setPosition(uint8_t x, uint8_t y, uint16_t sizeX, uint16_t sizeY);
	void getPosition(uint8_t& x, uint8_t& y);
	uint8_t getSpeedValue();
};

#endif // AGENT_OBJECTAGENT_H_
