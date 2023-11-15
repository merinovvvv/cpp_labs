#include <string>
#include <map>
#include "Country.h"
#include <ostream>

//countryName (countryCode): population[YYYY], population[YYYY], …

std::string Country::toString() const{
	std::string str = name + " (" + code + ") " + ": ";
	for (const auto& [year, population] : yearPopulation) {
		str += std::to_string(population) + "[" + std::to_string(year) + "], ";
	}
	return str;
}

std::ostream& operator << (std::ostream& os, const Country& country)
{
	os << country.name << " (" << country.code << ") " << ": ";
	for (const auto& [year, population] : country.yearPopulation) {
		os << population << "[" << year << "], ";
	}
	return os;
}