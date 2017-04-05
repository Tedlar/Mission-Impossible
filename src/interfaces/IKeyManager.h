/*
 * IKeyManager.h
 *
 *  Created on: 17 lut 2017
 *      Author: Antoni Tomaszuk
 */

#ifndef INTERFACES_IKEYMANAGER_H_
#define INTERFACES_IKEYMANAGER_H_

#include <src/interfaces/IKeyType.h>
#include <memory>


class IKeyManager {
public:
	virtual ~IKeyManager() {}
	static std::shared_ptr<IKeyManager> createKeyManager();

	virtual void write(const KeyType& _type) = 0;
	virtual void readKey(KeyType&) = 0;
};


#endif // INTERFACES_IKEYMANAGER_H_
