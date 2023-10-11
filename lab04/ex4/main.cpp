/**
*	Two increasing arrays are given. Find the number of common elements in them.
*
*			test cases:
*
*	size of 1	size of 2	items 1			items2					result
*	5			5			1 2 3 4 5		1 2 3 5 6				4 common elements
*	0			5													0 common elements
*	6			8			3 4 8 10 12 5	5 8 9 10 12 14 16 17	One of the vectors is not increasing
*	3			3			1 1 1			1 2 3					1 common element
*/


#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::sort;

int sizeInput1(string input);
int commonElemets(vector <int>& vec1, vector <int>& vec2);


int main()
{
	int size1 = sizeInput1("Input the size of 1st vector:\n");
	int size2 = sizeInput1("Input the size of 2nd vector:\n");
	if (size1 == 0 || size2 == 0) {
		cout << "0 common elements";
	}
	else {
		vector <int> firstVector(size1);
		vector <int> secondVector(size2);
		for (int i = 0; i < firstVector.size(); ++i) {
			cout << "Input the item of the 1st vector: ";
			cin >> firstVector[i];
		}
		for (int j = 0; j < secondVector.size(); ++j) {
			cout << "Input the item of the 2nd vector: ";
			cin >> secondVector[j];
		}
		int counter = commonElemets(firstVector, secondVector);
		cout << "\n" << counter << " common element(s)";
	}
}

int sizeInput1(string input)
{
	int size1;
	cout << input;
	cin >> size1;
	return size1;
}

int commonElemets(vector <int>& vec1, vector <int>& vec2) {
	int counter = 0;
	vector <int> vec1Sorted = vec1;
	vector <int> vec2Sorted = vec2;
	sort(vec1Sorted.begin(), vec1Sorted.end());
	sort(vec2Sorted.begin(), vec2Sorted.end());
	//compare our vectors with the same sorted in ascending order (check for ascending)
	if (vec1 == vec1Sorted && vec2 == vec2Sorted) {
		for (int k = 0; k < vec1.size(); ++k) {
			for (int h = 0; h < vec2.size(); ++h) {
				if (vec1[k] == vec2[h]) {
					counter++; //add one to the counter if there are identical elements	
					vec2.erase(vec2.begin() + h);
				}
			}
		}
	}
	else {
		cout << "One of the vectors is not increasing";//cout if at least one of the vectors is not increasing
		exit(0); 
	}

	return counter;
}