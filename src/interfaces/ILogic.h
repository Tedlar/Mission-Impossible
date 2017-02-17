/*
 * ILogic.h
 *
 *  Created on: 16 lut 2017
 *      Author: tedlar
 */

#ifndef INTERFACES_ILOGIC_H_
#define INTERFACES_ILOGIC_H_

#include <src/interfaces/IKeyType.h>
#include <QObject>
#include <memory>


class ILogic : public QObject {
	Q_OBJECT
public:
	virtual ~ILogic() {}
	static std::shared_ptr<ILogic> createLogic();

	virtual void create() = 0;
	virtual void configure(int& argc, char **argv) = 0;
	virtual void initialize() = 0;
	virtual void start() = 0;

	virtual void receiveKeyGame(KeyType) = 0;

signals:
	void sendObjectPossitionSignal(uint8_t _id, uint8_t _x, uint8_t _y);

public slots:
	virtual void onSendKeySignal(KeyType _key) = 0;
	virtual void onConfigureGameSignal(uint8_t _n, uint8_t _sx, uint8_t _sy) = 0;
	virtual void onStartGameSignal() = 0;
	virtual void onStopGameSignal() = 0;
};


#endif // INTERFACES_ILOGIC_H_
