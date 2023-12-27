#include <iostream>
#include "spdlog/spdlog.h"
#include "Vehicle.h"
#include "Car.h"
#include "ElectricCar.h"
#include "Motorcycle.h"
#include "Truck.h"

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

	ElectricCar car4(100, 5, ELECTRIC, 5);
	std::cout << car4.toString() << "\n";
	car4.engineOn();
	car4.engineOff();

	Motorcycle moto1(100, 5, ELECTRIC, 5);
	std::cout << moto1.toString() << "\n";
	moto1.engineOn();
	moto1.engineOff();

	Truck truck1(100, 5, ELECTRIC, 5);
	std::cout << truck1.toString() << "\n";
	truck1.engineOn();
	truck1.engineOff();
	

	spdlog::info("Application finished");
	return 0;
}