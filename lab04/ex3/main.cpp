/**
* Дан массив из n целых чисел.
* Проверить, является ли он перестановкой, то есть содержит различные числа от 1 до n.
* 
*			test cases:
*
*	size	items					result
*	5		1 2 3 4 5				The vector is the permutation.
*	7		3 8 0 6 8 9 0			The vector is not the permutation.
*	2		2 1						The vector is the permutation.
*	10		5 7 9 10 6 8 3 4 1 2	The vector is the permutation.
*	0								Vector is empty.
*	5		1 2 3 5 6				The vector is not the permutation.
*/


#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::sort;

int sizeInput(string input);


int main()
{
	int size = sizeInput("Input the size of vector:\n");
	if (size == 0){
		cout << "Vector is empty.";
	}
	else {
		vector <int> firstVector(size);
		for (int i = 0; i < firstVector.size(); ++i) { //вводим элементы вектора
			cout << "Input the item of the vector: ";
			cin >> firstVector[i];
		}
		sort(firstVector.begin(), firstVector.end()); //отсортировали вектор по возрастанию
		vector <int> secondVector(size);
		for (int j = 0; j < secondVector.size(); ++j) { //создали второй вектор с элементами от 1 до n
			secondVector[j] = j + 1;
		}
		for (int k = 0; k < secondVector.size(); ++k) { //по индексам проверяем первоначальный вектор с вектором от 1 до n
			if (firstVector[k] != secondVector[k]) {
				cout << "\nThe vector is not the permutation.";
				return 0;
			}
		}
		cout << "\nThe vector is the permutation.";
		return 0;
	}
}

int sizeInput(string input)
{
	int sizeOfVector;
	cout << input;
	cin >> sizeOfVector;
	return sizeOfVector;
}