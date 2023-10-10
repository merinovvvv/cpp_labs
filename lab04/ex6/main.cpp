/**
* Two matrices of size n x k and k x m are given. Find their multiplication.
*	test case:
*	
*	n		k		m
* 
*	2		3		2
*	
* nk matrix:	km matrix:
* 
*	1 2 3		1 2
*	4 5 6		3 4
*				5 6		
*	
* final matrix:
* 
* 22 28
* 49 64
*
*/

#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
using std::string;

int size(string label);
vector < vector <int> > matrix(const int& a, const int& b);
void matrixMult(vector <vector <int> >& matrix1, vector <vector <int> >& matrix2, const int& n, const int& m, const int& k);

int main()
{
	int n = size("Input the n:\n");
	int k = size("Input the k:\n");
	int m = size("Input the m:\n");
	cout << "Input the n x k matrix:\n";
	vector < vector <int> > matrix1 = matrix(n, k);
	cout << "Input the k x m matrix:\n";
	vector < vector <int> > matrix2 = matrix(k, m);
	matrixMult(matrix1, matrix2, n, m, k);
}

int size(string label)
{
	int size;
	cout << label;
	cin >> size;
	return size;
}

vector < vector <int> > matrix(const int& a, const int& b)
{
	vector < vector <int> > matrixVector(a, vector <int>(b));
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) { //inputting the values in matrix
			cin >> matrixVector[i][j];
		}
	}
	return matrixVector;
}

void matrixMult(vector <vector <int> >& matrix1, vector <vector <int> >& matrix2, const int& n, const int& m, const int& k)
{
	vector < vector <int> > result(n, vector <int>(m));
	for (int row = 0; row < n; ++row) {
		for (int column = 0; column < m; ++column) {
			for (int inner = 0; inner < k; inner++) {
				result[row][column] += matrix1[row][inner] * matrix2[inner][column]; //multiplicating tha matrices

			}
		}
	}
	for (int row = 0; row < n; ++row) {
		for (int column = 0; column < m; ++column) {
			cout << result[row][column] << " ";
		}
		cout << "\n";
	}
}