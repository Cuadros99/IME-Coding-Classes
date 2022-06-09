#include <iostream>
#define N 2

using namespace std;

template <unsigned i, unsigned type> struct Nonacci;

template <unsigned i, unsigned type>
unsigned somatory() {
  int result = 0;
  for(int j=1; j<=type; j++) {
    int num = i-j;
    result =+ Nonacci<num>::result;
  }
}

template <unsigned i, unsigned type> struct Nonacci {
  static const unsigned result = somatory<i,type>();
};

template<unsigned type>
void firstElements() {
  for(int j=1; j<=type; j++) {
    struct Nonacci<j,type> {
      static const unsigned result = 1;   
    };
  }
}

int main() {

  cout << Nonacci<3,N>::result <<endl;



  cout << N <<endl;

  return 0;
}