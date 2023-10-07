/**
* Дано число n. Найти наименьшую цифру,
* которая отсутствует в его десятичной записи.
* Подумайте, над возможностью использования контейнеров std::map, std::set.
*
*		test cases:
* 
*  number		result
*	123			0
*	120			3
*	012			0
*	123456780	9
*	234567		0
*	1023		4
*/
#include <iostream>
#include <set>
using std::cin;
using std::cout;
using std::string;
using std::set;

int sizeInput(string input);

int main()
{
	int number = sizeInput("Input the number: ");
	set <int> numSet;
	while (number != 0) {
		int figure = number % 10;
		number /= 10;
		numSet.insert(figure); //запись цифр в set
	}
	for (int i = 0; i <= 9; ++i) { //проверка наличия цифры в числе (set)
		if (numSet.count(i) == 0) {
			cout << i << " is missing";
			return 0;
		}
	}
	return 0;
}

int sizeInput(string input)
{
	int number;
	cout << input;
	cin >> number;
	return number;
}