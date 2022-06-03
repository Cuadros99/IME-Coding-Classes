#include <iostream>
#include <cmath>

using namespace std;

class Node {
public:
  char value;
  Node *pRight,*pLeft;
  Node(char value):
    value(value), pLeft(NULL), pRight(NULL) {
  }
  Node(const Node &n):
    value(n.value), pLeft(n.pLeft), pRight(n.pRight) {
  }

  bool operator==(Node &n) {
    return value == n.value;
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

Node* retrieveTree(Node preoder[], Node inorder[], int pr_begin, int pr_end, int in_begin, int in_end) {
  int lenght = sizeof(preoder)/sizeof(preoder[0]);
  int index = 0, size = 0;


// 1. Take the first element in the PREORDER
// 2. Search this element in the INORDER 
// 3. retrieveTree(left subtree traversals)
// 4. retrieveTree(right subtree traversals)
// 5. return the element found in the first step

  //Handle the trivial case
  if(pr_begin == pr_end) {
    return &preoder[pr_begin];
  }
  
  Node aux = preoder[pr_begin];

  // Search the first element of PREORDER in INORDER
  for( ; index<lenght ; index++) {
    if(inorder[index] == aux) break;
  }
  size = index - pr_begin;
  preoder[pr_begin].pLeft = retrieveTree(preoder, inorder, pr_begin + 1, pr_begin + size, in_begin, index - 1);
  preoder[pr_begin].pRight = retrieveTree(preoder, inorder, pr_begin + size + 1, pr_end, index + 1, in_end);
  
  return &preoder[pr_begin];
}

int main() {


  Tree tr1;


  Node nA('A');
  Node nB('B');
  Node nC('C');
  Node nD('D');
  Node nE('E');
  Node nF('F');
  Node nG('G');
  
  Node preoder[7] = {nA, nB, nC, nD, nE, nF, nG};
  Node inorder[7] = {nD, nC, nB, nE, nA, nF, nG};

  tr1.pRoot = retrieveTree(preoder, inorder, 0, 7, 0, 7);


  tr1.preorderTraversal();
  tr1.inorderTraversal();

  

  return 0;
}