#include <iostream>
#include <stack>
#include <map>
#include "../colorPrint.h"
#include "../../getUserInput/getInput.h"

void print_replace_result(int* mass, int size, int* replaced_indices, int count) {
    std::cout << "\nЭл-т(-ы) успешно заменен(-ы)." << std::endl;
    std::cout << "Результат: ";
    print_array_with_highlight(mass, size, replaced_indices, count, COLOR_YELLOW);
}

void replaceByIndices(int* mass, int size, const int indices[], const int newValues[], int count) {
    // Проверяем корректность всех индексов
    for(int i = 0; i < count; i++) {
        if (indices[i] < 0 || indices[i] >= size) {
            std::cout << "Индекс " << indices[i] << " выходит за границы массива" << std::endl;
            return;
        }
    }

    // Выполняем замену
    for(int i = 0; i < count; i++) {
        mass[indices[i]] = newValues[i];
    }
    
    print_replace_result(mass, size, (int*)indices, count);
}

void replaceFirstEntry(int* mass, int size, std::map<int, int> replaceValues) {
    int* replaced_indices = (int*)malloc(size * sizeof(int));
    int count = 0;
    
    for (const auto& pair : replaceValues) {
        int oldValue = pair.first;
        int newValue = pair.second;
        for (int j = 0; j < size; j++) {
            if (mass[j] == oldValue) {
                mass[j] = newValue;
                replaced_indices[count++] = j;
                break;
            }
        }
    }
    
    if(count > 0) {
        print_replace_result(mass, size, replaced_indices, count);
    }
    free(replaced_indices);
}

void replaceLastEntry(int* mass, int size, std::map<int, int> replaceValues) {
    int* replaced_indices = (int*)malloc(size * sizeof(int));
    int count = 0;
    
    for (const auto& pair : replaceValues) {
        int oldValue = pair.first;
        int newValue = pair.second;
        for (int j = size-1; j >= 0; --j) {
            if (mass[j] == oldValue) {
                mass[j] = newValue;
                replaced_indices[count++] = j;
                break;
            }
        }
    }
    
    if(count > 0) {
        print_replace_result(mass, size, replaced_indices, count);
    }
    free(replaced_indices);
}

void replaceAllEntry(int* mass, int size, std::map<int, int> replaceValues) {
    int* replaced_indices = (int*)malloc(size * sizeof(int));
    int count = 0;
    
    for (const auto& pair : replaceValues) {
        int oldValue = pair.first;
        int newValue = pair.second;
        for (int j = 0; j < size; j++) {
            if (mass[j] == oldValue) {
                mass[j] = newValue;
                replaced_indices[count++] = j;
            }
        }
    }
    
    if(count > 0) {
        print_replace_result(mass, size, replaced_indices, count);
    }
    free(replaced_indices);
}

int* getReplaceIndices(int count, bool& is_back) {
    std::cout << "Введите индексы элементов для замены (нумерация с 0): " << std::endl;
    int* indices = (int*)malloc(count * sizeof(int));
    if (indices == nullptr) {
        std::cout << "Ошибка выделения памяти!" << std::endl;
        is_back = true;
        return nullptr;
    }
    indices = getElementsFromUser(indices, count);
    if(indices == nullptr) {
        free(indices);
        is_back = true;
        return nullptr;
    }
    return indices;
}

int* getReplaceValues(int count, bool& is_back) {
    std::cout << "Введите новые значения для этих элементов: " << std::endl;
    int* newValues = (int*)malloc(count * sizeof(int));
    if (newValues == nullptr) {
        std::cout << "Ошибка выделения памяти!" << std::endl;
        is_back = true;
        return nullptr;
    }
    newValues = getElementsFromUser(newValues, count);
    if(newValues == nullptr) {
        free(newValues);
        is_back = true;
        return nullptr;
    }
    return newValues;
}

int* getElementsToReplace(int count, bool& is_back) {
    std::cout << "Введите элементы, которые нужно заменить: " << std::endl;
    int* elements = (int*)malloc(count * sizeof(int));
    if (elements == nullptr) {
        std::cout << "Ошибка выделения памяти!" << std::endl;
        is_back = true;
        return nullptr;
    }
    elements = getElementsFromUser(elements, count);
    if(elements == nullptr) {
        free(elements);
        is_back = true;
        return nullptr;
    }
    return elements;
}