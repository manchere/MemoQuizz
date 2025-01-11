#include "quizzmanager.h"
#include "helper.h"
#include "question.h"


QuizzManager::QuizzManager(QObject* parent) : QObject(parent) {}

bool QuizzManager::loadQuestionsFromJson(const QString& filePath) {
	QFile file(filePath);
	if (!file.open(QIODevice::ReadOnly)) {
		qWarning() << "Couldn't open file";
		return false;
	}

	QByteArray jsonData = file.readAll();
	QJsonDocument doc = QJsonDocument::fromJson(jsonData);
	if (!doc.isArray()) {
		qWarning() << "Couldn't parse JSON";
		return false;
	}

	QJsonArray jsonArray = doc.array();
	m_questions.clear();

	for (const QJsonValue& value : jsonArray) {
		QJsonObject obj = value.toObject();
		int id = obj.value("id").toInt();
		QString text = obj.value("question").toString();
		QVector<QString> options;

		for (const QJsonValue& option : obj.value("options").toArray()) {
			options.push_back(option.toString());
		}

		QString image_path = obj.value("image_path").toString();

		QVariant answer = obj.value("answer").isArray()
			? QVariant(obj.value("answer").toArray().toVariantList())
			: QVariant(obj.value("answer").toString());

		QString typeStr = obj.value("type").toString();
		Question::Type type = Question::MCQ;

		QString hint = obj.value("hint").toString();


		if (typeStr == "MCQ") {
			type = Question::MCQ;
		}
		else if (typeStr == "FillIn") {
			type = Question::FillIn;
		}

		Question question = Question();
		question.setQuestion(id, text, options, image_path, answer, type, hint);
		m_questions.push_back(question);
	}
	return true;
}

void QuizzManager::startQuizz() {
	m_currentScore = 0;
	m_currentQuestionIndex = 0;
		if (!m_questions.empty()) {
		m_currentQuestion = m_questions[m_currentQuestionIndex];
	}
	emit scoreChanged();
	emit currentQuestionIndexChanged();
}

void QuizzManager::answerQuestion(bool answer) {
	if (m_currentQuestionIndex < 0 || m_currentQuestionIndex >= m_questions.size()) {
		return;
	}

	/*if (m_questions[m_currentQuestionIndex].isCorrect(answer)) {
		m_score++;
		emit scoreChanged();
	}*/
}

void QuizzManager::nextQuestion() {
	if (m_currentQuestionIndex < m_questions.size() - 1) {
		m_currentQuestionIndex++;
		emit currentQuestionIndexChanged();
	}
	else {
		emit isFinishedChanged();
	}
} 

Question QuizzManager::currentQuestion() {
	if (m_currentQuestionIndex >= 0 && m_currentQuestionIndex < m_questions.size()) {
		return m_questions[m_currentQuestionIndex];
	}
	return Question();
}

int QuizzManager::currentScore() const {
	return m_currentScore;
}

int QuizzManager::currentQuestionIndex() const {
	return m_currentQuestionIndex;
}

bool QuizzManager::isQuizzFinished() const {
	return isHintGiven(0) && isHintGiven(1) && isHintGiven(2);
}

bool QuizzManager::isHintGiven(int hintNum) const {
	if (m_hintGiven[hintNum]) {
		return true;
	}
	return false;	
}

bool QuizzManager::isFullHintGiven() const {
	return std::all_of(std::begin(m_hintGiven), std::end(m_hintGiven), [](bool hint) { return hint; });
}