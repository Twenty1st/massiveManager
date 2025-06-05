#include <iostream>
#include <stack>
#include "../colorPrint.h"
#include "../../getUserInput/getInput.h"

int getFindCount(int submenu_type, int size, bool& is_back) {
	int count = 1;
	if(submenu_type == 2) {
		std::cout << "Введите количество элементов для поиска: ";
		if(!getCountForOperation(&count, size)) {
			is_back = true;
			return -1;
		}
	}
	return count;
}

int* getFindElements(int count, bool& is_back) {
	std::cout << "Введите элементы для поиска: " << std::endl;
	int* elements = (int*)malloc(count * sizeof(int));
	if (elements == nullptr) {
		std::cout << "Ошибка выделения памяти!" << std::endl;
		is_back = true;
		return nullptr;
	}
	elements = getElementsFromUser(elements, count);
	if(elements == nullptr) {
		free(elements);
		is_back = true;
		return nullptr;
	}
	return elements;
}

std::stack<int> findFirstEntry(int* mass, int size, const int values[], int sizeValues) {
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

std::stack<int> findLastEntry(int* mass, int size, const int values[], int sizeValues) {
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

std::stack<int> findAllEntry(int* mass, int size, const int values[], int sizeValues) {
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

void print_find_result(int* mass, int size, std::stack<int>& result) {
	if (result.empty()) {
		std::cout << "Элементы не найдены." << std::endl;
		return;
	}

	int count = result.size();
	int* found_indices = (int*)malloc(count * sizeof(int));
	if (found_indices != nullptr) {
		int index = 0;
		while (!result.empty()) {
			found_indices[index++] = result.top() - 1; // -1 потому что в стеке индексы с 1
			result.pop();
		}

		std::cout << "\nНайдено " << count << " совпадений." << std::endl;
		std::cout << "Номера найденных совпадений: ";
		for (int i = 0; i < count; i++) {
			std::cout << found_indices[i] + 1;
			if (i < count - 1) {
				std::cout << ", ";
			}
		}
		std::cout << std::endl;
		std::cout << "Результат: ";
		print_array_with_highlight(mass, size, found_indices, count, COLOR_BLUE);

		free(found_indices);
	}
}