import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 900
    height: 480
    title: "Memory Quizz"

    Rectangle {
        anchors.fill: parent
        color: "lightblue"

        Column {
            anchors.fill: parent
            spacing: 20

            Text {
                text: "Welcome to Our Memory Quiz"
                font.pixelSize: 24
                color: "darkblue"
            }

            IntroTextTypeWriter {
                id: introText0
				text: ""
                delay: 1000
                duration: 1500 
                onFinished: startQuizBtn.visible = true
            }

             Button {
                id: startQuizBtn
                text: "Start Quiz"
                font.pixelSize: 20
                font.bold: true
                visible: false
                
                background: Rectangle {
                implicitWidth: 120
                implicitHeight: 50
                radius: 12
                border.color: "black"
                border.width: 2
                gradient: Gradient {
                    GradientStop { position: 0.0; color: "lightgray" }
                    GradientStop { position: 1.0; color: "white" }
                    }
                }

                onClicked: stackView.push("QuizzPage.qml")
            }
        }
    }
    
    StackView {
        id: stackView
        anchors.fill: parent
    }
}
