#include "Number.h"
#include "Item.h"

Number::Number(int value) : value_(value) {}

Number* Number::calcValue() const {
	return new Number(value_);
}

Number Number::operator+(const Number& other) const {
	return Number(value_ + other.value_);
}