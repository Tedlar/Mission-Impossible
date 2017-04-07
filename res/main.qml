import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Window 2.0

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 640
    height: width * 0.8
    Component.onCompleted: {
        setX(Screen.width / 2  );
        setY(Screen.height / 2  );
//        gameCanvas.setPlayerPosition(1,1)
//        gameCanvas.setPlayerPosition(0,0)
        console.log("activeFocusControl: ",mainWindow.activeFocusControl)
    }
    title: qsTr("Mission Impossible Game")
//    focus: true


    GameCanvas{
        id: gameCanvas
        width: parent.width*0.8
        anchors.left: parent.left
        anchors.top: parent.top
    }
    GameMenu{
        anchors.left: gameCanvas.right
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom


    }

    GameConfiguratorWindow{
        id: configurationWindow

    }

    GameSignals{
        focus: true
        id: gameSignals
        objectName: "gameSignals"

    }



}
