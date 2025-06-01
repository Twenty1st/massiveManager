#include <iostream>
#include <windows.h> // управляющие консолью библиотеки, для цветов
#include <conio.h>
#include <sstream>
#include "menu.h"
#include "../utils/sort_shuffle_Massive/sort_shuffle_Massive.h"
#include "../utils/insertElements/insertElements.h"
#include "../utils/deleteElements/deleteElements.h"
#include "../utils/searchElements/searchElements.h"
#include "../utils/replaceElements/replaceElements.h"
#include "../utils/createMassive/createMassive.h"
#include "../getUserInput/getInput.h"
#include <stack>
#include <map>

#define MAIN_MENU_SIZE 7
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

void get_selected_menu_item(int* selected_item, int menu_size) {
    char ch;
    while (true) {
        ch = _getch();
        if (ch >= '0' && ch <= '0' + menu_size) {
            *selected_item = ch - '0';
            break;
        }
    }
}

int* getElementsFromUser(int* elements, int maxSize) {    
    for(int i = 0; i < maxSize; i++) {
        if(!getNumber(&elements[i])) {
            // если пользователь ввел 'r', освобождаем память и возвращаем nullptr
            delete[] elements;
            return nullptr;
        }
    }
    return elements;
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

    while (!is_back) {
        printMassive(mass, size);
        std::cout << "МЕНЮ ВСТАВКИ\n" << std::endl
                  << "\t1. Вставить один элемент." << std::endl
                  << "\t2. Вставить несколько элементов." << std::endl
                  << "\t3. Назад." << std::endl
                  << "\t0. Выход.\n" << std::endl;

        get_selected_menu_item(&selected_item, INSERT_MENU_SIZE);
        system("cls");

        if (selected_item == EXIT) { exit(0); }
        if (selected_item == BACK) { is_back = true; continue; }

        switch (selected_item) {
            case 1:
                insertSubmenu(mass, size, 1);
                break;
            case 2:
                insertSubmenu(mass, size, 2);
                break;
        }
    }
}

void insertSubmenu(int*& mass, int& size, int submenu_type) {
    int selected_item;
    bool is_back = false;

    while (!is_back) {
        printMassive(mass, size);
        std::cout << "ВТОРОЕ МЕНЮ ВСТАВКИ\n" << std::endl
                  << "\t1. Вставить в начало." << std::endl
                  << "\t2. Вставить в конец." << std::endl
                  << "\t3. Вставить по указанной позиции." << std::endl
                  << "\t4. Назад." << std::endl
                  << "\t0. Выход.\n" << std::endl;

        get_selected_menu_item(&selected_item, INSERT_SUBMENU_SIZE);
        system("cls");

        if (selected_item == EXIT) { exit(0); }
        if (selected_item == BACK) { is_back = true; continue; }

        int* newElems = new int[submenu_type == 1 ? 1 : size];
        newElems = getElementsFromUser(newElems, submenu_type == 1 ? 1 : size);
        if(newElems == nullptr) {
            is_back = true;
            continue;
        }

        switch (selected_item) {
            case 1:
                insertInStart(&mass, &size, newElems, submenu_type == 1 ? 1 : size);
                break;
            case 2:
                insertInEnd(&mass, &size, newElems, submenu_type == 1 ? 1 : size);
                break;
            case 3:
                int position;
                std::cout << "Введите позицию для вставки: ";
                if(!getNumber(&position)) {
                    delete[] newElems;
                    is_back = true;
                    break;
                }
                insertInPosition(&mass, &size, newElems, submenu_type == 1 ? 1 : size, position);
                break;
            case 4:
                is_back = true;
                break;
            case 0:
                exit(0);
        }
        delete[] newElems;
    }
}

