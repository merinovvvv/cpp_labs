#include "Sortings.h"

void insertionSort (std::vector <int>& vector) {
    for (int i = 1; i < vector.size(); ++i) {
        int key = vector[i];
        int j = i - 1;
        for (j; j >= 0 && vector[j] > key; --j) {
            std::swap(vector[j], vector[j + 1]);
        }
    }
}