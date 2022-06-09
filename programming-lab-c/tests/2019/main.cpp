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
    No<N> *aux = root;

    if(root == NULL) {
      root = novoN;
      return true;
    }

    do {
      if((aux->value) == (novoN->value)) {return false;}

      if((novoN->value) > (aux->value)) {
        if(aux->pDireita == NULL) {
          aux->pDireita = novoN;
          return true;
        }
        else
          aux = aux->pDireita;
      }
      else {
        if(aux->pEsquerda == NULL) {
          aux->pEsquerda = novoN;
          return true;
        }
        else
          aux = aux->pEsquerda;
      }
    } while(true);

  }
  bool buscarNo(N val) {
    No<N> *aux = root;

    if(root == NULL) {return false;}
    do {
      if((aux->value) == val) {return true;}

      if(val > (aux->value)) {
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

  

  cout << ar.buscarNo(25) << endl;

  return 0;
}