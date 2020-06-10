import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle
{
    id: inputText
    width: 200
    height: 50
    border.width: 2
    // border.color: black

    TextInput
    {
        text: "hex & Enter"
        cursorVisible: true
        anchors.centerIn: parent
        font.pixelSize: 32
        focus: true

        validator: RegExpValidator { regExp: /([0-9A-Fa-f]{1,2})/ }

        onAccepted:
        {
            layout.sendNum(text)
        }
    }
}
