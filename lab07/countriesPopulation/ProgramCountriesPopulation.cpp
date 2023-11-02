#include <iostream>
#include "ProgramCountriesPopulation.h"
#include "Country.h"
#include "WorldPopulation.h"

int ProgramCountriesPopulation::main() {
	Country country{
		"Belarus", "BY", {{2022, 9'200'617}, {2021, 9'349'645}}
	};
	std::cout << country.toString();
	WorldPopulation wp;
	wp.readCountryPopulationFromFile("data/world_population_1960-2018.csv");
	wp.readCountryPopulationFromFile("data/output.txt");
	return 0;
}