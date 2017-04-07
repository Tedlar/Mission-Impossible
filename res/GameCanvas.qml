import QtQuick 2.0

Item {
    id: canvas
    property Repeater repeater: enemiesRepeater
    property int mapSize: 3
    property int squareSize: width/mapSize
    height: width
    Component.onCompleted: {
        console.log("width/mapSize: " + canvas.width)
        setPlayerPosition(1,1)
        setPlayerPosition(0,0)
    }
    Rectangle {
        anchors.fill: parent
        border.color: "black"
        border.width: canvas.width/50


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
