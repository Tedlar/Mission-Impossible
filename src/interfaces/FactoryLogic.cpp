/*
 * FactoryGUI.cpp
 *
 *  Created on: 15 lut 2017
 *      Author: Antoni Tomaszuk
 */

#include <src/interfaces/ILogic.h>
#include <src/logic/Logic.h>


std::shared_ptr<ILogic> ILogic::createLogic() {
	return std::make_shared<Logic>();
}
