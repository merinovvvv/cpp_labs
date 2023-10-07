/**
* Rearrange the array elements in reverse order without additional arrays.
* 
*			test cases:
* 
*	size	items			result
*	5		1 2 3 4 5		5 4 3 2 1
*	7		3 8 0 6 8 9 0	0 9 8 6 0 8 3
*	2		1 2				2 1
*	1		9				9
*	0						Vector is empty.
*/


#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::reverse;

int sizeInput(string input);

int main()
{
	int size = sizeInput("Input the size of vector:\n");
	if (size == 0){
		cout << "Vector is empty.";
	}	else {
		vector <int> firstVector(size);
		for (int i = 0; i < firstVector.size(); ++i) {
			cout << "Input the item of the vector: ";
			cin >> firstVector[i];
		}
		reverse(firstVector.begin(), firstVector.end()); //rearrange the array elements in reverse order
		for (int i = 0; i < firstVector.size(); ++i) {
			cout << firstVector[i] << " "; //output the elements of the presented array
		}
	}
	
}

int sizeInput(string input)
{
	int sizeOfVector;
	cout << input;
	cin >> sizeOfVector;
	return sizeOfVector;
}