import QtQuick 2.3
import QtQuick.Controls 2.15

Item {
        id: introTextItem
        property string text: ""
        property color textColor: "black"
        property int delay: 5000
        property int duration: 1500

        width: parent.width
        height: introText.implicitHeight

    Text {
        id: introText
        text: introTextItem.text
        font.pixelSize: 20
        color: introTextItem.textColor
        opacity: 0 // Start invisible
        wrapMode: Text.WordWrap
        width: parent.width

        // Fade-in animation
        Behavior on opacity {
            NumberAnimation {
                duration: introTextItem.duration // 1.5 second
            }
        }

            Timer {
                interval: introTextItem.delay // Delay before animation starts (500ms)
                running: true
                repeat: false
                onTriggered: introText.opacity = 1 // Fade in
        }
    }
}