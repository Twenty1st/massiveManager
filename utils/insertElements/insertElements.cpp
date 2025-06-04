#include <iostream>
#include "../arrayUtils.h"
#include "insertElements.h"
#include "../colorPrint.h"

void insertInStart(int** mas, int* size, const int newElems[], int sizeNewElems){
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
    if (position < 1) {
        std::cout << "Некорректная позиция для вставки." << std::endl;
        return;
    }
    
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
    std::cout << "Debug: Начало print_insert_result" << std::endl;
    if (count <= 0 || count > size) {
        std::cout << "Ошибка: некорректное количество элементов для подсветки" << std::endl;
        return;
    }

    std::cout << "Debug: Выделяем память для highlight_indices" << std::endl;
    int* highlight_indices = new int[count];
    
    // Определяем индексы для подсветки в зависимости от типа вставки
    std::cout << "Debug: Перед switch" << std::endl;
    switch(insert_type) {
        case 1: // в начало
            std::cout << "Debug: Вставка в начало" << std::endl;
            for(int i = 0; i < count; i++) {
                highlight_indices[i] = i;
            }
            std::cout << "Элементы успешно вставлены в начало." << std::endl;
            break;
            
        case 2: // в конец
            std::cout << "Debug: Вставка в конец" << std::endl;
            for(int i = 0; i < count; i++) {
                highlight_indices[i] = size - count + i;
            }
            std::cout << "Элементы успешно вставлены в конец." << std::endl;
            break;
            
        case 3: // по позиции
            std::cout << "Debug: Вставка по позиции" << std::endl;
            for(int i = 0; i < count; i++) {
                highlight_indices[i] = position - 1 + i;
            }
            std::cout << "Элементы успешно вставлены на позицию " << position << "." << std::endl;
            break;
    }
    
    std::cout << "Debug: Перед print_array_with_highlight" << std::endl;
    std::cout << "Результат: ";
    print_array_with_highlight(arr, size, highlight_indices, count, COLOR_GREEN);
    std::cout << "Debug: После print_array_with_highlight" << std::endl;
    
    std::cout << "Debug: Перед удалением highlight_indices" << std::endl;
    delete[] highlight_indices;
    std::cout << "Debug: После удаления highlight_indices" << std::endl;
    std::cout << "Debug: Конец print_insert_result" << std::endl;
}
