import QtQuick 2.0

Item {
    id: canvas
    property Repeater repeater: enemiesRepeater
    property Repeater tiles: tileRepeater
    property Grid gameGrid: grid
    property int mapSize: 3
    property int squareSize: width/mapSize
    height: width
    Component.onCompleted: {
        console.log("width/mapSize: " + canvas.width)
    }
//    Rectangle {
//        anchors.fill: parent
////        border.color: "black"
////        border.width: canvas.width/50


//    }
    Grid {
        id: grid
        columns: mapSize
        rows: mapSize
        anchors.fill: parent
        Repeater{
            id: tileRepeater
            model: mapSize*mapSize
            Rectangle{
                color: "transparent"
                border.width: 2
                border.color: "black"
                width: squareSize
                height: squareSize
            }
        }

    }
    Object{
        id: player
        number: 0
        squareSize: canvas.squareSize
        headColor: "green"
//        x: squareSize*(mapSize - 1)/2
//        y: squareSize*(mapSize - 1)/2
//        squareSize: root.squareSize


    }
    Repeater{
        id: enemiesRepeater
        model: 0
        Object{
            number: index+1
            squareSize: canvas.squareSize
            headColor: "red"
        }
    }


    function setPlayerPosition(x,y) {
        player.setObjectPosition(x,y)
    }

}
