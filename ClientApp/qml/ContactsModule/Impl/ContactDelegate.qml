import QtQuick 2.0
import ContactsModule.Base 1.0
import StyleModule 1.0
import ResourceProvider 1.0


BaseListDelegate {
    id: root

    ImageBubble {
        id: _contactBubble
        anchors.left: root.left
        anchors.leftMargin: Style.defaultOffset
        anchors.verticalCenter: root.verticalCenter
        boundingRadius: root.height - 15
        image.source: Resources.contacts.defaultContactIcon

    }

    Column {
        anchors.left: _contactBubble.right
        anchors.leftMargin: Style.defaultOffset
        anchors.verticalCenter: root.verticalCenter
        Row {
            spacing: Style.smallSpacing
            BaseText {
                text: firstname
            }
            BaseText {
                text: surname
            }
        }
        BaseText {
            text: "+" + phoneNumber
            color: Style.primaryColor
        }
    }
}
