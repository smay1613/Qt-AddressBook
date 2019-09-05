import QtQuick 2.0
import StyleModule 1.0


Rectangle {
    id: root
    color: Style.backgroundColor
    opacity: _delegateArea.pressed ? Style.secondaryOpacity : Style.emphasisOpacity
    MouseArea {
        id: _delegateArea
        anchors.fill: root
    }




}
