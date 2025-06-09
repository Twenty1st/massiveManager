#pragma once

#include <stack>

// Объявление функций
void insertInStart(int** mas, int* size, int* newElems, int sizeNewElems);
void insertInEnd(int** mas, int* size, const int newElems[], int sizeNewElems);
void insertInPosition(int** mas, int* size, const int newElems[], int sizeNewElems, int position);
void print_insert_result(const int* arr, int size, int count, int position, int insert_type);
int getPositionToInsert();

// #endif 