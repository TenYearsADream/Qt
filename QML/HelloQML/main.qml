import QtQuick 2.10
import QtQuick.Window 2.10

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("QML Project.")

    MouseArea{
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }

    Text {
        id: test
        text: qsTr("I am new to QML.")
        anchors.centerIn: parent
    }
}
