import QtQuick 2.0

Rectangle{
    width: 200;
    height: 200;

    Rectangle {
        color: "blue";
        anchors.fill: parent;
        border.width: 6;
        border.color: "#888888";

        Rectangle{
            anchors.centerIn: parent;
            width: 120;
            height: 120;
            radius: 8;
            border.width: 2;
            border.color: "black";
            antialiasing: true;
            color: "red";
        }
    }
}
