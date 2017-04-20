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
	void configureGameSignal(uint8_t _n, uint8_t _sx, uint8_t _sy);
	void startGameSignal();
	void stopGameSignal();

public slots:
	virtual void onSendObjectPossitionSignal(uint16_t _id, uint16_t _x, uint16_t _y) = 0;
};

#endif // SRC_INTERFACES_IGUI_H_
