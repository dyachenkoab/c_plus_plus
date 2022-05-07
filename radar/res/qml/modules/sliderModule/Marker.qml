import QtQuick 2.0
import QtLocation 5.6
import QtPositioning 5.6

MapQuickItem {
    property alias active: image.focus
    id: marker
    objectName: "mark"
    anchorPoint.x: image.width / 2
    anchorPoint.y: image.height
    opacity: 0.5
    sourceItem: Image {
        id: image
        source: focus == true ? "image/loc.png" : "image/dot.png"
    }
}
