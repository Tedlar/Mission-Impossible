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

	//!  GUI interface implementation
	/*!
		GUI class connects to qml
	*/
class GUI : public IGUI {
	Q_OBJECT
public:

	//! destructor
	/*!
	*/
	~GUI();

	//! Function which create GUI, should be called after initialuze
	/*!
	*/
	void create();

	//! set argc & argv and configure GUI
	/*!
	  \param argc number of arguments
	  \param argv arguments
	*/
	void configure(int& argc, char **argv);

	//! init GUI, should be called after configure
	/*!
	*/
	void initialize();

	//! starts GUI
	/*!
	*/
	void start();
signals:

	//! SIGNAL used by SLOT in QML GUI
	/*!
	  \param object object id
	  \param x x position to be set
	  \param y y position to be set
	*/
	void sendObjectPossitionSignal(QVariant object, QVariant x, QVariant y);
	//!Signal triggered when game ends
	/*!
	*/
	void endGameSignal();
public slots:
	//! SLOT triggered by SIGNAL from game logic when object positions needs to be set. This function converts format of parametrs and triggers signal for QML GUI
	/*!
	 \param id object id
	 \param x x position to be set
	 \param y y position to be set
	*/
	void onSendObjectPossitionSignal(uint16_t id, uint16_t x, uint16_t y);

	//! SLOT trigerred by SIGNAL from QML GUI when configuration should be send
	/*!
	 \param x width of map
	 \param y height of map
	 \param enemyNumber number of enemies
	*/
	void onConfigureGameSignal(int x, int y, int enemyNumber);
	//! SLOT trigerred by SIGNAL from QML GUI when key is pushed
	/*!
	 \param key key value regarding KeyType class
	*/
	void onsendKey(int key);


private:
	//! argc
	/*!
	*/
	int argc_ = 1;
	//! argv
	/*!
	*/
	char* argv_[1] = { (char*)"Game" };

	//! GUI object
	/*!
	*/
	std::shared_ptr<QGuiApplication> app_;
};

#endif // GUI_GUI_H_
