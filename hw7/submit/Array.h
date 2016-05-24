#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <iomanip>
#include "IndexOutOfBoundsException.h"
//using namespace std;
template
< typename T>
class Array
{
private:
	int len;
	T * buf;

public:
    Array(int newLen):len( newLen ), buf(new T[newLen]){}

    Array ( const Array& l): len( l.len ),buf(new T[l.len])
		{

			for ( int i = 0; i < l.len; i++ )
				buf[i] = l.buf[i];
		}

	int length()
		{
			return len;
		}
	T & operator [] ( int i )
		throw (IndexOutOfBoundsException)
		{
			if (!(0 <= i && i < len))
			{
				throw (IndexOutOfBoundsException());
			}
			return buf[i];
		}

	void print( std::ostream & out )
		{
			for (int i = 0; i < len; i++)
			    out << std::setw(5) << std::setprecision(2) << std::fixed << buf[i];
		}
	friend std::ostream & operator << ( std::ostream & out, Array & a )
		{
			a.print(out);
			return out;
		}

	friend std::ostream & operator << ( std::ostream & out, Array * ap )
		{
			ap->print(out);
			return out;
		}
  // note the overloading of operator << on a pointer as well
	~Array()
		{
			delete[] buf;
		}
};






#endif
