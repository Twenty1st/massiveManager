#ifndef deleteElements_H
#define deleteElements_H

#include <stack>

// Объявление функций
void deleteAtStart(int** p, int* size, int countDelElems);
void deleteAtEnd(int** p, int* size, int countDelElems);
void deleteAtPosition(int** p, int* size, int* positions, int countDelElems);
#endif 