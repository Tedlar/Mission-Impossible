/*
 * IControllerFactory.cpp
 *
 *  Created on: 15 lut 2017
 *      Author: tedlar
 */

#include "IController.h"
#include "../controller/Controller.h"


std::shared_ptr<IController> IController::produceController() {
	return std::make_shared<Controller>();
}


