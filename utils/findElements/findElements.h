#ifndef findElements_H
#define findElements_H

#include <stack>

// Объявление функций
void print_find_result(int* mass, int size, std::stack<int>& result);
std::stack<int> findFirstEntry(int* mass, int size, const int values[], int sizeValues);
std::stack<int> findLastEntry(int* mass, int size, const int values[], int sizeValues);
std::stack<int> findAllEntry(int* mass, int size, const int values[], int sizeValues);
int getFindCount(int submenu_type, int size, bool& is_back);
int* getFindElements(int count, bool& is_back);

#endif 