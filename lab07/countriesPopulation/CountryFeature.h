#pragma once
#ifndef COUNTRY_FEATURE_H_
#define COUNTRY_FEATURE_H_
#include <string>
#include <vector>

class CountryFeature
{
public:
	std::string countryCode;
	std::string region;
	std::string incomeGroup;

	void countryCollection(std::string filePath);
};
#endif //COUNTRY_FEATURE_H_