/*
 * IController.h
 *
 *  Created on: 15 lut 2017
 *      Author: tedlar
 */

#ifndef INTERFACES_ICONTROLLER_H_
#define INTERFACES_ICONTROLLER_H_

#include <src/interfaces/IKeyType.h>
#include <QObject>
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

	virtual void receiveKeyGame(KeyType) = 0;

signals:
	void sendObjectPossitionSignal(uint8_t, uint8_t, uint8_t);
};


#endif // INTERFACES_ICONTROLLER_H_
