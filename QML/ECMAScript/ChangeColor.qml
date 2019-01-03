import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Rectangle {
    width: 320
    height: 240
    color: "gray"

    Text {
        id: text1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 20
        text: qsTr("Text One")
        color: "blue"
        font.pixelSize: 28
    }

    Text {
        id: text2
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: text1.bottom
        anchors.topMargin: 8
        color: "blue"
        font.pixelSize: 28
        text: qsTr("Text Two")
    }

    Button {
        id: changeButton
        anchors.top: text2.bottom
        anchors.topMargin: 8
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("Change")
    }

    Connections {
        target: changeButton
        onClicked: {
            text1.color = Qt.rgba(Math.random(), Math.random(),
                                  Math.random(), 1)
            text2.color = Qt.rgba(Math.random(), Math.random(),
                                  Math.random(), 1)
        }
    }
}
