/**
* Given an integer k and k sets of non-zero integers.
* The sign of completion of each set is the number 0 (it is not included in the set).
* For each set output the number of its elements.
* Also output the total number of elements in all sets.
*
*	test cases:
*	
*	k	elements	result (the anount of elements in each row)		result (the amount of all the elements)
*	3	1 2 3 0		3 3 2											8
*		2 4 5 0
*		2 4 0
* 
* 
*	5	1 1 0		2 2 2 2 2										10
*		2 2 0
*		3 3 0
*		4 4 0
*		5 5 0
* 
* 
* 
*	0																0
*/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::string;

void vecFunc(const int& k);
int kValue(string label);

int main()
{
	int k = kValue("Input the k value: ");
	if (k == 0) {
		cout << "0 elements in matrix.";
		return 0;
	}
	vecFunc(k);
}

int kValue(string label)
{
	int k;
	cout << label;
	cin >> k;
	return k;
}

void vecFunc(const int& k)
{
	vector<vector<int>> vec(k, vector<int>());
	cout << "enter the elements of the matrix:\n";
	for (size_t i = 0; i != k; ++i) {
		for (size_t j = 0; ; ++j)
		{
			int elementsInColumn;
			cin >> elementsInColumn;
			if (elementsInColumn != 0) {
				vec[i].push_back(elementsInColumn);//if an element is not zero push it back
			}
			else {
				vec[i].push_back(elementsInColumn);//if an element is zero push it back and move to the next row
				break;

			}
		}
	}
	int answer = 0;
	cout << "result:\n";
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i].size() - 1 << " ";
		answer += vec[i].size() - 1;
	}
	cout << '\n' << "There are " << answer << " elements in the matrix.";
}