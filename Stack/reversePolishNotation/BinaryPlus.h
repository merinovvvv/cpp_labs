#pragma once

#include "BinaryOperations.h"
#include "StackOnList.h"

class BinaryPlus : public BinaryOperations
{
	Number* calcValue(StackOnList<Number*>& stack) const override;
};

