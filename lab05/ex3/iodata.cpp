#include "iodata.h"
#include <fstream>
#include <iostream>

void readData(std::vector <std::string>& list, const std::string& filePath)
{
	std::string str;
	std::ifstream fin(filePath, std::ios::in);
	if (!fin) {
		throw std::invalid_argument("File doesn't exist.");
	}
	while (!fin.eof()) {
		fin >> str;
		list.push_back(str);
	}
	fin.close();
}

void outToConsole(const std::vector <std::string>& vec, const std::string& delimeter) {
	for (const auto& element : vec) {
		std::cout << element << delimeter;
	}
	std::cout << '\n';
}

void writeData(const std::map<std::string, size_t>& set, const std::string& filePath){
	std::ofstream fout(filePath, std::ios::out);
	for (const auto& tmp : set) {
		fout << tmp.first << " " << tmp.second << "\n";
	}
	fout.close();
}