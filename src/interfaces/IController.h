/*
 * IController.h
 *
 *  Created on: 15 lut 2017
 *      Author: tedlar
 */

#ifndef INTERFACES_ICONTROLLER_H_
#define INTERFACES_ICONTROLLER_H_

#include <memory>


class IController {

public:
	virtual ~IController() {}
	static std::shared_ptr<IController> produceController();

	virtual void setPlayerPosition(uint16_t _posX, uint16_t _posY) = 0;
	virtual void setPlayerPositionLost() = 0;
	virtual bool getPlayerPosition(uint16_t& _posX, uint16_t& _posY) = 0;
	virtual bool getPlayerPositionValid() = 0;
};


#endif // INTERFACES_ICONTROLLER_H_
