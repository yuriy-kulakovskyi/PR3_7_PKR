#include <iostream>
#include <fstream>
#include "./functions/functions.h"

int main() {
    Node* list = nullptr;
    int choice;
    std::cout << "Створити список:\n1 - з клавіатури\n2 - з файлу\nВаш вибір: ";
    std::cin >> choice;
    if (choice == 1) {
        list = createListFromKeyboard();
    } else if (choice == 2) {
        std::string filename;
        std::cout << "Введіть назву файлу: ";
        std::cin >> filename;
        list = createListFromFile(filename);
    } else {
        std::cout << "Невірний вибір!" << std::endl;
        return 1;
    }
    printList(list, "Початковий список");
    int m, n;
    std::cout << "Введіть значення m (яке потрібно замінити): ";
    std::cin >> m;
    std::cout << "Введіть значення n (на яке замінити): ";
    std::cin >> n;
    replaceValues(list, m, n);
    printList(list, "Список після заміни");
    deleteList(list);
    return 0;
}
