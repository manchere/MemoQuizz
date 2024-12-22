import QtQuick 2.3
import QtQuick.Controls 2.15

Item {
        id: introTextItem
        property string text: ""
        property color textColor: "black"
        property int delay: 500
        property int duration: 150
        property string displayText: ""
        property int interval: 1
        property int startDelay: 1000

        signal finished

        width: parent.width
        height: typeWriterText.implicitHeight

        function start() {
            delayTimer.start()
        }

    Text {
        id: typeWriterText
        font.pixelSize: 20
        color: introTextItem.textColor
        text: introTextItem.displayText


        Timer {
            id: delayTimer
            interval: introTextItem.startDelay
            running: true
            repeat: false
            onTriggered: typingTimer.start()
        }

        Timer {
            id: typingTimer
            interval: introTextItem.interval // Delay before animation starts (500ms)
            running: false
            repeat: true

            onTriggered: {
                if (introTextItem.text.length > introTextItem.displayText.length) {
                    introTextItem.displayText += introTextItem.text[introTextItem.displayText.length];
                } else {
                    typingTimer.stop();
                    introTextItem.finished(); // Emit the finished signal
                }
            }
        }

    }
}