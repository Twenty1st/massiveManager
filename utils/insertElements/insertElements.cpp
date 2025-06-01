#include <iostream>
#include "../arrayUtils.h"
#include "insertElements.h"

void insertInStart(int** mas, int* size, const int newElems[], int sizeNewElems){
	resize_array(mas, size, *size + sizeNewElems);

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
    
    // Вставляем новые элементы в конец массива
    for (int i = *size; i < sizeNewElems; ++i) {
        (*mas)[i] = newElems[i];
    }
}

void insertInPosition(int** mas, int* size, const int newElems[], int sizeNewElems, int position){
    
    // Проверка корректности позиции
    if (position < 0) {
        std::cout << "Некорректная позиция для вставки." << std::endl;
        return;
    }
    if(position < *size){
        resize_array(mas, size, *size + sizeNewElems);
    }else{
        resize_array(mas, size, position + sizeNewElems+1);
    }
    
    if(position < *size-sizeNewElems-1){
        for (int i = position; i < *size; ++i) {
			(*mas)[i + sizeNewElems] = (*mas)[i];
	    }
    }

	for (int i = position; i < position+sizeNewElems; ++i) {
			(*mas)[i] = newElems[i-position];
	}
}
