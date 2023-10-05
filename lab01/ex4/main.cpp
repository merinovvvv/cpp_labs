#include <iostream>
using std::cin;
using std::cout;


int main()
{
	double x, y, res;
	cout << "Input the value of x: ";
	cin >> x;
	cout << "Input the value of y: ";
	cin >> y;
	res = (((3 + (x * x) - (y * y * y)) * ((x + 3) * (x + 3))) / (x - y * y));
	cout << "The result is " << res;
}