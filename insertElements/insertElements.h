#ifndef insertElements_H
#define insertElements_H

#include <stack>

// Объявление функций
void insertInStart(int** p, int* size, const int newElems[], int sizeNewElems);
void insertInEnd(int** p, int* size, const int newElems[], int sizeNewElems);
void insertInPosition(int** p, int* size, const int newElems[], int sizeNewElems, int position);

#endif 