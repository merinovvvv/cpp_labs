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
	int plus_x = +x;
	int plus_y = +y;
	int minus_x = -x;
	int minus_y = -y;
	int sum = x + y;
	int sub = x - y;
	int mult = x * y;
	int div = x / y;
	int div_percent = x % y;
	int compl1 = (~x);
	int compl2 = (~y);
	int and_ = (x & y);
	int or_ = (x | y);
	int xor_ = (x ^ y);
	int left = (x << y);
	int right = (x >> y);
	cout << plus_x << "\n";
	cout << plus_y << "\n";
	cout << minus_x << "\n";
	cout << minus_y << "\n";
	cout << sum << "\n";
	cout << sub << "\n";
	cout << mult << "\n";
	cout << div << "\n";
	cout << div_percent << "\n";
	cout << compl1 << "\n";
	cout << compl2 << "\n";
	cout << and_ << "\n";
	cout << or_ << "\n";
	cout << xor_ << "\n";
	cout << left << "\n";
	cout << right << "\n";
}