#pragma once

#include "Item.h"
#include "Number.h"

class BinaryOperations : public Number
{
public:
	virtual Number* calcValue() const override = 0;
};

