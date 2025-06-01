#include <cstdlib> 
#include <ctime> 
#include <algorithm> 


void shuffleMassive(int* mass, int size) {
    if (size <= 1) return;

    for (int i = size - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        std::swap(mass[i], mass[j]);
    }
}

void sortMassive(int* mass, int size){
	for(int i = 0; i < size - 1; ++i){
		for(int j = size-1; j > i; --j){
			if(mass[j] > mass[i]){
				std::swap(mass[j], mass[i]);
			}
		}
	}
}