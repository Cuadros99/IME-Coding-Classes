#include <iostream>

using namespace std;

template <unsigned i> struct Fibonacci {
  static const unsigned result =
    Fibonacci<i-1>::result + Fibonacci<i-2>::result;
};
template <> struct Fibonacci<1> {
  static const unsigned result = 1;
    
};
template <> struct Fibonacci<2> {
  static const unsigned result =1;
};


int main() {

  cout << Fibonacci<6>::result <<endl;

  return 0;
}