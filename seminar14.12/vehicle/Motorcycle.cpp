#include "Motorcycle.h"

Motorcycle::Motorcycle(int maxSpeed, double engineCapacity, EngineType engineType, int seatsNumber) : Car(maxSpeed, engineCapacity, engineType, seatsNumber) {
	spdlog::debug("Motorcycle costr with parametres: {0:d}, {1:f}, {2:s}, {3:d}", maxSpeed, engineCapacity, engineTypeToString(engineType), seatsNumber);
};

void Motorcycle::engineOn() const {
	spdlog::info("Motorcycle's engine is on");
}

void Motorcycle::engineOff() const {
	spdlog::info("Motorcycle's engine is off");
}

std::string Motorcycle::toString() const {
	spdlog::info("Motorcycle's toString func");
	return Car::toString();
}

Motorcycle::~Motorcycle() {
	spdlog::debug("Motorcycle's destr");
}