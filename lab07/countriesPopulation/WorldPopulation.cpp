#include "WorldPopulation.h"
#include <sstream>
#include <fstream>
#include <string>

void WorldPopulation::readCountryPopulationFromFile(std::string file) {
	std::vector <std::string> list;
	std::string str;
	std::ifstream fin(file, std::ios::in);
	while (!fin.eof()) {
		fin >> str;
		list.push_back(str);
	}
	fin.close();

	//string parcing
	//first string contains the names of columns of data
	std::stringstream ss(list.at(0));
	getline(ss, str, ';');
	if (str != "Country Name") {
		throw std::invalid_argument("File contains wrong data");
	}
	getline(ss, str, ';');
	if (str != "Country Code") {
		throw std::invalid_argument("File contains wrong data");
	}
	int year;
	char ch;
	std::vector <int> years;
	while (!ss.eof()) {
		//read a year and ";" sign
		ss >> year >> ch;
		years.push_back(year);
	}
	//get data about each country
	int population;
	for (size_t i = 1; i < list.size(); ++i) {
		std::stringstream ssCountry(list.at(i));
		Country country;
		getline(ssCountry, country.name, ';');
		getline(ssCountry, country.code, ';');
		int count = 0;
		while (!ssCountry.eof()) {
			ssCountry >> population >> ch;
			/*std::pair yearPopulation = {years[count], population};
			country.yearPopulation.insert(yearPopulation);*/ //1st way
			country.yearPopulation[years[count]] = population; //2nd way
			++count;
		}
		countries.push_back(country);
	}
}

void WorldPopulation::writeDataAmount(std::string filePath)
{
	std::ofstream fout(filePath, std::ios::out);
	for (const auto& item : countries) {
		fout << item.toString();
	}
	fout.close();
}