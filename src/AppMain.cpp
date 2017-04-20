/*
 * AppMain.cpp
 *
 *  Created on: 15 lut 2017
 *      Author: tedlar
 */

#include <src/AppMain.h>
#include <QObject>
#include <iostream>


AppMain::~AppMain() {}

void AppMain::create() {
	qRegisterMetaType<uint8_t>();
	qRegisterMetaType<uint16_t>("uint16_t");
	createGUI();
	createLogic();
}

void AppMain::configure(int& argc, char **argv) {
	configureGUI(argc, argv);
}

void AppMain::initialize() {

	initializeGUI();
	QObject::connect(gui_.get(),   SIGNAL(sendKeySignal(KeyType)),
                     logic_.get(), SLOT(onSendKeySignal(KeyType)));
	QObject::connect(gui_.get(),   SIGNAL(configureGameSignal(uint8_t,uint8_t,uint8_t)),
                     logic_.get(), SLOT(onConfigureGameSignal(uint8_t,uint8_t,uint8_t)));
	QObject::connect(gui_.get(),   SIGNAL(startGameSignal()),
                     logic_.get(), SLOT(onStartGameSignal()));
	QObject::connect(gui_.get(),   SIGNAL(stopGameSignal()),
                     logic_.get(), SLOT(onStopGameSignal()));
	QObject::connect(logic_.get(), SIGNAL(sendObjectPossitionSignal(uint16_t,uint16_t,uint16_t)),
	gui_.get(),   SLOT(onSendObjectPossitionSignal(uint16_t,uint16_t,uint16_t)));
	QObject::connect(logic_.get(), SIGNAL(endGameSignal()),
	gui_.get(),   SIGNAL(endGameSignal()));

}

void AppMain::start() {
//	logic_->onConfigureGameSignal(8, 25, 25);
//	logic_->onStartGameSignal();
	startGUI();
}

void AppMain::createGUI() {
	gui_ = IGUI::createGUI();
	gui_->create();
}

void AppMain::createLogic() {
	logic_ = ILogic::createLogic();
}

void AppMain::configureGUI(int argc, char **argv) {
	gui_->configure(argc, argv);
}

void AppMain::initializeGUI() {
	gui_->initialize();
}

void AppMain::startGUI() {
	gui_->start();
}


