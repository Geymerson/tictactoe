import QtQuick 2.7
import ia2.project 1.0

/**
    @author: Geymerson Ramos
    email: geymerson@ic.ufal.br
    last updated july, 2017

    This software is distributed under
    the MIT License terms

    Game grid component with 9 grid cells
    to represent TIC-TAC-TOE's board
**/

Item {
    id: grid
    width: 280
    height: width

    Board {
        id: gridBoard

        onBoardChanged: {
            pos0.cellType = position(0);
            pos1.cellType = position(1);
            pos2.cellType = position(2);
            pos3.cellType = position(3);
            pos4.cellType = position(4);
            pos5.cellType = position(5);
            pos6.cellType = position(6);
            pos7.cellType = position(7);
            pos8.cellType = position(8);
        }

        onXWon: {
            victoryInfoBox.text = parseInt(victoryInfoBox.text) + 1;
            enableCells(false);
        }

        onOWon: {
            defeatInfoBox.text = parseInt(defeatInfoBox.text) + 1
            enableCells(false);
        }

        onDrawGame: {
            drawInfoBox.text = parseInt(drawInfoBox.text) + 1
            enableCells(false);
        }
    }

    Grid {
        width: 195
        height: 195
        columns: 3
        rowSpacing: 18
        columnSpacing: 15
        anchors.centerIn: parent

        GridCell { //default index 0
            id: pos0
            onPressed: {
                if(cellType === 1) {
                    gridBoard.setPosition(2, pos0.index);
                }
            }
        }

        GridCell {
            id: pos1
            index: 1
            onPressed: {
                if(cellType === 1) {
                    gridBoard.setPosition(2, pos1.index);
                }
            }
        }

        GridCell {
            id: pos2
            index: 2
            onPressed: {
                if(cellType === 1) {
                    gridBoard.setPosition(2, pos2.index);
                }
            }
        }

        GridCell {
            id: pos3
            index: 3
            onPressed: {
                if(cellType === 1) {
                    gridBoard.setPosition(2, pos3.index);
                }
            }
        }

        GridCell {
            id: pos4
            index: 4
            onPressed: {
                if(cellType === 1) {
                    gridBoard.setPosition(2, pos4.index);
                }
            }
        }

        GridCell {
            id: pos5
            index: 5
            onPressed: {
                if(cellType === 1) {
                    gridBoard.setPosition(2, pos5.index);
                }
            }
        }

        GridCell {
            id: pos6
            index: 6
            onPressed: {
                if(cellType === 1) {
                    gridBoard.setPosition(2, pos6.index);
                }
            }
        }
        GridCell {
            id: pos7
            index: 7
            onPressed: {
                if(cellType === 1) {
                    gridBoard.setPosition(2, pos7.index);
                }
            }
        }
        GridCell {
            id: pos8
            index: 8
            onPressed: {
                if(cellType === 1) {
                    gridBoard.setPosition(2, pos8.index);
                }
            }
        }
    }

    Image {
        id: gridImg
        source: "../images/grid.png"
        anchors.centerIn: parent
        width: 200
        height: 200
    }

    function newGame() {
        gridBoard.initBoard();
        enableCells(true);
    }

    function enableCells(val) {
        pos0.enabled = val
        pos1.enabled = val
        pos2.enabled = val
        pos3.enabled = val
        pos4.enabled = val
        pos5.enabled = val
        pos6.enabled = val
        pos7.enabled = val
        pos8.enabled = val
    }
}
