#include <iostream>
using std::cin;
using std::cout;


int main()
{
	double a;
	cout << "Input the value of a: ";
	cin >> a;
	double a2 = a * a;
	double a3 = a2 * a;
	double a4 = a2 * a2;
	double a5 = a4 * a;
	double a6 = a3 * a3;
	double a7 = a6 * a;
	double a8 = a4 * a4;
	double a9 = a8 * a;
	double a10 = a4 * a4 * a2;
	double a13 = a9 * a4;
	double a15 = a5 * a5 * a5;
	double a16 = a8 * a8;
	double a21 = a6 * a6 * a6 * a3;
	double a28 = a8 * a8 * a8 * a4;
	double a32 = a16 * a16;
	double a64 = a32 * a32;
	cout << "a^4 = " << a4 << "\n";
	cout << "a^6 = " << a6 << "\n";
	cout << "a^7 = " << a7 << "\n";
	cout << "a^8 = " << a8 << "\n";
	cout << "a^9 = " << a9 << "\n";
	cout << "a^10 = " << a10 << "\n";
	cout << "a^13 = " << a13 << "\n";
	cout << "a^15 = " << a15 << "\n";
	cout << "a^21 = " << a21 << "\n";
	cout << "a^28 = " << a28 << "\n";
	cout << "a^64 = " << a64;
}