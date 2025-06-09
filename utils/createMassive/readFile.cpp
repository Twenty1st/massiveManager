#include "createMassive.h"
#include "../../getUserInput/getInput.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include <vector>

bool isValidNumber(const std::string& str) {
    try {
        std::stoi(str);
        return true;
    } catch (const std::invalid_argument& e) {
        return false;
    } catch (const std::out_of_range& e) {
        return false;
    }
}

void readFromFile(int*& mass, int& size) {
    std::ifstream fin("massive.txt");

    if (!fin) {
        std::cout << "Не удалось открыть файл!" << std::endl;
        return;
    }

    int count = 0;
    std::string line;
    while (std::getline(fin, line)) {
        std::istringstream iss(line);
        std::string token;
        while (iss >> token) {
            if (isValidNumber(token)) {
                count++;
            }
        }
    }

    if (count == 0) {
        std::cout << "Файл пуст или не содержит чисел!" << std::endl;
        fin.close();
        return;
    }

    fin.clear();
    fin.seekg(0);

    mass = (int*)malloc(count * sizeof(int));
    if (mass == nullptr) {
        std::cout << "Ошибка выделения памяти!" << std::endl;
        fin.close();
        return;
    }

    size = 0;
    while (std::getline(fin, line)) {
        std::istringstream iss(line);
        std::string token;
        while (iss >> token) {
            if (isValidNumber(token)) {
                mass[size++] = std::stoi(token);
            } else {
                std::cout << "Пропущено некорректное значение: " << token << std::endl;
            }
        }
    }

    fin.close();
}