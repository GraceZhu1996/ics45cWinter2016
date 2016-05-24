#include <iostream>
using namespace std;
class Complex
{
public:
  float re, im;
  Complex( float newRe = 0.0, float newIm = 0.0 )
    : re( newRe ), im( newIm )
  {
    cout << "Complex number ";
    print( cout );
    cout << " is born.\n";
  }
  Complex add( Complex c )
  {
    return Complex( re + c.re, im + c.im );
  }
  void print( ostream & out )
  {
    out << "(" << re << "+" << im << "i)";
  }
  ~Complex()
  {
  }
};
