// работа с памятью
void clear_memory(int* mass);
int* set_memory(int size);
/* … */
// заполнение массива
void default_init(int* mass, int size);
/* … */
// вставка
void insert_elems(int* mass, int size, int pos, int* values, int count);
/* … */
// поиск
int* find_elems(int* mass, int size, int* values, int count);
/* … */
// удаление
void pop_back_elems(int* mass, int size, int count);
/* … */
// замена
void replace_by_value(int* mass, int size, int value, int new_value);
void replace_by_indeces(int* mass, int size, int* indeces, int count, int new_value);
// вывод на экран
void print(int* mass, int size);
