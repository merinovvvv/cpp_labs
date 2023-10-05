/*
Заданы две окружности: с центром в точке О(x0, y0) и
радиусом R0 и с центром в точке О(x1, y1) и радиусом R1.
Определите, в скольких точках пересекаются окружности,
и определите координаты точек пересечения.
*/

#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::string;

int main()
{
	double x0;
	double y0;
	double r0;
	double x1;
	double y1;
	double r1;

	cout << "First circle is smallet than the second one.\n";

	cout << "Input the x0 value: ";
	cin >> x0;
	cout << "Input the y0 value: ";
	cin >> y0;
	cout << "Input the r0 value: ";
	cin >> r0;
	cout << "Input the x1 value: ";
	cin >> x1;
	cout << "Input the y1 value: ";
	cin >> y1;
	cout << "Input the r1 value: ";
	cin >> r1;

	double distance = sqrt(((x1 - x0) * (x1 - x0)) + ((y1 - y0) * (y1 - y0)));
	double a = (r1 * r1 - r0 * r0 + distance * distance) / (2 * distance);
	double h = sqrt(r1 * r1 - a * a);
	double x3 = x1 + (a / distance) * (x0 - x1);
	double y3 = y1 + (a / distance) * (y0 - y1);
	double x4_1 = x3 + (h / distance * (y0 - y1));
	double y4_1 = y3 - (h / distance * (x0 - x1));
	double x4_2 = x3 - (h / distance * (y0 - y1));
	double y4_2 = y3 + (h / distance * (x0 - x1));

	if ((x0 == x1) && (y0 == y1) && r0 == r1) {
		cout << "The circles are match.";
	}
	else if ((distance > r0 + r1) &&
		(distance < abs(r1 - r0))) {
		cout << "The circles do not have the intersection points.";
	}
	else if ((distance == r0 + r1) ||
		(distance == abs(r1 - r0))) {
		cout << "The circles have one intersection point.\n";
		cout << "It's coordinates are:\n";
		cout << "x: " << x3 << "\n";
		cout << "y: " << y3;
	}
	else {
		cout << "The circles have two intersection points.\n";
		cout << "It's coordinates are:\n";
		cout << "x1: " << x4_1 << "\n";
		cout << "y1: " << y4_1 << "\n";
		cout << "x2: " << x4_2 << "\n";
		cout << "y2: " << y4_2<< "\n";
	}
}