import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Rectangle {
    id: window
    anchors.fill: parent
    color: "#80000000"
    Rectangle{
        color: "#FFFFFF"
        width: parent.width*0.8
        height: parent.height*0.8
        anchors.centerIn: parent
        GridLayout {
               anchors.fill: parent // GridLayout must have the right size now
               rows: 3; columns: 2
               columnSpacing: 0; rowSpacing: 0 // changed from spacing: 0

               Text{
                   text: "Map size: "
                   Layout.alignment: Qt.AlignHCenter
               }
               SpinBox {
                   id: mapSize
                   from: 0
                   to: items.length - 1
                   value: 1 // "Medium"
                   Layout.alignment: Qt.AlignHCenter


                   property var items: ["Small", "Medium", "Large"]

                   textFromValue: function(value) {
                       return items[value];
                   }

                   valueFromText: function(text) {
                       for (var i = 0; i < items.length; ++i) {
                           if (items[i].toLowerCase().indexOf(text.toLowerCase()) === 0)
                               return i
                       }
                       return sb.value
                   }
               }
               Text{
                   text: "Enemies number:  "
                   Layout.alignment: Qt.AlignHCenter
               }
               SpinBox{
                   id: enemiesNumber
                   Layout.alignment: Qt.AlignHCenter
                   value: 1

               }
               Text{
                   text: " "
               }
               Button{
                   Layout.alignment: Qt.AlignHCenter
                   text: "Configure"
                   onClicked: {

                       var x
                       var y
                       if(mapSize.value == 0){
                           x = 5
                           y = 5
                       }
                       if(mapSize.value == 1){
                           x = 25
                           y = 25
                       }
                       if(mapSize.value == 2){
                           x = 50
                           y = 50
                       }
                       console.log("mapSize.value: ",mapSize.value)
                       console.log("configure game(enemies, x, y): ",enemiesNumber.value,x,y)
                       gameCanvas.mapSize = x
                       gameCanvas.repeater.model = enemiesNumber.value
                       gameCanvas.tiles.model = x*x
                       gameCanvas.gameGrid.columns = x
                       gameCanvas.gameGrid.rows = x
                       gameSignals.stopGameSignal()
                       gameSignals.configureGameSignal(enemiesNumber.value,x,y)
                       window.visible = false
                       console.log("activeFocusControl: ",mainWindow.activeFocusControl)
                       gameSignals.startGameSignal()
                       gameSignals.focus = true

                       console.log("activeFocusControl: ",mainWindow.activeFocusControl)

                   }
               }
        }
    }


}
