#ifndef searchElements_H
#define searchElements_H

#include <stack>

// Объявление функций
void print_search_result(int* mass, int size, int* found_indices, int count);
std::stack<int> searchFirstEntry(int* mass, int size, const int values[], int sizeValues);
std::stack<int> searchLastEntry(int* mass, int size, const int values[], int sizeValues);
std::stack<int> searchAllEntry(int* mass, int size, const int values[], int sizeValues);
#endif 