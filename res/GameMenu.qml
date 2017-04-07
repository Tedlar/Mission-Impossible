import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    property bool gameStarted: false
    Rectangle {
        anchors.fill: parent
        color: "grey"
    }
    Button {
        id: startButton
        text: "START"
        width: parent.width
        height: parent.height*0.2
        onClicked: {
            if(gameStarted){
                gameSignals.stopGameSignal()
                startButton.text = "START"
                gameStarted = false
                configurationWindow.visible = true

            }else{
                gameSignals.startGameSignal()
                startButton.text = "STOP"
                gameStarted = true
                gameSignals.setObjectPosition(0,2,1)
                gameSignals.setObjectPosition(1,1,1)
                gameSignals.setObjectPosition(2,2,2)
                gameSignals.forceActiveFocus()
                console.log("activeFocusControl: ",mainWindow.activeFocusControl)
            }
        }

    }
//    Button {
//        text: "Stop"
//        width: parent.width
//        height: parent.height*0.2
//        anchors.top: startButton.bottom


//    }

}
