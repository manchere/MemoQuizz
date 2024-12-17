#include "question.h"

Question::Question(const QString text, const QVector<QString> options, const QVariant answer, Type type) : m_text(text), m_options(options), m_answer(answer), m_type(type) {}

QString Question::text() const {
	return m_text;
}

QVector<QString> Question::options() const {
	return m_options;
}

QVariant Question::answer() const {
	return m_answer;
}

Question::Type Question::type() const {
	return m_type;
}