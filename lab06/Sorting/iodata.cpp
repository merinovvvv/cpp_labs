#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "iodata.h"
using std::ofstream;
using std::ifstream;
using std::ios;
// TODO add templates for iodata
void outToConsole(const std::vector <int>& vec, const std::string& delimeter) {
	for (const int& element : vec) {
		std::cout << element << delimeter;
	}
	std::cout << '\n';
}

void writeData(const std::vector <int>& list, const std::string& filePath)
{
	ofstream output(filePath, ios::out);
	for (const auto& item : list) {
		output << item << '\n';
	}
	output.close();
}

void readData(std::vector <int>& list, const std::string& filePath)
{
	//std::vector <int> result;
	std::string str;
	ifstream fin(filePath, ios::in);
	int tmp;
	while (getline(fin, str)) {
		std::stringstream ss(str);
		while (!ss.eof()) {
			ss >> tmp;
			list.push_back(tmp);

		}
	}
}