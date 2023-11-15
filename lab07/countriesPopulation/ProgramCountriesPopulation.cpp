#include <iostream>
#include <iostream>
#include "ProgramCountriesPopulation.h"
#include "Country.h"
#include "WorldPopulation.h"

int ProgramCountriesPopulation::main() {
	try {
		WorldPopulation wp;
		wp.readCountryPopulationFromFile("data/world_population_1960-2018.csv");
		wp.writeDataAmount("data/output.txt");				
		wp.calcWorldPopulation();
		wp.writeWorldPopulationToFile("data/worldPopulation.csv", ';');
		return 0;
	}
	catch (std::invalid_argument &ex) {
		std::cerr << ex.what();
	}
}