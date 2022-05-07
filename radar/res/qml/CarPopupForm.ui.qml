import QtQuick 2.4

Item {
    property alias carImage: carImage
    id: itemCarImage
    width: carImage.width
    height: carImage.height
    Image {
        id: carImage
    }
    MouseArea {
        anchors.fill: parent
        onClicked: itemCarImage.visible = false
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
