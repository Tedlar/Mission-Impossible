/*
 * IUnit.h
 *
 *  Created on: 15 lut 2017
 *      Author: tedlar
 */

#ifndef INTERFACES_IUNIT_H_
#define INTERFACES_IUNIT_H_

#include <src/interfaces/IKeyType.h>
#include <src/logic/controller/Controller.h>
#include <stdint.h>
#include <memory>


class IObject {
public:
	virtual ~IObject() {}
	
	static std::shared_ptr<IObject> createAgent();
	static std::shared_ptr<IObject> createPlayer();

	void setMapSize(uint16_t _sizeX, uint16_t _sizeY) {
		sizeX_ = _sizeX;
		sizeY_ = _sizeY;
	}

	void setStartPosition(uint16_t _posX, uint16_t _posY) {
		posX_ = _posX;
		posY_ = _posY;
	}

	void getPosition(uint16_t& _posX, uint16_t& _posY) {
		_posX = posX_;
		_posY = posY_;
	}

	uint8_t getSpeedValue() {
		return speed_;
	}

	void setController(const std::shared_ptr<IController> _controller) {
		controller_ = _controller;
	}

	virtual void move(uint16_t& _x, uint16_t& _y, KeyType _key = MOVE_STAY) = 0;

protected:
	uint16_t sizeX_, sizeY_;
	uint16_t posX_, posY_;
	uint8_t  speed_;
	std::shared_ptr<IController> controller_;
};

#endif // INTERFACES_IUNIT_H_
