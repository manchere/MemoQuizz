import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 900
    height: 640
    title: "Memories Quiz"

    Rectangle {
        anchors.fill: parent
        color: "lightblue"

        Column {
            anchors.fill: parent
            spacing: 20
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            Text {
                text: "Memories"
                font.pixelSize: 24
                color: "black"
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Rectangle {
                width: 800
                height: 500
                color: "white"
                radius: 10
                border.color: "darkblue"
                border.width: 2
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter

                Column {
                    anchors.fill: parent
                    spacing: 30
                    padding: 20

                    IntroTextTypeWriter {
                        id: introText0
                        text: ""
                        textColor: "darkblue"
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
                        anchors.horizontalCenter: parent.horizontalCenter

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
        }
    }

    StackView {
        id: stackView
        anchors.fill: parent
    }
}