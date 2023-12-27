#include "Truck.h"

Truck::Truck(int maxSpeed, double engineCapacity, EngineType engineType, double liftingCapacity) : Vehicle(maxSpeed, engineCapacity, engineType), liftingCapacity_(liftingCapacity) {
	spdlog::debug("Truck costr with parametres: {0:d}, {1:f}, {2:s}, {3:d}", maxSpeed, engineCapacity, engineTypeToString(engineType), liftingCapacity);
};

void Truck::engineOn() const {
	spdlog::info("Truck's engine is on");
}

void Truck::engineOff() const {
	spdlog::info("Truck's engine is off");
}

std::string Truck::toString() const {
	spdlog::info("Truck's toString func");
	return Vehicle::toString() + " lifting capacity: " + std::to_string(liftingCapacity_);
}

Truck::~Truck() {
	spdlog::debug("Truck's destr");
}