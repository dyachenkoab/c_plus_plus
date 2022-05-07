import QtQuick 2.14
import QtQuick.Controls 1.4
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.12
import "modules/sliderModule"

Item{
    id: shadowRouteItem
    property var date: new Date()
    property alias dateCol: dateCol
    property alias timeCol: timeCol
    property alias numberCol: numberCol
    property alias tableView: tableView
    property alias photoCol: photoCol

    property alias watcher: watcher
    property alias routeItemMA: routeItemMA
    property alias routeHide: routeHide
    property alias shadowRouteItem: shadowRouteItem

    property alias shadow: shadow
    property alias bottomArea: bottomArea
    property alias leftArea: leftArea
    property alias rightArea: rightArea
    property alias dragArea: dragArea
    property alias topArea: topArea
    property alias background: background
    property bool dragActive: dragArea.drag.active
    property alias hideAnim: hideAnim
    property alias disappearAnim: disappearAnim

    width: background.width
    height: background.height
    anchors.margins: 10

    MouseArea {
        id: routeItemMA
        anchors.fill: parent
        hoverEnabled: true
        onExited: mapModule.focus = true
    }

    DropShadow {
        id: shadow
        anchors.fill: background
        source: background
        horizontalOffset: 3
        verticalOffset: 30
        radius: 18.0
        samples: 17
        color: "#80000000"
    }

    Rectangle {
        id: background
        color: 'white'
        visible: true
        width: mainWindow.width / 3
        height: mainWindow.height * 0.8

        Drag.active: dragArea.drag.active

        MouseArea {
            id: dragArea
            anchors.top: topArea.bottom
            anchors.bottom: tableView.top
            anchors.left: parent.left
            anchors.right: parent.right
            drag.target: parent
        }

        MouseArea {
            id: topArea
            height: 10
            anchors {
                top: parent.top
                left: parent.left
                right: parent.right
            }
            // Устанавливаем форму курсора, чтобы было понятно, что это изменение размера
            cursorShape: Qt.SizeVerCursor
        }

        MouseArea {
            id: bottomArea
            height: 10
            anchors {
                bottom: parent.bottom
                left: parent.left
                right: parent.right
            }
            cursorShape: Qt.SizeVerCursor
        }

        MouseArea {
            id: leftArea
            width: 20
            anchors {
                top: topArea.bottom
                bottom: bottomArea.top
                left: parent.left
            }
            cursorShape: Qt.SizeHorCursor

        }

        MouseArea {
            id: rightArea
            width: 20
            anchors {
                top: topArea.bottom
                bottom: bottomArea.top
                right: parent.right
            }
            cursorShape:  Qt.SizeHorCursor
        }

        Text {
            id: routeText
            text: 'Маршруты'
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.margins: 18
            font.pixelSize: 20
            font.family: 'system-ui'
        }

        Button {
           id: routeHide
           width: 20
           height: 20
           anchors.right: parent.right
           NumberAnimation {
                id: hideAnim
                properties: 'x'
                target: shadowRouteItem
                duration: 2500
                from: shadowRouteItem.x
                to: mainWindow.width
                easing.type: Easing.OutExpo
           }
           NumberAnimation {
                id: disappearAnim
                properties: 'opacity'
                target: shadowRouteItem
                duration: 1900
                from: 1
                to: 0
           }
        }

        TableView {
            id: tableView
            model: myModel
            width: parent.width - 5
            height: parent.height - 100
            anchors.top: routeText.bottom
            anchors.centerIn: parent
            anchors.topMargin: 10
            rowDelegate: Rectangle {
                height: 100
                color: 'lightgrey'
                clip: true
                anchors.margins: 10
                border.color: styleData.selected ? 'white' : 'black'
                border.width: 1
            }


            TableViewColumn {
                id: dateCol
                role: 'date'
                title: 'Дата'
                horizontalAlignment: Text.AlignHCenter
                width: background.width / 5
                delegate: dateDelegate
            }
            TableViewColumn {
                id: timeCol
                role: 'time'
                title: 'Время'
                horizontalAlignment: Text.AlignHCenter
                width: background.width / 5
                delegate: timeDelegate
            }
            TableViewColumn {
                id: nameCol
                role: 'name'
                title: 'Марка'
                horizontalAlignment: Text.AlignHCenter
                width: background.width / 5
            }
            TableViewColumn {
                id: colorCol
                role: 'color'
                title: 'Цвет'
                horizontalAlignment: Text.AlignHCenter
                width: background.width / 5
            }
            TableViewColumn {
                id: numberCol
                role: 'numberplate'
                title: 'Номер'
                horizontalAlignment: Text.AlignHCenter
                width: background.width / 5
            }
            TableViewColumn {
                role: 'accuracy'
                title: 'Точность'
                horizontalAlignment: Text.AlignHCenter
                width: background.width / 5
            }
            TableViewColumn {
                id: photoCol
                role: 'photo'
                title: 'Фото'
                horizontalAlignment: Text.AlignHCenter
                width: background.width / 5
                delegate: imageDelegate
            }
        }

        Watcher {
            id: watcher
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.top: tableView.bottom
            anchors.leftMargin: 5
            anchors.topMargin: 5
            mapview: mapModule
        }
    }
}
