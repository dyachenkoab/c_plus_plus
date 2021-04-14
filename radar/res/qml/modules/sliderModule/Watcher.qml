import QtQuick.Controls 2.12
import QtQuick 2.12
import QtLocation 5.6
import QtPositioning 5.6

WatcherForm {
    id: watcherForm
    property variant points: []
    property var mapview
    property int firstMarker: 0
    property alias sliderVisible: watcherForm.visible
    property bool check: true
    property int i: 0

    visible: true

    play.onClicked: {
        if (check) {
            routeBlock.downNum(0)
            routeBlock.currentItem = 0
            timer.start()
            play.text = "PAUSE"
        }
        else {
            timer.stop()
            play.text = "PLAY"
            mapview.children[slide.value + firstMarker].focus = true
        }

        check = !check
    }

    slide.onMoved: {
        mapview.center = points[slide.value]
        mapview.children[slide.value + firstMarker].focus = true
    }

    Timer {
        id: timer
        repeat: true
        interval: 500
        onTriggered: {
            if (slide.value == points.length-1){
                stop()
                play.text = "PLAY"
                check = true
                slide.value = 0
            } else {
                slide.increase()
                routeBlock.upNum(slide.value)
                routeBlock.currentItem = slide.value
                mapview.center = points[slide.value]
                mapview.children[slide.value + firstMarker].focus = true
            }
        }
    }

    function addMark(coord) {
        var component = Qt.createComponent("qrc:/qml/Pointer.qml")

        if (component.status === Component.Ready) {
            var item = component.createObject(mapview, {center: coord, myiD: i++})
            mapview.addMapItem(item)
        }
    }

    function place(rawCoord) {
        points.length = 0
        let re = new RegExp('[0-9]{2}\\.[0-9]+', 'g')
        let lat = re.exec(rawCoord)
        let lon = re.exec(rawCoord)

        let point = new Array

        if (lon)
            mapview.center = QtPositioning.coordinate(lat, lon)
            addMark(QtPositioning.coordinate(lat, lon))
            points.push(QtPositioning.coordinate(lat, lon))

        while(lat) {
            lat = re.exec(rawCoord)
            lon = re.exec(rawCoord)
            if (lat && lon){
                let pointed = QtPositioning.coordinate(lat, lon)
                addMark(pointed)
                points.push(pointed)
            }

//            mapview.children[mapview.currentPolyLine].addCoordinate(pointed) // линии передвижения

        }
        console.log(points, 'points-points')
        slide.to = points.length - 1
        getChildren()
        mapview.zoomLevel = 17
    }

    function getChildren() {
        while (firstMarker < mapview.children.length) {
                console.log(mapview.children[firstMarker])
            if (mapview.children[firstMarker].objectName === "mark") {
                console.log(firstMarker)
                break
            }
            firstMarker += 1
        }
    }

    function cleanMarks(){
        mapview.clearMapItems()
    }
}
