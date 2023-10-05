//Задание 3. Валидация кредитной карты

#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

int main()
{
    unsigned long long creditCardNumber;
    cout << "Input the credit card number: ";
    cin >> creditCardNumber;
    unsigned long long numbersAmount = creditCardNumber;
    int n = 0;
    int sumOfNumbers = 0;
    int sumOfVecI = 0;
    int sum1 = 0;
    int sumOfVecJ = 0;
    int finalSum = 0;
    vector<long long> vec = {};
    while (numbersAmount != 0)
    {
        numbersAmount = numbersAmount / 10;
        n++;
    }
    if (n == 16) {
        while (vec.size() <= 16)
        {
            vec.push_back(creditCardNumber % 10);
            creditCardNumber /= 10;
        }
        for (int i = 1; i <= n - 1; i += 2)
        {
            if (vec[i] * 2 >= 10)
            {
                sumOfNumbers = sumOfNumbers + ((vec[i] * 2) / 10 + (vec[i] * 2) % 10);
            }
            else {
                sumOfVecI = sumOfVecI + (vec[i] * 2);
            }
            sum1 = sumOfVecI + sumOfNumbers;
        }
        for (int j = 0; j <= n - 1; j += 2)
        {
            sumOfVecJ = sumOfVecJ + vec[j];
        }
        finalSum = sumOfVecJ + sum1;
        if (finalSum % 10 == 0)
        {
            cout << "Credit card is valid.";
        }
        else {
            cout << "The card number is invalid.";
        }
    }
    else {
        cout << "The card number is invalid.";
    }
}