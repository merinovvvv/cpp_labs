#include <iostream>
using std::cin;
using std::cout;


int main()
{
	double m;
	cout << "Input the value of m: ";
	cin >> m;
	double h = m / 3600;
	double h2 = int(h);
	double min = (h - h2) * 60;
	double min2 = int(min);
	double sec = (min - min2) * 60;
	cout << "Your number of seconds (m) equals to " << h2 << " hour(s) " << min2
		<< " minute(s) " << sec << " second(s).";
}