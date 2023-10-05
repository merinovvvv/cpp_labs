//Задание 4. Количество точек решетки

#include <iostream>
using std::cout;
using std::cin;

int main() {
    int n;
    int NumberOfPairs = 0;

    cout << "Input n: ";
    cin >> n;

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            if (x * x + y * y < n * n) {
                NumberOfPairs++;
            }
        }
    }

    cout << "Number of non-negative integer pairs x and y: " << NumberOfPairs << "\n";
}