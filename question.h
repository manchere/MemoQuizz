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
		ImageArr,
		Undefined
	};

	Question();

	int id() const;
	QString text() const;
	QString image_path() const;
	QVector<QString> options() const;
	QVariant answer() const;
	Type type() const;
	QString hint() const;

	void setQuestion(int id, QString text, QVector<QString> options, QString image_path, QVariant answer, Type type, QString hint);
	void setQuestion(int id, QString text, QVector<QString> options, QVariant answer);

private:
	int m_id;
	QString m_text;
	QString m_image_path;
	QVector<QString> m_options;
	QVariant m_answer;
	Type m_type;
	QString m_hint;
};
#endif // !QUESTION_H
