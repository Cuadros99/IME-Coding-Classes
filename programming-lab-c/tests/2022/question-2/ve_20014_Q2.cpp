#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

template <typename T>
class vetorOrdenado {
  vector<T> valores;
  int capacidade, quantidade;
public:
  vetorOrdenado(int capacidade): valores({}), capacidade(capacidade), quantidade(0) {}
  ~vetorOrdenado() {
  }
  void inserirValor(T valor) {
    if(quantidade >= capacidade) {
      cout << "Vetor cheio" << endl;
      return;
    }
    valores.push_back(valor);
    sort(valores.begin(), valores.end());
    quantidade++;
  }
  void operator<<(ifstream &arquivo) {
    T novoValor;
    char lixo;
    while(!arquivo.eof()) {
      arquivo >> novoValor;
      inserirValor(novoValor);
      arquivo >> lixo;
    }
  }
  int operator+(T valor) {
    auto it = find(valores.begin(), valores.end(), valor);
    if(valores.end() == it) {return capacidade+1;}
    return it - valores.begin();
  }
  template <typename U>
  friend ostream& operator<<(ostream &out, vetorOrdenado<U> &vt);
};

template <typename T>
ostream& operator<<(ostream &out, vetorOrdenado<T> &vt) {
  for(int i=0; i<vt.valores.size(); i++) {
    out << vt.valores[i];
    if((i+1)<vt.valores.size())
      cout << " - ";
  }
  out << endl;
  return out;
}

int main() {

  vetorOrdenado<float> vetor(5);

  ifstream arquivo("input.txt", ios::in);

  if(!arquivo.is_open()) {
    return 1;
  }

  vetor << arquivo;

  cout << vetor+1 << "ª posicao" << endl;

  cout << vetor;

  arquivo.close();

  return 0;
}