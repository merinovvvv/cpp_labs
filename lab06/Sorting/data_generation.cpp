#include <string>
#include <vector>
#include "iodata.h"
#include "data_generation.h"
#include <random>

std::vector <int> generateDataAscending(size_t amount)
{
	std::vector <int> list(amount);
	for (size_t i = 0; i < amount; ++i) {
		list[i] = i;
	}
	return list;
}

std::vector <int> generateDataDescending(size_t amount)
{
	std::vector <int> list(amount);
	int value = 0;
	for (auto iterator = list.rbegin(); iterator != list.rend(); ++iterator, ++value) {
		*iterator = value;
	}
	return list;
}

std::vector <int> generateDataRandom(size_t amount, size_t n)
{
	std::vector <int> list(amount);
	srand(time(NULL));
	for (auto& item : list) {
		item = 1 + rand() % n + 1;
		list.push_back(item);
	}
	return list;
}