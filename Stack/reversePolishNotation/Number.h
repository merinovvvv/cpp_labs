#pragma once
#include "Item.h"

class Number : public Item
{
public:
	Number() = delete;
	Number(int value);
	//Number (const Number& other) = default;
	virtual Number* calcValue() const override;
	Number operator+(const Number& other) const;
private:
	int value_;
};

