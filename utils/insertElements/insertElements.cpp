#include <iostream>
#include "../arrayUtils.h"
#include "insertElements.h"
#include "../colorPrint.h"
#include "../../getUserInput/getInput.h"

void insertInStart(int** mas, int* size, int* newElems, int sizeNewElems){
    resize_array(mas, size, *size + sizeNewElems);
    if (*mas == nullptr) {
        return; // Если resize_array вернул ошибку, выходим
    }

    // Сдвигаем существующие элементы вправо
    for (int i = *size - 1; i >= 0; --i) {
        (*mas)[i + sizeNewElems] = (*mas)[i];
    }

    // Вставляем новые элементы в начало массива
    for (int i = 0; i < sizeNewElems; ++i) {
        (*mas)[i] = newElems[i];
    }
}

void insertInEnd(int** mas, int* size, const int newElems[], int sizeNewElems){
    resize_array(mas, size, *size + sizeNewElems);
    if (*mas == nullptr) {
        return; // Если resize_array вернул ошибку, выходим
    }
    
    // Вставляем новые элементы в конец массива
    for (int i = 0; i < sizeNewElems; ++i) {
        (*mas)[*size - sizeNewElems + i] = newElems[i];
    }
}

void insertInPosition(int** mas, int* size, const int newElems[], int sizeNewElems, int position){
    
    position = position - 1;
    
    // Если позиция больше размера, увеличиваем массив и заполняем промежуток нулями
    if (position > *size) {
        int oldSize = *size;
        resize_array(mas, size, position + sizeNewElems);
        if (*mas == nullptr) {
            return; // Если resize_array вернул ошибку, выходим
        }
        for (int i = oldSize; i < position; ++i) {
            (*mas)[i] = 0;
        }
    } else {
        resize_array(mas, size, *size + sizeNewElems);
        if (*mas == nullptr) {
            return; // Если resize_array вернул ошибку, выходим
        }
    }
    
    for (int i = *size - 1; i >= position; --i) {
        (*mas)[i + sizeNewElems] = (*mas)[i];
    }

    for (int i = 0; i < sizeNewElems; ++i) {
        (*mas)[position + i] = newElems[i];
    }
}

void print_insert_result(const int* arr, int size, int count, int position, int insert_type) {
    if (count <= 0 || count > size) {
        std::cout << "Ошибка: некорректное количество элементов для подсветки" << std::endl;
        return;
    }

    int* highlight_indices = (int*)malloc(count * sizeof(int));
    if (highlight_indices == nullptr) {
        std::cout << "Ошибка выделения памяти!" << std::endl;
        return;
    }
    
    // Определяем индексы для подсветки в зависимости от типа вставки
    switch(insert_type) {
        case 1: // в начало
            for(int i = 0; i < count; i++) {
                std::cout << "yes";
                highlight_indices[i] = i;
            }
            std::cout << "Элементы успешно вставлены в начало." << std::endl;
            break;
            
        case 2: // в конец
            for(int i = 0; i < count; i++) {
                highlight_indices[i] = size - count + i;
            }
            std::cout << "Элементы успешно вставлены в конец." << std::endl;
            break;
            
        case 3: // по позиции
            for(int i = 0; i < count; i++) {
                highlight_indices[i] = position - 1 + i;
            }
            std::cout << "Элементы успешно вставлены на позицию " << position << "." << std::endl;
            break;
    }
    
    std::cout << "Результат: ";
    print_array_with_highlight(arr, size, highlight_indices, count, COLOR_GREEN);
    
    free(highlight_indices);
}

int getPositionToInsert() {
    int position;
    std::cout << "Введите позицию для вставки: ";
    while(true) {
        if(!getNumber(&position)) {
            return -1;  // Пользователь нажал 'r' для возврата
        }
        if(position < 1) {
            std::cout << "Некорректная позиция для вставки. Повторите ввод:" << std::endl;
            continue;
        }
        return position;
    }
}
