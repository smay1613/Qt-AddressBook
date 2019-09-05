pragma Singleton
import QtQuick 2.0

Item {
    property alias contacts: _contacts
    QtObject {
        id: _contacts
        readonly property string defaultContactIcon: "qrc:/qml/resources/default-contact-icon.svg"
    }

    property alias addContacts: _addContacts
    QtObject {
        id: _addContacts
        readonly property string defaultAddContactIcon:"qrc:/qml/resources/default-add-contacts-image.svg"
    }

}
