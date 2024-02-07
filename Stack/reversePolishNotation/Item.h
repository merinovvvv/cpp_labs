#pragma once

class Item {
public:
	virtual Item* calcValue() const = 0;
};