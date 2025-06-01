#include "createMassive.h"
#include "../../getUserInput/getInput.h"
#include <iostream>
#include <fstream>

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

void readFromFile(int*& mass, int& size) {
    
}

void userInputMassive(int*& mass, int& size) {
    std::cout << "Enter massive size: ";
    if (!getNumber(&size) || size <= 0) {
        std::cout << "Invalid array size!" << std::endl;
        return;
    }
    
    mass = new int[size];
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter element " << i << ": ";
        if (!getNumber(&mass[i])) {
            delete[] mass;
            mass = nullptr;
            size = 0;
            return;
        }
    }
}