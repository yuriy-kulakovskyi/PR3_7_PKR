#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct Node {
  int value;
  Node* next;
};

Node* createNode(int value);
Node* appendNode(Node* head, int value);
void printList(Node* head, const std::string& title);
void replaceValues(Node* head, int m, int n);
void deleteList(Node* head);
Node* createListFromKeyboard();
Node* createListFromFile(const std::string& filename);


#endif //FUNCTIONS_H