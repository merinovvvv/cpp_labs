#pragma once
#ifndef COUNTRY_FEATURE_H_
#define COUNTRY_FEATURE_H_
#include <string>

class CountryFeature
{
private:
	std::string countryCode;
	std::string region;
	std::string incomeGroup;
public:
	std::string getCountryCode();
	void setCountryCode(std::string code);
};
#endif //COUNTRY_FEATURE_H_