void deleteMenu(int*& mass, int& size) {
    int selected_item;
    bool is_back = false;

    while (!is_back) {
        printMassive(mass, size);
        std::cout << "МЕНЮ УДАЛЕНИЯ\n" << std::endl
                  << "\t1. Удалить один элемент." << std::endl
                  << "\t2. Удалить несколько элементов." << std::endl
                  << "\t3. Назад." << std::endl
                  << "\t0. Выход.\n" << std::endl;

        get_selected_menu_item(&selected_item, DELETE_MENU_SIZE);
        system("cls");

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
        printMassive(mass, size);
        std::cout << "ВТОРОЕ МЕНЮ УДАЛЕНИЯ\n" << std::endl
                  << "\t1. Удалить из начала." << std::endl
                  << "\t2. Удалить из конца." << std::endl
                  << "\t3. Удалить по указанной позиции." << std::endl
                  << "\t4. Назад." << std::endl
                  << "\t0. Выход.\n" << std::endl;

        get_selected_menu_item(&selected_item, DELETE_SUBMENU_SIZE);
        system("cls");

        if (selected_item == EXIT) { exit(0); }
        if (selected_item == BACK) { is_back = true; continue; }

        int* elements = new int[submenu_type == 1 ? 1 : size];
        elements = getElementsFromUser(elements, submenu_type == 1 ? 1 : size);
        if(elements == nullptr) {
            is_back = true;
            continue;
        }

        switch (selected_item) {
            case 1:
                deleteAtStart(&mass, &size, submenu_type == 1 ? 1 : size);
                break;
            case 2:
                deleteAtEnd(&mass, &size, submenu_type == 1 ? 1 : size);
                break;
            case 3:
                int position;
                std::cout << "Введите позицию для удаления: ";
                if(!getNumber(&position)) {
                    delete[] elements;
                    is_back = true;
                    break;
                }
                deleteAtPosition(&mass, &size, position, submenu_type == 1 ? 1 : size);
                break;
            case 4:
                is_back = true;
                break;
            case 0:
                exit(0);
        }
        delete[] elements;
    }
}

void findMenu(int* mass, int size) {
    int selected_item;
    bool is_back = false;

    while (!is_back) {
        printMassive(mass, size);
        std::cout << "МЕНЮ ПОИСКА\n" << std::endl
                  << "\t1. Найти один элемент." << std::endl
                  << "\t2. Найти несколько элементов." << std::endl
                  << "\t3. Назад." << std::endl
                  << "\t0. Выход.\n" << std::endl;

        get_selected_menu_item(&selected_item, FIND_MENU_SIZE);
        system("cls");

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
        printMassive(mass, size);
        std::cout << "ВТОРОЕ МЕНЮ ПОИСКА\n" << std::endl
                  << "\t1. Найти первое вхождение." << std::endl
                  << "\t2. Найти последнее вхождение." << std::endl
                  << "\t3. Найти все вхождения." << std::endl
                  << "\t4. Назад." << std::endl
                  << "\t0. Выход.\n" << std::endl;

        get_selected_menu_item(&selected_item, FIND_SUBMENU_SIZE);
        system("cls");

        if (selected_item == EXIT) { exit(0); }
        if (selected_item == BACK) { is_back = true; continue; }

        int* elements = new int[submenu_type == 1 ? 1 : size];
        elements = getElementsFromUser(elements, submenu_type == 1 ? 1 : size);
        if(elements == nullptr) {
            is_back = true;
            continue;
        }

        std::stack<int> result;
        switch (selected_item) {
            case 1:
                result = searchFirstEntry(mass, size, elements, submenu_type == 1 ? 1 : size);
                break;
            case 2:
                result = searchLastEntry(mass, size, elements, submenu_type == 1 ? 1 : size);
                break;
            case 3:
                result = searchAllEntry(mass, size, elements, submenu_type == 1 ? 1 : size);
                break;
            case 4:
                is_back = true;
                break;
            case 0:
                exit(0);
        }

        // Вывод результатов поиска
        if(result.empty()) {
            std::cout << "Элементы не найдены." << std::endl;
        } else {
            std::cout << "Найдены элементы на позициях: ";
            while(!result.empty()) {
                std::cout << result.top() << " ";
                result.pop();
            }
            std::cout << std::endl;
        }

        delete[] elements;
    }
}

