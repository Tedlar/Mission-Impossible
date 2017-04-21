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

	//!  Object interface
	/*!

	*/
class IObject {
public:

	//! destructor
	/*!
	*/
	virtual ~IObject() {}
	
	//! Create Agent
	/*!
	*/
	static std::shared_ptr<IObject> createAgent();

	//! Create Player
	/*!
	*/
	static std::shared_ptr<IObject> createPlayer();

	//! set Map Size
	/*!
	  \param _sizeX x size of map
	  \param _sizeY y size of map
	*/
	void setMapSize(uint16_t _sizeX, uint16_t _sizeY) {
		sizeX_ = _sizeX;
		sizeY_ = _sizeY;
	}

	//! set start position
	/*!
	  \param _posX x of start position
	  \param _posY y size of map
	*/
	void setStartPosition(uint16_t _posX, uint16_t _posY) {
		posX_ = _posX;
		posY_ = _posY;
	}

	//! get position
	/*!
	  \param _posX x of start position
	  \param _posY y size of map
	*/
	void getPosition(uint16_t& _posX, uint16_t& _posY) {
		_posX = posX_;
		_posY = posY_;
	}

	//! get speed
	/*!
	  \return uint8_t speed value
	*/
	uint8_t getSpeedValue() {
		return speed_;
	}

	//! set controller
	/*!
	  \param _controller to set
	*/
	void setController(const std::shared_ptr<IController> _controller) {
		controller_ = _controller;
	}

	//! move
	/*!
	 \param x
	 \param y
	 \param keyType
	*/
	virtual void move(uint16_t& _x, uint16_t& _y, KeyType _key = MOVE_STAY) = 0;

protected:
	//! sizeX_, sizeY_ variable
	/*!
	*/
	uint16_t sizeX_, sizeY_;

	//! posX_, posY_ variable
	/*!
	*/
	uint16_t posX_, posY_;

	//! speed variable
	/*!
	*/
	uint8_t  speed_;

	//! controller_ variable
	/*!
	*/
	std::shared_ptr<IController> controller_;
};

#endif // INTERFACES_IUNIT_H_
