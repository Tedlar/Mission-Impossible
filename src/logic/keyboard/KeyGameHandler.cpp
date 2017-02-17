/*
 * KeyGameHandler.cpp
 *
 *  Created on: 17.02.2017
 *      Author: Antoni Tomaszuk
 */

#include <src/logic/keyboard/KeyGameHandler.h>


KeyGameHandler::KeyGameHandler() {
	isStoped_ = false;
	key_ = GAME_RECONFIGURE;
}

KeyGameHandler::~KeyGameHandler() {
	stop();
}

void KeyGameHandler::create() {
	isStoped_ = false;
	key_ = GAME_RECONFIGURE;
}

void KeyGameHandler::configure(const std::shared_ptr<IController>& _controller,
                               const std::shared_ptr<IKeyManager>& _keyManager) {
	controller_ = _controller;
	keyManager_ = _keyManager;
}

void KeyGameHandler::start(const std::shared_ptr<IKeyGameHandler>& _ptr) {
	worker_ = std::unique_ptr<boost::thread>(new boost::thread(boost::bind(&IKeyGameHandler::process, _ptr.get())));
}

void KeyGameHandler::stop() {
	isStoped_ = true;
	worker_->interrupt();
	worker_->join();
}

void KeyGameHandler::process() {
	while (true) {
		keyManager_->readKeyGame(key_);
		if (isStoped_) break;
		controller_->receiveKeyGame(key_);
	}
}

