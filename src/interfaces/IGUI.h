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


	//!  GUI Interface
	/*!

	*/
class IGUI : public QObject {
	Q_OBJECT
public:

	//! destructor
	/*!
	*/
	virtual ~IGUI() {}
	static std::shared_ptr<IGUI> createGUI();

	//! Function which create GUI, should be called after initialuze
	/*!
	*/
	virtual void create() = 0;

	//! set argc & argv and configure GUI
	/*!
	  \param argc number of arguments
	  \param argv arguments
	*/
	virtual void configure(int& argc, char **argv) = 0;

	//! init GUI, should be called after configure
	/*!
	*/
	virtual void initialize() = 0;

	//! starts GUI
	/*!
	*/
	virtual void start() = 0;

	//! sendKey
	/*!
	*/
	void sendKey(KeyType _key) { emit sendKeySignal(_key); }

signals:
	//! SIGNAL sendKeySignal
	/*!
	*/
	void sendKeySignal(KeyType);

	//! SIGNAL configureGameSignal
	/*!
	*/
	void configureGameSignal(uint8_t _n, uint8_t _sx, uint8_t _sy);

	//! SIGNAL startGameSignal
	/*!
	*/
	void startGameSignal();

	//! SIGNAL stopGameSignal
	/*!
	*/
	void stopGameSignal();

public slots:

	//! SIGNAL used by SLOT in QML GUI
	/*!
	  \param object object id
	  \param x x position to be set
	  \param y y position to be set
	*/
	virtual void onSendObjectPossitionSignal(uint16_t _id, uint16_t _x, uint16_t _y) = 0;
};

#endif // SRC_INTERFACES_IGUI_H_
