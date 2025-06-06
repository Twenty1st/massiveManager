#include <iostream>
#include <windows.h> // управляющие консолью библиотеки, для цветов
#include <conio.h>
#include <sstream>
#include <limits>
#include "menu.h"
#include "../utils/sort_shuffle_Massive/sort_shuffle_Massive.h"
#include "../utils/insertElements/insertElements.h"
#include "../utils/deleteElements/deleteElements.h"
#include "../utils/findElements/findElements.h"
#include "../utils/replaceElements/replaceElements.h"
#include "../utils/createMassive/createMassive.h"
#include "../getUserInput/getInput.h"
#include <stack>
#include <map>
#include "menuTexts.h"

#define MAIN_MENU_SIZE 8
#define INIT_MENU_SIZE 5

#define INSERT_MENU_SIZE 3
#define INSERT_SUBMENU_SIZE 4

#define DELETE_MENU_SIZE 3
#define DELETE_SUBMENU_SIZE 4

#define FIND_MENU_SIZE 3
#define FIND_SUBMENU_SIZE 4

#define REPLACE_MENU_SIZE 3
#define REPLACE_SUBMENU1_SIZE 3
#define REPLACE_SUBMENU2_SIZE 4
#define REPLACE_SUBMENU3_SIZE 4

#define EXIT 0
#define BACK -1

void get_selected_menu_item(int* menu_item, int item_count) {
    std::cout << "Ваш выбор: ";
    while (1) {
        std::string input;
        std::getline(std::cin, input);
        
        try {
            *menu_item = std::stoi(input);
            if (*menu_item >= 0 && *menu_item <= item_count) {
                break;
            }
        } catch (const std::invalid_argument& e) {
            // Игнорируем некорректный ввод
        }
        std::cout << "Некорректный ввод, попробуйте снова: ";
    }
    if (*menu_item == item_count) *menu_item = BACK;
}

