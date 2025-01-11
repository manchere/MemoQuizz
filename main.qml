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
                text: "Choupi's Memories"
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
                        text: "Choupi! Over the time we've spent together, we've created some of the most
beautiful memories of my life. From little moments to unforgettable adventures,
every moment with you is magic, but today, I have a surprise for you! 
I've created something special, a quizz app, just for us 💕
This quiz is a playful walk down memory lane, 
filled with moments in our journey together. All the questions are related 
to our memories, they are MCQ, sometime with an image to help you remember 
the moment or answer the question. 

Every question is 1 point, you need 7 points for each digit of the code making a 
total of 21 points for the full code.
that will give you access to the padlock of your Christmas gift.
You are allowed a clue per question if you are stuck, but be careful
if you use the clue you will be given half a point for the question.

I hope you enjoy it as much as I enjoyed creating it for you.
I know you will ace it, gros bisou!"
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