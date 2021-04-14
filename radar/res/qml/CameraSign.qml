import QtQuick 2.0
import QtLocation 5.11
import QtGraphicalEffects 1.14

MapQuickItem {
    property var myiD
    property var name: "camera"
    property alias carImage: cameraImage
    property alias layerEn: cameraImage.layer.enabled
    signal cameraId(string id)

    function sendId(){
        if (cameraImage.layer.enabled)
            cameraId(myiD)
    }

    id: itemCamera
//    zoomLevel: 15
//    width: cameraImage.width
//    height: cameraImage.height
    sourceItem: Image {
        id: cameraImage
        source: "../image/camera.png"
        layer.enabled: false
        layer.effect: Glow {
            anchors.fill: cameraImage
            radius: 5
            samples: 50
            color: "red"
            source: cameraImage
            transparentBorder: true
        }
        MouseArea {
            id: cameraImageMA
            anchors.fill: parent
            onClicked: {
                cameraImage.layer.enabled = cameraImage.layer.enabled ? false : true
                cameraId(myiD)
                console.log('x: ', itemCamera.x, 'y: ', itemCamera.y)
            }
        }
    }
}
