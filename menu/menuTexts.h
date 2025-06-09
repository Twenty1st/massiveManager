#ifndef menuTexts_H
#define menuTexts_H

#include <iostream>

const char* RETURN_TO_MENU = "Для возврата в меню введите 'r'.";

void printMainMenu() {
    std::cout << "ГЛАВНОЕ МЕНЮ\n" << std::endl
              << "\t1. Создать массив." << std::endl
              << "\t2. Вставить элементы." << std::endl
              << "\t3. Удалить элементы." << std::endl
              << "\t4. Найти элементы." << std::endl
              << "\t5. Заменить элементы." << std::endl
              << "\t6. Помешать массив." << std::endl
              << "\t7. Сортировать массив." << std::endl
              << "\t0. Выход.\n" << std::endl;
}

void printCreateMassMenu(){
	std::cout << "МЕНЮ СОЗДАНИЯ МАССИВА\n" << std::endl
                  << "\t1. Заполнить тривиально." << std::endl
                  << "\t2. Сгенерировать случайно." << std::endl
                  << "\t3. Ввести элементы массива вручную." << std::endl
                  << "\t4. Прочитать из файла." << std::endl
                  << "\t5. Назад." << std::endl
                  << "\t0. Выход.\n" << std::endl;
}

void printFindMenu() {
    std::cout << "МЕНЮ ПОИСКА\n" << std::endl
              << "\t1. Найти один элемент." << std::endl
              << "\t2. Найти несколько элементов." << std::endl
              << "\t3. Назад." << std::endl
              << "\t0. Выход.\n" << std::endl;
}

void printFindSubmenu() {
    std::cout << "ВТОРОЕ МЕНЮ ПОИСКА\n" << std::endl
              << "\t1. Найти первое вхождение." << std::endl
              << "\t2. Найти последнее вхождение." << std::endl
              << "\t3. Найти все вхождения." << std::endl
              << "\t4. Назад." << std::endl
              << "\t0. Выход.\n" << std::endl;
}

void printInsertMenu() {
    std::cout << "МЕНЮ ВСТАВКИ\n" << std::endl
              << "\t1. Вставить один элемент." << std::endl
              << "\t2. Вставить несколько элементов." << std::endl
              << "\t3. Назад." << std::endl
              << "\t0. Выход.\n" << std::endl;
}

void printInsertSubMenu(){
	std::cout << "МЕНЮ ВСТАВКИ\n" << std::endl
                  << "\t1. Вставить в начало." << std::endl
                  << "\t2. Вставить в конец." << std::endl
                  << "\t3. Вставить по указанной позиции." << std::endl
                  << "\t4. Назад." << std::endl
                  << "\t0. Выход.\n" << std::endl;
}

void printDeleteMenu() {
    std::cout << "МЕНЮ УДАЛЕНИЯ\n" << std::endl
              << "\t1. Удалить один элемент." << std::endl
              << "\t2. Удалить несколько элементов." << std::endl
              << "\t3. Назад." << std::endl
              << "\t0. Выход.\n" << std::endl;
}

void printDeleteSubMenu() {
	std::cout << "МЕНЮ УДАЛЕНИЯ\n" << std::endl
                  << "\t1. Удалить из начала." << std::endl
                  << "\t2. Удалить из конца." << std::endl
                  << "\t3. Удалить по указанной позиции." << std::endl
                  << "\t4. Назад." << std::endl
                  << "\t0. Выход.\n" << std::endl;
}

void printReplaceMenu(){
	std::cout << "МЕНЮ ЗАМЕНЫ\n" << std::endl
                  << "\t1. Заменить один элемент." << std::endl
                  << "\t2. Заменить несколько элементов." << std::endl
                  << "\t3. Назад." << std::endl
                  << "\t0. Выход.\n" << std::endl;
}

void printReplaceSubMenu1(){
	std::cout << "МЕНЮ ЗАМЕНЫ\n" << std::endl
                  << "\t1. Задать элемент(-ы) индексами (нумерация с нуля)." << std::endl
                  << "\t2. Задать элемент(-ы) значениями." << std::endl
                  << "\t3. Назад." << std::endl
                  << "\t0. Выход.\n" << std::endl;
}

void printReplaceSubMenu2() {
	std::cout << "МЕНЮ ЗАМЕНЫ\n" << std::endl
                  << "\t1. Заменить первое вхождение." << std::endl
                  << "\t2. Заменить последнее вхождение." << std::endl
                  << "\t3. Заменить все вхождения." << std::endl
                  << "\t4. Назад." << std::endl
                  << "\t0. Выход.\n" << std::endl;
}

#endif 