#include <string>
#include <vector>
#include "Vehicle.h"

void Vehicle::setMaxSpeed(int maxSpeed) {
	maxSpeed_ = maxSpeed;
}
void Vehicle::setEngineCapacity(int engineCapacity) {
	engineCapacity_ = engineCapacity;
}
void Vehicle::setEngineType(EngineType engineType) {
	engineType_ = engineType;
}
std::string Vehicle::toString() const// виртуальная функция
{
	return "Max speed: " + std::to_string(maxSpeed_) + "km/h, Engine capacity: " + std::to_string(engineCapacity_) + "l, Engine type: " + engineTypeToString(engineType_);
}

std::string engineTypeToString(EngineType type) {
	std::vector <std::string> names{
	"PETROL",
	"DIESEL",
	"GAS",
	"ELECTRIC"
	};
	return names[type];
}

Vehicle::~Vehicle() {
	spdlog::debug("Vehicle's destr");
}