#ifndef searchElements_H
#define searchElements_H

#include <stack>

// Объявление функций
std::stack<int> searchFirstEntry(int* mass, int size, const int values[], int sizeValues);
std::stack<int> searchLastEntry(int* mass, int size, const int values[], int sizeValues);
std::stack<int> searchAllEntry(int* mass, int size, const int values[], int sizeValues);
#endif 