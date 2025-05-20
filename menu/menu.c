#include <iostream>
#include <windows.h> // управляющие консолью библиотеки, для цветов
#include <conio.h>
#include "menu.h"

#define MAIN_MENU_SIZE 7
#define INIT_MENU_SIZE 5
#define EXIT 0
#define BACK -1

void start_main_menu() {
	int* mass = nullptr, size = 0, capacity = 0, deleted = 0;
	int selected_item;
	bool is_exit = 0;
	while (1) {
		std::cout << "TBD: massive output\n" << std::endl;
		std::cout << "ГЛАВНОЕ МЕНЮ\n" << std::endl;
		std::cout << "\t1. Создать массив." << std::endl;
		std::cout << "\t2. Вставить." << std::endl;
		std::cout << "\t3. Удалить." << std::endl;
		std::cout << "\t4. Найти." << std::endl;
		std::cout << "\t5. Заменить." << std::endl;
		std::cout << "\t6. Перемешать массив." << std::endl;
		std::cout << "\t7. Отсортировать массив." << std::endl;
		std::cout << "\t0. Выход.\n" << std::endl;
		get_selected_menu_item(&selected_item, MAIN_MENU_SIZE);
		system("cls");
		if (selected_item == EXIT) { break; }
		switch (selected_item) {
			case 1:
				is_exit = start_init_menu(&mass, &size);
				break;
			/* ... */
			case 4:
			// просто пример!!! ненастоящее содержимое кейса!!!
				int mass_example[10] = { 1, 2, 3, 2, 4, 5, 1, 5, 2, 2 }, size_example = 10;
				int found_2_example[5] = { 4, 1, 3, 8, 9 };
				int found_7_example[1] = { 0 };
				std::cout << "Пример вывода для поиска значения 2 в массиве." << std::endl;
				show_found_result(mass_example, size_example, found_2_example);
				std::cout << "Пример вывода для поиска значения 7 в массиве." << std::endl;
				show_found_result(mass_example, size_example, found_7_example);
				break;
				/* ... */
		}
	}
	if (mass != nullptr) { // лучше заранее прописать
			delete[] mass;
	}
}
int start_init_menu(int** mass, int* size) {
	int selected_item;
	bool is_exit = 0, is_back = 0;
	std::cout << "TBD: massive output" << std::endl;
	std::cout << "ГЛАВНОЕ МЕНЮ\n" << std::endl;
	std::cout << "\t1. Заполнить тривиально." << std::endl;
	std::cout << "\t2. Сгенерировать случайно." << std::endl;
	std::cout << "\t3. Ввести элементы массива вручную." << std::endl;
	std::cout << "\t4. Прочитать из файла." << std::endl;
	std::cout << "\t5. Назад." << std::endl;
	std::cout << "\t0. Выход.\n" << std::endl;
	get_selected_menu_item(&selected_item, INIT_MENU_SIZE);
	if (selected_item == EXIT) { is_exit = 1; system("cls"); return is_exit; }
	if (selected_item == BACK) { is_exit = 0; system("cls"); return is_exit; }
	std::cout << "TBD: set memory for massive" << std::endl;
	switch (selected_item) { 
	// содержимое кейсов лучше вынести
	// в отдельные функции с именами вида
	// start_НАЗВАНИЕ_ОПЕРАЦИИ()
	case 1:
		get_size(size);
		std::cout << "TBD: elementary massive filling" << std::endl;
		break;
	case 2:
		int min, max;
		get_size(size);
		get_lower_bound(&min);
		get_upper_bound(&max, min);
		std::cout << "TBD: random massive filling" << std::endl;
		break;
		/* ... */
	}
 system("cls");
 return is_exit;
}

void get_selected_menu_item(int* menu_item, int item_count) {
	printf("Ваш выбор: ");
	while (1) {
		std::cin >> *menu_item;
		if (*menu_item >= 0 && *menu_item <= item_count) {
			break;
		}
		printf("Некорректный ввод, попробуйте снова: ");
	}
	if (*menu_item == item_count) *menu_item = BACK;
}
void get_size(int* size) {
	std::cout << "Введите количество элементов: ";
	while (1) {
		td::cin >> *size;
		if (*size > 0) {
			break;
		}
		std::cout << "Некорректный ввод, попробуйте снова: ";
	}
}

void get_lower_bound(int *min) {
	std::cout << "Введите минимальное значение: ";
	std::cin >> *min;
}

void get_upper_bound(int *max, int min) {
	std::cout << "Введите максимальное значение: ";
	while (1) {
		std::cin >> *max;
		if (*max >= min) {
			break;
		}
		std::cout << "Некорректный ввод (max < min), попробуйте снова: ";
	}
}

void show_found_result(int* mass, int size, int* found) { // нарочно содержит ошибки !!
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "Найдено " << found[0] << " совпадений на следующих позициях:\n{ ";
	for (int i = 1; i < found[0]; i++) { std::cout << found[i] + 1 << ", "; }
	if (found[0] != 0) { std::cout << found[found[0]] + 1; }
	std::cout << " }" << std::endl;
	if (found[0] != 0) {
		std::cout << "Результат (найденные позиции выделены красным): " << std::endl;
		for (int i = 0, j = 1; i < size; i++) {
			if (j <= found[0] && i == found[j]) {
				SetConsoleTextAttribute(console, 0 * 16 + 4);
				std::cout << mass[i];
				j++;
			} else {
				SetConsoleTextAttribute(console, 0 * 16 + 7);
				std::cout << mass[i];
			}
			SetConsoleTextAttribute(console, 0 * 16 + 7);
			if (i != size - 1) { std::cout << ", "; }
		}
		std::cout << std::endl;
	}
	system("pause");
	system("cls");
}
 