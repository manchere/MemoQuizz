#include "question.h"

Question::Question() {
	m_id = 0;
	m_text = "";
	m_image_path = "";
	m_options = QVector<QString>();
	m_answer = QVariant();
	m_type = MCQ;
	m_hint = "";
}

int Question::id() const {
	return m_id;
}

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

QString Question::hint() const {
	return m_hint;
}

QString Question::image_path() const {
	return m_image_path;
}

void Question::setQuestion(int id, QString text, QVector<QString> options, QString image_path, QVariant answer, Type type, QString hint) {
	m_id = id;
	m_text = text;
	m_options = options;
	m_type = type;
	m_hint = hint;
	m_image_path = image_path;
}