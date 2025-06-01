#include <stdlib.h> // srand, NULL
#include <time.h>   // time
#include <locale.h> // setlocale
#include <iostream> // cerr, endl
#include <stdexcept> // exception
#include <windows.h> // для SetConsoleCP и SetConsoleOutputCP
#include "menu/menu.h"

int main() {
    // Установка кодировки UTF-8 для консоли
    SetConsoleCP(65001); // CP_UTF8
    SetConsoleOutputCP(65001); // CP_UTF8

    setlocale(LC_ALL, "ru_RU.UTF-8");

    srand(time(0));

    try {
        start_main_menu();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
        return 1;
    }

    return 0;
}