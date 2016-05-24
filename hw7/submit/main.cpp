/*(20 points) Get your Matrix to work with the following main (put it in main.cpp which includes Matrix.h). Test your matrix for at least two different element types (such as int and double), but feel free to try something else. I wrote all this off the top of my head (without compiling), so there may be some errors, but it will be good practice for you to eliminate them.
 */

#include "Array.h"
#include "Matrix.h"
#include "IndexOutOfBoundsException.h"
using namespace std;
template< typename T >
void fillMatrix( Matrix <T> & m )
{

  int i, j;
  for ( i = 0; i < m.numRows(); i++ )
    m[i][0] = T();
  for ( j = 0; j < m.numCols(); j++ )
    m[0][j] = T();
  for ( i = 1; i < m.numRows(); i++ )
    for ( j = 1; j < m.numCols(); j++ )
    {
      m[i][j] = T(i * j);
    }
}
template < typename T>
void testExceptions(Matrix<T>& m, int row, int col = 0)
{
	try
	{
    
		m[row][col];
	}

	catch ( IndexOutOfBoundsException & e)
	{
		cout << "col " << col << " or row " << row<< " out of bounds\n";
	}

}
void test_int_matrix()
{ // here is a start, but make it better
    Matrix < int > m(10,5);
    fillMatrix( m );
    cout << m << endl;
    // PUT YOUR TRY/CATCH HERE AND TEST EXCEPTIONS
	cout << "start to test exceptions for int matrix" << endl;
	cout << "try m[11][0] (matrix row out of bounds)" << endl;
	testExceptions<int>(m, 11);
	cout << "try m[9][6] (inner array out of bounds)" << endl;
	testExceptions<int> (m, 9, 6);
	cout << "try m[11][6] (both matrix row and inner array out of bounds)" << endl;
	testExceptions<int>(m, 11, 6);
}
void test_double_matrix()
{ // you get to write this entire function
    Matrix < double > M(8,10);
    fillMatrix( M );
    cout << M;
	cout << "start to test exceptions for double matrix" << endl;
	cout << "try m[11][0] (matrix row out of bounds)" << endl;
	testExceptions < double > (M, 11);
	cout << "try m[7][11] (inner array out of bounds)" << endl;
	testExceptions < double > (M, 7, 11);
	cout << "try m[11][11] (both matrix row and inner array out of bounds)"
		 << endl;
	testExceptions < double > (M, 11, 11);

}


int main()
{
   test_int_matrix();
   test_double_matrix();
   return 0;
}
