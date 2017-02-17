/*
 * Gui.cpp
 *
 *  Created on: 16 lut 2017
 *      Author: tedlar
 */

#include <src/gui/GUI.h>

#include <src/gui/Window.h>

#include <QtWidgets/qapplication.h>
#include <QtWidgets/qmainwindow.h>


GUI::~GUI() {}

void GUI::create() {
	app_ = std::make_shared<QApplication>(argc_, argv_);
}

void GUI::configure(int& argc, char **argv) {}
void GUI::initialize() {}

void GUI::start() {
	// Test -------
	Window m;
	m.installEventFilter(&m);
	m.show();

	connect(&m, SIGNAL(sendKeySignal(KeyType)), this, SIGNAL(sendKeySignal(KeyType)));
	//-------------

	app_->exec();
}

void GUI::onSendObjectPossitionSignal(uint8_t id, uint8_t x, uint8_t y) {

}

