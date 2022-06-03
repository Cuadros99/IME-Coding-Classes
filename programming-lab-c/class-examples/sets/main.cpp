#include <iostream>

using namespace std;

template <typename T>
class Conjunto {
  int capacidade, total;
  T *elems;
public:
  Conjunto(int capacidade)
  try 
    :capacidade(capacidade), total(0),elems(new T[capacidade]) {
    }  
  catch(...) {
    cout << "erro na alocacao" << endl;
  }
  ~Conjunto() {
    try {
      delete[] elems;
    }
    catch(...) {
    }
  }
  Conjunto& operator+=(const T &valor) {
    if(total == capacidade)
      return *this;
    for(int i=0; i<total; i++)
      if(elems[i]==valor)
        return *this;
    elems[total++] = valor;
    return *this;
  }
  Conjunto& operator+=(const Conjunto &ca) {
    for(int i=0; i < ca.total; i++) {
      *this += ca.elems[i];
    }
    return *this;
  }
  void operator!() {
    for(int i=0; i<total; i++)
      cout << elems[i] << " ";
    cout << endl;
  }
};




int main() {

  Conjunto <int> c1(10);
  Conjunto <int> c2(10);

  (c1+=5) +=4;
  (c2+=5) +=3;
  !c1;

  !(c1+=c2);


  return 0;
}