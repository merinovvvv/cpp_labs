#pragma once
#ifndef IODATA_H_
#define IODATA_H_
#include <vector>
#include <string>
#include <set>

void readData(std::vector <std::string>& list, std::string filePath);
void writeDataAmount(const std::set <std::string>& set, std::string filePath);


#endif // IODATA_H_
