#include <iostream>
#include "fillTheVector.h"

void fillTheVector (std::vector <int>& vector) {
    size_t size;
    std::cout << "Input the vector size: \n";
    std::cin >> size;
    std::cout << "Input the vector's items: \n";
    for (size_t i = 0; i < size; ++i) {
        int value;
        std::cin >> value;
        vector.push_back(value);
    }
}