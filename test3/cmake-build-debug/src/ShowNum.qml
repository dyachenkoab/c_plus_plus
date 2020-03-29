import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle
{
    id: showText
    width: 100
    height: 50
    property string num: "0"

    TextInput
    {
        text: parent.num
        enabled: false
        anchors.centerIn: parent
        font.pixelSize: 32
    }
}
