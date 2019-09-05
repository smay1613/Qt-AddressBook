import QtQuick 2.0

//CANCLE_____________
Rectangle {
    id: buttonCancle
    anchors.bottom: parent.bottom
    anchors.right: parent.right
    anchors.bottomMargin: 10
    anchors.rightMargin: 10
    width: 100
    height: 30

    color: "gray"

    Text {
        id: buttonLabel
        text: "Cancle"
        anchors.centerIn: parent;
        color: Style.textColor
    }

    MouseArea {
        anchors.fill: parent
        id: mouseAreaCancle
    }
}

////SAVE______________
//Rectangle {
//    id: buttonSave
//    anchors.bottom: parent.bottom
//    anchors.right: buttonCancle.left
//    anchors.bottomMargin: 10
//    anchors.rightMargin: 10

//    width: 100
//    height: 30


//    color: "gray"


//    Text {
//        id: buttonLabel1
//        text: "Save"
//        anchors.centerIn: parent;
//        color: Style.textColor
//    }


//    MouseArea {
//        anchors.fill: parent
//        id: mouseAreaSave
//    }
//}
