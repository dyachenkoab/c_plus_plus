import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.3
 GridLayout
 {
     //  сигналы для Qt
     signal sendIndex(int ind)
     signal sendNum(string num)
     signal openFile(string file)
     signal invert()

     //  сигнал для Qml
     signal txtChanged(int ind, string txt)

     id: layout
     columns: 1
     rows: 2
     columnSpacing: 10
     rowSpacing: 5

     Connections{
         target: widget

         onChangeIndex:{
         bit.bits.itemAt(ind).tx = x
         }

         onShowResult:{
             showNum.num = res
         }
     }

     onTxtChanged:{
         if (txt == "1") {radio.rRep.itemAt(ind).checked = true}
         if (txt == "0") {radio.rRep.itemAt(ind).checked = false}
     }

     ShowNum
     {
         id: showNum
         Layout.column: 1
         Layout.row: 0
     }

     InputText
     {
         id: inputText
         Layout.column: 0
         Layout.row: 0
         Layout.leftMargin: 150
         Layout.topMargin: 50
     }

     Butt
     {
         Layout.column: 1
         Layout.row: 1
         Layout.leftMargin: 50
         Layout.rightMargin: 20
     }

     Bits
     {
         id: bit
         Layout.alignment: Qt.AlignBottom
         Layout.column: 0
         Layout.row: 1
         Layout.leftMargin: 50
     }

     Radio
     {
         id: radio
         spacing: 32
         Layout.column: 0
         Layout.row: 2
         Layout.leftMargin: 65
         Layout.bottomMargin: 25
     }
 }
