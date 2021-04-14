import QtQuick 2.4
import QtPositioning 5.12
SearchBlockForm {

    property string coord: "59.893456, 30.282855. 59.894517, 30.284484. 59.897719, 30.289028. 59.900358, 30.289551. 59.904233, 30.291093. 59.908581, 30.296059."
//    property string coord: "59.895103, 30.237508. 59.901779, 30.218245."
    property string coord1: "59.901229, 30.2742295. 59.903763, 30.277800. 59.908570, 30.275003. 59.913276, 30.277727. 59.916797, 30.279825. 59.916779, 30.281997."
    property int currentPolyLine

    property string currentWord
    property var lst: []

    NumberAnimation on y {
         from: -30;
         to: 10;
         duration: 2000;
         easing.type: Easing.OutExpo
    }

    function clean(){
        for (let i = 0; i < mapModule.children.length; i++){
            if(mapModule.children[i].toString().startsWith('PolyLine') || mapModule.children[i].objectName === 'mark')
                mapModule.children[i].destroy()
        }
        myModel.setEmpty()
        routeBlock.currentItem = 0
        routeBlock.watcher.i = 0
        routeBlock.watcher.points.length = 0
    }

    clear.onClicked: {
        clean()
    }

    Timer { // чтобы переменные успели обнулиться при повторном нажатии на поиск
        id: timer
        interval: 25
        onTriggered: show()
        repeat: false
    }

    function show(){
        //фукция поиска и постройки PolyLine`ов
            let temp = myModel.numberPlateSearch(date1.text, date2.text, clock1Text.text, clock2Text.text, carNameText.text, colorPicText.text, numberText.text.toUpperCase())

            if(temp !== 0) {
                routeBlock.watcher.place(coord)
                var component = Qt.createComponent("PolyLine.qml");
                if (component.status === Component.Ready){
                   var a = component.createObject(mapModule, { myiD: 'line' });
                   var b = component.createObject(mapModule, { myiD: 'upperLine' });
                   mapModule.addMapItem(a)
                   mapModule.addMapItem(b)
                   console.log(a, 'CREATED OBJ, NOT NULL')
                   console.log(b, 'CREATED SECOND OBJ, NOT NULL')
                }

                // находим первый polyLine
                for (let v = 0; v < mapModule.children.length; v++){
                   if(mapModule.children[v].myiD === 'line'){
                        // рисуем первую линию - весь маршрут
                        routeBlock.watcher.points.forEach(function(point){
                            mapModule.children[v].addCoordinate(point)
                        })
                       break
                   }
                }

                // запоминаем второй polyLine
                for (let j = 0; j < mapModule.children.length; j++){
                   if(mapModule.children[j].myiD === 'upperLine'){
                       currentPolyLine = j
                       mapModule.children[currentPolyLine].line.color = 'green'
                       console.log(mapModule.children[currentPolyLine].line.color, '<----ORANGE')
                       break
                   }
                }

                mapModule.children[searchBlock.currentPolyLine].addCoordinate(routeBlock.watcher.points[0]) // заносим первую точку в polyLine

                console.log(mapModule.children[currentPolyLine].pathLength(), '<----PATH')
        }
    }

    search.onClicked: {
        // ищем
        clean()
        timer.start()

    }

    numberText.onTextChanged: {
        if (numberText.text.length >= 1 && currentWord != numberText.text)
            suggestionRectNumberplate.visible = true

        if (numberText.text !== ''){
            lst = myModel.suggestions('numberplate', numberText.text.toUpperCase())
            console.log(lst)
        } else
            suggestionRectNumberplate.visible = false

    }

    colorPicText.onTextChanged: {
        if (colorPicText.text.length >= 1 && currentWord != colorPicText.text)
            suggestionRectColor.visible = true

        if (colorPicText.text !== ''){
            lst = myModel.suggestions('color', colorPicText.text)
            console.log(lst)
        } else
            suggestionRectColor.visible = false
    }

    carNameText.onTextChanged: {
        if (carNameText.text.length >= 1 && currentWord != carNameText.text)
            suggestionRectName.visible = true

        if (carNameText.text !== ''){
            lst = myModel.suggestions('name', carNameText.text)
            console.log(lst)
        } else
            suggestionRectName.visible = false

    }

     Component {
         id: searchNumberplateDelegate
         Rectangle {
            height: 20
            width: suggestionRectNumberplate.width
            Text {
                id: txt
                text: modelData //name
                anchors.fill: parent
                anchors.leftMargin: 7
                anchors.topMargin: 2
                clip: true
//            	anchors.centerIn: parent
            }
            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    currentWord = txt.text //чтобы дважды не искались номера при изменении текста
                    suggestionRectNumberplate.visible = false
                    numberText.clear()
                    numberText.text = txt.text
                }
                onHoveredChanged: {
                    suggestionViewNumberplate.currentIndex = index
                }
            }
        }
     }

     Component {
         id: searchNameDelegate
         Rectangle {
            height: 20
            width: suggestionRectName.width
            Text {
                id: txt
                text: modelData //name
                anchors.fill: parent
                anchors.leftMargin: 7
                anchors.topMargin: 2
                clip: true
//            	anchors.centerIn: parent
            }
            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    currentWord = txt.text
                    suggestionRectName.visible = false
                    carNameText.clear()
                    carNameText.text = txt.text
                }
                onHoveredChanged: {
                    suggestionViewName.currentIndex = index
                }
            }
        }
     }

     Component {
         id: searchColorDelegate
         Rectangle {
            height: 20
            width: suggestionRectColor.width
            Text {
                id: txt
                text: modelData //name
                anchors.fill: parent
                anchors.leftMargin: 7
                anchors.topMargin: 2
                clip: true
//            	anchors.centerIn: parent
            }
            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    currentWord = txt.text
                    suggestionRectColor.visible = false
                    colorPicText.clear()
                    colorPicText.text = txt.text
                }
                onHoveredChanged: {
                    suggestionViewColor.currentIndex = index
                }
            }
        }
     }

    numberTextInputMouseArea.onClicked: {
        numberText.clear()
        numberText.color = 'black'
        if (suggestionRectNumberplate.visible)
            suggestionRectNumberplate.visible = false
    }

    carNameInputMouseArea.onClicked: {
        carNameText.clear()
        carNameText.color = 'black'
        if (suggestionRectName.visible)
            suggestionRectName.visible = false
    }

    colorPicInputMouseArea.onClicked: {
        colorPicText.clear()
        colorPicText.color = 'black'
        if (suggestionRectColor.visible)
            suggestionRectColor.visible = false
    }

    clock2InputMouseArea.onClicked: {
        clock2Text.clear()
        clock2Text.focus = true
        clock2Text.color = 'black'
    }

    clock1InputMouseArea.onClicked: {
        clock1Text.clear()
        clock1Text.focus = true
        clock1Text.color = 'black'
   }

    date1.text: ''//date.toLocaleDateString('dd.MM.yyyy')

    date2.text: ''//date.toLocaleDateString('dd.MM.yyyy')

    cal.locale: Qt.locale('ru_RU')

    cal.onDoubleClicked: {
        date1.text = cal.selectedDate.toLocaleDateString('yyyy-MM-dd')
        cal.visible = false
        firstUnderBlock.visible = true
    }

    cal1.locale: Qt.locale('ru_RU')

    cal1.onDoubleClicked: {
         date2.text = cal1.selectedDate.toLocaleDateString('yyyy-MM-dd')
         cal1.visible = false
         secondUnderBlock.visible = true
    }


    calendarImageFirstMouseArea.onClicked: {
             if (cal.visible) {
                 cal.visible = false
                 firstUnderBlock.visible = true
             } else {
                 cal.visible = true
                 firstUnderBlock.visible = false
             }
         }

    calendarImageSecondMouseArea.onClicked: {
        if (cal1.visible) {
            cal1.visible = false
            secondUnderBlock.visible = true
        } else {
            cal1.visible = true
            secondUnderBlock.visible = false
        }
    }


}
