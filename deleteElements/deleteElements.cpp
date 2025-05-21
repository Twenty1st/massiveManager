#include <iostream>

void resize_array(int** arr, int* currentSize, int newSize) {
    if (newSize < 0) {
        std::cerr << "Новый размер не может быть отрицательным!" << std::endl;
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

void deleteAtPosition(int** p, int* size, int position, int countDelElems) {
    if (position < 0 || position >= *size) {
        std::cout << "Некорректная позиция для удаления." << std::endl;
        return;
    }

    if (countDelElems + position > *size) {
        //Количество удаляемых элементов превышает доступное количество элементов с указанной позиции. Удаляются все элементы с указанной позиции.
        countDelElems = *size - position;
    }

    // Сдвигаем существующие элементы влево
    for (int i = position; i < *size - countDelElems; ++i) {
        (*p)[i] = (*p)[i + countDelElems];
    }

    // Изменяем размер массива
    resize_array(p, size, *size - countDelElems);
}
