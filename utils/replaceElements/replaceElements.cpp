#include <iostream>
#include <stack>
#include <map>


void replaceFirstEntry(int* mass, int size, std::map<int, int> replaceValues){
	for (int i = 0; i < replaceValues.size(); i++){
		for (int j = 0; j < size; j++){
			if (replaceValues.find(j) != replaceValues.end()){
				mass[j] = replaceValues[j];
				break;
			}
		}	
	}
}

void replaceLastEntry(int* mass, int size, std::map<int, int> replaceValues){
	for (int i = 0; i < replaceValues.size(); i++){
		for (int j = size-1; j >= 0; --j){
			if (replaceValues.find(j) != replaceValues.end()){
				mass[j] = replaceValues[j];
				break;
			}
		}	
	}
}

void replaceAllEntry(int* mass, int size, std::map<int, int> replaceValues){
	for (int i = 0; i < replaceValues.size(); i++){
		for (int j = 0; j < size; j++){
			if (replaceValues.find(j) != replaceValues.end()){
				mass[j] = replaceValues[j];
			}
		}	
	}
}