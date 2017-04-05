/*
 * ObjectAgent.h
 *
 *  Created on: 15 lut 2017
 *      Author: tedlar
 */

#ifndef AGENT_OBJECTAGENT_H_
#define AGENT_OBJECTAGENT_H_

#include <src/interfaces/IObject.h>


enum class AlgorithmType {
	None,
	Diagonally,
	FirstHorizontally,
	FirstVertically
};

enum class MoveDirection {
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT,
	MOVE_STAY
};


class ObjectAgent : public IObject {
public:
	ObjectAgent();
	ObjectAgent(const ObjectAgent&) = delete;

	void move(uint16_t& _x, uint16_t& _y, KeyType _key = MOVE_STAY);

private:
	static int seed_;
	AlgorithmType algorithmType_;
	uint8_t moveCounter_;

private:
	void selectAlgorithm();
	MoveDirection moveAlgorithmDiagonally(uint16_t _posX, uint16_t _posY);
	MoveDirection moveAlgorithmFirstHorizontally(uint16_t _posX, uint16_t _posY);
	MoveDirection moveAlgorithmFirstVertically(uint16_t _posX, uint16_t _posY);
	MoveDirection moveAlgorithmRandom();
	void changePosition(uint16_t& _posX, uint16_t& _posY, MoveDirection _direction);
};

#endif // AGENT_OBJECTAGENT_H_
