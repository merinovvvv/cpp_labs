#include "stringLib.h"
#include <algorithm>
#include <iostream>
#include <set>

void deletePunctuationSign(std::string& str)
{
	for (size_t i = 0; i < str.size(); ++i) {
		if (std::ispunct(static_cast<unsigned char>(str[i]))) {
			str.erase(i, 1);
			--i;
		}
	}
}

void deletePunctuationSign(std::vector<std::string>& list)
{
	for (auto& str : list) {
		deletePunctuationSign(str);	
	}
}

std::map <std::string, size_t> wordAmount(const std::vector <std::string>& list)
{
	std::map <std::string, size_t> numOfWords{};
	for (const auto& word : list) {
		++numOfWords[word];
	}
	if (numOfWords.find("") != numOfWords.end()) {
		numOfWords.erase("");
	}
	return numOfWords;
}