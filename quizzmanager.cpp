#include "quizzmanager.h"
#include "helper.h"

QuizzManager::QuizzManager(QObject* parent) : QObject(parent), m_currentScore(0), m_currentQuestionIndex(-1) {}

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
		QString text = obj.value("text").toString();
		QVector<QString> options;

		for (const QJsonValue& option : obj.value("options").toArray()) {
			options.push_back(option.toString());
		}
		QVariant answer = obj.value("answer").isArray()
			? QVariant(obj.value("answer").toArray().toVariantList())
			: QVariant(obj.value("answer").toString());

		QString typeStr = obj.value("type").toString();
		Question::Type type = Question::MCQ;

		if (typeStr == "MCQ") {
			type = Question::MCQ;
		}
		else if (typeStr == "FillIn") {
			type = Question::FillIn;
		}

		m_questions.push_back(Question(text, options, answer, type));

	}
	return true;
}

void QuizzManager::startQuizz() {
	m_currentScore = 0;
	m_currentQuestionIndex = 0;
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