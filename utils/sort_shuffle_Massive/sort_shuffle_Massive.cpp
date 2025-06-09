#include <cstdlib> 
#include <ctime> 
#include <algorithm> 
#include <iostream>


void shuffleMassive(int* mass, int size) {
    if (size <= 1) return;

    for (int i = size - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        std::swap(mass[i], mass[j]);
    }
}

void sortMassive(int* mass, int size) {
    for (int i = 0; i < size - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; ++j) {
            if (mass[j] > mass[j + 1]) {
                std::swap(mass[j], mass[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}