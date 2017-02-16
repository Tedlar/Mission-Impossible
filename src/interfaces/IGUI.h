/*
 * IGUI.h
 *
 *  Created on: 16 lut 2017
 *      Author: tedlar
 */

#ifndef INTERFACES_IGUI_H_
#define INTERFACES_IGUI_H_

#include <src/interfaces/IKeyType.h>
#include <QObject>
#include <memory>


class IGUI : public QObject {
	Q_OBJECT
public:
	virtual ~IGUI() {}
	static std::shared_ptr<IGUI> createGUI();

	virtual void create() = 0;
	virtual void configure(int& argc, char **argv) = 0;
	virtual void initialize() = 0;
	virtual void start() = 0;

	void sendKey(KeyType _key) { emit sendKeySignal(_key); }

signals:
	void sendKeySignal(KeyType);

public slots:
	virtual void onSendObjectPossitionSignal(uint8_t, uint8_t, uint8_t) = 0;
};

#endif // SRC_INTERFACES_IGUI_H_
