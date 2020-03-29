import QtQuick 2.0
import QtQuick.Controls 1.4

Row
{
    id: radioRow
    property alias rRep: radioRep

    Repeater
    {
        id: radioRep
        model: 8

        RadioButton
        {
            onClicked:
            {
                 layout.sendIndex(index)
            }
        }
    }
}