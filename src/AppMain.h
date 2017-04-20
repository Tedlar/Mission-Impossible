/*
 * AppMain.h
 *
 *  Created on: 15 lut 2017
 *      Author: tedlar
 */

#ifndef APPMAIN_H_
#define APPMAIN_H_

#include <src/interfaces/IGUI.h>
#include <src/interfaces/ILogic.h>
Q_DECLARE_METATYPE(uint16_t)

class AppMain {
public:
	~AppMain();

	void create();
	void configure(int& argc, char **argv);
	void initialize();
	void start();

private:
	std::shared_ptr<IGUI>   gui_;
	std::shared_ptr<ILogic> logic_;

private:
	void createGUI();
	void createLogic();

	void configureGUI(int argc, char **argv);

	void initializeGUI();

	void startGUI();

};

#endif // APPMAIN_H_
