#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
void printVector(const T *vector, int quantity) {
  for(int i=0; i<quantity; i++) {
    cout << vector[i] << " ";
  }
  cout << endl;
}


int main() {

  string words[3] = {"maçã", "abacate", "abacaxi"};
  int numbers[3] = {1, 2, 3};

  printVector(words, 3);
  printVector(numbers, 3);

  return 0;
}