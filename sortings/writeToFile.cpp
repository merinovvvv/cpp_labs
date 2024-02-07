#include <fstream>
#include <vector>
#include <iostream>
#include "writeToFile.h"

void writeToFile (std::string& filePath, std::vector <int>& vec) {
    std::ofstream out (filePath, std::ios::app);
    for (size_t i = 0; i < vec.size(); ++i) {
        out << vec[i] << ' ';
    }
    std::cout << '\n';
}