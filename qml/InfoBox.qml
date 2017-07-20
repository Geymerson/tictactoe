import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

/**
    @author: Geymerson Ramos
    email: geymerson@ic.ufal.br
    last updated july, 2017

    This software is distributed under
    the MIT License terms

    A component to display game points
**/

Item {
    id: infoBox
    width:100
    height: 50
    property string imgSource: ""
    property int imgWidth: 120
    property int imgHeight: 28
    property alias text: scoreLabel.text

    Row {
        anchors.fill: parent
        spacing: 5

        Image {
            id: img
            source: imgSource
            height: imgHeight
            width: imgWidth
        }

        Label {
            id: scoreLabel
            text: "0"
            font.pixelSize: 22
            color: "darkblue"
        }
    }
}
