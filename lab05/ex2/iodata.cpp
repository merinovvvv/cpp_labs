#include "iodata.h"
#include <fstream>
#include <set>

void readData(std::vector <std::string>& list, std::string filePath)
{
	std::string str;
	std::ifstream fin(filePath, std::ios::in);
	while(!fin.eof()) {
		fin >> str;
		list.push_back(str);
	}
	fin.close();
}	

void writeDataAmount(const std::set <std::string>& set, std::string filePath)
{
	std::ofstream fout(filePath, std::ios::out);
	fout << set.size();
	fout.close();
}