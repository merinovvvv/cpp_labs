#pragma once
#ifndef ELECTRICCAR_H_
#define ELECTRICCAR_H_

#include "ElectricVehicle.h"
#include "Car.h"

class ElectricCar: public ElectricVehicle, public Car
{
public:
	ElectricCar(int maxSpeed = 0, double engineCapacity = 0, EngineType engineType = ELECTRIC, int seatsNumber = 0, int powerReserve = 0);
	~ElectricCar();
	virtual void engineOn() const override;
	virtual void engineOff() const override;
	virtual std::string toString() const override;

};

#endif //ELECTRICCAR_H_

