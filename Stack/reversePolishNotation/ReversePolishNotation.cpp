#include "ReversePolishNotation.h"

void ReversePolishNotation::setString (std::string_view str) {
	str_ = str;
}

ReversePolishNotation::ReversePolishNotation (std::string_view str) : str_(str) {}