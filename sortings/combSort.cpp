#include "Sortings.h"

void combSort (std::vector <int>& vector) {
    constexpr double factor = 1.247; //фактор уменьшения
    double step = vector.size() - 1;
    while (step >= 1) {
        for (int i = 0; i + step < vector.size(); ++i) {
            if (vector[i] > vector[i+step]){
                std::swap (vector[i], vector[i+step]);
            }
        }
        step /= factor;
    }
    BubbleSort(vector);
}