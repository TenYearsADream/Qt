import QtQuick 2.0
import QtQuick.Controls 2.2

Rectangle{
    width: 320;
    height: 240;
    color: "gray";

    Button{
        text: qsTr("Quit");
        anchors.centerIn: parent;
        onClicked: {
            Qt.quit();
        }
    }
}
