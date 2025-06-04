#include <iostream>
#include <stack>
#include "../colorPrint.h"

void print_search_result(int* mass, int size, int* found_indices, int count) {
	std::cout << "\nНайдено " << count << " совпадений." << std::endl;
	std::cout << "Номера найденных совпадений: ";
	for(int i = 0; i < count; i++) {
		std::cout << found_indices[i] + 1;
		if(i < count - 1) {
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
	std::cout << "Результат: ";
	print_array_with_highlight(mass, size, found_indices, count, COLOR_BLUE);
}

std::stack<int> searchFirstEntry(int* mass, int size, const int values[], int sizeValues) {
	std::stack<int> stack;
	if (size == 0) {
		std::cout << "Массив пуст!" << std::endl;
		return stack;
	}

	for (int i = 0; i < sizeValues; i++) {
		for (int j = 0; j < size; j++) {
			if (mass[j] == values[i]) {
				stack.push(j+1);
				break;
			}
		}
	}
	return stack;
}

std::stack<int> searchLastEntry(int* mass, int size, const int values[], int sizeValues) {
	std::stack<int> stack;
	if (size == 0) {
		std::cout << "Массив пуст!" << std::endl;
		return stack;
	}

	for (int i = 0; i < sizeValues; i++) {
		for (int j = size-1; j >= 0; --j) {
			if (mass[j] == values[i]) {
				stack.push(j+1);
				break;
			}
		}
	}
	return stack;
}

std::stack<int> searchAllEntry(int* mass, int size, const int values[], int sizeValues) {
	std::stack<int> stack;
	if (size == 0) {
		std::cout << "Массив пуст!" << std::endl;
		return stack;
	}

	for (int i = 0; i < sizeValues; i++) {
		for (int j = 0; j < size; j++) {
			if (mass[j] == values[i]) {
				stack.push(j+1);
			}
		}
	}
	return stack;
}