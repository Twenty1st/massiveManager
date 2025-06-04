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
    // Проверяем корректность позиций
    for (int i = 0; i < countDelElems; ++i) {
        if (positions[i] < 1 || positions[i] > *size) {
            std::cout << "Некорректная позиция для удаления: " << positions[i] << std::endl;
            return;
        }
    }

    // Сортируем позиции
    sortMassive(positions, countDelElems);

    // Создаем новый массив
    int* newArray = (int*)malloc((*size - countDelElems) * sizeof(int));
    if (newArray == nullptr) {
        std::cout << "Ошибка выделения памяти!" << std::endl;
        return;
    }

    int newIndex = 0;
    int posIndex = 0;

    // Копируем элементы, пропуская удаляемые
    for (int i = 0; i < *size; ++i) {
        if (posIndex < countDelElems && i + 1 == positions[posIndex]) {
            posIndex++;
            continue;
        }
        newArray[newIndex++] = (*p)[i];
    }

    free(*p);
    *p = newArray;
    *size = newIndex;
}
