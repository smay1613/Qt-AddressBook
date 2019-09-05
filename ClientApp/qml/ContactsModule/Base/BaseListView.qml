import QtQuick 2.0
import ResourceProvider 1.0
import StyleModule 1.0

ListView {
    spacing: 1
    section.criteria: ViewSection.FirstCharacter
    section.property: "name"



    ImageBubble {
        id: _contactBubble
        anchors.right: root.right
        anchors.bottom: root.bottom
        boundingRadius: root.height / 10
        anchors.margins: 30
        image.source: Resources.addContacts.defaultAddContactIcon
        MouseArea {
            id: _mouse
            anchors.fill: parent
            onClicked: {
                //need add event (new contact)
                var component = Qt.createComponent("AddContactWindow.qml")
                var window    = component.createObject(root)
                window.show()
                mainWindow.hide()
            }
        }
    }
}

