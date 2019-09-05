import QtQuick 2.11
import QtQuick.Window 2.11
import ContactsModule.Impl 1.0
import StyleModule 1.0

Window {
    id : mainWindow
    visible: true
    width: 480
    height: 640
    title: qsTr("Address book")

    ContactsView {
        anchors.fill: parent
    }

    Rectangle {
        id: _background
        z: -100
        anchors.fill: parent
        color: Style.backgroundColor
        opacity: Style.emphasisOpacity
    }
}
