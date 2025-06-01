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
        } catch (const std::out_of_range& e) {
            std::cout << "Ошибка: Число вне допустимого диапазона! Повторите ввод:" << std::endl;
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


