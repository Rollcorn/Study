import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("15 puzzle")

/*   Tile {
        width: root.width / root.model.dimension
        height: root.height / root.model.dimension
    }
*/
    GameBoard {
        id: _gameBoard
        anchors.fill: parent
        anchors.margins: 5
    }
}
