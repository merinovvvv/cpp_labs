/**
* An array of n + m elements is given.
* Without using auxiliary arrays, swap the beginning of length n and the end of length m.
* 
*		test cases
* 
*	n		m		n elements		m elements		res
*	1		2		1				2	3			2	3	1
*	5		4		1 2 7 2 4		5 6 3 2			5 6 3 2 1 2 7 2 4
*	0		4										At least one of the vectors is empty.
*/



#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
using std::string;

int sizeN(string label);

int main()
{
	int vectorSizeN = sizeN("Input the n size: ");
	int vectorSizeM = sizeN("Input the m size: ");
	if (vectorSizeM == 0 || vectorSizeN == 0) {
		cout << "At least one of the vectors is empty.";
	}
	else {
		vector <int> firstVector(vectorSizeN + vectorSizeM);
		for (int i = 0; i < vectorSizeN; ++i) {
			cout << "Input the n item of vector: ";
			cin >> firstVector[i];
		}
		for (int j = vectorSizeN; j < (vectorSizeN + vectorSizeM); ++j)
		{
			cout << "Input the m item of vector: ";
			cin >> firstVector[j];
		}
		for (int c = 0; c < vectorSizeN; ++c) { //delete first elements before n (including n) and add them in the end of the vector
			firstVector.push_back(firstVector[0]);
			firstVector.erase(firstVector.begin());
		}
		cout << "A changed vector looks like:\n";
		for (int e = 0; e < firstVector.size(); ++e) {
			cout << firstVector[e] << " ";
		}
	}
}

int sizeN(string label)
{
	int n;
	cout << "Input the n: ";
	cin >> n;
	return n;
}