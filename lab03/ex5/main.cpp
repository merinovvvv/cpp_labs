//Задание 5. Ох уж эти поляки
//треугольник Серпинского


#include <iostream>
#include <bitset>

using std::cin;
using std::cout;
using std::string;

int main()
{
	unsigned long long a = 1;
	string binary = std::bitset<64>(a).to_string();

		for (int j = 0; j <= binary.size(); j++)
		{
			if (binary[j] == '0')
			{
				binary[j] = ' ';
			}
		}
		cout << binary << "\t" << a << "\n";
	
	for (int i = 0; i < 999; ++i) {
		a = (2 * a) ^ a;
		binary = std::bitset<64>(a).to_string();
		for (int j = 0; j <= binary.size(); j++)
		{
			if (binary[j] == '0')	
			{
				binary[j] = ' ';
			}
		}
		cout << binary << "\t" << a << "\n";
	}
}
