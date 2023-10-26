#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include "iodata.h"
#include "sameElements.h"

int main()
{
	std::vector <std::string> list;
	readData(list, "data/input.txt");
	std::set <std::string> newSet = result(list);
	writeDataAmount(newSet, "data/output.txt");
}