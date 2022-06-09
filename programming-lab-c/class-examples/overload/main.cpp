#include <iostream>
// #include <cmath>

using namespace std;

class Complex {
  float re, im;
public:
  Complex(float re, float im): re(re), im(im) {}
  friend ostream& operator<<(ostream &os, const Complex &c);
  Complex& operator++() {
    re++;
    im++;
    return *this;
  }
  Complex operator++(int) {
    Complex temp(re,im);
    re++;
    im++;
    return temp;
  }

  operator int(){
    return re;
  }
};

ostream& operator<<(ostream &os, const Complex &c) {
  os << c.re << (c.im > 0 ? "+" : "")  << c.im << "i" << endl;
  return os;
}

int main() {

  Complex c1(2,2);
  Complex c2(1,-2);

  cout << (int)c1 << endl;

  return 0;
}