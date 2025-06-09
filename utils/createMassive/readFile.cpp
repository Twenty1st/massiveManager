#include "createMassive.h"
#include "../../getUserInput/getInput.h"
#include <iostream>
#include <fstream>

int countNumsInFile(std::ifstream& fin){
    int count = 0;
    int number;
    while (fin >> number) {
        count++;
    }

    return count;
}

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

    int count = countNumsInFile(fin);

		if (count == 0) {
			std::cout << "Файл пуст или не содержит чисел!" << std::endl;
			return;
		}

    fin.clear();
    fin.seekg(0);
    
    mass = (int*)malloc(count * sizeof(int));
    if (mass == nullptr) {
        std::cout << "Ошибка выделения памяти!" << std::endl;
        return;
    }
    
    size = 0;
    std::string line;
    while (std::getline(fin, line)) {
        if (isValidNumber(line)) {
            mass[size++] = std::stoi(line);
        } else {
            std::cout << "Пропущено некорректное значение: " << line << std::endl;
        }
    }

    fin.close();
}