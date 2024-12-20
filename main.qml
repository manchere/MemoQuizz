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

            IntroTextFade {
                id: introText0
				text: "Choupi! Over the time we've spent together, we've create some of the most
                       beautiful memories of my life. From little moments to unforgettable adventures,
                       evry moment with you is magic"
				textColor: "darkblue"
                delay: 500
                duration: 1500 
            }

            IntroTextFade {
                id: introText1
				text: "but today, I have a surprise for you! I've created something special, a quizz app, just for us 💕
                       This quiz is a playful walk down memory lane, filled with moments in our journey together."
				textColor: "darkblue"
                delay: 7000
                duration: 1500 
            }
            
            IntroTextFade {
                id: introText2
				text: "all questions are related  to our memories"
				textColor: "darkblue"
                delay: 14000
                duration: 1500 
            }

            IntroTextFade {
                id: introText3
				text: "you will have two types of questions, MCQ and fill in the blank
                        both with images, videos and messsages"
				textColor: "darkblue"
                delay: 21000
                duration: 1500 
            }

            IntroTextFade {
                id: introText5
				text: "After every 7 questions answered correctly you will unlock one of the digits that will give you access to your christmas gift"
				textColor: "darkblue"
                delay: 28000
                duration: 1500 
            }

            IntroTextFade {
                id: introText6
				text: "I wish you the best of luck, I know you will ace it, gros bisou!"
				textColor: "darkblue"
                delay: 35000
                duration: 1500 
            }


            Button {
                text: "Start Quiz"
                font.pixelSize: 20
                font.bold: true
                
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
                visible: introText1.opacity === 1
            }
        }
    }
}
