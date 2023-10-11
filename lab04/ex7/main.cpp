/**
* The Farey sequence.
Print in ascending order all simple irreducible fractions
enclosed between 0 and 1, whose denominators are less than a given number n.
* 
*   test cases:
*   
*   n   result
* 
*   5   0/1 1/4 1/3 1/2 2/3 3/4 1/1
*   7   0/1 1/6 1/5 1/4 1/3 2/5 1/2 3/5 2/3 3/4 4/5 5/6 1/1
*   2   0/1 1/1
*   4   0/1 1/3 1/2 2/3 1/1 
*   0   undefined
*   1   undefined
*/
#include <iostream>
using std::cin;
using std::cout;

void printFareySequence(int);

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    if (n == 0 || n == 1) {
        cout << "undefined";
        return 0;
    }

    printFareySequence(n - 1);

    return 0;
}

void printFareySequence(int n) {
    int a = 0, b = 1, c = 1, d = n;
    int tmp_a, tmp_b;

    cout << "Farey Sequence:\n";

    cout << a << '/' << b << '\n';
    while (c <= n) {
        int k = (n + b) / d;

        tmp_a = a;
        tmp_b = b;

        a = c;
        b = d;
        c = k * c - tmp_a;
        d = k * d - tmp_b;
        cout << a << '/' << b << '\n';
    }
}