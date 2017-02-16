/*
 * Window.cpp
 *
 *  Created on: 16 lut 2017
 *      Author: tedlar
 */

#include <src/gui/Window.h>
#include <QKeyEvent>

#include <QDebug>


Window::~Window() {}

bool Window::eventFilter(QObject *target, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        switch (keyEvent->key()) {
			case Qt::Key_Up:
	            qDebug() << "Key Up";
	            emit sendKeySignal(MOVE_UP);
				break;
			case Qt::Key_Down:
				qDebug() << "Key Down";
	            emit sendKeySignal(MOVE_DOWN);
				break;
			case Qt::Key_Left:
				qDebug() << "Key Left";
	            emit sendKeySignal(MOVE_LEFT);
				break;
			case Qt::Key_Right:
				qDebug() << "Key Right";
	            emit sendKeySignal(MOVE_RIGHT);
				break;
			case Qt::Key_Space:
				qDebug() << "Key Space";
	            emit sendKeySignal(MOVE_STAY);
				break;
			case Qt::Key_Q:
				qDebug() << "Key Restart";
	            emit sendKeySignal(GAME_RESTART);
				break;
			case Qt::Key_A:
				qDebug() << "Key Reconfigure";
	            emit sendKeySignal(GAME_RECONFIGURE);
				break;
			default:
				break;
        }
    }
    return QMainWindow::eventFilter(target, event);
}
