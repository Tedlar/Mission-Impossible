/*
 * Logic.h
 *
 *  Created on: 16 lut 2017
 *      Author: tedlar
 */

#ifndef LOGIC_LOGIC_H_
#define LOGIC_LOGIC_H_

#include <src/interfaces/ILogic.h>
#include <src/interfaces/IController.h>
#include <src/interfaces/IKeyManager.h>
#include <src/interfaces/IObject.h>

#include <thread>
#include <vector>

	//!  Logic interface implementation
	/*!

	*/
class Logic : public ILogic {
public:
	//! constructor
	/*!
	*/
	Logic();
	//! destructor
	/*!
	*/
	~Logic();

public slots:
	//! SLOT trigerred by SIGNAL from QML GUI when key is pushed
	/*!
	 \param key key value regarding KeyType class
	*/
	void onSendKeySignal(KeyType);

	//! SLOT trigerred by SIGNAL from QML GUI when configuration is sent
	/*!
	 \param x width of map
	 \param y height of map
	 \param enemyNumber number of enemies
	*/
	void onConfigureGameSignal(uint8_t _n, uint8_t _sx, uint8_t _sy);

	//! SLOT triggered on startGameSignal from GUI
	/*!
	*/
	void onStartGameSignal();

	//! SLOT triggered on stopGameSignal from GUI
	/*!
	*/
	void onStopGameSignal();

private:
	//! variable holds info if game is configured
	/*!
	*/
	bool gameConfigured_;
	//! variable holds info if game is started
	/*!
	*/
	bool gameStarted_;

	//! variable holds info about player move length
	/*!
	*/
	uint8_t playerMove_;

	//! variable holds info about objectNumber
	/*!
	*/
	uint8_t objectNumber_;

	//! variables holding info about map size
	/*!
	*/
	uint16_t sizeX_, sizeY_;

	//! variable holding controller
	/*!
	*/
	std::shared_ptr<IController>     controller_;

	//! variable holding keyManager
	/*!
	*/
	std::shared_ptr<IKeyManager>     keyManager_;

	//! vector holding objects
	/*!
	*/
	std::vector<std::shared_ptr<IObject>> objects_;

	//! logic thread
	/*!
	*/
	std::shared_ptr<std::thread> logicThread_;

private:
	//! create controller
	/*!
	*/
	void createController();
	//! create Key Manager
	/*!
	*/
	void createKeyManager();

	//! logic thread loop
	/*!
	*/
	void logicLoop();

	//! executes player move
	/*!
	*/
	bool playerMove(KeyType _key);

	//! check if position is occupied
	/*!
	*/
	bool checkForObject(uint16_t& _posX, uint16_t& _posY, uint8_t _id, uint8_t _view, bool _checkForPlayer = true);

	//! clear game logic
	/*!
	*/
	void gameClearLogic();

	//! print positions to stdout
	/*!
	*/
	void printPositions();
};

#endif // LOGIC_LOGIC_H_
