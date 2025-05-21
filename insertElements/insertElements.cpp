#include <iostream>
#include "insertElements.h"

void resize_array(int** arr, int* currentSize, int newSize) {
    if (newSize <= *currentSize) {
        std::cout << "Новый размер должен быть больше текущего!" << std::endl;
        return;
    }

    // Перераспределяем память для нового размера массива
    int* new_arr = (int*)realloc(*arr, newSize * sizeof(int));
    if (new_arr == nullptr) {
        std::cout << "Ошибка!Память не выделена!" << std::endl;
        return;
    }

    // Обновляем указатель и размер
    *arr = new_arr;
    *currentSize = newSize;
}


void insertInStart(int** p, int* size, const int newElems[], int sizeNewElems){
	resize_array(p, size, *size + sizeNewElems);

	// Сдвигаем существующие элементы вправо
	for (int i = *size - 1; i >= 0; --i) {
			(*p)[i + sizeNewElems] = (*p)[i];
	}

	// Вставляем новые элементы в начало массива
	for (int i = 0; i < sizeNewElems; ++i) {
			(*p)[i] = newElems[i];
	}
}

void insertInEnd(int** p, int* size, const int newElems[], int sizeNewElems){
    resize_array(p, size, *size + sizeNewElems);
    
    // Вставляем новые элементы в конец массива
    for (int i = *size; i < sizeNewElems; ++i) {
        (*p)[i] = newElems[i];
    }
}

void insertInPosition(int** p, int* size, const int newElems[], int sizeNewElems, int position){
    
    // Проверка корректности позиции
    if (position < 0) {
        std::cout << "Некорректная позиция для вставки." << std::endl;
        return;
    }
    if(position < *size){
        resize_array(p, size, *size + sizeNewElems);
    }else{
        resize_array(p, size, position + sizeNewElems+1);
    }
    
    if(position < *size-sizeNewElems-1){
        for (int i = position; i < *size; ++i) {
			(*p)[i + sizeNewElems] = (*p)[i];
	    }
    }

	for (int i = position; i < position+sizeNewElems; ++i) {
			(*p)[i] = newElems[i-position];
	}
}