void replaceMenu(int* mass, int size) {
    int selected_item;
    bool is_back = false;

    while (!is_back) {
        printMassive(mass, size);
        std::cout << "МЕНЮ ЗАМЕНЫ\n" << std::endl
                  << "\t1. Заменить один элемент." << std::endl
                  << "\t2. Заменить несколько элементов." << std::endl
                  << "\t3. Назад." << std::endl
                  << "\t0. Выход.\n" << std::endl;

        get_selected_menu_item(&selected_item, REPLACE_MENU_SIZE);
        system("cls");

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

    while (!is_back) {
        printMassive(mass, size);
        std::cout << "ПЕРВОЕ ПОДМЕНЮ ЗАМЕНЫ\n" << std::endl
                  << "\t1. Задать элемент(-ы) индексами (нумерация с нуля)." << std::endl
                  << "\t2. Задать элемент(-ы) значениями." << std::endl
                  << "\t3. Назад." << std::endl
                  << "\t0. Выход.\n" << std::endl;

        get_selected_menu_item(&selected_item, REPLACE_SUBMENU1_SIZE);
        system("cls");

        if (selected_item == EXIT) { exit(0); }
        if (selected_item == BACK) { is_back = true; continue; }

        switch (selected_item) {
            case 1:
                replaceSubmenu2(mass, size, 1);
                break;
            case 2:
                replaceSubmenu2(mass, size, 2);
                break;
            case 3:
                is_back = true;
                break;
            case 0:
                exit(0);
        }
    }
}

void replaceSubmenu2(int* mass, int size, int submenu_type) {
    int selected_item;
    bool is_back = false;

    while (!is_back) {
        printMassive(mass, size);
        std::cout << "ВТОРОЕ ПОДМЕНЮ ЗАМЕНЫ\n" << std::endl
                  << "\t1. Заменить первое вхождение." << std::endl
                  << "\t2. Заменить последнее вхождение." << std::endl
                  << "\t3. Заменить все вхождения." << std::endl
                  << "\t4. Назад." << std::endl
                  << "\t0. Выход.\n" << std::endl;

        get_selected_menu_item(&selected_item, REPLACE_SUBMENU2_SIZE);
        system("cls");

        if (selected_item == EXIT) { exit(0); }
        if (selected_item == BACK) { is_back = true; continue; }

        // Получаем элементы для замены
        int* elements = new int[submenu_type == 1 ? 1 : size];
        elements = getElementsFromUser(elements, submenu_type == 1 ? 1 : size);
        if(elements == nullptr) {
            is_back = true;
            continue;
        }
        
        std::cout << "Вы хотите заменить элемент(-ы): ";
        printMassive(elements, submenu_type == 1 ? 1 : size);
        

        // Получаем новые значения
        int* newValues = new int[submenu_type == 1 ? 1 : size];
        newValues = getElementsFromUser(newValues, submenu_type == 1 ? 1 : size);
        if(newValues == nullptr) {
            delete[] elements;
            is_back = true;
            continue;
        }

        std::cout << "на соответствующие элемент(-ы): ";
        printMassive(newValues, submenu_type == 1 ? 1 : size);

        // Создаем map для замены
        std::map<int, int> replaceValues;
        for(int i = 0; i < (submenu_type == 1 ? 1 : size); i++) {
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
            case 4:
                is_back = true;
                break;
            case 0:
                exit(0);
        }

        delete[] elements;
        delete[] newValues;
    }
}

void generateMassiveMenu(int*& mass, int& size, int& capacity) {
    int selected_item;
    bool is_back = false;

    while (!is_back) {
        printMassive(mass, size);
        std::cout << "МЕНЮ СОЗДАНИЯ МАССИВА\n" << std::endl
                  << "\t1. Заполнить тривиально." << std::endl
                  << "\t2. Сгенерировать случайно." << std::endl
                  << "\t3. Ввести элементы массива вручную." << std::endl
                  << "\t4. Прочитать из файла." << std::endl
                  << "\t5. Назад." << std::endl
                  << "\t0. Выход.\n" << std::endl;

        get_selected_menu_item(&selected_item, INIT_MENU_SIZE);
        system("cls");

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
                    delete[] mass;
                }

                // Создаем новый массив
                mass = new int[newSize];
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
                    delete[] mass;
                }

                // Создаем новый массив
                mass = new int[newSize];
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
        printMassive(mass, size);
        std::cout << "ГЛАВНОЕ МЕНЮ\n" << std::endl
                  << "\t1. Создать массив." << std::endl
                  << "\t2. Вставить." << std::endl
                  << "\t3. Удалить." << std::endl
                  << "\t4. Найти." << std::endl
                  << "\t5. Заменить." << std::endl
                  << "\t6. Перемешать массив." << std::endl
                  << "\t7. Отсортировать массив." << std::endl
                  << "\t0. Выход.\n" << std::endl;

        get_selected_menu_item(&selected_item, MAIN_MENU_SIZE);
        system("cls");

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
                shuffleMassive(mass, size);
                break;
            case 7:
                sortMassive(mass, size);
                break;
            case 0:
                exit(0);
        }
    }

    if (mass != nullptr) {
        delete[] mass;
    }
}