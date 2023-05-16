#include <iostream>

using namespace std;

class Node {
  int value;
public:
  Node(int value): value(value) {}
  Node(const Node &n): value(n.value) {}
  Node(): value(0) {}
  ~Node() {
    cout << "Destruído" << endl;
  }
  int getValue() {
    return value;
  }
  void printValue() {
    cout << value <<endl;
  }
};

class NodesList {
  Node *list[8];
  int size, quantity;
public:
  NodesList(): list{NULL}, size(8), quantity(0) {}
  ~NodesList() {
    for(int i=0; i < quantity; i++) {
      delete list[i];
    }
  }
  bool insertNode(int value) {
    if(quantity == size) 
      return false;
    Node *nAux = new Node(value);
    list[quantity] = nAux;
    quantity++;
    return true;
  }
  void printList() {
    for(int i=0; i< size; i++) {
      if(list[i] == NULL) {
        cout << "NULL" << " ";
      }
      else{
        cout << list[i]->getValue() << " ";
      }
    }
    cout << endl;
  }
};

Node* createNode(int value) {
  Node *nAux = new Node(value);
  return nAux;
}

int main() {

  NodesList objectsList;
  
  objectsList.printList();
  
  objectsList.insertNode(10);
  objectsList.insertNode(30);
  objectsList.insertNode(20);

  objectsList.printList();

  return 0;
}