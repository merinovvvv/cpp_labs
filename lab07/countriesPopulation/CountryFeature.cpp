#include <string>
#include <map>
#include <fstream>
#include "Country.h"
#include "CountryFeature.h"

//countryName (countryCode): population[YYYY], population[YYYY], …
void CountryFeature::countryCollection(std::string filePath)
{
	std::vector <std::string> collection;
	std::string str;
	std::ifstream fin(filePath, std::ios::in);
	if (!fin) {
		throw std::invalid_argument("File doesn't exist");
	}
	int count = 0;
	while (!fin.eof()) {
		/*std::cout << count++ << "\n";*/
		getline(fin, str);
		if (str != "") {
			collection.push_back(str);
		}
	}
	fin.close();
}

//std::ostream& operator << (std::ostream& os, const CountryFeature& country)
//{
//	os << country.regin << " (" << country.code << ") " << ": ";
//	for (const auto& [year, population] : country.yearPopulation) {
//		os << population << "[" << year << "], ";
//	}
//	return os;
//}