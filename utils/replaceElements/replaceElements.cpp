#include <iostream>
#include <stack>
#include <map>


void replaceByIndices(int* mass, int size, const int indices[], const int newValues[], int count) {
		int replaceIndex = 0;
    for(int i = 0; i < count; i++) {
				if (indices[replaceIndex] >= 0 && indices[replaceIndex] < size && replaceIndex == i) {
            mass[indices[replaceIndex]] = newValues[replaceIndex];
						++replaceIndex;
        } else {
            std::cout << "Индекс " << indices[replaceIndex] << " выходит за границы массива" << std::endl;
        }
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