import QtQuick 2.12
import QtLocation 5.6

MapCircle {
    property int myiD: 0
//    property string objectName: "mark"
    objectName: "mark"
    id: circle
    color: focus == true ? "red" : "black"
//    opacity: 0.5
    radius: 3
}
