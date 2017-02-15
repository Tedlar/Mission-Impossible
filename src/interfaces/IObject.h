/*
 * IUnit.h
 *
 *  Created on: 15 lut 2017
 *      Author: tedlar
 */

#ifndef INTERFACES_IUNIT_H_
#define INTERFACES_IUNIT_H_

#include <stdint.h>
#include <memory>


class IObject {
public:
	virtual ~IObject() {}
	
	static std::shared_ptr<IObject> createAgent();
	static std::shared_ptr<IObject> createPlayer();

	virtual void create() = 0;
	virtual void setPosition(uint8_t x, uint8_t y, uint16_t sizeX, uint16_t sizeY) = 0;
	virtual void getPosition(uint8_t& x, uint8_t& y) = 0;
	virtual uint8_t getSpeedValue() = 0;
};

#endif // INTERFACES_IUNIT_H_
