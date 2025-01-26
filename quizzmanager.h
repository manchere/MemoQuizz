#pragma once
#ifndef QUIZZMANAGER_H
#define QUIZZMANAGER_H

#include <QJsonDocument>
#include <QObject>
#include <QVector>
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include "question.h"

class QuizzManager : public QObject
{
	Q_OBJECT
		Q_PROPERTY(Question currentQuestion READ currentQuestion NOTIFY currentQuestionChanged)
		Q_PROPERTY(int currentQuestionIndex READ currentQuestionIndex NOTIFY currentQuestionIndexChanged)
		Q_PROPERTY(int currentScore READ currentScore NOTIFY scoreChanged)
		Q_PROPERTY(bool isQuizzFinished READ isQuizzFinished NOTIFY isFinishedChanged)

public:
	explicit QuizzManager( const QString &jsonFile, QObject* parent = nullptr);
	Q_INVOKABLE void startQuizz();
	Q_INVOKABLE void answerQuestion(bool answer);
	Q_INVOKABLE Question currentQuestion();	
	Q_INVOKABLE void nextQuestion();

	Q_INVOKABLE bool loadQuestionsFromJson(const QString& filePath);
	Q_INVOKABLE bool loadIntroText(const QString& filePath);

	int currentScore() const;
	int currentQuestionIndex() const;
	bool isQuizzFinished() const;
	QString introText() const;
	QJsonDocument jsonDoc();

	bool isHintGiven(int hintNum) const;
	bool isFullHintGiven() const;

signals:	
	void currentQuestionChanged();
	void currentQuestionIndexChanged();
	void scoreChanged();
	void isFinishedChanged();

private:
	QJsonDocument m_jsonDoc;
	QVector<Question> m_questions;
	Question m_currentQuestion;
	int m_currentScore;
	int m_currentQuestionIndex;
	bool m_hintGiven[3] = { false, false, false };
	QString m_introText;
};
#endif // !QUIZZMANAGER_H
 