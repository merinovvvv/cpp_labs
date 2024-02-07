#include "Sortings.h"

void BubbleSort (std::vector <int>& vector) {
    for (size_t i = 0; i < vector.size(); ++i) {
        for (size_t j = 0; j < vector.size() - 1 - i; ++j) {
            if (vector[j] > vector[j + 1]) {
                std::swap (vector[j], vector[j + 1]);
            }
        }
    }
}