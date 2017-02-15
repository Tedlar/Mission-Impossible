/*
 * IController.h
 *
 *  Created on: 15 lut 2017
 *      Author: tedlar
 */

#ifndef INTERFACES_ICONTROLLER_H_
#define INTERFACES_ICONTROLLER_H_

#include <qt5/QtCore/qobjectdefs.h>
#include <qt5/QtCore/qobject.h>

#include <memory>


class IController : public QObject {

	Q_OBJECT

public:
	virtual ~IController() {}
	static std::shared_ptr<IController> produceController();

	virtual void create() = 0;
	virtual void configure() = 0;
	virtual void initialize() = 0;
	virtual void start() = 0;

signals:
	void setObjectPosition(uint8_t id, uint8_t x, uint8_t y);
};


#endif // INTERFACES_ICONTROLLER_H_
