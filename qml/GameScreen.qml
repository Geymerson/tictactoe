import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "../qml"

/**
    @author: Geymerson Ramos
    email: geymerson@ic.ufal.br
    last updated july, 2017

    This software is distributed under
    the MIT License terms

    Game screen component
**/

Item {
    id: gameScreen
    anchors.fill: parent

    Image {
        id: background
        source: "../images/bgImage.jpg"
    }

    Image {
        id: title
        source: "../images/titleimg2.png"
        height: 50
        width: parent.width * 0.6
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: parent.height * 0.02
    }

    Image {
        id: ornament1
        source: "../images/ornament1.png"
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.bottomMargin: parent.height * 0.05
        anchors.leftMargin: parent.height * 0.05
        opacity: 0.5
    }

    Image {
        id: ornament2
        width: parent.width * 0.15
        height: width
        source: "../images/ornament2b.png"
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.bottomMargin: parent.height * 0.15
        anchors.rightMargin: parent.width * 0.1
        rotation: 30
    }

    MGrid {
        id: grid
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: title.bottom
        anchors.topMargin: parent.height * 0.04
    }

    InfoBox {
        id: victoryInfoBox
        imgSource: "../images/vic.png"
        anchors.top: title.bottom
        anchors.left: parent.left
        anchors.topMargin: parent.height * 0.03
        anchors.leftMargin: parent.width * 0.02
    }

    InfoBox {
        id: drawInfoBox
        rotation: 30
        imgSource: "../images/draw.png"
        anchors.bottom: ornament1.top
        anchors.left: parent.left
        anchors.leftMargin: parent.width * 0.02
    }

    InfoBox {
        id: defeatInfoBox
        imgSource: "../images/def.png"
        imgHeight: 45
        anchors.top: grid.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Button {
        id: newGameButton
        text: "New game"
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.bottomMargin: parent.height * 0.02
        anchors.rightMargin: parent.height * 0.02
        onClicked: {
            grid.newGame();
        }
    }
}
