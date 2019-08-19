import QtQuick 2.0
import ContactsModule.Base 1.0
import StyleModule 1.0
import ResourceProvider 1.0

BaseListDelegate {
    id: root

    ImageBubble {
        id: _contactBubble
    }

    Column {
        id: _contactInfo
    }
}
