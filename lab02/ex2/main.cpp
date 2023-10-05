/*
Даны координаты двух различных полей шахматной доски x1, y1, x2, y2 (целые числа, 
лежащие в диапазоне 1–8). Проверить истинность высказывания: 
«Ладья за один ход может перейти с одного поля на другое».
*/


#include <iostream>
using std::cin;
using std::cout;
using std::string;

int main()
{
	cout << "Let's check if the statement \"The rook may go from the 1st square to the 2nd\"\
\ is true of false:\n";
	int x1;
	int y1;
	int x2;
	int y2;
	cout << "Input the x1 value: ";
	cin >> x1;
	cout << "Input the y1 value: ";
	cin >> y1;
	cout << "Input the x2 value: ";
	cin >> x2;
	cout << "Input the y2 value: ";
	cin >> y2;
	if (x1 >= 1 && x1 <= 8 && x2 >= 1 && x2 <= 8 && y1 >= 1 && y1 <= 8 && y2 >= 1 && y2 <= 8) {
		if ((x1 == x2) && (y1 != y2) || (y1 == y2) && (x1 != x2)) {
			cout << "The statement is true";
		}
		else if ((x1 == x2) && (y1 == y2)) {
			cout << "The squares are the same.";
		}
		else {
			cout << "The statement is false";
		}
	}
	else {
		cout << "Wrong input.";
	}
}