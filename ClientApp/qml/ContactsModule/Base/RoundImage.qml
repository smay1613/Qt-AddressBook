import QtQuick 2.0
import QtGraphicalEffects 1.0
import StyleModule 1.0

Image {
    id: root
    property bool rounded: true
    property bool adapt: true

    layer.enabled: rounded
    layer.effect: OpacityMask {
        maskSource: Item {
            width: root.width
            height: root.height
            Rectangle {
                anchors.centerIn: parent
                width: root.adapt ? root.width : Math.min(root.width, root.height)
                height: root.adapt ? root.height : width
                radius: Math.min(width, height)
            }
        }
    }

}
