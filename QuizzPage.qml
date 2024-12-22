import QtQuick 2.3
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: quizzPage
    anchors.fill: parent
    color: "#f8f9fa"

        ColumnLayout {
        anchors.fill: parent
        Layout.fillWidth: true
        spacing: 20

        // Top area for question and image
          RowLayout {
            Layout.fillWidth: true

            // Question area
            Text {
                id: questionText
                text: "Quel est le nom de la boutique où tu as porté cette robe ?" // Example question
                font.pixelSize: 18
                wrapMode: Text.WordWrap
                Layout.preferredWidth: 300
                color: "#343a40"
            }

            Image {
                id: questionImage
                source: "qrc:/images/ui/heart.png" // Replace with actual image
                Layout.preferredWidth: 200
                Layout.preferredHeight: 150
                fillMode: Image.PreserveAspectFit
            }

            ColumnLayout { 
               id: optionsArea
               spacing: 10
               Layout.fillWidth: true

               RadioButton {
				   id: option1
				   text: "Option 1"
			   }

               RadioButton {
				   id: option2
				   text: "Option 1"
			   }

               RadioButton {
				   id: option3
				   text: "Option 1"
			   }

               RadioButton {
				   id: option4
				   text: "Option 1"
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

                Text {
                    id: hintText
                    text: "Indice : C'est une marque danoise connue pour ses styles ludiques."
                    font.pixelSize: 14
                    color: "#6c757d"
                    wrapMode: Text.WordWrap
                    visible: false
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
    }
}
