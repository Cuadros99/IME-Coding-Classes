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

Node* retrieveTree(Node preorder[], Node inorder[], int pr_begin, int pr_end, int in_begin, int in_end) {
  int index = in_begin, leftSize = 0, rightSize=0;

  //Handle the trivial case
  if(in_begin == in_end) {
    return &preorder[pr_begin];
  }
  
  Node aux = preorder[pr_begin];

  // Search the first element of PREORDER in INORDER
  for( ; index<=in_end ; index++) {
    if(inorder[index] == aux) break;
  }
  leftSize = index - in_begin;
  rightSize = in_end - index;
      
  if(leftSize>0)
    preorder[pr_begin].pLeft = retrieveTree(preorder, inorder, pr_begin + 1, pr_begin + leftSize, in_begin, index - 1);
  
  if(rightSize>0)
    preorder[pr_begin].pRight = retrieveTree(preorder, inorder, pr_begin + leftSize + 1, pr_end, index + 1, in_end);
  
  return &preorder[pr_begin];
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
  
  Node preorder[7] = {nA, nB, nC, nD, nE, nF, nG};
  Node inorder[7] = {nD, nC, nB, nE, nA, nF, nG};

  tr1.pRoot = retrieveTree(preorder, inorder, 0, 6, 0, 6);

  
  

  tr1.preorderTraversal();
  tr1.inorderTraversal();

  

  return 0;
}