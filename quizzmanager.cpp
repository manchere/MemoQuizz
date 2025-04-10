#include "quizzmanager.h"
#include "helper.h"
#include "question.h"
#include <QDebug>
#include <QDir>
#include <QCoreApplication>

QuizzManager::QuizzManager(const QString& jsonFile, QObject* parent)
	: QObject(parent) {
	loadMetaData(jsonFile);
	loadData(jsonFile);
}


bool QuizzManager::loadData(const QString& filePath) {
	QFile file(filePath);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qWarning() << "Couldn't open file";
		return false;
	}

	QString jsonFile = file.readAll();
	file.close();

	QJsonDocument doc = QJsonDocument::fromJson(jsonFile.toUtf8());

	m_questions.clear();

	QJsonObject root = doc.object();
	QJsonArray questions = root.value("questions").toArray();

	for (const QJsonValue& value : questions) {
		QJsonObject obj = value.toObject();
		int id = obj.value("id").toInt();
		QString text = obj.value("question").toString();
		QVector<QString> options;

		for (const QJsonValue& option : obj.value("options").toArray()) {
			options.append(option.toString());
		}

		qDebug() << obj.value("options").toArray();

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

		Question question;
		question.setQuestion(id, text, options, answer);
		m_questions.append(question);
	}
	return true;
}

bool QuizzManager::loadMetaData(const QString& filePath) {
	QFile file(filePath);
	if (!file.open(QIODevice::ReadOnly)) {
		qWarning() << "Couldn't open file";
		return false;
	}

	QString jsonFile = file.readAll();
	file.close();

	QJsonDocument doc = QJsonDocument::fromJson(jsonFile.toUtf8());
	QJsonObject root = doc.object();

	QJsonObject misc = root.value("misc").toObject();
	m_introText = misc.value("intro").toString();
	return true;
}

void QuizzManager::start() {
	m_currentScore = 0;
	m_currentQuestionIndex = 0;
	if (!m_questions.empty()) {
		m_currentQuestion = m_questions[m_currentQuestionIndex];
	}
	emit scoreChanged();
	emit currentStepChanged();
}

void QuizzManager::processInput(const QVariant) {
	if (m_currentQuestionIndex < 0 || m_currentQuestionIndex >= m_questions.size()) {
		return;
	}

	/*if (m_questions[m_currentQuestionIndex].isCorrect(answer)) {
		m_score++;
		emit scoreChanged();
	}*/
}

void QuizzManager::nextStep() {
	if (m_currentQuestionIndex < m_questions.size() - 1) {
		m_currentQuestionIndex++;
		emit currentStepChanged();
	}
	else {
		emit isFinishedChanged();
	}
}

Question QuizzManager::getCurrentstate() const {
	if (m_currentQuestionIndex >= 0 && m_currentQuestionIndex < m_questions.size()) {
		return m_questions[m_currentQuestionIndex];
	}
	return Question();
}

int QuizzManager::getProgress() const {
	return m_currentScore;
}

int QuizzManager::currentStep() {
	return m_currentQuestionIndex;
}

bool QuizzManager::isFinished() const {
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

QString QuizzManager::introText() const {
	return m_introText;
}

QJsonDocument QuizzManager::jsonDoc() {
	return m_jsonDoc;
}