#pragma once
#ifndef WORLD_COUNTRY_
#define  WORLD_COUNTRY_
#include <string>
#include <map>
#include "CountryFeature.h"
class WorldCountry
{
public:
	std::string ñountryName;
	CountryFeature countryFeature;
	std::map<int, long long int> yearPopulation;

	void readCountryPopulationFromFile(std::string file);

};

#endif //WORLD_COUNTRY_

