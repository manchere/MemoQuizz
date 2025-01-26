#pragma once
#ifndef HELPER_H
#define HELPER_H
#include <QString>
#include <string>

class Helper
{
public:
	Helper();
	~Helper();
	QString trimFromWord(const std::string& str, const std::string& word);
};

#endif // !HELPER_H