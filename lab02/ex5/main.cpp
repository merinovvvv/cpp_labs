/*
В восточном календаре принят 60-летний цикл,
состоящий из 12-летних подциклов, обозначаемых названиями цвета:
зеленый, красный, желтый, белый и черный.
В каждом подцикле годы носят названия животных:
крысы, коровы, тигра, зайца, дракона, змеи, лошади, овцы,
обезьяны, курицы, собаки и свиньи. 
По номеру года определить название года по восточному календарю,
если 2022 — годом черного тигра.
*/


#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::string;
using std::vector;

int main()
{
	vector<string> colors = { "green", "red", "yellow", "white", "black" };
	vector<string> animals = { "rat", "cow", "tiger", "hare", "dragon", "snake",
		"horse", "sheep", "monkey", "hen", "dog", "pig" };
	cout << "The 2022 year is the year of black tiger.\n";
	int year;
	cout << "Input the number of the year: ";
	cin >> year;

	int color = year % 10;

	switch (color) {
	case 0:
	case 1:
		cout << colors[3] << " ";
		break;
	case 2:
	case 3:
		cout << colors[4] << " ";
		break;
	case 4:
	case 5:
		cout << colors[0] << " ";
		break;
	case 6:
	case 7:
		cout << colors[1] << " ";
		break;
	case 8:
	case 9:
		cout << colors[2] << " ";
		break;
	}

	int animal = year % 12;

	switch (animal) {
	case 0:
		cout << animals[8];
		break;
	case 1:
		cout << animals[9];
		break;
	case 2:
		cout << animals[10];
		break;
	case 3:
		cout << animals[11];
		break;
	case 4:
		cout << animals[0];
		break;
	case 5:
		cout << animals[1];
		break;
	case 6:
		cout << animals[2];
		break;
	case 7:
		cout << animals[3];
		break;
	case 8:
		cout << animals[4];
		break;
	case 9:
		cout << animals[5];
		break;
	case 10:
		cout << animals[6];
		break;
	case 11:
		cout << animals[7];
		break;
	}
	return 0;
}