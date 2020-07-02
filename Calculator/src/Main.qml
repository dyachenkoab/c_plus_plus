import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3

Window
{
id: mainWindow
visible: true
width: 300
height: 500
title: qsTr("Hello World")

signal sendText(string ind);

 Connections
 {
         target: Layer
    //сигналы из Qt
         onChangeIndex:
            {
                display.input = x
            }
 }

    ColumnLayout
    {
        id: baseLayout
        anchors.fill: parent
        anchors.margins: 5


        Display
        {
            id: display
            Layout.topMargin: 30
            Layout.alignment: Qt.AlignTop
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Buttons
       {
           id: buttons
           Layout.alignment: Qt.AlignCenter
           Layout.topMargin: 30
           Layout.bottomMargin: 10
       }

    }
}
