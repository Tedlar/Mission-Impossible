/*
 * FactoryGUI.cpp
 *
 *  Created on: 15 lut 2017
 *      Author: Antoni Tomaszuk
 */

#include <src/interfaces/IGUI.h>
#include <src/gui/GUI.h>


std::shared_ptr<IGUI> IGUI::createGUI() {
	return std::make_shared<GUI>();
}
