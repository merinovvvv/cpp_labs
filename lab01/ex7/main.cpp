#include <iostream>
using std::cin;
using std::cout;

int main()
{
	double x;
	cout << "Input the value of x: ";
	cin >> x;
	double x2 = x * x;
	double twox2plus1 = 2 * x2 + 1;
	double a = 2 * x * twox2plus1;
	double b = twox2plus1 + x2;
	double res1 = a + b;
	double res2 = b - a;
	cout << res1 << "\n";
	cout << res2;
}
