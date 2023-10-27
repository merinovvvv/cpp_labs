#include <iostream>
#include <string>
#include <vector>
#include "iodata.h"
#include "subsequence.h"

int main()
{
	std::vector<std::pair<std::string, std::string>> vecPair;
	readData(vecPair, "data/input.txt");
	std::vector<std::pair<std::string, int>> result = yesOrNo(vecPair);
	writeData(result, "data/output.txt");
}