#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <locale.h>
#include <iostream>
#include "menu/menu.h"

int main() {
    SetConsoleOutputCP(CP_UTF8); // установить UTF-8 как кодировку вывода
    std::setlocale(LC_ALL, "ru_RU.UTF-8"); // или ""
   //setlocale(LC_ALL, "rus");
    srand(time(0));
    start_main_menu();
    return 0;
}