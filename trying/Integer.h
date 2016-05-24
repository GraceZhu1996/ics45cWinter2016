 #include <iostream>
using namespace std;

class Integer
{
private:
  int value;
public:
  Integer( int i = 0 );
  void print( ostream & out );
  int getValue();
  void setValue( int i );
  ~Integer();
};
ostream & operator << ( ostream & out, Integer i );
