import QtQuick 2.8
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4

Grid{
    id: buttonLayout
    columns: 4
    columnSpacing: display.width / 10
    rowSpacing: baseLayout.width / 10

    property var sign: ""

    Repeater
    {
        id: repeat
        model: ["C", " ", " ", "/","1", "2", "3", "*", "4", "5", "6", "-", "7", "8", "9", "+", "-", ".", "0", "="]


        Rectangle
        {
            id: button
            width: 50
            height: 50
            border.color: "slategrey"
            radius: 10

            Text
            {
                id: texT
                anchors.centerIn: parent
                text: modelData
                color: mouseArea.containsMouse ? "red" : "slategrey"

            }

            MouseArea
            {
                id: mouseArea
                anchors.fill: parent
                hoverEnabled: true

                onClicked:
                {

                    if ((index == 16) && (display.input.charAt(0) != "-"))
                    {
                        display.input = texT.text + display.input
                    }

                    switch (texT.text)
                    {
                    case "C":
                        display.input = ""
                        break;

                    case "-":
                        if (index != 16)
                        {
                            display.input += texT.text
                        }
                        break;

                    case "=":
                        mainWindow.sendText(display.input)
                        break;

                    default:
                        display.input += texT.text
                        break;
                    }
                }

            }
        }

    }
}
