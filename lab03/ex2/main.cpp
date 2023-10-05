//Задание 2. Гипотеза Коллатца

#include <iostream>
using std::cin;
using std::cout;

int main()
{
	int counter = 0;
	unsigned long long n;
	cout << "Input the value of n: ";
	cin >> n;
	if (n > 0)
	{
		cout << n << " ";
		while (n != 1)
		{
			if (n % 2 == 0) {
				n = n / 2;
			}
			else if (n % 2 == 1) {
				n = 3 * n + 1;
			}
			cout << n << " ";
			counter++;
			if (counter > 100000) {
				break;
			}
		}
	}
	else {
		cout << "The number is not natural";
	}
}