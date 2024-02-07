#include "Sortings.h"

void oddEvenSort (std::vector <int>& vector) {
    for (size_t i = 0; i < vector.size(); ++i) {
        for (size_t j = i; j < vector.size() / 2; j = j + 2) {
            if (vector[j] > vector[j + 1]) {
                std::swap(vector[j], vector[j + 1]);
            }
        }
    }
}
