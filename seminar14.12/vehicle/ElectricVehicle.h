#pragma once

#ifndef ELECTRICVEHICLE_H_
#define ELECTRICVEHICLE_H_
#include "Vehicle.h"


class ElectricVehicle : virtual public Vehicle
{
public:
	ElectricVehicle(int maxSpeed = 0, double engineCapacity = 0, EngineType engineType = ELECTRIC , int powerReserve = 0);
	~ElectricVehicle();
	virtual std::string toString() const override;
	virtual void engineOn() const;
	virtual void engineOff() const;
protected:
	int powerReserve_;
};

#endif //ELECTRICVEHICLE_H_

