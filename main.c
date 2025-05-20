#include <stdlib.h> // srand, NULL
#include <time.h> // time
#include <locale.h> // setlocale
#include "menu.h"

int main() {
 setlocale(LC_ALL, "rus");
 srand(time(0));
 // запуск главного меню
 start_main_menu();
 return 0;
}