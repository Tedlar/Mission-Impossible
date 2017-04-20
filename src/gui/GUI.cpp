/*
 * Gui.cpp
 *
 *  Created on: 16 lut 2017
 *      Author: tedlar
 */

#include <src/gui/GUI.h>

#include <src/gui/Window.h>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>


GUI::~GUI() {}

void GUI::create() {
	app_ = std::make_shared<QGuiApplication>(argc_, argv_);
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	qRegisterMetaType<uint8_t>();
	qRegisterMetaType<uint16_t>("uint16_t");

}

void GUI::configure(int& argc, char **argv) {}
void GUI::initialize() {}

void GUI::start() {
	// Test -------
	QQmlApplicationEngine engine;
	QString qml = QStringLiteral("qrc:/main.qml");
	engine.load(QUrl(qml));
	QObject *topLevel = engine.rootObjects().value(0);
	QObject *childObj = topLevel->findChild<QObject *>("gameSignals");
	if (childObj)
	{
		connect(childObj, SIGNAL(configureGameSignal(int,int,int)), this, SLOT(onConfigureGameSignal(int,int,int)));
		connect(childObj, SIGNAL(startGameSignal()), this, SIGNAL(startGameSignal()));
		connect(childObj, SIGNAL(stopGameSignal()), this, SIGNAL(stopGameSignal()));
		connect(childObj, SIGNAL(sendKey(int)), this, SLOT(onsendKey(int)));
		connect(this, SIGNAL(sendObjectPossitionSignal(QVariant, QVariant, QVariant)), childObj, SLOT(setObjectPosition(QVariant, QVariant, QVariant)));
		connect(this, SIGNAL(endGameSignal()), childObj, SLOT(onEndGameSignal()));
	}

//	connect(&m, SIGNAL(sendKeySignal(KeyType)), this, SIGNAL(sendKeySignal(KeyType)));
	//-------------

	app_->exec();
}

void GUI::onSendObjectPossitionSignal(uint16_t id, uint16_t x, uint16_t y) {
	emit sendObjectPossitionSignal(QVariant(QString::number(id)),QVariant(QString::number(x)),QVariant(QString::number(y)));
}

void GUI::onConfigureGameSignal(int x, int y, int enemyNumber)
{
	emit configureGameSignal(x ,y,enemyNumber);


}

void GUI::onsendKey(int key)
{
	sendKey(static_cast<KeyType>(key));
}

