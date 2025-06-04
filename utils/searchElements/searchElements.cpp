#include <iostream>
#include <stack>


std::stack<int> searchFirstEntry(int* mass, int size, const int values[], int sizeValues){
	std::stack<int> stack;
	if (size == 0) {
		std::cout << "Массив пуст!" << std::endl;
		return stack;
	}

	for (int i = 0; i < sizeValues; i++){
		for (int j = 0; j < size; j++){
			if (mass[j] == values[i]){
				stack.push(j+1);
				break;
			}
		}
	}

	return stack;
}

std::stack<int> searchLastEntry(int* mass, int size, const int values[], int sizeValues){
	std::stack<int> stack;
	if (size == 0) {
		std::cout << "Массив пуст!" << std::endl;
		return stack;
	}

	for (int i = 0; i < sizeValues; i++){
		for (int j = size-1; j >= 0; --j){
			if (mass[j] == values[i]){
				stack.push(j+1);
				break;
			}
		}
	}

	return stack;
}

std::stack<int> searchAllEntry(int* mass, int size, const int values[], int sizeValues){
	std::stack<int> stack;
	if (size == 0) {
		std::cout << "Массив пуст!" << std::endl;
		return stack;
	}

	for (int i = 0; i < sizeValues; i++){
		for (int j = 0; j < size; j++){
			if (mass[j] == values[i]){
				stack.push(j+1);
			}
		}
	}

	return stack;
}