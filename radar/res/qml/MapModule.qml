//import QtQuick.Controls 2.12
import QtQuick.Controls 1.4
import QtQuick 2.12
import QtPositioning 5.6
import QtQuick.Dialogs 1.0
import QtLocation 5.6
import QtQuick.Controls.Styles 1.4

Map {
    id: mapview

    property var cameraCoord: [QtPositioning.coordinate(59.896638, 30.285300), QtPositioning.coordinate(59.895270, 30.283313), QtPositioning.coordinate(59.894105, 30.286220),QtPositioning.coordinate(59.895559, 30.2860238), QtPositioning.coordinate(59.897183, 30.288422), QtPositioning.coordinate(59.897202, 30.281960)]

    property variant points: []
    property int i: 0
    property alias mapV: mapview
    property int lengthX: 0
    property int lengthY: 0
    property int startX: 0
    property int startY: 0
    property int endX: 0
    property int endY: 0
    property int rotatione: 0

    property bool canSecreting: false
    property alias rollRouteUp: rollRouteUp
    property alias anim1: rollOutAnim


    anchors.fill: parent
    plugin: plugin
    center: QtPositioning.coordinate(59.89435, 30.28225)
    zoomLevel: 17
    copyrightsVisible: false
    gesture.enabled: true
    focus: true

    Plugin {
        id: plugin
        name: "osm"
    }

    function cleanCoordinate() {
        startX = 0
        startY = 0
        endX = 0
        endY = 0
        lengthX = 0
        lengthY = 0
    }


    Button {
        id: rollRouteUp
        width: 20
        z: 1
        height: routeBlock.height
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        visible: false
        style: ButtonStyle {
            background: Rectangle {
                anchors.fill: parent
                color: 'lightgrey'
                radius: 5
            }
        }
        onClicked: {
//            rollRouteUp.z = 0
            rollOutAnim.start()
            routeBlock.shadowRouteItem.opacity = 1
            routeBlock.shadowRouteItem.visible = true
            rollRouteUp.visible = false
        }
        NumberAnimation {
            id: rollOutAnim
            properties: 'x'
            target: routeBlock.shadowRouteItem
            from: routeBlock.shadowRouteItem.x
            to: (mainWindow.width - routeBlock.shadowRouteItem.width) - 20;
            duration: 2000;
            easing.type: Easing.OutExpo
        }
    }

    Rectangle {
        id: rectAssig
        visible: false
        border.color: "black"
        border.width: 1
        opacity: 0.5
        width: lengthX
        height: lengthY
        x: startX
        y: startY
        transform: Rotation { angle: rotatione }
    }

    Keys.onPressed: {
        if (event.key === Qt.Key_Control) {
            canSecreting = true
            mapMA.preventStealing = true
            event.accepted = true;
            console.log('press')
        }
    }

    Keys.onReleased: {
        if (event.key === Qt.Key_Control) {
            canSecreting = false
            mapMA.preventStealing = false
            event.accepted = true;
            cleanCoordinate() // отмена выделения
            console.log('release')
        }
    }

    MouseArea {
        id: mapMA
        anchors.fill: parent

//        onClicked: console.log(mainWindow.width,' ', mouseY)

        onPressed: {
            if (mouse.button === Qt.LeftButton && canSecreting) {
                startX = mouseX
                startY = mouseY
                rectAssig.visible = true
                rectAssig.z = 2
            }
        }
        onPositionChanged: {
            if (canSecreting){
                if (rectAssig.visible == true) {
                    if (mouseX >= startX) {
                       if (mouseY >= startY) {
                           rotatione = 0
                       } else {
                           rotatione = -90
                       }
                    } else {
                          if (mouseY >= startY) {
                              rotatione = 90
                          } else {
                              rotatione = -180
                          }
                     }
                }
                if(containsMouse){
                    if(rotatione == 0 || rotatione == -180) {
                         lengthX = Math.abs(mouseX - startX)
                         lengthY = Math.abs(mouseY - startY)
                       } else {
                        lengthX = Math.abs(mouseY - startY)
                        lengthY = Math.abs(mouseX - startX)
                       }
                }
            }
        }
        onReleased: {
            if (canSecreting){
                endX = mouseX
                endY = mouseY

                for(let i = 0; i < mapview.children.length; i++){
                    if (mapview.children[i].name === "camera"){
                        if(rotatione === 0){
                            if (mapview.children[i].x >= startX &&
                                mapview.children[i].y >= startY &&
                                (mapview.children[i].x + mapview.children[i].width) <= endX &&
                                (mapview.children[i].y + mapview.children[i].height) <= endY) {
                                    mapview.children[i].layerEn = mapview.children[i].layerEn ? false : true
                                    mapview.children[i].sendId()
                            }
                        }
                        if(rotatione === -180){
                            if (mapview.children[i].x <= startX &&
                                mapview.children[i].y <= startY &&
                                (mapview.children[i].x + mapview.children[i].width) >= endX &&
                                (mapview.children[i].y + mapview.children[i].height) >= endY) {
                                    mapview.children[i].layerEn = mapview.children[i].layerEn ? false : true
                                    mapview.children[i].sendId()
                            }
                        }
                        if(rotatione === 90){
                            if (mapview.children[i].x <= startX &&
                                mapview.children[i].y >= startY &&
                                (mapview.children[i].x + mapview.children[i].width) >= endX &&
                                (mapview.children[i].y + mapview.children[i].height) <= endY) {
                                    mapview.children[i].layerEn = mapview.children[i].layerEn ? false : true
                                    mapview.children[i].sendId()
                            }
                        }
                        if(rotatione === -90){
                            if (mapview.children[i].x >= startX &&
                                mapview.children[i].y <= startY &&
                                (mapview.children[i].x + mapview.children[i].width) <= endX &&
                                (mapview.children[i].y + mapview.children[i].height) >= endY) {
                                    mapview.children[i].layerEn = mapview.children[i].layerEn ? false : true
                                    mapview.children[i].sendId()
                            }
                        }
                    }
                }
                cleanCoordinate()
            }
        }
    }

    function getId(id) {
        console.log(id)
    }

    Component.onCompleted: {
        for (var i = 0; i < cameraCoord.length; i++){
            var component = Qt.createComponent("CameraSign.qml");
            if (component.status === Component.Ready){
                console.log('component ready')
               var a = component.createObject(mapview, { myiD: i, coordinate: cameraCoord[i] });
                a.cameraId.connect(getId)
               mapModule.addMapItem(a)
            }
        }
    }

//    MapPolyline {
//        id: line1
//        line.width: 3
//        line.color: 'grey'
//    }

//    MapPolyline {
//        id: upperLine
//        line.width: 3
//        line.color: 'orange'
//    }

}
