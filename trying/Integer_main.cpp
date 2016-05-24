
#include "Integer.cpp"
using namespace std;

int main()
{
  Integer i = 20;
  {
    Integer j = 30;
    {
      Integer k(40);
      k.setValue( i.getValue() + j.getValue() );
      cout << "k is " << k << endl;
    }
    cout << "j is " << j << endl;
  }
  cout << "i is " << i << endl;
  return 0;
}
