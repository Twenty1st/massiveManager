#include <iostream>
#include "../arrayUtils.h"
#include "../sort_shuffle_Massive/sort_shuffle_Massive.h"
#include "../colorPrint.h"

// int* copy_array(const int* source, int size) {
//     int* copy = (int*)malloc(size * sizeof(int));
//     if (!copy) {
//         std::cerr << "Ошибка выделения памяти!" << std::endl;
//         return nullptr;
//     }
//     for (int i = 0; i < size; ++i) {
//         copy[i] = source[i];
//     }
//     return copy;
// }

void print_delete_result(int* mass, int size, int* deleted_indices, int count) {
    std::cout << "\nЭл-т(-ы) успешно удален(-ы)." << std::endl;
    std::cout << "Результат: ";
    print_array_with_highlight(mass, size, deleted_indices, count, COLOR_RED);
}

void deleteAtStart(int** p, int* size, int countDelElems) {
    if (countDelElems <= 0 || countDelElems > *size) {
        std::cout << "Некорректное количество элементов для удаления!" << std::endl;
        return;
    }

    // Массив индексов удаляемых элементов
    int* deleted_indices = (int*)malloc(countDelElems * sizeof(int));
    for (int i = 0; i < countDelElems; ++i) {
        deleted_indices[i] = i;
    }

    // Выводим результат удаления ДО изменения массива
    print_delete_result(*p, *size, deleted_indices, countDelElems);

    // Сдвигаем элементы влево
    for (int i = 0; i < *size - countDelElems; ++i) {
        (*p)[i] = (*p)[i + countDelElems];
    }

    // Обновляем размер массива
    resize_array(p, size, *size - countDelElems);

    free(deleted_indices);
}

void deleteAtEnd(int** p, int* size, int countDelElems) {
    if (countDelElems <= 0 || countDelElems > *size) {
        std::cout << "Некорректное количество элементов для удаления!" << std::endl;
        return;
    }

    // Сохраняем индексы удаляемых элементов
    int* deleted_indices = (int*)malloc(countDelElems * sizeof(int));
    for (int i = 0; i < countDelElems; ++i) {
        deleted_indices[i] = *size - countDelElems + i;
    }

    // Выводим результат удаления ДО изменения массива
    print_delete_result(*p, *size, deleted_indices, countDelElems);

    // Создаём новый массив без удаляемых элементов
    int new_size = *size - countDelElems;
    int* newArray = (int*)malloc(new_size * sizeof(int));
    if (!newArray) {
        std::cerr << "Ошибка выделения памяти!" << std::endl;
        return;
    }

    // Копируем оставшиеся элементы
    for (int i = 0; i < new_size; ++i) {
        newArray[i] = (*p)[i];
    }

    // Обновляем массив
    free(*p);
    *p = newArray;
    *size = new_size;

    free(deleted_indices);
}

void deleteAtPosition(int** p, int* size, int* positions, int countDelElems) {
    // Проверяем корректность позиций (нумерация с 1)
    for (int i = 0; i < countDelElems; ++i) {
        if (positions[i] < 1 || positions[i] > *size) {
            std::cout << "Некорректная позиция для удаления: " << positions[i] << std::endl;
            return;
        }
    }

    // Переводим позиции в индексы (нумерация с 0)
    for (int i = 0; i < countDelElems; ++i) {
        positions[i]--;
    }

    // Сортируем индексы перед обработкой
    sortMassive(positions, countDelElems);

    // Выводим результат удаления ДО изменения массива
    print_delete_result(*p, *size, positions, countDelElems);

    // Создаём новый массив
    int new_size = *size - countDelElems;
    int* newArray = (int*)malloc(new_size * sizeof(int));
    if (!newArray) {
        std::cerr << "Ошибка выделения памяти!" << std::endl;
        return;
    }

    int newIndex = 0;
    int posIndex = 0;

    // Копируем элементы, пропуская удаляемые
    for (int i = 0; i < *size; ++i) {
        if (posIndex < countDelElems && i == positions[posIndex]) {
            posIndex++;
            continue;
        }
        newArray[newIndex++] = (*p)[i];
    }

    // Обновляем массив
    free(*p);
    *p = newArray;
    *size = newIndex;
}
