#pragma once
#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <iostream>
#include "spdlog/spdlog.h"

enum EngineType
{
	PETROL = 0,
	DIESEL = 1,
	GAS = 2,
	ELECTRIC = 3
};

std::string engineTypeToString(EngineType type);

class Vehicle
{
public:
	/*Vehicle() : Vehicle(0, 0, PETROL) {}	
	Vehicle(int maxSpeed) : Vehicle (maxSpeed, 0, PETROL){}
	Vehicle(int maxSpeed, double engineCapacity) : Vehicle(maxSpeed, engineCapacity, PETROL) {}
	Vehicle(int maxSpeed, double engineCapacity, EngineType engineType) : maxSpeed_(maxSpeed), engineCapacity_(engineCapacity) , engineType_(engineType){}*/
	Vehicle(int maxSpeed = 0, double engineCapacity = 0, EngineType engineType = PETROL) : maxSpeed_(maxSpeed), engineCapacity_(engineCapacity), engineType_(engineType) {
		spdlog::debug("vehicle costr");
	}
	~Vehicle();
	Vehicle(const Vehicle& other) = default;
	Vehicle& operator= (const Vehicle& other) = default;
	Vehicle(Vehicle&& other) = default;
	Vehicle& operator= (Vehicle&& other) = default;
	virtual void setMaxSpeed(int maxSpeed);
	virtual void setEngineCapacity(int engineCapacity);
	virtual void setEngineType(EngineType engineType);
	virtual std::string toString() const;
	virtual void engineOn() const = 0 ;
	virtual void engineOff() const = 0;
protected:
	int maxSpeed_;
	double engineCapacity_; //объем двигателя
	EngineType engineType_;

};



#endif //VEHICLE_H_
