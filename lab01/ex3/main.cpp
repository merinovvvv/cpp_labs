#include <iostream>
using std::cin;
using std::cout;

int main()
{
	int x, y;
	cout << "Input the value of x: ";
	cin >> x;
	cout << "Input the value of y: ";
	cin >> y;
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;
	cout << x << "\n" << y;
}