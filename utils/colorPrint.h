#pragma once
#include <windows.h>
#include <iostream>

// Цвета для консоли
#define COLOR_DEFAULT 7    // Белый
#define COLOR_RED 12       // Красный
#define COLOR_GREEN 10     // Зеленый
#define COLOR_BLUE 9       // Синий
#define COLOR_YELLOW 14    // Желтый

// Установка цвета текста
inline void set_color(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Сброс цвета на стандартный
inline void reset_color() {
    set_color(COLOR_DEFAULT);
}

// Вывод массива с подсветкой элементов
inline void print_array_with_highlight(const int arr[], int size, const int highlight_indices[], int highlight_count, int highlight_color) {
    std::cout << "{ ";
    for (int i = 0; i < size; ++i) {
        bool is_highlighted = false;
        for (int j = 0; j < highlight_count; ++j) {
            if (highlight_indices[j] == i) {
                is_highlighted = true;
                break;
            }
        }

        if (is_highlighted) {
            set_color(highlight_color);
            std::cout << arr[i];
            reset_color();
        } else {
            std::cout << arr[i];
        }

        if (i < size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " }" << std::endl;
} 