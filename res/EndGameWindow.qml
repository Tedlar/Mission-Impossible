import QtQuick 2.0
import QtQuick.Controls 2.0

Rectangle {
    id: window
    anchors.fill: parent
    color: "#80000000"
    Rectangle{
        color: "#FFFFFF"
        width: parent.width*0.8
        height: parent.height*0.8
        anchors.centerIn: parent
        Text{
            anchors.horizontalCenter: parent.Center
            x: 20
            text: "You was catched by agent: game ended."
        }
        Button{
            text: "Ok"
            anchors.centerIn: parent
            onClicked: {
                endGameWindow.visible = false
                configurationWindow.visible = true
            }
        }
    }
}
