import QtQuick 2.7

/**
    @author: Geymerson Ramos
    email: geymerson@ic.ufal.br
    last updated july, 2017

    This software is distributed under
    the MIT License terms

    A grid cell for placing X's and O's
**/

Item {
    id: gridCell
    width: 55
    height: 55
    property int cellType: 1
    property int index: 0

    signal pressed

    onCellTypeChanged: {
        if(cellType === 2) {
            icon.source = "../images/cross.png"
            icon.visible = true
        } else if(cellType === 3) {
            icon.source = "../images/circle.png"
            icon.visible = true
        }
        else {
            icon.visible = false;
        }
    }

    Image {
        id: icon
        width: parent.width
        height: parent.height
        visible: false
    }

    MultiPointTouchArea {
        id: multiPointTouchArea
        anchors.fill: parent
        onPressed: {
            gridCell.pressed()
        }
    }
}
