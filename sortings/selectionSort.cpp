#include "Sortings.h"

void selectionSort (std::vector <int>& vector) {
    for (size_t i = 0; i < vector.size() - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < vector.size(); ++j) {
            if (vector[j] < vector[min]) {
                min = j;
            }
        }
    std::swap (vector[i], vector[min]);
    }
}