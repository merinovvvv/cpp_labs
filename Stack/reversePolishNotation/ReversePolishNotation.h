#pragma once
#include <string>
#include <string_view>
#include <queue>

#include "Item.h"

class ReversePolishNotation
{
public:
	ReversePolishNotation() = delete;
	ReversePolishNotation(std::string_view str);
	void setString(std::string_view str);
private:
	std::string str_;
	std::queue<*Item> expressionInPostfixNotation;
};

