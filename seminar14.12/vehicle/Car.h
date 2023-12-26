#pragma once
#ifndef CAR_H_
#define CAR_H_

#include "Vehicle.h"

class Car : virtual public Vehicle
{
public:
	Car(int maxSpeed = 0, double engineCapacity = 0, EngineType engineType = PETROL, int seatsNumber = 0);
	~Car();
	virtual void engineOn() const override;
	virtual void engineOff() const override;
	virtual std::string toString() const override;
protected:
	int seatsNumber_;
};

#endif // CAR_H_

