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

#include "interfaces/iloadable.h"
#include "interfaces/istatusable.h"
#include "interfaces/iprocessable.h"

class QuizzManager : public QObject, public ILoadable, public IStatusable<Question>, public IProcessable
{
	Q_OBJECT
		Q_PROPERTY(Question getCurrentState READ getCurrentstate NOTIFY currentStateChanged)
		Q_PROPERTY(int currentStep READ currentStep NOTIFY currentStepChanged)
		Q_PROPERTY(bool isFinished READ isFinished NOTIFY isFinishedChanged)
		Q_PROPERTY(QString introText READ introText CONSTANT)

public:
	explicit QuizzManager(const QString& jsonFile, QObject* parent = nullptr);
	Q_INVOKABLE void start();
	Q_INVOKABLE void processInput(const QVariant);
	Q_INVOKABLE Question getCurrentstate() const;
	Q_INVOKABLE void nextStep();

	Q_INVOKABLE bool loadData(const QString& filePath);
	Q_INVOKABLE bool loadMetaData(const QString& filePath);

	int getProgress() const;
	int currentStep();
	bool isFinished() const;
	QString introText() const;
	QJsonDocument jsonDoc();

	bool isHintGiven(int hintNum) const;
	bool isFullHintGiven() const;

signals:
	void currentStateChanged();
	void currentStepChanged();
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
