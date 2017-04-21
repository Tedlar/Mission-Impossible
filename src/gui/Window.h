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

	//!  Window interface implementation
	/*!
		Window class
	*/
class Window : public QMainWindow {
	Q_OBJECT
public:

	//! destructor
	/*!
	*/
	virtual ~Window();

	//! set event filter
	/*!
	  \param target object id
	  \param event number of arguments
	*/
	bool eventFilter(QObject *target, QEvent *event);

signals:
	//!Signal triggered when new key is triggered
	/*!
	*/
	void sendKeySignal(KeyType);
};

#endif // GUI_WINDOW_H_
