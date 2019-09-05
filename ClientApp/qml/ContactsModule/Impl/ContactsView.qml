import QtQuick 2.0
import Contacts 1.0
import ContactsModule.Base 1.0

BaseListView {
    id: root
    model: ContactsModel {
        onDataChanged: console.log(rowCount())
    }

    delegate: ContactDelegate {
        width: root.width
        height: 70
    }




}
