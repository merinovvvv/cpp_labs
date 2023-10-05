//Задание 1. Разминка

#include <iostream>
using std::cin;
using std::cout;

int main()
{
	int n;
	cout << "Input n: ";
	cin >> n;
	/*
	1.1
	while (n != 0){
		cout << n << "\n";
		n--;
	}*/
	//1.2
	for (unsigned int i = (n - 1); i >= 0 && i < n; --i) {
		cout << i << " ";
	}
}