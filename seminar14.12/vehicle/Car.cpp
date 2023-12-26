#include "Car.h"

Car::Car(int maxSpeed, double engineCapacity, EngineType engineType, int seatsNumber) : Vehicle(maxSpeed, engineCapacity, engineType), seatsNumber_(seatsNumber) {
	spdlog::debug("car costr with parametres: {0:d}, {1:f}, {2:s}, {3:d}", maxSpeed, engineCapacity, engineTypeToString(engineType), seatsNumber);
};

void Car::engineOn() const {
	spdlog::info("Car's engine is on");
}

void Car::engineOff() const {
	spdlog::info("Car's engine is off");
}

std::string Car::toString() const {
	spdlog::info("Car's toString func");
	return Vehicle::toString() + " Seats number: " + std::to_string(seatsNumber_);
}

Car::~Car() {
	spdlog::debug("Car's destr");
}