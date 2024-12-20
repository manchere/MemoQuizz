import QtQuick 2.15
import QtQuick.Controls 2.15

Page {
    id: quizPage
    property int currentQuestionIndex: 0
    property int score: 0

    Column {
        anchors.fill: parent
        spacing: 10

        Text {
            id: questionText
            text: "Question goes here"
            font.pixelSize: 20
        }

        ListView {
            id: optionsList
            model: ["Option 1", "Option 2", "Option 3", "Option 4"]
            delegate: RadioButton {
                text: modelData
            }
        }

        Button {
            text: "Submit"
            onClicked: {
                // Call C++ backend to check answer
            }
        }
    }
}
