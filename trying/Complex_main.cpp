#include "Complex.h"
int main()
{
  Complex c1( 1.5, 5.3); /// c1 is born
  Complex c2( 2.5, 2.7 ); /// c2 is born
  c1.print( cout );
  c2.print( cout );
  {
    Complex result; /// What happens here? Note no parens!!!
    result.print( cout );
    result = c1.add( c2 );  /// and here??
    result.print( cout );
  } /// and here???
  c1 = Complex( 2.0, 3.0 ); /// a literal Complex number
  c1.print( cout );
  return 0;
} /// and here????
