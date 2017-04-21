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

	//!  Logic interface
	/*!
		Interface for game logic
	*/
class ILogic : public QObject {
	Q_OBJECT
public:
	//! destructor
	/*!
	*/
	virtual ~ILogic() {}
	//! Function which create Logic
	/*!
	*/
	static std::shared_ptr<ILogic> createLogic();

signals:

	//! SIGNAL triggered when object position is changed
	/*!
	  \param object object id
	  \param x x position to be set
	  \param y y position to be set
	*/
	void sendObjectPossitionSignal(uint16_t _id, uint16_t _x, uint16_t _y);

	//! SIGNAL of end game
	/*!
	*/
	void endGameSignal();

public slots:

	//! SLOT trigerred by SIGNAL from QML GUI when key is pushed
	/*!
	 \param key key value regarding KeyType class
	*/
	virtual void onSendKeySignal(KeyType _key) = 0;

	//! SLOT trigerred by SIGNAL from QML GUI when configuration is sent
	/*!
	 \param x width of map
	 \param y height of map
	 \param enemyNumber number of enemies
	*/
	virtual void onConfigureGameSignal(uint8_t _n, uint8_t _sx, uint8_t _sy) = 0;

	//! SLOT triggered on startGameSignal from GUI
	/*!
	*/
	virtual void onStartGameSignal() = 0;

	//! SLOT triggered on stopGameSignal from GUI
	/*!
	*/
	virtual void onStopGameSignal() = 0;
};


#endif // INTERFACES_ILOGIC_H_
