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

signals:
	void sendObjectPossitionSignal(uint8_t, uint8_t, uint8_t);

public slots:
	virtual void onSendKeySignal(KeyType) = 0;
};


#endif // INTERFACES_ILOGIC_H_
