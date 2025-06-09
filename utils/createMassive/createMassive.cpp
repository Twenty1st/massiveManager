#include "createMassive.h"
#include "../../getUserInput/getInput.h"
#include <iostream>

void generateTrivialMassive(int* mass, int size) {
    for (int i = 0; i < size; ++i) {
        mass[i] = i + 1;
    }
}

void generateRandomMassive(int* mass, int size) {
    for (int i = 0; i < size; ++i) {
        mass[i] = rand() % 100;
    }
}

void userInputMassive(int*& mass, int& size) {
    std::cout << "Введите размер массива: ";
    if (!getNumber(&size) || size <= 0) {
        std::cout << "Некорректный размер массива!" << std::endl;
        return;
    }
    
    mass = (int*)malloc(size * sizeof(int));
    if (mass == nullptr) {
        std::cout << "Ошибка выделения памяти!" << std::endl;
        return;
    }
    
    for (int i = 0; i < size; ++i) {
        std::cout << "Введите элемент " << i << ": ";
        if (!getNumber(&mass[i])) {
            free(mass);
            mass = nullptr;
            size = 0;
            return;
        }
    }
}

