import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import ia2.project 1.0
import "qml"

/**
    @author: Geymerson Ramos
    email: geymerson@ic.ufal.br
    last updated july, 2017

    This software is distributed under
    the MIT License terms

    Game screen render
**/

ApplicationWindow {
    id: root
    visible: true
    width: 330
    height: 520
    title: qsTr("Tic-Tac-Toe")
    maximumHeight: 520
    maximumWidth: 330

    GameScreen {
        id: mainScreen
        anchors.fill: parent
    }
}
