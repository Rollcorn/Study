import QtQuick 2.0

Rectangle {
    id: root

    property string displayText: ""
//    readonly property alias internalText: _firstText

    color: "lightgreen"

    radius: 10

    border {
        color: "black"
        width: 1
    }

    Text {
        id: _firstText
        anchors.centerIn: root

        text: root.displayText
        font {
            pointSize: Math.min(root.width, root.height) / 3
            bold: true
        }
    }
}
