/*
 * Controller.h
 *
 *  Created on: 15 lut 2017
 *      Author: tedlar
 */

#ifndef CONTROLLER_CONTROLLER_H_
#define CONTROLLER_CONTROLLER_H_

#include <src/interfaces/IController.h>

	//!  Class implementing Controller
	/*!

	*/
class Controller : public IController {
public:
	//! constructor
	/*!
	*/
	Controller();

	//! set player position
	/*!
	  \param object object id
	  \param x x position to be set
	  \param y y position to be set
	*/
	void setPlayerPosition(uint16_t _posX, uint16_t _posY);

	//! set player position lost
	/*!
	*/
	void setPlayerPositionLost();

	//! set player position
	/*!
	  \param x x position to write into
	  \param y y position to write into
	  \return if position is valid
	*/
	bool getPlayerPosition(uint16_t& _posX, uint16_t& _posY);

	//! get player position lost
	/*!
	*/
	bool getPlayerPositionValid();

private:

	//! Holds if position is valid
	/*!
	*/
	bool positionValid_;
	//! HOlds X and Y position
	/*!
	*/
	uint16_t posX_, posY_;
};

#endif // CONTROLLER_CONTROLLER_H_
