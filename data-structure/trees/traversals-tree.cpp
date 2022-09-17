#include <iostream>
#include <cmath>

using namespace std;

class Node {
public:
  char value;
  Node *pRight,*pLeft;
  Node(char value):
    value(value), pRight(NULL), pLeft(NULL) {
  }
};

class Tree {
public:
  Node *pRoot;
  Tree(): pRoot(NULL) {}
  void preorderTraversal() {
    cout << "Preorder Traversal: ";
    preorderAlgorithm(pRoot);
    cout << endl;
  }
  void inorderTraversal() {
    cout << "Inorder Traversal: ";
    inorderAlgorithm(pRoot);
    cout << endl;
  }
  void preorderAlgorithm(Node *pRt) {
    cout << pRt->value << " ";
    if(pRt->pLeft != NULL){
      preorderAlgorithm(pRt->pLeft);
    }
    if(pRt->pRight != NULL) {
      preorderAlgorithm(pRt->pRight);
    }
  }
  void inorderAlgorithm(Node *pRt) {
    if(pRt->pLeft != NULL){
      inorderAlgorithm(pRt->pLeft);
    }
    cout << pRt->value << " ";
    if(pRt->pRight != NULL) {
      inorderAlgorithm(pRt->pRight);
    }
  }
};

int main() {

  Tree tr1;
  Node nA('A');
  Node nB('B');
  Node nC('C');
  Node nD('D');
  Node nE('E');
  Node nF('F');
  Node nG('G');
  

  tr1.pRoot = &nA;
  nA.pLeft = &nB;
  nA.pRight = &nF;
  nB.pLeft = &nC;
  nB.pRight = &nE;
  nC.pLeft = &nD;
  nF.pRight = &nG;

  tr1.preorderTraversal();
  tr1.inorderTraversal();

  return 0;
}