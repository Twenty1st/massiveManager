#ifndef deleteElements_H
#define deleteElements_H

#include <stack>

// Объявление функций
void print_delete_result(int* mass, int size, int* deleted_indices, int count);
void deleteAtStart(int** p, int* size, int countDelElems);
void deleteAtEnd(int** p, int* size, int countDelElems);
void deleteAtPosition(int** p, int* size, int* positions, int countDelElems);
int* getPositionsForDeletion(int count, int submenu_type, bool& is_back);
#endif 