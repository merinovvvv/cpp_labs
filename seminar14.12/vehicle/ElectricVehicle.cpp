#include "ElectricVehicle.h"
#include "spdlog/spdlog.h"

ElectricVehicle::ElectricVehicle(int maxSpeed, double engineCapacity, EngineType engineType, int powerReserve) : Vehicle(maxSpeed, engineCapacity, engineType), powerReserve_(powerReserve) {
	spdlog::debug("ElectricVehicle costr");
};


std::string ElectricVehicle::toString() const {
	spdlog::trace("ElectricVehicle's toString func");
	return Vehicle::toString() + " Power reserve: " + std::to_string(powerReserve_);
}

ElectricVehicle::~ElectricVehicle() {
	spdlog::debug("ElectricVehicle's destr");
}

void ElectricVehicle::engineOn() const {
	spdlog::info("ElectricVehicle's engine is on");
}

void ElectricVehicle::engineOff() const {
	spdlog::info("ElectricVehicle's engine is off");
}