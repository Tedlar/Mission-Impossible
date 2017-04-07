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
	void sendObjectPossitionSignal(QVariant object, QVariant x, QVariant y);
public slots:
	void onSendObjectPossitionSignal(uint16_t, uint16_t, uint16_t);
	void onConfigureGameSignal(int x, int y, int enemyNumber);
	void onsendKey(int key);


private:
	int argc_ = 1;
	char* argv_[1] = { (char*)"Game" };
	std::shared_ptr<QGuiApplication> app_;
};

#endif // GUI_GUI_H_
