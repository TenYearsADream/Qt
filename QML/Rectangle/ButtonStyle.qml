import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4

Rectangle{
    width: 300;
    height: 200;

    Button {
        text: qsTr("Quit");
        anchors.centerIn: parent;
        style: ButtonStyle{
            background: Rectangle{
                implicitWidth: 70;
                implicitHeight: 25;
                border.width: control.pressed ? 2 : 1;
                border.color: (control.hoverd || control.pressed) ? "green" : "#888888";
            }
        }
        onClicked: Qt.quit();
    }
}
