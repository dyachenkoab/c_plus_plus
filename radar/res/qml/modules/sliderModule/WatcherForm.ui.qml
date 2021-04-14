import QtQuick.Controls 2.3
import QtQuick 2.12
import QtLocation 5.6
import QtPositioning 5.6

Item {
    id: itemSlider
    property alias slide: slide
    property alias play: play

    Slider {
        id: slide
        width: mapview.width - 100
        visible: false
        opacity: 1
        from: 0
        to: 10
        stepSize: 1
        snapMode: Slider.SnapAlways
    }

    Button {
        id: play
        text: "PLAY"
        opacity: 0.7
        anchors.left: parent.left
//        anchors.left: slide.right
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
