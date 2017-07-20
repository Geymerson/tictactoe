import QtQuick 2.0

Item {
    id: button
    width: 80
    height: 50

    signal pressed

    Image {
        id: buttonImg
        source: "../images/newgame.png"
        anchors.fill: parent
        anchors.centerIn: parent
    }

    MultiPointTouchArea {
        id: multiPointTouchArea
        anchors.fill: parent
        onPressed: button.pressed()
    }
}
