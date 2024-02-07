#include <iostream>
#include "printVector.h"

void printVector (std::vector <int>& vector) {
    for (auto item: vector) {
        std::cout << item << ' ';
    }
    std::cout << '\n';
}