#include "Sortings.h"

void doubleSelectionSort (std::vector <int>& vector) {
    for (size_t i = 0; i < vector.size() - 1; ++i) {
        int min = i;
        int max = vector.size() - i;
        for (int j = i + 1; j < vector.size(); ++j) {
            if (vector[j] < vector[min]) {
                min = j;
            }
            else if (vector[j] > vector[max]) {
                max = j;
            }
        }
        std::swap (vector[i], vector[min]);
        std::swap (vector[vector.size() - i], vector[max]);
    }
}