/*
 * Controller.h
 *
 *  Created on: 15 lut 2017
 *      Author: tedlar
 */

#ifndef CONTROLLER_CONTROLLER_H_
#define CONTROLLER_CONTROLLER_H_

#include <src/interfaces/IController.h>


class Controller : public IController {
public:
	Controller();

	void setPlayerPosition(uint16_t _posX, uint16_t _posY);
	void setPlayerPositionLost();
	bool getPlayerPosition(uint16_t& _posX, uint16_t& _posY);
	bool getPlayerPositionValid();

private:
	bool positionValid_;
	uint16_t posX_, posY_;
};

#endif // CONTROLLER_CONTROLLER_H_
