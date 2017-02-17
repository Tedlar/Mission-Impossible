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
#include <memory>


//template<class T>
//class QueueData;


class KeyManager : public IKeyManager {
public:
	KeyManager();
	~KeyManager();

	void create();
	void write(const KeyType& _type);
	void readKeyGame(KeyType&);
	void readKeyMove(KeyType&);

private:
	QueueData<KeyType> keyGame_;
	QueueData<KeyType> keyMove_;
//	std::shared_ptr<QueueData<KeyType>> keyGame_;
//	std::shared_ptr<QueueData<KeyType>> keyMove_;
};

#endif // LOGIC_KEYBOARD_KEYMANAGER_H_
