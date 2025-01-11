import QtQuick 2.3
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Page {
    Rectangle {
        id: quizzPage
        anchors.fill: parent
        color: "#f8f9fa"
        anchors.margins: 20

        ColumnLayout {
            anchors.fill: parent
            Layout.fillWidth: true
            spacing: 20

            ColumnLayout {
			    Layout.fillWidth: true
			    Layout.alignment: Qt.AlignCenter

                RowLayout {
                    anchors.fill: parent
                    Layout.fillWidth: true
                    spacing: 100
			        Text {
				        text: "Question 1/10"
				        font.pixelSize: 18
				        color: "#343a40"
			        }

                    Text {
				        text: "456"
				        font.pixelSize: 18
				        color: "#343a40"
			        }
                }
                Rectangle {
				    Layout.fillWidth: true
				    Layout.alignment: Qt.AlignCenter
				    implicitHeight: 2
                    implicitWidth : 2
				    color: "#343a40"
			    }
		    }

            // Top area for question and image
              RowLayout {
                Layout.fillWidth: true
                // Question area
                Text {
                    id: questionText
                    text: quizzManager.currentQuestion.question
                    font.pixelSize: 18
                    wrapMode: Text.WordWrap
                    Layout.preferredWidth: 300
                    color: "#343a40"
                }

                Image {
                    id: questionImage
                    source: "qrc:/images/ui/heart.png" 
                    Layout.preferredWidth: 200
                    Layout.preferredHeight: 150
                    fillMode: Image.PreserveAspectFit
                }

                ColumnLayout { 
                   id: optionsArea
                   spacing: 10
                   Layout.fillWidth: true
                   Layout.alignment: Qt.AlignCenter

                   RadioButton {
				       id: option1
				       text: quizzManager.currentQuestion.options[0]
                       font.pixelSize: 18
                       font.bold: true
			       }

                   RadioButton {
				       id: option2
				       text: quizzManager.currentQuestion.options[1]
                       font.pixelSize: 18
                       font.bold: true
			       }

                   RadioButton {
				       id: option3
				       text: quizzManager.currentQuestion.options[2]
                       font.pixelSize: 18
                       font.bold: true
			       }

                   RadioButton {
				       id: option4
				       text: quizzManager.currentQuestion.options[3]
                       font.pixelSize: 18
                       font.bold: true
			       }

                   ColumnLayout {
                    id: hintArea
                    spacing: 10
                    Layout.fillWidth: true

                    Button {
                        id: hintButton
                        text: "Afficher un indice"
                        font.bold: true
                        font.pixelSize: 20
                        Layout.alignment: Qt.AlignLeft
                        background: Rectangle {
                        implicitWidth: 240
                        implicitHeight: 50
                        radius: 12
                        border.color: "black"
                        border.width: 2
                        gradient: Gradient {
                            GradientStop { position: 0.0; color: "lightgray" }
                            GradientStop { position: 1.0; color: "white" }
                            }
                        }
                        onClicked: {
                            hintText.visible = true
                        }
                    }


                    RowLayout {
                        Button {
                        id: submintBtn
                        text: "Soumettre"
                        font.bold: true
                        font.pixelSize: 20
                        Layout.alignment: Qt.AlignLeft
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

                        onClicked: {
                            // Check if the selected option is correct
                        }
                        }

                        Button {
                            id: nextBtn
                            text: "Suivant"
                            font.bold: true
                            font.pixelSize: 20
                            Layout.alignment: Qt.AlignLeft
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
                            onClicked: {
                                // Load next question
                            }
                        }
                 }
                } 
              }
            }
            
            Text {
                id: hintText
                text: "Indice : C'est une marque danoise connue pour ses styles ludiques."
                font.pixelSize: 14
                font.bold: true
                Layout.alignment: Qt.AlignCenter
                color: "#6c757d"
                wrapMode: Text.WordWrap
                visible: false
            }
        }
    }
}