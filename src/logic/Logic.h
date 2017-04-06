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


class Logic : public ILogic {
public:
	Logic();
	~Logic();

public slots:
	void onSendKeySignal(KeyType);
	void onConfigureGameSignal(uint8_t _n, uint8_t _sx, uint8_t _sy);
	void onStartGameSignal();
	void onStopGameSignal();

private:
	bool gameConfigured_;
	bool gameStarted_;

	uint8_t playerMove_;
	uint8_t objectNumber_;
	uint16_t sizeX_, sizeY_;
	std::shared_ptr<IController>     controller_;
	std::shared_ptr<IKeyManager>     keyManager_;
	std::vector<std::shared_ptr<IObject>> objects_;
	std::shared_ptr<std::thread> logicThread_;

private:
	void createController();
	void createKeyManager();
	void logicLoop();
	bool playerMove(KeyType _key);
	bool checkForObject(uint16_t& _posX, uint16_t& _posY, uint8_t _id, uint8_t _view, bool _checkForPlayer = true);
	void gameClearLogic();

	void printPositions();
};

#endif // LOGIC_LOGIC_H_
