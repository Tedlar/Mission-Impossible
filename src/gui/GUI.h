/*
 * Gui.h
 *
 *  Created on: 16 lut 2017
 *      Author: tedlar
 */

#ifndef GUI_GUI_H_
#define GUI_GUI_H_

#include <src/interfaces/IGUI.h>
#include <QVariant>
Q_DECLARE_METATYPE(uint16_t)

class QGuiApplication;


class GUI : public IGUI {
	Q_OBJECT
public:
	~GUI();

	void create();
	void configure(int& argc, char **argv);
	void initialize();
	void start();
signals:
	/**
	* SIGNAL used by SLOT in QML GUI
	* @see sendObjectPossitionSignal(QVariant object, QVariant x, QVariant y)
	* @param object object id
	* @param x x position to be set
	* @param y y position to be set
	*/
	void sendObjectPossitionSignal(QVariant object, QVariant x, QVariant y);
	void endGameSignal();
public slots:
	/**
	* SLOT triggered by SIGNAL from game logic when object positions needs to be set. This function converts format of parametrs and triggers signal for QML GUI
	* @see onSendObjectPossitionSignal(uint16_t id, uint16_t x, uint16_t y)
	* @param id object id
	* @param x x position to be set
	* @param y y position to be set
	*/
	void onSendObjectPossitionSignal(uint16_t id, uint16_t x, uint16_t y);
	/**
	* SLOT trigerred by SIGNAL from QML GUI when configuration should be send
	* @see onConfigureGameSignal(int x, int y, int enemyNumber)
	* @param x width of map
	* @param y height of map
	* @param enemyNumber number of enemies
	*/
	void onConfigureGameSignal(int x, int y, int enemyNumber);
	/**
	* SLOT trigerred by SIGNAL from QML GUI when key is pushed
	* @see onConfigureGameSignal(int x, int y, int enemyNumber)
	* @param key key value regarding KeyType class
	*/
	void onsendKey(int key);


private:
	int argc_ = 1;
	char* argv_[1] = { (char*)"Game" };
	std::shared_ptr<QGuiApplication> app_;
};

#endif // GUI_GUI_H_
