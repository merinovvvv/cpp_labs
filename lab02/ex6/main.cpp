/*
Написать программу, которая определяет дату предыдущего дня.
*/

#include <iostream>
#include <vector>
using std::cin;
using std::cout;

int main()
{
	int year;
	int day;
	int month;
	cout << "Input the number of day: ";
	cin >> day;
	cout << "Input the number of month: ";
	cin >> month;
	cout << "Input the number of the year: ";
	cin >> year;
	int previousDay = day - 1;
	int previousMonth = month;
	if (month == 1 && day == 1)
	{
		year = year - 1;
	}
	if ((month > 12 || month < 1) || (day > 31 || day < 1)) {
		cout << "Invalid input.\n";
		previousDay = 0;
		previousMonth = 0;
	}
	else if (day == 1)	
	{
		switch (month) {
		case 1:
			previousDay = 31;
			previousMonth = 12;
			break;
		case 3:
			previousDay = 28;
			previousMonth = month - 1;
			break;
		case 2:
		case 4:
		case 6:
		case 8:
		case 9:
		case 11:
			previousDay = 31;
			previousMonth = month - 1;
		case 5:
		case 7:
		case 10:
		case 12:
			previousDay = 30;
			previousMonth = month - 1;
		}

	}
	cout << "Previous date: " << previousDay << "." << previousMonth << "." << year;
	return 0;
}