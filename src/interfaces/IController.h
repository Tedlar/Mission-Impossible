/*
 * IController.h
 *
 *  Created on: 15 lut 2017
 *      Author: tedlar
 */

#ifndef INTERFACES_ICONTROLLER_H_
#define INTERFACES_ICONTROLLER_H_

#include <memory>

	//!  Controller interface
	/*!

	*/
class IController {

public:
	//! destructor
	/*!
	*/
	virtual ~IController() {}
	static std::shared_ptr<IController> produceController();

	//! set argc & argv and configure GUI
	/*!
	  \param _posX
	  \param _posY
	*/
	virtual void setPlayerPosition(uint16_t _posX, uint16_t _posY) = 0;

	//! Function which create GUI, should be called after initialuze
	/*!
	*/
	virtual void setPlayerPositionLost() = 0;

	//! set argc & argv and configure GUI
	/*!
	  \param _posX
	  \param _posY
	*/
	virtual bool getPlayerPosition(uint16_t& _posX, uint16_t& _posY) = 0;

	//! Checks if position is valid
	/*!
	*/
	virtual bool getPlayerPositionValid() = 0;
};


#endif // INTERFACES_ICONTROLLER_H_
