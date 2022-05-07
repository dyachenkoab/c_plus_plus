import QtQuick 2.14
import QtQuick.Window 2.14
//import "modules/sliderModule"

Window {
    id: mainWindow
    width: 1024
    height: 768
    visible: true
    title: qsTr("Hello World")


    MapModule {
        id: mapModule
        anchors.fill: parent
    }

    SearchBlock {
        id: searchBlock
        anchors.topMargin: 5
        anchors.left: parent.left
//        anchors.top: parent.top
    }

    RouteBlock {
        id: routeBlock
//        anchors.margins: 5
//        anchors.right: parent.right
        anchors.bottom: parent.bottom

    }

    CarPopup {
        id: carPopup
        anchors.centerIn: parent
        visible: false
    }
}
