#include <array>
#include <vector>

#ifndef SORTING_ALGORITHMS_H_
#define SORTING_ALGORITHMS_H_

template<typename T>
void insertionSort(std::vector<T>& a) {
	for (size_t i = 1; i < a.size(); i++) {
		for (size_t j = i; j > 0 && a[j - 1] > a[j]; j--) {// пока j>0 и элемент j-1 > j
			std::swap(a[j - 1], a[j]);
		}
	}// меняем местами элементы j и j-1
}



template<typename T>
void shellSort(std::vector<T>& a) {
	for (size_t gap = a.size() / 2; gap > 0; gap /= 2) {
		for (size_t i = gap; i < a.size(); i++) {
			int temp = a[i];
			int j = i;
			for (size_t j = i; j >= gap && a[j - gap] > temp; j -= gap) {
				a[j] = a[j - gap];
			}
			a[j] = temp;
		}
	}
}



template<typename T>
void bubbleSort(std::vector<T>& a) { //void bubbleSort(T& a) {
	for (size_t i = 0; i < a.size(); ++i) {
		for (int j = a.size() - 1; j > i; --j) {
			if (a[j - 1] > a[j]) {
				std::swap(a[j - 1], a[j]);
			}
		}
	}
}



template<typename T>
void oddEvenSort(std::vector<T>& a) {
	bool isSorted = false; // Флаг, указывающий, отсортирован ли массив
	while (!isSorted) {
		isSorted = true;
		// Чётный проход
		for (int i = 0; i < a.size() - 1; i += 2) {
			if (a[i] > a[i + 1]) {
				std::swap(a[i], a[i + 1]);
				isSorted = false;
			}
		}
		// Нечётный проход
		for (int i = 1; i < a.size() - 1; i += 2) {
			if (a[i] > a[i + 1]) {
				std::swap(a[i], a[i + 1]);
				isSorted = false;
			}
		}
	}
}



template <typename T>
void cocktailSort(std::vector<T>& a) {
	int left = 0;
	int right = a.size() - 1;
	bool swapped = true;

	while (swapped) {
		swapped = false;

		// Проход снизу вверх
		for (int i = left; i < right; ++i) {
			if (a[i] > a[i + 1]) {
				std::swap(a[i], a[i + 1]);
				swapped = true;
			}
		}

		if (!swapped) {
			break;  // Если не было обменов, массив уже отсортирован
		}

		--right;  // Уменьшаем правую границу, так как самый большой элемент уже находится на своем месте

		// Проход сверху вниз
		for (int i = right; i > left; --i) {
			if (a[i] < a[i - 1]) {
				std::swap(a[i], a[i - 1]);
				swapped = true;
			}
		}

		++left;  // Увеличиваем левую границу, так как самый маленький элемент уже находится на своем месте
	}
}



template <typename T>
void combSort(std::vector<T>& arr) {
	int n = arr.size();
	int gap = n;
	bool swapped = true;

	while (gap > 1 || swapped) {
		// Уменьшаем шаг
		gap = (gap * 10) / 13;
		if (gap < 1) {
			gap = 1;
		}

		swapped = false;

		// Проход с текущим шагом
		for (int i = 0; i < n - gap; i++) {
			if (arr[i] > arr[i + gap]) {
				std::swap(arr[i], arr[i + gap]);
				swapped = true;
			}
		}
	}
}



template<typename T>
void selectionSort(std::vector<T>& a) { //void bubbleSort(T& a) {
	T max;
	size_t iMax;
	for (size_t i = a.size() - 1; i > 0; --i) {
		max = a[0];
		iMax = 0;
		for (size_t j = 0; j <= i; ++j) {
			if (max < a[j]) {
				max = a[j];
				iMax = j;
			}
		}
		std::swap(a[iMax], a[i]);
	}
}



template <typename T>
void doubleSelectionSort(std::vector<T>& a) {
	int left = 0;
	int right = a.size() - 1;

	while (left < right) {
		int minIndex = left;
		int maxIndex = left;

		for (int i = left; i <= right; i++) {
			if (a[i] < a[minIndex]) {
				minIndex = i;
			}
			else if (a[i] > a[maxIndex]) {
				maxIndex = i;
			}
		}

		std::swap(a[left], a[minIndex]);

		// Проверяем, нужно ли обновить индекс максимального элемента
		if (maxIndex == left) {
			maxIndex = minIndex;
		}

		std::swap(a[right], a[maxIndex]);

		left++;
		right--;
	}
}



template <typename T>
int partition(std::vector<T>& a, int low, int high) {
	T pivot = a[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (a[j] < pivot) {
			i++;
			std::swap(a[i], a[j]);
		}
	}

	std::swap(a[i + 1], a[high]);
	return (i + 1);
}
template <typename T>
void quickSort(std::vector<T>& a, int low, int high) {
	if (low < high) {
		int pivotIndex = partition(a, low, high);

		quickSort(a, low, pivotIndex - 1);
		quickSort(a, pivotIndex + 1, high);
	}
}
template <typename T>
void quickSort(std::vector<T>& a) {
	int low = 0;
	int high = a.size() - 1;
	quickSort(a, low, high);
}



template <typename T>
void merge(std::vector<T>& a, int left, int middle, int right) {
	int n1 = middle - left + 1;
	int n2 = right - middle;

	std::vector<T> L(n1);
	std::vector<T> R(n2);

	for (int i = 0; i < n1; i++) {
		L[i] = a[left + i];
	}

	for (int i = 0; i < n2; i++) {
		R[i] = a[middle + 1 + i];
	}

	int i = 0;
	int j = 0;
	int k = left;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		a[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		a[k] = R[j];
		j++;
		k++;
	}
}
template <typename T>
void mergeSort(std::vector<T>& a, int left, int right) {
	if (left < right) {
		int middle = left + (right - left) / 2;
		mergeSort(a, left, middle);
		mergeSort(a, middle + 1, right);
		merge(a, left, middle, right);
	}
}
template <typename T>
void mergeSort(std::vector<T>& a) {
	int n = a.size();
	mergeSort(a, 0, n - 1);
}

#endif // SORTING_ALGORITHMS_H_