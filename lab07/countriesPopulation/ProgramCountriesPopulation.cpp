#include <iostream>
#include <iostream>
#include "ProgramCountriesPopulation.h"
#include "Country.h"
#include "WorldPopulation.h"
#include "CountryFeature.h"

int ProgramCountriesPopulation::main() {
	try {
		WorldPopulation wp;
		wp.readCountryPopulationFromFile("data/world_population_1960-2018.csv");
		wp.writeDataAmount("data/output.txt");				
		wp.calcWorldPopulation();
		wp.writeWorldPopulationToFile("data/worldPopulation.csv", ';');
		return 0;
		CountryFeature cf;
		cf.countryCollection("data/countries.csv");
	}
	catch (std::invalid_argument &ex) {
		std::cerr << ex.what();
	}
}