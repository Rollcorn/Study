import QtQuick 2.0

GridView {
    id: root

    cellHeight: height / 4
    cellWidth: width / 4

    delegate: Item {
       id: _backgroundDelegate
       width: root.cellWidth
       height: root.cellHeight

       visible: display != 16

        Tile {
           anchors.fill: _backgroundDelegate
           anchors.margins: 5

           displayText: display
        }
    }

}
