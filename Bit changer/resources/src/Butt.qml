import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

Column{
         id: buttonRow
         spacing: 10

    Repeater
    {
        id: repeat
        model: ["invertBit", "open", "quit"]

        Rectangle
        {
            id: button
            width: 116
            height: 26
            border.color: "slategrey"

            Text
            {
                id: texT
                anchors.centerIn: parent
                text: modelData
            }

            MouseArea
            {
                id: mouseArea
                hoverEnabled: true
                onEntered: parent.color = "gold"
                onExited:  parent.color = "white"
                anchors.fill: parent
                onClicked: {
                    if (index == 0) { onClicked: layout.invert() }
                    if (index == 2) { onClicked: Qt.quit() }
                    if (index == 1)
                    {
                        onClicked:
                        {
                            fileDialog.visible = true
                        }
                    }
                }
            }
        }
    }

    FileDialog
    {
        id: fileDialog
        visible: false
        title: "open"
        folder: "file:/home/"
        nameFilters: ["All files (*)"]
        onAccepted:
        {
            layout.openFile(fileUrls)
        }
    }

    MessageDialog
    {
        id: messageDialog
        visible: false
        title: "Message"
    }
}
