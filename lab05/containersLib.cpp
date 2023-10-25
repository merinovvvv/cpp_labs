#include <fstream>
#include <set>
#include <string>
#include "containersLib.h";

using std::ofstream;
using std::ifstream;
using std::multiset;
using std::string;

	std::multiset<std::string> readMultiset(std::string filePath) {
	string str;
	ifstream fin(filePath, std::ios::in);
	multiset<string> container;
	while (getline(fin, str)) {
		container.insert(str);
	}
	fin.close();
	return container;
}

void printMultiset(std::string filePath, std::multiset<string> container) {
	ofstream output(filePath);
	for (const auto& tmp : container) {
		output << tmp << "\n";
	}
	output.close();
}