import QtQuick 2.9

Rectangle {
    width: 320;
    height: 200;

    Text {
        id: blue_text
        width: 150;
        height: 100;
        wrapMode: Text.WordWrap;
        text: qsTr("I am new to QML, but I familar with Qt.");
        font.bold: true;
        font.pixelSize: 24;
        font.underline: true;
        anchors.centerIn: parent;
        color: "blue";
    }
}
