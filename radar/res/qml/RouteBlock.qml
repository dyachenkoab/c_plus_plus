import QtQuick 2.4

RouteBlockForm {
    property int currentItem: 0
    property bool firstClick: false
    property int minWidth: 228
    property int minHeight: 223
    property int previousX
    property int previousY

    routeHide.onClicked: {
        disappearAnim.start()
        hideAnim.start()
    }

    hideAnim.onStopped: {
        shadowRouteItem.visible = false
        mapModule.rollRouteUp.visible = true
        mapModule.rollRouteUp.z = 1
    }

    NumberAnimation on x {
         from: mainWindow.width;
         to: (mainWindow.width - shadowRouteItem.width) - 20;
         duration: 2000;
         easing.type: Easing.OutExpo
    }

    function upNum(row){
        for(let i = currentItem; i < row; i++) {
            mapModule.children[searchBlock.currentPolyLine].addCoordinate(watcher.points[i+1])
        }
    }

    function downNum(row){
        for(let j = currentItem; j > row; j--){
            mapModule.children[searchBlock.currentPolyLine].removeCoordinate(watcher.points[j])
        }
    }

    tableView.onClicked: {
        for (let v = 0; v < mapModule.children.length; v++){ // переход по точкам при нажатии на row
           if(mapModule.children[v].myiD === row){
                 mapModule.children[v].focus = true
                 mapModule.center = mapModule.children[v].center
               console.log(mapModule.children[v].center)
           }
        }

        if (currentItem < row)
            upNum(row)
        else if(currentItem > row)
            downNum(row)

        currentItem = row
        watcher.slide.value = row
    }

    onDragActiveChanged: {
        if (dragActive) {
            routeBlock.anchors.right = undefined
            routeBlock.anchors.bottom = undefined
        }
    }

    Component {
        id: dateDelegate
        Item {
            anchors.fill: parent
            Text {
                text: styleData.value ? styleData.value.toLocaleDateString('en-GB') : ''
                anchors.centerIn: parent
                clip: true
                color: styleData.selected ? 'white' : 'black'
            }
        }
    }

    Component {
        id: timeDelegate
        Item {
            anchors.fill: parent
            Text {
                text: styleData.value ? styleData.value.toLocaleTimeString('en-GB') : ''
                anchors.centerIn: parent
                clip: true
                color: styleData.selected ? 'white' : 'black'
            }
        }
    }

    Component {
        id: imageDelegate
        Item {
            id: delegateItem
            Image {
                id: sourceImage
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
                source: styleData.value
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log(sourceImage.source)
                    carPopup.carImage.source = sourceImage.source
                    carPopup.visible = true
                }
            }
        }
    }
// ---------------------------- масштабирование --------------------------------- //
    topArea.onPressed: {
        previousY = topArea.mouseY
    }
    topArea.onMouseXChanged: {
            if (background.height <= minHeight){
                background.height = minHeight
            }
            else if (background.height > minHeight) {
                routeBlock.anchors.right = undefined
                routeBlock.anchors.bottom = undefined
                var dy = topArea.mouseY - previousY
                background.y = (background.y + dy)
                background.height = (background.height - dy)
            }
    }
    topArea.onReleased: background.height <= minHeight ? background.height = minHeight + 0.01 : background.height = background.height

    bottomArea.onPressed: {
        previousY = bottomArea.mouseY
    }
    bottomArea.onMouseYChanged: {
            if (background.height <= minHeight){
                background.height = minHeight
            }
            else if (background.height > minHeight) {
                routeBlock.anchors.right = undefined
                routeBlock.anchors.bottom = undefined
                var dy = bottomArea.mouseY - previousY
                console.log(bottomArea.mouseX, bottomArea.mouseY)
                background.height = (background.height + dy)
            }
    }
    bottomArea.onReleased: background.height <= minHeight ? background.height = minHeight + 0.01 : background.height = background.height

    leftArea.onPressed: {
        previousX = leftArea.mouseX
    }
    leftArea.onMouseXChanged: {
            if (background.width <= minWidth){
                background.width = minWidth
            }
            else if (background.width > minWidth) {
                routeBlock.anchors.right = undefined
                routeBlock.anchors.bottom = undefined
                var dx = leftArea.mouseX - previousX
                background.x = (background.x + dx)
                background.width = (background.width - dx)
            }
    }
    leftArea.onReleased: background.width <= minWidth ? background.width = minWidth + 0.01 : background.width = background.width

    rightArea.onPressed: {
        previousX = rightArea.mouseX
    }
    rightArea.onMouseXChanged: {
            if (background.width <= minWidth){
                background.width = minWidth
            }
            else if (background.width > minWidth) {
                routeBlock.anchors.right = undefined
                routeBlock.anchors.bottom = undefined
                var dx = rightArea.mouseX - previousX
                background.width = (background.width + dx)
            }
    }
    rightArea.onReleased: background.width <= minWidth ? background.width = minWidth + 0.01 : background.width = background.width
}
