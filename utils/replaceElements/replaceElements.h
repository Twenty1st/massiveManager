#ifndef replaceElements_H
#define replaceElements_H

#include <map>

// Объявление функций
void print_replace_result(int* mass, int size, int* replaced_indices, int count);
void replaceByIndices(int* mass, int size, const int indices[], const int newValues[], int count);
void replaceFirstEntry(int* mass, int size, std::map<int, int> replaceValues);
void replaceLastEntry(int* mass, int size, std::map<int, int> replaceValues);
void replaceAllEntry(int* mass, int size, std::map<int, int> replaceValues);

// Функции для получения данных от пользователя
int* getReplaceIndices(int count, bool& is_back);
int* getReplaceValues(int count, bool& is_back);
int* getElementsToReplace(int count, bool& is_back);

#endif 