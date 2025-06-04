#include <iostream>
#include "../arrayUtils.h"
#include "../sort_shuffle_Massive/sort_shuffle_Massive.h"
#include "../colorPrint.h"

void print_delete_result(int* mass, int size, int* deleted_indices, int count) {
    std::cout << "\nЭл-т(-ы) успешно удален(-ы)." << std::endl;
    std::cout << "Результат: ";
    print_array_with_highlight(mass, size, deleted_indices, count, COLOR_RED);
}

void deleteAtStart(int** p, int* size, int countDelElems) {
    if (countDelElems >= *size) {
        int* deleted_indices = (int*)malloc(*size * sizeof(int));
        for(int i = 0; i < *size; i++) {
            deleted_indices[i] = i;
        }
        print_delete_result(*p, *size, deleted_indices, *size);
        free(deleted_indices);
        resize_array(p, size, 0);
        return;
    }

    int* deleted_indices = (int*)malloc(countDelElems * sizeof(int));
    for(int i = 0; i < countDelElems; i++) {
        deleted_indices[i] = i;
    }

    // Сдвигаем существующие элементы вправо
    for (int i = 0; i < *size; ++i) {
        (*p)[i] = (*p)[i+countDelElems];
    }

    print_delete_result(*p, *size, deleted_indices, countDelElems);
    resize_array(p, size, *size - countDelElems);
    free(deleted_indices);
}

void deleteAtEnd(int** p, int* size, int countDelElems) {
    if (countDelElems >= *size) {
        int* deleted_indices = (int*)malloc(*size * sizeof(int));
        for(int i = 0; i < *size; i++) {
            deleted_indices[i] = i;
        }
        print_delete_result(*p, *size, deleted_indices, *size);
        free(deleted_indices);
        resize_array(p, size, 0);
        return;
    }

    int* deleted_indices = (int*)malloc(countDelElems * sizeof(int));
    for(int i = 0; i < countDelElems; i++) {
        deleted_indices[i] = *size - countDelElems + i;
    }

    print_delete_result(*p, *size, deleted_indices, countDelElems);
    resize_array(p, size, *size - countDelElems);
    free(deleted_indices);
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

    print_delete_result(*p, *size, positions, countDelElems);
    free(*p);
    *p = newArray;
    *size = newIndex;
}
