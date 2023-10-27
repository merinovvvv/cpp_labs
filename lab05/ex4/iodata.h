#pragma once
#ifndef IODATA_H_
#define IODATA_H_
#include <vector>
#include <string>

void readData(std::vector<std::pair<std::string, std::string>>& list, std::string filePath);
std::vector<std::pair<std::string, int>> yesOrNo(std::vector<std::pair<std::string, std::string>>& list);
void writeData(const std::vector<std::pair<std::string, int>>& list, std::string filePath);
#endif // IODATA_H_
