import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2

Rectangle {
    id: rootItem
    width: 360
    height: 240
    color: "#EEEEEE"

    Text {
        id: centerText
        text: qsTr("I am not new to QML")
        anchors.centerIn: parent
        font.pixelSize: 24
        font.bold: true
    }

    function setTextColor(clr) {
        centerText.color = clr
    }

    Row {
        anchors.left: parent.left
        anchors.leftMargin: 4
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 4
        spacing: 4
    }
}
