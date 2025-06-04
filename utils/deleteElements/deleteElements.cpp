#include <iostream>
#include "../arrayUtils.h"
#include "../sort_shuffle_Massive/sort_shuffle_Massive.h"

void deleteAtStart(int** p, int* size, int countDelElems){
	if (countDelElems >= *size) {
        resize_array(p, size, 0);
        return;
  }

	// Сдвигаем существующие элементы вправо
	for (int i = 0; i < *size; ++i) {
			(*p)[i] = (*p)[i+countDelElems];
	}

	resize_array(p, size, *size - countDelElems);
}

void deleteAtEnd(int** p, int* size, int countDelElems){
	if (countDelElems >= *size) {
        resize_array(p, size, 0);
        return;
  }

  resize_array(p, size, *size - countDelElems);
}

void deleteAtPosition(int** p, int* size, int* positions, int countDelElems) {
    std::cout << "Debug: size = " << *size << ", countDelElems = " << countDelElems << std::endl;
    std::cout << "Debug: positions = ";
    for(int i = 0; i < countDelElems; i++) {
        std::cout << positions[i] << " ";
    }
    std::cout << std::endl;

    // Проверяем корректность позиций
    for (int i = 0; i < countDelElems; ++i) {
        if (positions[i] < 1 || positions[i] > *size) {
            std::cout << "Некорректная позиция для удаления: " << positions[i] << std::endl;
            return;
        }
    }

    // Сортируем позиции
    sortMassive(positions, countDelElems);
    std::cout << "Debug: sorted positions = ";
    for(int i = 0; i < countDelElems; i++) {
        std::cout << positions[i] << " ";
    }
    std::cout << std::endl;

    int* newArray = new int[*size - countDelElems];
    int delPosition = 0, newArrayIndex = 0;

    // Копируем элементы, пропуская удаляемые
    for (int i = 0; i < *size; ++i) {
        if(positions[delPosition] >= i){
            if (delPosition < countDelElems && i+1 == positions[delPosition]) {
                delPosition++;
                continue;
            }
        }
        newArray[newArrayIndex++] = (*p)[i];
    }

    delete[] *p;
    *p = newArray;
    *size = newArrayIndex;
}
