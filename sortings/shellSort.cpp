#include "Sortings.h"

void shellSort (std::vector <int>& vector) {
    int step = vector.size() / 2;
    while (step >= 1) {
        for (int i = step; i < vector.size(); ++i) {
            int key = vector[i];
            int j = i - step;
            for (j; j >= 0 && vector[j] > key; --j) {
                std::swap(vector[j], vector[j + step]);
            }
            ++i;
        }
        step /= 2;
    }
}