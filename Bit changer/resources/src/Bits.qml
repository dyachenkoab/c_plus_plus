import QtQuick 2.0
import QtQuick.Controls 1.4

Row
{
    id:rowBits
    spacing: 2

    property alias bits: repeatBits

    Repeater
    {
        id: repeatBits
        model: 8

        Rectangle
        {
            property string tx: "0"
            id: rect
            width: 50
            height: 50

            TextInput
            {
                id:txt
                text: parent.tx
                font.pixelSize: 32
                anchors.centerIn: parent
                enabled: false

                onTextChanged:
                {
                    layout.txtChanged(index, text)
                }
            }
        }
    }
}