#include <iostream>
#include <stack>
#include <map>


void replaceByIndices(int* mass, int size, const int indices[], const int newValues[], int count) {
    // Проверяем корректность всех индексов
    for(int i = 0; i < count; i++) {
        if (indices[i] < 0 || indices[i] >= size) {
            std::cout << "Индекс " << indices[i] << " выходит за границы массива" << std::endl;
            return;
        }
    }

    // Выполняем замену
    for(int i = 0; i < count; i++) {
        mass[indices[i]] = newValues[i];
    }
}

void replaceFirstEntry(int* mass, int size, std::map<int, int> replaceValues){
	for (const auto& pair : replaceValues) {
		int oldValue = pair.first;
		int newValue = pair.second;
		for (int j = 0; j < size; j++) {
			if (mass[j] == oldValue) {
				mass[j] = newValue;
				break;
			}
		}
	}
}

void replaceLastEntry(int* mass, int size, std::map<int, int> replaceValues){
	for (const auto& pair : replaceValues) {
		int oldValue = pair.first;
		int newValue = pair.second;
		for (int j = size-1; j >= 0; --j) {
			if (mass[j] == oldValue) {
				mass[j] = newValue;
				break;
			}
		}
	}
}

void replaceAllEntry(int* mass, int size, std::map<int, int> replaceValues){
	for (const auto& pair : replaceValues) {
		int oldValue = pair.first;
		int newValue = pair.second;
		for (int j = 0; j < size; j++) {
			if (mass[j] == oldValue) {
				mass[j] = newValue;
			}
		}
	}
}