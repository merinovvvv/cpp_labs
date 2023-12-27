#pragma once
#ifndef TRUCK_H_
#define TRUCK_H_

#include "Vehicle.h"

class Truck : virtual public Vehicle
{
public:
	Truck(int maxSpeed = 0, double engineCapacity = 0, EngineType engineType = PETROL, double liftingCapacity = 0);
	~Truck();
	virtual void engineOn() const override;
	virtual void engineOff() const override;
	virtual std::string toString() const override;
private:
	double liftingCapacity_;
};

#endif //TRUCK_H_

