#include <iostream>
#include <vector>
#include <chrono>
#include "sorting_algorithms.h"
#include "iodata.h"
#include "data_generation.h"


using namespace std::chrono;

int main()
{
	/*std::cout << "Input the upper ceil: ";
	int up;
	std::cin >> up;
	std::vector <int> list = generateDataRandom(10, up);*/
	/*std::vector <int> list = generateDataDescending(42);*/
	std::vector <int> list = generateDataAscending(10);
	std::cout << "\n";
	auto start = system_clock::now();
	insertionSort(list);
	auto end = system_clock::now();
	auto elapsed_seconds = duration_cast<seconds>(end - start).count();
	auto elapsed_milliseconds = duration_cast<milliseconds>(end - start).count();
	std::time_t end_time = system_clock::to_time_t(end);
#pragma warning(suppress : 4996)
	std::cout << "Calculations are finished on " << std::ctime(&end_time) << "Algorithm execution time: "
		<< elapsed_seconds << "s\n" << "Algorithm execution time: " << elapsed_milliseconds << "ms\n";
	sortCount(list);
}
/*writeData(list, "data/SelectionSort.txt");
insertionSort(list);
writeData(list, "data/InsertionSort.txt");
bubbleSort(list);
writeData(list, "data/bubbleSort.txt");
oddEvenSort(list);
writeData(list, "data/oddEvenSort.txt");
cocktailSort(list);
writeData(list, "data/cocktailSort.txt");
combSort(list);
writeData(list, "data/combSort.txt");
selectionSort(list);
writeData(list, "data/selectionSort.txt");
doubleSelectionSort(list);
writeData(list, "data/doubleSelectionSort.txt");
quickSort(list);
writeData(list, "data/quickSort.txt");
mergeSort(list);
writeData(list, "data/mergeSort.txt");
}  */