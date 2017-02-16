/*
 * Window.h
 *
 *  Created on: 16 lut 2017
 *      Author: tedlar
 */

#ifndef GUI_WINDOW_H_
#define GUI_WINDOW_H_

#include <src/interfaces/IKeyType.h>
#include <QtWidgets/qmainwindow.h>


class Window : public QMainWindow {
	Q_OBJECT
public:
	virtual ~Window();

	bool eventFilter(QObject *target, QEvent *event);

signals:
	void sendKeySignal(KeyType);
};

#endif // GUI_WINDOW_H_
