#include "sameElements.h"

std::set <std::string> result(std::vector <std::string> list)
{
	std::set <std::string> final;
	for (std::string element : list) {
		final.insert(element);
	}
	return final;
}