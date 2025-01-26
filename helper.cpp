#include "helper.h"
#include <algorithm>


Helper::Helper() {}
Helper::~Helper() {}

QString Helper::trimFromWord(const std::string& str, const std::string& word) {
	size_t targetWord = str.find(word);

	if (targetWord == std::string::npos) {
		return QString::fromStdString(str);
	}

	return QString::fromStdString(str.substr(0, targetWord));
}