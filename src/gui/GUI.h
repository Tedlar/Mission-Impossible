/*
 * Gui.h
 *
 *  Created on: 16 lut 2017
 *      Author: tedlar
 */

#ifndef GUI_GUI_H_
#define GUI_GUI_H_

#include <src/interfaces/IGUI.h>

class QApplication;

class GUI : public IGUI {
public:
	~GUI();

	void create();
	void configure(int& argc, char **argv);
	void initialize();
	void start();

public slots:
	void onSendObjectPossitionSignal(uint8_t, uint8_t, uint8_t);

private:
	int argc_ = 1;
	char* argv_[1] = { (char*)"Game" };
	std::shared_ptr<QApplication> app_;
};

#endif // GUI_GUI_H_
