import QtQuick 2.14
import QtQuick.Controls 1.4
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.12
import QtQuick.Layouts 1.3

Item{
    id: shadowSearchItem
    width: background.width + (2*shadow.radius)
    height: background.height + (2*shadow.radius)
    anchors.margins: 10

    property var date: new Date()
    property var _width: shadowSearchItem.width / 5
    property var _height: shadowSearchItem.height / 5

    property alias calendarImageFirstMouseArea: calendarImageFirstMouseArea
    property alias calendarImageSecondMouseArea: calendarImageSecondMouseArea
    property alias date1: date1
    property alias cal: cal
    property alias date2: date2
    property alias cal1: cal1
    property alias numberTextInputMouseArea: numberTextInputMouseArea
    property alias clock1InputMouseArea: clock1InputMouseArea
    property alias clock2InputMouseArea: clock2InputMouseArea
    property alias firstUnderBlock: firstUnderBlock
    property alias secondUnderBlock: secondUnderBlock

    property alias carNameInputMouseArea: carNameInputMouseArea
    property alias colorPicInputMouseArea: colorPicInputMouseArea
    property alias clear: clear
    property alias search: search
    property alias clock1Text: clock1Text
    property alias clock2Text: clock2Text
    property alias numberText: numberText
    property alias carNameText: carNameText
    property alias colorPicText: colorPicText

    property alias suggestionRectNumberplate: suggestionRectNumberplate
    property alias suggestionViewNumberplate: suggestionViewNumberplate
    property alias suggestionRectName: suggestionRectName
    property alias suggestionViewName: suggestionViewName
    property alias suggestionRectColor: suggestionRectColor
    property alias suggestionViewColor: suggestionViewColor
//    property alias suggestionModel: suggestionModel

    property alias searchBlockMA: searchBlockMA

    MouseArea {
        id: searchBlockMA
        hoverEnabled: true
        anchors.fill: parent
        onHoveredChanged: mapModule.focus = true
        // фокус для перехвата нажатия клавиш (выделения области)
    }

    DropShadow {
        id: shadow
        anchors.fill: shadowSearchItem
        source: background
        horizontalOffset: 3
        verticalOffset: 30
        radius: 18.0
        samples: 17
        color: "#80000000"
    }

    Rectangle {
        id: background
        color: 'white'
        visible: true
        width: mainWindow.width / 2 + 50
        height: mainWindow.height / 7


//-------------------------------- firstBlock ---------------------------------------//
        Item {
            id: firstBlock
            width: _width
            height: _height
            anchors.top: parent.top
            anchors.left: parent.left

            Image {
                id: calendarImageFirst
                source: "../image/calendar.png"
                width: 15
                height: 15
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 200
                anchors.topMargin: (mainWindow.width + mainWindow.height) / 200
                anchors.bottomMargin: (mainWindow.width + mainWindow.height) / 300
                scale: (mainWindow.width + mainWindow.height) / 2000
                MouseArea {
                    id: calendarImageFirstMouseArea
                    anchors.fill: parent
                }

            }

            Text {
                id: date1
                anchors.left: calendarImageFirst.right
                anchors.top: parent.top
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 300
                anchors.topMargin: 15
                font.pixelSize: (mainWindow.width + mainWindow.height) / 200
                anchors.bottomMargin: (mainWindow.width + mainWindow.height) / 300
                width: parent.width - 20
                height: parent.height
                rightPadding: 30
                clip: true
            }

            Calendar{
                id: cal
                width: date1.width + calendarImageFirst.width
                height: mainWindow.height / 4
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 300
                 anchors.top: underLine.bottom
                 anchors.left: parent.left
                 visible: false
            }

            Rectangle {
                id: underLine
                width: date1.width + calendarImageFirst.width
                height: 2
                anchors.top: date1.bottom
                anchors.left: parent.left
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 300
                anchors.topMargin: -5
                color: 'black'
            }
        }
//-------------------------------- secondBlock ---------------------------------------//
        Item {
            id: secondBlock
            width: _width
            height: _height
            anchors.top: parent.top
            anchors.left: firstBlock.right
            anchors.leftMargin: (mainWindow.width + mainWindow.height) / 70

            Image {
                id: calendarImageSecond
                source: "../image/calendar.png"
                width: 15
                height: 15
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 200
                anchors.topMargin: (mainWindow.width + mainWindow.height) / 200
                anchors.bottomMargin: (mainWindow.width + mainWindow.height) / 300
                scale: (mainWindow.width + mainWindow.height) / 2000
                MouseArea {
                    id: calendarImageSecondMouseArea
                    anchors.fill: parent
                }

            }

            Text {
                id: date2
                anchors.left: calendarImageSecond.right
                anchors.top: parent.top
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 300
                anchors.topMargin: 15
                font.pixelSize: (mainWindow.width + mainWindow.height) / 200
                anchors.bottomMargin: (mainWindow.width + mainWindow.height) / 300
                width: parent.width - 20
                height: parent.height
                rightPadding: 30
                clip: true
            }

            Calendar{
                id: cal1
                width: date2.width + calendarImageSecond.width
                height: mainWindow.height / 4
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 300
                anchors.top: textLine1.bottom
                anchors.left: parent.left
                visible: false
                weekNumbersVisible: false
            }

            Rectangle {
                id: textLine1
                width: date2.width + calendarImageSecond.width
                height: 2
                anchors.top: date2.bottom
                anchors.left: parent.left
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 400
                color: 'black'
                anchors.topMargin: -5
            }
        }

//-------------------------------- thirdBlock ---------------------------------------//
        Item {
            id: thirdBlock
            width: _width
            height: _height
            anchors.top: parent.top
            anchors.left: secondBlock.right
            anchors.leftMargin: (mainWindow.width + mainWindow.height) / 70

            Image {
                id: carNumber
                source: "../image/carNumber.png"
                width: 15
                height: 15
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 200
                anchors.topMargin: (mainWindow.width + mainWindow.height) / 200
                anchors.bottomMargin: (mainWindow.width + mainWindow.height) / 300
                scale: (mainWindow.width + mainWindow.height) / 2000
            }

            TextInput {
                id: numberText
                text: ''
                color: 'grey'
                anchors.left: carNumber.right
                anchors.top: parent.top
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 300
                anchors.topMargin: 15
                font.pixelSize: (mainWindow.width + mainWindow.height) / 200
                anchors.bottomMargin: (mainWindow.width + mainWindow.height) / 300
                width: parent.width - 20/// 3
                height: parent.height /// 5
                rightPadding: 20
                clip: true
                font.capitalization: Font.AllUppercase
//                validator: RegularExpressionValidator { regularExpression: /((^[a-zA-Z])([0-9]{3})([a-zA-Z]{2})([0-9]{2,3}$))/ }
                MouseArea {
                    id: numberTextInputMouseArea
                    hoverEnabled: true
                    onEntered: parent.focus = true
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: textLine3
                width: numberText.width + carNumber.width
                height: 2
                anchors.top: numberText.bottom
                anchors.left: parent.left
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 300
                color: 'black'
                anchors.topMargin: -5

            }
        }
//------------------------ Suggestion -----------------------------------------//
            Rectangle {
                id: suggestionRectNumberplate
                visible: false
                width: textLine3.width
                height: 100
                anchors.top: thirdBlock.bottom
                anchors.left: thirdBlock.left
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 300
                anchors.topMargin: 20
                z: 1
                color: 'white'
                ListView {
                    id: suggestionViewNumberplate
                    anchors.fill: parent
                    model: lst // suggestionModel
                    highlight: Rectangle { color: "lightgrey"; radius: 5; z: 2; opacity: 0.5 }
                    focus: true
                    delegate: searchNumberplateDelegate
                }
                MouseArea {
                    anchors.left: parent.left
                    height: parent.height
                    width: 5
                    hoverEnabled: true
                    onExited: parent.visible = false
                }
                MouseArea {
                    anchors.right: parent.right
                    height: parent.height
                    width: 5
                    hoverEnabled: true
                    onExited: parent.visible = false
                }
                MouseArea {
                    anchors.bottom: parent.bottom
                    height: 5
                    width: parent.width
                    hoverEnabled: true
                    onExited: parent.visible = false
                }
              }

            Rectangle {
                id: suggestionRectName
                visible: false
                width: textLine3.width
                height: 100
                anchors.top: fourthBlock.bottom
                anchors.left: fourthBlock.left
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 300
                anchors.topMargin: 20
                z: 1
                color: 'white'
                ListView {
                    id: suggestionViewName
                    anchors.fill: parent
                    model: lst
                    highlight: Rectangle { color: "lightgrey"; radius: 5; z: 2; opacity: 0.5 }
                    focus: true
                    delegate: searchNameDelegate
                }
                MouseArea {
                    anchors.left: parent.left
                    height: parent.height
                    width: 5
                    hoverEnabled: true
                    onExited: parent.visible = false
                }
                MouseArea {
                    anchors.right: parent.right
                    height: parent.height
                    width: 5
                    hoverEnabled: true
                    onExited: parent.visible = false
                }
                MouseArea {
                    anchors.bottom: parent.bottom
                    height: 5
                    width: parent.width
                    hoverEnabled: true
                    onExited: parent.visible = false
                }
              }

            Rectangle {
                id: suggestionRectColor
                visible: false
                width: textLine3.width
                height: 100
                anchors.top: thirdUnderBlock.bottom
                anchors.left: thirdUnderBlock.left
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 300
                anchors.topMargin: 20
                z: 1
                color: 'white'
                ListView {
                    id: suggestionViewColor
                    anchors.fill: parent
                    model: lst // suggestionModel
                    highlight: Rectangle { color: "lightgrey"; radius: 5; z: 2; opacity: 0.5 }
                    focus: true
                    delegate: searchColorDelegate
                }
                MouseArea {
                    anchors.left: parent.left
                    height: parent.height
                    width: 5
                    hoverEnabled: true
                    onExited: parent.visible = false
                }
                MouseArea {
                    anchors.right: parent.right
                    height: parent.height
                    width: 5
                    hoverEnabled: true
                    onExited: parent.visible = false
                }
                MouseArea {
                    anchors.bottom: parent.bottom
                    height: 5
                    width: parent.width
                    hoverEnabled: true
                    onExited: parent.visible = false
                }
              }

//-------------------------------- fourthBlock ---------------------------------------//

        Item {
            id: fourthBlock
            width: _width
            height: _height
            anchors.top: parent.top
            anchors.left: thirdBlock.right
            anchors.leftMargin: (mainWindow.width + mainWindow.height) / 70
//            anchors.topMargin: (mainWindow.width + mainWindow.height) / 70

            Image {
                id: carName
                source: "../image/car.png"
                width: 15
                height: 15
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 200
                anchors.topMargin: (mainWindow.width + mainWindow.height) / 200
                anchors.bottomMargin: (mainWindow.width + mainWindow.height) / 300
                scale: (mainWindow.width + mainWindow.height) / 2000

            }

            TextInput {
                id: carNameText
                text: ''
                color: 'grey'
                anchors.left: carName.right
                anchors.top: parent.top
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 300
                anchors.bottomMargin: (mainWindow.width + mainWindow.height) / 300
                anchors.topMargin: 15
                font.pixelSize: (mainWindow.width + mainWindow.height) / 200
                width: parent.width - 20
                height: parent.height
                rightPadding: 20
                clip: true
//                validator: RegularExpressionValidator { regularExpression: /^([a-zA-Z])/ }
                MouseArea {
                    id: carNameInputMouseArea
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: parent.focus = true
                }
            }

            Rectangle {
                id: textLine7
                width: clock2Text.width + clock2.width
                height: 2
                anchors.top: carNameText.bottom
                anchors.left: parent.left
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 300
                color: 'black'
                anchors.topMargin: -5
            }
        }





//-------------------------------- firstUnderBlock ---------------------------------------//
        Item {
            id: firstUnderBlock
            width: _width
            height: _height
            anchors.top: firstBlock.bottom
            anchors.left: parent.left
            anchors.topMargin: (mainWindow.width + mainWindow.height) / 70

            Image {
                id: clock1
                source: "../image/clock.png"
                width: 15
                height: 15
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 200
                anchors.topMargin: (mainWindow.width + mainWindow.height) / 200
                anchors.bottomMargin: (mainWindow.width + mainWindow.height) / 300
                scale: (mainWindow.width + mainWindow.height) / 2000

            }

            TextInput {
                id: clock1Text
                text: ''
                color: 'grey'
                anchors.left: clock1.right
                anchors.top: parent.top
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 300
                anchors.topMargin: 15
                font.pixelSize: (mainWindow.width + mainWindow.height) / 200
                anchors.bottomMargin: (mainWindow.width + mainWindow.height) / 300
                width: parent.width - 20/// 3
                height: parent.height /// 5
                rightPadding: 20
                clip: true
                validator: RegularExpressionValidator { regularExpression: /^(([0,1][0-9])|(2[0-3])):[0-5][0-9]$/ }
                MouseArea {
                    id: clock1InputMouseArea
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: textLine4
                width: clock1Text.width + clock1.width
                height: 2
                anchors.top: clock1Text.bottom
                anchors.left: parent.left
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 300
                color: 'black'
                anchors.topMargin: -5
                }
            }
//-------------------------------- secondUnderBlock ---------------------------------------//
        Item {
            id: secondUnderBlock
            width: _width
            height: _height
            anchors.top: secondBlock.bottom
            anchors.left: firstUnderBlock.right
            anchors.leftMargin: (mainWindow.width + mainWindow.height) / 70
            anchors.topMargin: (mainWindow.width + mainWindow.height) / 70

            Image {
                id: clock2
                source: "../image/clock.png"
                width: 15
                height: 15
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 200
                anchors.topMargin: (mainWindow.width + mainWindow.height) / 200
                anchors.bottomMargin: (mainWindow.width + mainWindow.height) / 300
                scale: (mainWindow.width + mainWindow.height) / 2000

            }

            TextInput {
                id: clock2Text
                text: ''
                color: 'grey'
                anchors.left: clock2.right
                anchors.top: parent.top
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 300
                anchors.bottomMargin: (mainWindow.width + mainWindow.height) / 300
                anchors.topMargin: 15
                font.pixelSize: (mainWindow.width + mainWindow.height) / 200
                width: parent.width - 20
                height: parent.height
                rightPadding: 20
                clip: true
                validator: RegularExpressionValidator { regularExpression: /^(([0,1][0-9])|(2[0-3])):[0-5][0-9]$/ }
                MouseArea {
                    id: clock2InputMouseArea
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: textLine5
                width: clock2Text.width + clock2.width
                height: 2
                anchors.top: clock2Text.bottom
                anchors.left: parent.left
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 300
                color: 'black'
                anchors.topMargin: -5
            }
        }
//-------------------------------- thirdUnderBlock ---------------------------------------//
        Item {
            id: thirdUnderBlock
            width: _width
            height: _height
            anchors.top: secondBlock.bottom
            anchors.left: secondUnderBlock.right
            anchors.leftMargin: (mainWindow.width + mainWindow.height) / 70
            anchors.topMargin: (mainWindow.width + mainWindow.height) / 70

            Rectangle {
                id: colorPic
//                source: "../image/clock.png"
                color: 'darkgrey'
                width: 15
                height: 15
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 200
                anchors.topMargin: (mainWindow.width + mainWindow.height) / 200
                anchors.bottomMargin: (mainWindow.width + mainWindow.height) + 30 / 300
                scale: (mainWindow.width + mainWindow.height) / 2000

            }

            TextInput {
                id: colorPicText
                text: ''
                color: 'grey'
                anchors.left: colorPic.right
                anchors.top: parent.top
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 300
                anchors.bottomMargin: (mainWindow.width + mainWindow.height) / 300
                anchors.topMargin: 15
                font.pixelSize: (mainWindow.width + mainWindow.height) / 200
                width: parent.width - 20
                height: parent.height
                rightPadding: 20
                clip: true
//                validator: RegularExpressionValidator { regularExpression: /^(([0,1][0-9])|(2[0-3])):[0-5][0-9]$/ }
                MouseArea {
                    id: colorPicInputMouseArea
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: parent.focus = true
                }
            }

            Rectangle {
                id: textLine6
                width: clock2Text.width + clock2.width
                height: 2
                anchors.top: colorPicText.bottom
                anchors.left: parent.left
                anchors.leftMargin: (mainWindow.width + mainWindow.height) / 300
                color: 'black'
                anchors.topMargin: -5
            }
        }

//-------------------------------- buttonsUnderBlock ---------------------------------------//
        Item {
            id: buttonBlock
            anchors.left: thirdUnderBlock.right
            anchors.top: fourthBlock.bottom
            anchors.topMargin: (mainWindow.width + mainWindow.height) / 50
            anchors.leftMargin: (mainWindow.width + mainWindow.height) / 60
            anchors.bottomMargin: (mainWindow.width + mainWindow.height) / 50
                transform: Scale {
                    xScale: calendarImageFirst.scale * 0.4
                    yScale: calendarImageFirst.scale * 0.4
                }

            Button {
                id: search
                text: 'Поиск'
                width: 100
                height: 60
                anchors.left: parent.left
                anchors.top: parent.top
                contentItem: Text {
                    text: search.text
                    font.pixelSize: 13 * calendarImageFirst.scale
                    color: "#000000"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter

                }
             }

            Button {
                id: clear
                text: 'Очистить'
                width: 140
                height: 60
                anchors.left: search.right
                anchors.top: parent.top
                anchors.leftMargin: (mainWindow.width + mainWindow.height)* calendarImageFirst.scale / 150
                contentItem: Text {
                    text: clear.text
                    font.pixelSize: 13 * calendarImageFirst.scale
                    color: "#000000"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter

                }

            }
        }

    }
}
