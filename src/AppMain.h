/*
 * AppMain.h
 *
 *  Created on: 15 lut 2017
 *      Author: tedlar
 */

#ifndef APPMAIN_H_
#define APPMAIN_H_

#include <src/interfaces/IObject.h>
#include "interfaces/IController.h"
#include <map>


class AppMain {
public:
	AppMain();
	~AppMain();

	void create();
	void configure(int argc, char **argv);
	void initialize();
	void start();

private:
	uint8_t agentNumber_;
	std::shared_ptr<IController> controller_;
	std::map<uint8_t, std::shared_ptr<IObject>> objectsMap_;

private:
	void createController();
	void createObjects();

	void configureController();
	void initializeController();
	void startController();

};

#endif // APPMAIN_H_
