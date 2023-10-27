#pragma once
#ifndef IODATA_H_
#define IODATA_H_

#include <vector>
#include <string>
#include <map>

void readData(std::vector <std::string>& list, const std::string& filePath);
void outToConsole(const std::vector <std::string>& vec, const std::string& delimeter);
void writeData(const std::map<std::string, size_t>& set, const std::string& filePath);

#endif //IODATA_H_