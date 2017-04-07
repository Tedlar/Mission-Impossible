import QtQuick 2.0

Item {
    width: squareSize
    height: squareSize
    id: root
    property int number: 0
    objectName: "object_"+number.toString()
    property int squareSize
    property int oldX: 0
    property int oldY: 0
//    focus: true
    property color headColor: "green"

    Rectangle{
        width: parent.width
        height: parent.height/2
//        anchors.left:parent.left
        anchors.centerIn: parent
        color: "black"
        radius: width/5

    }
    Rectangle {
        color: headColor
        width: parent.width/2
        height: width
        anchors.centerIn: parent
        radius: width/2

    }
    function refreshRotation(){
        root.rotation = Math.atan2(root.y - oldY, root.x - oldX);

    }
    function setObjectPosition(x,y){//co jest trzecim argumentem?
        oldX = root.x
        oldY = root.y
        root.x = squareSize*x
        root.y = gameCanvas.mapSize * squareSize - squareSize*y
        console.log("square size: ",squareSize)
        console.log("x: ",x)
        console.log("y: ",y)
        console.log("new x: ",root.x)
        console.log("new y: ",root.y)
//        refreshRotation()
    }


}
