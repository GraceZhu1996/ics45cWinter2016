 #include "Integer.h"

Integer :: Integer( int i )
  : value(i)
{
  cout << "Integer " << value << " was just born.\n";
}
void Integer :: print( ostream & out )
{
  out << value;
}
int Integer :: getValue()
{
  return value;
}
void Integer :: setValue( int i )
{
  value = i;
}
Integer :: ~Integer()
{
  cout << "Integer " << value << " has just died.\n";
}
ostream & operator << ( ostream & out, Integer i )
{
  i.print( out );
  return out;
}