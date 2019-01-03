import QtQuick 2.0

Rectangle {
    width: 320;
    height: 200;

    Text {
        id: normal
        anchors.left: parent.left;
        anchors.leftMargin: 20;
        anchors.top: parent.top;
        anchors.topMargin: 20;
        font.pointSize: 24;
        text: qsTr("Normal Text")
    }

    Text {
        id: raised
        anchors.left: normal.left;
        anchors.top: normal.bottom;
        anchors.topMargin: 4;
        font.pointSize: 24;
        style: Text.Raised;
        styleColor: "#AAAAAA";
        text: qsTr("Raised Text");
    }

    Text {
        id : outline;
        anchors.left: normal.left;
        anchors.top: raised.bottom;
        anchors.topMargin: 4;
        font.pointSize: 24;
        style: Text.Outline;
        styleColor: "red";
        text: qsTr("Outline Text");
    }

    Text {
        id: name
        anchors.left: normal.left;
        anchors.top: outline.bottom;
        anchors.topMargin: 4;
    font.pointSize: 24;
        style: Text.Sunken;
        styleColor: "#A00000";
        text: qsTr("text")
    }
}
