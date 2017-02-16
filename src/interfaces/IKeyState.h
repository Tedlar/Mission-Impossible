/*
 * IKeyState.h
 *
 *  Created on: 16 lut 2017
 *      Author: Antoni Tomaszuk
 */

#ifndef INTERFACES_IKEYSTATE_H_
#define INTERFACES_IKEYSTATE_H_

#include <src/interfaces/IKeyType.h>
#include <memory>


class IKeyState {
public:
	virtual ~IKeyState() {}
	static std::shared_ptr<IKeyState> createKeyState();

	virtual void create() = 0;

	virtual void setPressedKey(KeyType) = 0;
	virtual KeyType getPresedKey() = 0;
};


#endif // INTERFACES_IKEYSTATE_H_
