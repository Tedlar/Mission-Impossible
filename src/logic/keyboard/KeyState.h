/*
 * KeyState.h
 *
 *  Created on: 16 lut 2017
 *      Author: Antoni Tomaszuk
 */

#ifndef LOGIC_KEYBOARD_KEYSTATE_H_
#define LOGIC_KEYBOARD_KEYSTATE_H_

#include <src/interfaces/IKeyState.h>


class KeyState : public IKeyState {
public:
	~KeyState();

	void create();

	void setPressedKey(KeyType);
	KeyType getPresedKey();

private:
	bool unread_;
	KeyType key_;

};

#endif // LOGIC_KEYBOARD_KEYSTATE_H_
