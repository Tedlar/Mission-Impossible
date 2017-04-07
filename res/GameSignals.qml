import QtQuick 2.7

Item {
//        focus: true
        Keys.onPressed:{
//            console.log("button")
            if (event.key == Qt.Key_Up){
                console.log("up button")
    //            testUser.y-=10
                gameSignals.sendKey(0)
                return
            }
            if(event.key == Qt.Key_Down){
                console.log("down button")
    //            testUser.y+=10
                gameSignals.sendKey(1)
                return
            }
            if(event.key == Qt.Key_Left){
    //            testUser.x-=10
                console.log("left button")
                gameSignals.sendKey(2)
                return
            }
            if(event.key == Qt.Key_Right){
    //            testUser.x+=10
                console.log("right button")
                gameSignals.sendKey(3)
                return
            }


        }
    signal startGameSignal()
    signal stopGameSignal()
    signal sendKey(int key)
    signal configureGameSignal(int enemyNumber,int x,int y)
    function setObjectPosition(objectNumber,x,y){
        var name = "object_"+objectNumber.toString()
        for(var i = 0; i < gameCanvas.children.length; ++i){
            console.log("searching child name: " + name)
            console.log("current objectname: " + gameCanvas.children[i].objectName)
                 if(gameCanvas.children[i].objectName === name){
                     console.log("found child name: " + name)
                     gameCanvas.children[i].setObjectPosition(x,y)
                     console.log("position set object: " + name)

                 }
        }
    }



}
