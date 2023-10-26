/*
Даны два множества A и B(std::multiset).
Найти объединение(A U B), пересечение(A ∩ B), 
разность этих множеств(A / B, B / A).
*/

#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include "containersLib.h"
#include "multisetOperations.h"

using std::ofstream;
using std::ifstream;
using std::cin;
using std::cout;
using std::multiset;
using std::string;

int main()
{
	multiset<string> container1;
	container1 = readMultiset("data/set1.txt");
	multiset<string> container2;
	container2 = readMultiset("data/set2.txt");
	multiset<string> uniResultFinal;
	uniResultFinal = unification(container1, container2);
	printMultiset("data/outputUnification.txt", uniResultFinal);
	multiset<string> interResultFinal;
	interResultFinal = intersection(container1, container2);
	printMultiset("data/outputIntersection.txt", interResultFinal);
	multiset<string> difResultFinal;
	difResultFinal = multisetsDifference(container1, container2);
	printMultiset("data/outputDifferenceAB.txt", difResultFinal);
	difResultFinal = multisetsDifference(container2, container1);
	printMultiset("data/outputDifferenceBA.txt", difResultFinal);
	return 0;
}