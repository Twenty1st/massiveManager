#include <iostream>
#include <string>
#include <sstream>

bool getNumber(int* number) {
    std::string input;
    while (true) {
        std::getline(std::cin, input);

        if (input == "r") {
            std::cout << "Отмена действия. Возвращаемся в меню..." << std::endl;
            return false;
        }

        try {
            *number = std::stoi(input);
            return true;
        } catch (const std::invalid_argument& e) {
            std::cout << "Ошибка: Введите число! Повторите ввод:" << std::endl;
            std::cin.clear();
        } catch (const std::out_of_range& e) {
            std::cout << "Ошибка: Число вне допустимого диапазона! Повторите ввод:" << std::endl;
            std::cin.clear();
        }
    }
}

int getUserIndex(int* size){
	int index;
	if(!getNumber(&index)){
		return -1;
	}

	if (index < 0 || index >= *size) {
		std::cout << "Error!" << std::endl;
		return -1;
	}
	return index;
}

bool getCountForInsert(int* count) {
    while(true) {
        if(!getNumber(count)) {
            return false;
        } 
        if(*count <= 0) {
            std::cout << "Некорректное значение, повторите ввод: ";
        } else {
            return true;
        }
    }
}

bool getCountForOperation(int* count, int size) {
    while(true) {
        if(!getNumber(count)) {
            return false;
        } 
        if(*count <= 0 || *count > size) {
            std::cout << "Некорректное значение, повторите ввод: ";
        } else {
            return true;
        }
    }
}

int* getElementsFromUser(int* elements, int maxSize) {    
    for(int i = 0; i < maxSize; i++) {
        if(!getNumber(&elements[i])) {
            return nullptr;
        }
    }
    return elements;
}


