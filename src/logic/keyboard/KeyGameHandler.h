/*
 * KeyGameHandler.h
 *
 *  Created on: 17.02.2017
 *      Author: Antoni Tomaszuk
 */

#ifndef LOGIC_KEYBOARD_KEYGAMEHANDLER_H_
#define LOGIC_KEYBOARD_KEYGAMEHANDLER_H_

#include <src/interfaces/IKeyGameHandler.h>
#include <boost/thread.hpp>
#include <memory>


class IController;
class IKeyManager;

class KeyGameHandler : public IKeyGameHandler {
public:
	KeyGameHandler();
	KeyGameHandler(const KeyGameHandler&) = delete;
	~KeyGameHandler();

	void create();
	void configure(const std::shared_ptr<IController>& _controller,
                   const std::shared_ptr<IKeyManager>& _keyManager);
	void start(const std::shared_ptr<IKeyGameHandler>& _ptr);
	void stop();
	void process();

private:
	bool isStoped_;
	KeyType key_;
	std::unique_ptr<boost::thread> worker_;
	std::shared_ptr<IController> controller_;
	std::shared_ptr<IKeyManager> keyManager_;
};

#endif // LOGIC_KEYBOARD_KEYGAMEHANDLER_H_
