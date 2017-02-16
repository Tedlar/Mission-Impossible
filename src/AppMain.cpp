/*
 * AppMain.cpp
 *
 *  Created on: 15 lut 2017
 *      Author: tedlar
 */

#include <src/AppMain.h>
#include <QObject>


AppMain::~AppMain() {}

void AppMain::create() {
	createGUI();
	createLogic();
}

void AppMain::configure(int& argc, char **argv) {
	configureGUI(argc, argv);
	configureLogic(argc, argv);
}

void AppMain::initialize() {
	initializeGUI();
	initializeLogic();
	QObject::connect(gui_.get(), SIGNAL(sendKeySignal(KeyType)), logic_.get(), SLOT(onSendKeySignal(KeyType)));
}

void AppMain::start() {
	startLogic();
	startGUI();
}

void AppMain::createGUI() {
	gui_ = IGUI::createGUI();
	gui_->create();
}

void AppMain::createLogic() {
	logic_ = ILogic::createLogic();
	logic_->create();
}

void AppMain::configureGUI(int argc, char **argv) {
	gui_->configure(argc, argv);
}

void AppMain::configureLogic(int argc, char **argv) {
	logic_->configure(argc, argv);
}

void AppMain::initializeGUI() {
	gui_->initialize();
}

void AppMain::initializeLogic() {
	logic_->initialize();
}

void AppMain::startGUI() {
	gui_->start();
}

void AppMain::startLogic() {
	logic_->start();
}

