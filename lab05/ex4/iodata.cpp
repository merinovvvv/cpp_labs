#include <fstream>
#include <iostream>
#include "iodata.h"



void readData(std::vector<std::pair<std::string, std::string>>& list, std::string filePath)
{
	std::ifstream fin(filePath, std::ios::in);
	std::string str1;
	std::string str2;
	while (!fin.eof()) {
		fin >> str1 >> str2;
		list.push_back(std::make_pair(str1, str2));
	}
	fin.close();
}

void writeData(const std::vector<std::pair<std::string, int>>& list, std::string filePath)
{
	std::ofstream fout(filePath, std::ios::out);
	for (size_t i = 0; i != list.size(); ++i) {
		fout << list[i].first << " " << list[i].second << "\n";
	}
	fout.close();
}