#include <iostream>
#include "spdlog/spdlog.h"
#include "Vehicle.h"
#include "Car.h"
#include "ElectricCar.h"

int main()
{
	spdlog::set_level(spdlog::level::debug);
	spdlog::info("Application started");

	Car car1(100, 5, PETROL, 5);
	std::cout << car1.toString() << "\n";
	car1.engineOn();
	car1.engineOff();

	ElectricVehicle car2(100, 5, ELECTRIC, 5);
	std::cout << car2.toString() << "\n";
	car2.engineOn();
	car2.engineOff();
	

	spdlog::info("Application finished");
	return 0;
}