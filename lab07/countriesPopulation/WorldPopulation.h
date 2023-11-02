#pragma once
#ifndef WORLD_POPULATION_H_
#define WORLD_POPULATION_H_
#include <vector>
#include <map>
#include "Country.h"

struct WorldPopulation
{
	std::vector<Country> countries;
	std::map<int, long long int> year_population;
	void readCountryPopulationFromFile(std::string file);
	void writeDataAmount(std::string filePath);
};

#endif //WORLD_POPULATION_H_

