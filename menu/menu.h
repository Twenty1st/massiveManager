#ifndef menu_H
#define menu_H

void start_main_menu();
void generateMassiveMenu(int*& mass, int& size);
void insertMenu(int*& mass, int& size);
void insertSubmenu(int*& mass, int& size, int submenu_type);
void deleteMenu(int*& mass, int& size);
void deleteSubmenu(int*& mass, int& size, int submenu_type);
void findMenu(int* mass, int size);
void findSubmenu(int* mass, int size, int submenu_type);
void replaceMenu(int* mass, int size);
void replaceSubmenu1(int* mass, int size, int submenu_type);
void replaceSubmenu2(int* mass, int size, int submenu_type, bool isOneElement);
void replaceByIndicesSubmenu(int* mass, int size, int count);
void replaceByValuesSubmenu(int* mass, int size, int count, int selected_item);

#endif
