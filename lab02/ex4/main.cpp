/*
»звестны уравнени€ двух пр€мых y=a1x+b1 и y=a2x+b2.
ќпределить, €вл€ютс€ ли эти пр€мые параллельными или перпендикул€рными,
если нет, то найти угол между ними.
*/

#include <iostream>
#include <cmath>
using std::cin;
using std::cout;

int main()
{
	cout << "You have two equations:\n";
	cout << "y = a1x + b1\n";
	cout << "y = a2x + b2\n";
	double a1;
	cout << "Input the a1 value: ";
	cin >> a1;
	double b1;
	cout << "Input the b1 value: ";
	cin >> b1;
	double a2;
	cout << "Input the a2 value: ";
	cin >> a2;
	double b2;
	cout << "Input the b2 value: ";
	cin >> b2;

	cout << "Your eauations look like:\n";
	cout << "y = " << a1 << "x + " << b1 << "\n";
	cout << "y = " << a2 << "x + " << b2 << "\n";
	double arctg1 = atan(a1);
	double arctg2 = atan(a2);
	double angle = abs(arctg1 - arctg2);
	const double PI = acos(-1.0);

	if (a1 == a2) {
		cout << "Straight lines are parallel.";
	}
	else if (abs(arctg1 - arctg2) == asin(1.0)) {
		cout << "Straight lines are perpendicular.";
	}
	else {
		cout << "The angle between two lines equals to: " << (angle * 180 / PI) ;
	}
	return 0;
}