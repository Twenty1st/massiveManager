#include "arrayUtils.h"
#include <iostream>

void resize_array(int** arr, int* current_size, int new_size) {
    if (new_size < 0) {
        std::cerr << "Новый размер не может быть отрицательным!" << std::endl;
        return;
    }

    // Перераспределяем память для нового размера массива
    int* new_arr = (int*)realloc(*arr, new_size * sizeof(int));
    if (new_arr == nullptr) {
        std::cout << "Ошибка!Память не выделена!" << std::endl;
        // Освобождаем старую память
        if (*arr != nullptr) {
            free(*arr);
        }
        *arr = nullptr; 
        *current_size = 0;
        return;
    }

    // Обновляем указатель и размер
    *arr = new_arr;
    *current_size = new_size;
} 