void printMassive(int* p, int size) {
    if (size == 0) {
        std::cout << "Массив пуст." << std::endl;
        return;
    }
    std::cout << "{ ";
    for (int i = 0; i < size; ++i) {
        std::cout << p[i];
        if (i < size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " }" << std::endl;
}

void insertMenu(int*& mass, int& size) {
    int selected_item;
    bool is_back = false;

    if(size == 0){
        std::cout << "Сначала создайте массив!" <<std::endl;
        return;
    }

    while (!is_back) {
        //system("cls");
        std::cout << "Ваш текущий массив: ";
        printMassive(mass, size);
        printInsertMenu();

        get_selected_menu_item(&selected_item, INSERT_MENU_SIZE);
        //system("cls");

        if (selected_item == EXIT) { exit(0); }
        if (selected_item == BACK) { is_back = true; continue; }

        switch (selected_item) {
            case 1:
                insertSubmenu(mass, size, 1);
                break;
            case 2:
                insertSubmenu(mass, size, 2);
                break;
            case 3:
                is_back = true;
                break;
            case 0:
                exit(0);
        }
    }
}

void insertSubmenu(int*& mass, int& size, int submenu_type) {
    int selected_item;
    bool is_back = false;
    int count = 1;
    int* newElems = nullptr;

    while (!is_back) {
        //system("cls");
        std::cout << "Ваш текущий массив: ";
        printMassive(mass, size);
        printInsertSubMenu();

        get_selected_menu_item(&selected_item, INSERT_SUBMENU_SIZE);
        //system("cls");

        if (selected_item == EXIT) { exit(0); }
        if (selected_item == BACK) { is_back = true; continue; }

        if(submenu_type == 2) {
            std::cout << "Введите количество элементов для вставки: ";
            if(!getCountForInsert(&count)) {
                is_back = true;
                continue;
            }
        }

        // Освобождаем старую память если она есть
        if (newElems != nullptr) {
            free(newElems);
            newElems = nullptr;
        }
        newElems = (int*)malloc(count * sizeof(int));
        if (newElems == nullptr) {
            std::cout << "Ошибка выделения памяти!" << std::endl;
            is_back = true;
            continue;
        }

        std::cout << "Введите элементы для вставки: " << std::endl;
        newElems = getElementsFromUser(newElems, count);
        if(newElems == nullptr) {
            is_back = true;
            continue;
        }

        switch (selected_item) {
            case 1:
                insertInStartTest(&mass, &size, newElems, count);
                print_insert_result(mass, size, count, 0, 1);  
                is_back = true;
                break;
            case 2:
                insertInEnd(&mass, &size, newElems, count);
                print_insert_result(mass, size, count, 0, 2);
                is_back = true;
                break;
            case 3:
                int position;
                std::cout << "Введите позицию для вставки: ";
                if(!getNumber(&position)) {
                    free(newElems);
                    newElems = nullptr;
                    is_back = true;
                    break;
                }
                insertInPosition(&mass, &size, newElems, count, position);
                print_insert_result(mass, size, count, position, 3);
                is_back = true;
                break;
            case 4:
                is_back = true;
                break;
            case 0:
                exit(0);
        }
    }

    // Освобождаем память при выходе из функции
    if (newElems != nullptr) {
        free(newElems);
    }
}

// Функция для получения позиций для удаления
int* getPositionsForDeletion(int count, int submenu_type, bool& is_back) {
    int* elements = (int*)malloc(count * sizeof(int));
    if (elements == nullptr) {
        std::cout << "Ошибка выделения памяти!" << std::endl;
        is_back = true;
        return nullptr;
    }

    if (submenu_type == 2) {
        std::cout << "Введите позиции для удаления (нумерация с 1): " << std::endl;
        elements = getElementsFromUser(elements, count);
        if (elements == nullptr) {
            is_back = true;
            return nullptr;
        }
    } else {
        std::cout << "Введите позицию для удаления (нумерация с 1): ";
        if(!getNumber(&elements[0])) {
            free(elements);
            is_back = true;
            return nullptr;
        }
    }

    return elements;
}

void deleteMenu(int*& mass, int& size) {
    int selected_item;
    bool is_back = false;

    while (!is_back) {
        //system("cls");
        std::cout << "Ваш текущий массив: ";
        printMassive(mass, size);
        printDeleteMenu();

        get_selected_menu_item(&selected_item, DELETE_MENU_SIZE);
        //system("cls");

        if (selected_item == EXIT) { exit(0); }
        if (selected_item == BACK) { is_back = true; continue; }

        switch (selected_item) {
            case 1:
                deleteSubmenu(mass, size, 1);
                break;
            case 2:
                deleteSubmenu(mass, size, 2);
                break;
            case 3:
                is_back = true;
                break;
            case 0:
                exit(0);
        }
    }
}

void deleteSubmenu(int*& mass, int& size, int submenu_type) {
    int selected_item;
    bool is_back = false;

    while (!is_back) {
        //system("cls");
        std::cout << "Ваш текущий массив: ";
        printMassive(mass, size);
        printDeleteSubMenu();

        get_selected_menu_item(&selected_item, DELETE_SUBMENU_SIZE);
        //system("cls");

        if (selected_item == EXIT) { exit(0); }
        if (selected_item == BACK) { is_back = true; continue; }

        int count = 1;
        if (submenu_type == 2) {
            std::cout << "Введите количество элементов для удаления: ";
            if(!getCountForOperation(&count, size)) {
                is_back = true;
                continue;
            }
        }

        if (!is_back) {
            switch (selected_item) {
                case 1:
                    deleteAtStart(&mass, &size, count);
                    break;
                case 2:
                    deleteAtEnd(&mass, &size, count);
                    break;
                case 3: {
                    int* elements = getPositionsForDeletion(count, submenu_type, is_back);
                    if (is_back) break;
                    deleteAtPosition(&mass, &size, elements, count);
                    free(elements);
                    break;
                }
            }
        }
    }
}

void findMenu(int* mass, int size) {
    int selected_item;
    bool is_back = false;

    while (!is_back) {
        std::cout << "Ваш текущий массив: ";
        printMassive(mass, size);
        printFindMenu();

        get_selected_menu_item(&selected_item, FIND_MENU_SIZE);

        if (selected_item == EXIT) { exit(0); }
        if (selected_item == BACK) { is_back = true; continue; }

        switch (selected_item) {
            case 1:
                findSubmenu(mass, size, 1);
                break;
            case 2:
                findSubmenu(mass, size, 2);
                break;
            case 3:
                is_back = true;
                break;
            case 0:
                exit(0);
        }
    }
}

void findSubmenu(int* mass, int size, int submenu_type) {
    int selected_item;
    bool is_back = false;

    while (!is_back) {
        std::cout << "Ваш текущий массив: ";
        printMassive(mass, size);
        printFindSubmenu();

        get_selected_menu_item(&selected_item, FIND_SUBMENU_SIZE);

        if (selected_item == EXIT) { exit(0); }
        if (selected_item == BACK) { is_back = true; continue; }

        int count = getFindCount(submenu_type, size, is_back);
        if (is_back) continue;

        int* elements = getFindElements(count, is_back);
        if (is_back) continue;

        std::stack<int> result;
        switch (selected_item) {
            case 1:
                result = findFirstEntry(mass, size, elements, count);
                break;
            case 2:
                result = findLastEntry(mass, size, elements, count);
                break;
            case 3:
                result = findAllEntry(mass, size, elements, count);
                break;
            case 4:
                is_back = true;
                break;
            case 0:
                exit(0);
        }

        print_find_result(mass, size, result);
        free(elements);
    }
}

void replaceMenu(int* mass, int size) {
    int selected_item;
    bool is_back = false;

    while (!is_back) {
        //system("cls");
        std::cout << "Ваш текущий массив: ";
        printMassive(mass, size);
        printReplaceMenu();

        get_selected_menu_item(&selected_item, REPLACE_MENU_SIZE);
        //system("cls");

        if (selected_item == EXIT) { exit(0); }
        if (selected_item == BACK) { is_back = true; continue; }

        switch (selected_item) {
            case 1:
                replaceSubmenu1(mass, size, 1);
                break;
            case 2:
                replaceSubmenu1(mass, size, 2);
                break;
            case 3:
                is_back = true;
                break;
            case 0:
                exit(0);
        }
    }
}

void replaceSubmenu1(int* mass, int size, int submenu_type) {
    int selected_item;
    bool is_back = false;
    bool isOneElement = false;
    if(submenu_type == 1) {isOneElement = true;}
    while (!is_back) {
        //system("cls");
        std::cout << "Ваш текущий массив: ";
        printMassive(mass, size);
        printReplaceSubMenu1();

        get_selected_menu_item(&selected_item, REPLACE_SUBMENU1_SIZE);
        //system("cls");

        if (selected_item == EXIT) { exit(0); }
        if (selected_item == BACK) { is_back = true; continue; }

        switch (selected_item) {
            case 1:
                replaceSubmenu2(mass, size, 1, isOneElement);
                break;
            case 2:
                replaceSubmenu2(mass, size, 2, isOneElement);
                break;
            case 3:
                is_back = true;
                break;
            case 0:
                exit(0);
        }
    }
}

void replaceByIndicesSubmenu(int* mass, int size, int count) {
    bool is_back = false;
    
    // Получаем индексы
    int* indices = getReplaceIndices(count, is_back);
    if (is_back) return;

    // Получаем новые значения
    int* newValues = getReplaceValues(count, is_back);
    if (is_back) {
        free(indices);
        return;
    }

    // Выполняем замену
    replaceByIndices(mass, size, indices, newValues, count);
    
    free(indices);
    free(newValues);
}

void replaceByValuesSubmenu(int* mass, int size, int count, int selected_item) {
    bool is_back = false;
    
    // Получаем элементы для замены
    int* elements = getElementsToReplace(count, is_back);
    if (is_back) return;
    
    std::cout << "Вы хотите заменить элемент(-ы): ";
    printMassive(elements, count);
    
    // Получаем новые значения
    int* newValues = getReplaceValues(count, is_back);
    if (is_back) {
        free(elements);
        return;
    }

    std::cout << "на соответствующие элемент(-ы): ";
    printMassive(newValues, count);

    // Создаем map для замены
    std::map<int, int> replaceValues;
    for(int i = 0; i < count; i++) {
        replaceValues[elements[i]] = newValues[i];
    }

    switch (selected_item) {
        case 1:
            replaceFirstEntry(mass, size, replaceValues);
            break;
        case 2:
            replaceLastEntry(mass, size, replaceValues);
            break;
        case 3:
            replaceAllEntry(mass, size, replaceValues);
            break;
    }

    free(elements);
    free(newValues);
}

void replaceSubmenu2(int* mass, int size, int submenu_type, bool isOneElement) {
    int selected_item;
    bool is_back = false;

    while (!is_back) {
        //system("cls");
        std::cout << "Ваш текущий массив: ";
        printMassive(mass, size);
        printReplaceSubMenu2();

        get_selected_menu_item(&selected_item, REPLACE_SUBMENU2_SIZE);
        //system("cls");

        if (selected_item == EXIT) { exit(0); }
        if (selected_item == BACK) { is_back = true; continue; }

        int count = 1;
        if (!isOneElement) {
            std::cout << "Введите количество элементов для замены: ";
            if(!getCountForOperation(&count, size)) {
                is_back = true;
                continue;
            }
        }

        if (submenu_type == 1) { // Замена по индексам
            replaceByIndicesSubmenu(mass, size, count);
            is_back = true;
        } else { // Замена по значениям
            replaceByValuesSubmenu(mass, size, count, selected_item);
            is_back = true;
        }
    }
}

void generateMassiveMenu(int*& mass, int& size, int& capacity) {
    int selected_item;
    bool is_back = false;

    while (!is_back) {
        //system("cls");
        std::cout << "Ваш текущий массив: ";
        printMassive(mass, size);
        printCreateMassMenu();

        get_selected_menu_item(&selected_item, INIT_MENU_SIZE);
        //system("cls");

        if (selected_item == EXIT) { exit(0); }
        if (selected_item == BACK) { is_back = true; continue; }

        int newSize;
        switch (selected_item) {
            case 1: {
                std::cout << "Введите размер массива: ";
                if (!getNumber(&newSize) || newSize <= 0) {
                    std::cout << "Некорректный размер массива." << std::endl;
                    continue;
                }

                // Освобождаем старый массив если он есть
                if (mass != nullptr) {
                    free(mass);
                }

                // Создаем новый массив
                mass = (int*)malloc(newSize * sizeof(int));
                if (mass == nullptr) {
                    std::cout << "Ошибка выделения памяти!" << std::endl;
                    continue;
                }
                size = newSize;
                capacity = newSize;

                generateTrivialMassive(mass, size);
                break;
            }
            case 2: {
                std::cout << "Введите размер массива: ";
                if (!getNumber(&newSize) || newSize <= 0) {
                    std::cout << "Некорректный размер массива." << std::endl;
                    continue;
                }

                // Освобождаем старый массив если он есть
                if (mass != nullptr) {
                    free(mass);
                }

                // Создаем новый массив
                mass = (int*)malloc(newSize * sizeof(int));
                if (mass == nullptr) {
                    std::cout << "Ошибка выделения памяти!" << std::endl;
                    continue;
                }
                size = newSize;
                capacity = newSize;

                generateRandomMassive(mass, size);
                break;
            }
            case 3:
                userInputMassive(mass, size);
                capacity = size;
                break;
            case 4:
                break;
            case 5:
                is_back = true;
                break;
            case 0:
                exit(0);
        }
    }
}

void start_main_menu() {
    int* mass = nullptr, size = 0, capacity = 0, deleted = 0;
    int selected_item;
    bool is_exit = false;

    

    while (!is_exit) {
        std::cout << "Ваш текущий массив: ";
        printMassive(mass, size);
        printMainMenu();

        get_selected_menu_item(&selected_item, MAIN_MENU_SIZE);
        //system("cls");

        if (selected_item == EXIT) { is_exit = true; continue; }

        switch (selected_item) {
            case 1:
                generateMassiveMenu(mass, size, capacity);
                break;
            case 2:
                insertMenu(mass, size);
                break;
            case 3:
                deleteMenu(mass, size);
                break;
            case 4:
                findMenu(mass, size);
                break;
            case 5:
                replaceMenu(mass, size);
                break;
            case 6:
                if (size > 0) {
                    shuffleMassive(mass, size);
                } else {
                    std::cout << "Массив пуст!" << std::endl;
                    system("pause");
                }
                break;
            case 7:
                std::cout << size;
                if (size > 0) {
                    bubbleSort(mass, size);
                } else {
                    std::cout << "Массив пуст!" << std::endl;
                    system("pause");
                }
                break;
            case 0:
                exit(0);
        }
    }

    if (mass != nullptr) {
        free(mass);
    }
}