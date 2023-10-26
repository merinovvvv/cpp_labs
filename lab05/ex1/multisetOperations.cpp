#include "multisetOperations.h"

std::multiset<std::string> unification(std::multiset<std::string> container1, std::multiset<std::string> container2)
{
	std::multiset<std::string> uniResult;
	uniResult.insert(container1.begin(), container1.end());
	uniResult.insert(container2.begin(), container2.end());
	return uniResult;
}

std::multiset<std::string> intersection(std::multiset<std::string> container1, std::multiset<std::string> container2)
{
	std::multiset<std::string> interResult;
	std::set_intersection(container1.begin(), container1.end(),
		container2.begin(), container2.end(),
		std::inserter(interResult, interResult.begin()));
	return interResult;
}

std::multiset<std::string> multisetsDifference(std::multiset<std::string> container1, std::multiset<std::string> container2)
{
	std::multiset<std::string> difResult;
	std::set_difference(container1.begin(), container1.end(), container2.begin(), container2.end(),
		std::inserter(difResult, difResult.begin()));
	return difResult;
}