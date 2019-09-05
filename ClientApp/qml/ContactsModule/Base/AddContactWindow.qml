import QtQuick 2.0
import StyleModule 1.0
import QtQuick.Controls 1.2
import ResourceProvider 1.0
import Contacts 1.0

ApplicationWindow {
    id: rootSecond
    width: 480;
    height: 200
    title: qsTr("Add new contact")

    Rectangle {
        id: _background
        z: -100
        anchors.fill: parent
        color: Style.backgroundColor

    }


    ImageBubble {
        id: _contactPhoto
        boundingRadius: rootSecond.height / 1.5
        image.source: Resources.contacts.defaultContactIcon


    }

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
            onClicked: {
            rootSecond.close()
            mainWindow.show()
            }
        }
    }

    //SAVE______________
    Rectangle {
        id: buttonSave
        anchors.bottom: parent.bottom
        anchors.right: buttonCancle.left
        anchors.bottomMargin: 10
        anchors.rightMargin: 10

        width: 100
        height: 30


        color: "gray"


        Text {
            id: buttonLabel1
            text: "Save"
            anchors.centerIn: parent;
            color: Style.textColor
        }


        MouseArea {
            anchors.fill: parent
            id: mouseAreaSave
            onClicked: {

            ContactsModel.saveNewContact();
            ContactsModel.addNewContact(1);
            }
        }
    }

    Rectangle {
           id: textinputName
            anchors.top: parent.top
            anchors.left: _contactPhoto.right
            anchors.margins: 10

           width: parent.width /2
           height: 30

           color: "gray"

           TextInput {
               id: textinputN
               objectName: "textinputName"
               color: "White"
               font.pixelSize: 20;
               width: parent.width-4
               anchors.centerIn: parent
               focus: true
               text:"Name"
               }
       }
    Rectangle {
           id: textinputSurname
            anchors.top: textinputName.bottom
            anchors.left: _contactPhoto.right
            anchors.margins: 10

           width: parent.width /2
           height: 30

           color: "gray"

           TextInput {
               id: textinputS
               objectName: "textinputSurname"
               color: "White"
               font.pixelSize: 20;
               width: parent.width-4
               anchors.centerIn: parent
               focus: true
               text:"Surname"
               }
       }
    Rectangle {
           id: textinputPhone
            anchors.top: textinputSurname.bottom
            anchors.left: _contactPhoto.right
            anchors.margins: 10

           width: parent.width /2
           height: 30

           color: "gray"

           TextInput {
               id: textinputP
               objectName: "textinputPhone"
               color: "White"
               font.pixelSize: 20;
               width: parent.width-4
               anchors.centerIn: parent
               focus: true
               text:"Phone"
               }
       }



}
