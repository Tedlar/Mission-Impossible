/*
 * Controller.h
 *
 *  Created on: 15 lut 2017
 *      Author: tedlar
 */

#ifndef CONTROLLER_CONTROLLER_H_
#define CONTROLLER_CONTROLLER_H_

#include <src/interfaces/IController.h>


class Controller : public IController {
public:
	Controller();
	virtual ~Controller();

	void create();
	void configure();
	void initialize();
	void start();
};

#endif // CONTROLLER_CONTROLLER_H_
