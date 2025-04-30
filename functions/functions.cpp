#include <iostream>
#include <fstream>
#include "functions.h"

Node* createNode(int value) {
  Node* newNode = new Node;
  newNode->value = value;
  newNode->next = nullptr;
  return newNode;
}
Node* appendNode(Node* head, int value) {
  Node* newNode = createNode(value);
  if (head == nullptr) {
    return newNode;
  }
  Node* current = head;
  while (current->next != nullptr) {
    current = current->next;
  }
  current->next = newNode;
  return head;
}
void printList(Node* head, const std::string& title) {
  std::cout << "=== " << title << " ===" << std::endl;
  if (head == nullptr) {
    std::cout << "Список порожній" << std::endl;
    return;
  }
  Node* current = head;
  while (current != nullptr) {
    std::cout << current->value << " ";
    current = current->next;
  }
  std::cout << std::endl << std::endl;
}
void replaceValues(Node* head, int m, int n) {
  Node* current = head;
  while (current != nullptr) {
    if (current->value == m) {
      current->value = n;
    }
    current = current->next;
  }
}
void deleteList(Node* head) {
  while (head != nullptr) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}
Node* createListFromKeyboard() {
  Node* head = nullptr;
  int count;
  std::cout << "Введіть кількість елементів: ";
  std::cin >> count;
  for (int i = 0; i < count; ++i) {
    int value;
    std::cout << "Введіть елемент " << (i + 1) << ": ";
    std::cin >> value;
    head = appendNode(head, value);
  }
  return head;
}
Node* createListFromFile(const std::string& filename) {
  Node* head = nullptr;
  std::ifstream file(filename);
  if (!file) {
    std::cout << "Не вдалося відкрити файл!" << std::endl;
    return nullptr;
  }
  int value;
  while (file >> value) {
    head = appendNode(head, value);
  }
  file.close();
  return head;
}