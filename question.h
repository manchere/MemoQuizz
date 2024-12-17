#pragma once
#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
#include <QVector>
#include <QVariant>

class Question { 
public:
	enum Type {
		MCQ,
		FillIn,
		ImageArr
	};

	Question(const QString text, const QVector<QString> options, const QVariant answer, Type type);

	QString text() const;
	QVector<QString> options() const;
	QVariant answer() const;
	Type type() const;

private:
	QString m_text;
	QVector<QString> m_options;
	QVariant m_answer;
	Type m_type;
};
#endif // !QUESTION_H
