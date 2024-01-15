#include "ElectricCar.h"

ElectricCar::ElectricCar(int maxSpeed, double engineCapacity, EngineType engineType, int seatsNumber, int powerReserve) : Car(maxSpeed, engineCapacity, engineType, seatsNumber), ElectricVehicle(maxSpeed, engineCapacity, engineType, powerReserve) {
	spdlog::debug("ElectricCar costr with parametres: {0:d}, {1:f}, {2:s}, {3:d}, {4:d}", maxSpeed, engineCapacity, engineTypeToString(engineType), seatsNumber, powerReserve);
}
ElectricCar::~ElectricCar() {
	spdlog::debug("ElectricCar's destr");
}
void ElectricCar::engineOn() const{
	spdlog::info("Electric car's engine is on");	
}
void ElectricCar::engineOff() const{
	spdlog::info("Electric car's engine is off");
}
std::string ElectricCar::toString() const{
	spdlog::debug("Electic car's toString func");
	return Car::toString() + " Power reserve: " + std::to_string(powerReserve_);
}