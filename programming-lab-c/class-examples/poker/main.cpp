#include <iostream>

using namespace std;

enum eValue {
  DOIS, TRES, QUATRO, CINCO, SEIS, SETE, OITO, NOVE, DEZ, VALETE, DAMA, REI, AS
};
string values[] = {" 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", "Va", "Da", "Re", "As"};

enum eSuits {
  OUROS, ESPADAS, COPAS, PAUS
};
string suits[] = {"O", "E", "C", "P"};


class Card {
  eValue value;
  eSuits suit;
public:
  Card(eValue value, eSuits suit):
    value(value), suit(suit){
  }
  Card(const Card &c):
    value(c.value), suit(c.suit){
  }
};



int main() {

  cout << "Hello World" << endl;

  return 0;
}