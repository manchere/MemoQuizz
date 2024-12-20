import QtQuick 2.3

Page { 
    property alias quizzManager: quizzManager
	signal submitAnswers(var answer)


    QuizzManager {
		id: quizzManager
    }

	Column {
		spacing: 10
		anchors.centerIn: parent

	ListView {
		id: questionList
		anchors.fill: parent
		model: questionModel
		delegate: QuestionContainer {
			questionData: modelData
		}
	}

    
    QuestionContainer {
	    anchors.fill: parent
	    questionData: questionModel.get(questionIndex)
        width: 400
        height: 200
        color: "red"
    }

	Button {
		anchors.bottom: parent.bottom
		anchors.horizontalCenter: parent.horizontalCenter
		text: "Next"
		onClicked: quizzManager.nextQuestion()
	}
}
}
