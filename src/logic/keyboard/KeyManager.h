/*
 * KeyManager.h
 *
 *  Created on: 17.02.2017
 *      Author: Antoni Tomaszuk
 */

#ifndef LOGIC_KEYBOARD_KEYMANAGER_H_
#define LOGIC_KEYBOARD_KEYMANAGER_H_

#include <src/interfaces/IKeyManager.h>
#include <src/logic/keyboard/QueueData.h>

	//!  Key manager interface implementation
	/*!

	*/
class KeyManager : public IKeyManager {
public:
	//! constructor
	/*!
	*/
	KeyManager();

	//! destructor
	/*!
	*/
	~KeyManager();

	//! write key to manager
	/*!
	*/
	void write(const KeyType& _type);

	//! readKey
	/*!
	*/
	void readKey(KeyType&);

private:
	QueueData<KeyType> keyQueue_;
};

#endif // LOGIC_KEYBOARD_KEYMANAGER_H_
