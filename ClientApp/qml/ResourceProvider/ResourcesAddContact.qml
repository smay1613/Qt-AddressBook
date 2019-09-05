pragma Singleton
import QtQuick 2.0

Item {
    property alias contacts: _addContacts
    QtObject {
        id: _addContacts
        readonly property string defaultAddContactIcon: "qrc:/qml/resources/default-add-contacts-image.svg"
    }
}
