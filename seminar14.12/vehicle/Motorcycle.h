#pragma once
#ifndef MOTORCYCLE_H_
#define MOTORCYCLE_H_

#include "Car.h"

class Motorcycle : virtual public Car
{
public:
	Motorcycle(int maxSpeed = 0, double engineCapacity = 0, EngineType engineType = PETROL, int seatsNumber = 0);
	~Motorcycle();
	virtual void engineOn() const override;
	virtual void engineOff() const override;
	virtual std::string toString() const override;
};

#endif //MOTORCYCLE_H_

