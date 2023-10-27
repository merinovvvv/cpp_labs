#include "iodata.h"
#include "stringLib.h"
#include <iostream>

int main()
{
	std::vector<std::string> vec;
	std::string fileName = "data/outputVec.txt";
	try {
		readData(vec, "data/input.txt");
		outToConsole(vec, " ");
		deletePunctuationSign(vec);
		std::cout << "\n";
		outToConsole(vec, " ");
		std::map <std:: string, size_t> result = wordAmount(vec);
		writeData(result, "data/output.txt");
	}
	catch (std::invalid_argument& ex) {
		std::cerr << ex.what();
	}
}