#include "Sortings.h"

void cocktailSort (std::vector <int>& vector) {
    int low = 0;
    int up = vector.size() - 1;
    while (low < up) {
        for (size_t i = 0; i < up; ++i) {
            if (vector[i] > vector[i+1]) {
                std::swap (vector[i], vector[i+1]);
            }
        }
        up--;
        for (size_t j = up; j > low; --j) {
            if (vector[j+1] < vector[j]) {
                std::swap (vector[j], vector[j+1]);
            }
        }
        low++;
    }
}