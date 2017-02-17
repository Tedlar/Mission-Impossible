/*
 * IKeyGameHandler.h
 *
 *  Created on: 17 lut 2017
 *      Author: Antoni Tomaszuk
 */

#ifndef INTERFACES_IKEYGAMEHANDLER_H_
#define INTERFACES_IKEYGAMEHANDLER_H_

#include <src/interfaces/IController.h>
#include <src/interfaces/IKeyManager.h>
#include <src/interfaces/IKeyType.h>
#include <memory>


class IKeyGameHandler {
public:
	virtual ~IKeyGameHandler() {}
	static std::shared_ptr<IKeyGameHandler> createKeyGameHandler();

	virtual void create() = 0;
	virtual void configure(const std::shared_ptr<IController>& _controller,
                           const std::shared_ptr<IKeyManager>& _keyManager) = 0;
	virtual void start(const std::shared_ptr<IKeyGameHandler>& _ptr) = 0;

	virtual void process() = 0;
};


#endif // INTERFACES_IKEYGAMEHANDLER_H_
