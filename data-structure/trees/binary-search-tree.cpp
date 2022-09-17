#include <iostream>

using namespace std;

template <typename N>
class Arvore;

template <typename N>
class No {
  N value;
  No *pDireita, *pEsquerda;
public:
  No(N value): value(value), pDireita(NULL), pEsquerda(NULL) {}
  friend class Arvore<N>;
};

template <typename N>
class Arvore {
  No<N> *root;
public:
  Arvore(): root(NULL) {}
  bool inserirNo(No<N> *novoN) {
    No<N> *aux;

  bool searchResult = buscarNo(novoN, &aux);

    if(searchResult)
      return false;

    if(aux == NULL) {
      root = novoN;
      return true;
    }
    if(novoN->value > aux->value)
      aux->pDireita = novoN;
    if(novoN->value < aux->value)
      aux->pEsquerda = novoN;
    return true;
  }
  No<N>* buscarNo(No<N> ns, No<N> **aux) {
    *aux = root;

    if(root == NULL) {return false;}
    do {
      if((aux->value) == ns.value) {return true;}

      if(ns.value > (aux->value)) {
        if(aux->pDireita == NULL) {
          break;
        }
        else
          aux = aux->pDireita;
      }
      else {
        if(aux->pEsquerda == NULL) {
          break;
        }
        else
          aux = aux->pEsquerda;
      }
    } while(true);

    return false;
  }
};

int main() {

  Arvore<int> ar;
  No<int> n1(10);
  No<int> n2(20);
  No<int> n3(5);
  No<int> n4(7);

  ar.inserirNo(&n1);
  ar.inserirNo(&n2);
  ar.inserirNo(&n3);
  ar.inserirNo(&n4);

  


  return 0;
}