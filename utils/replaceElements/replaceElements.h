#ifndef replaceElements_H
#define replaceElements_H

#include <map>

// Объявление функций
void replaceByIndices(int* mass, int size, const int indices[], const int newValues[], int count);
void replaceFirstEntry(int* mass, int size, std::map<int, int> replaceValues);
void replaceLastEntry(int* mass, int size, std::map<int, int> replaceValues);
void replaceAllEntry(int* mass, int size, std::map<int, int> replaceValues);
#endif 