import QtQuick 2.0

Rectangle
{
    id: inputText
    border.width: 2
    border.color: "slategrey"
    property alias input: textInput.text

    TextInput
    {
        id: textInput
        color: "slategrey"
        maximumLength: 10
        cursorVisible: false
        readOnly: true
        anchors.centerIn: parent
        font.pixelSize: 32
    }

}
