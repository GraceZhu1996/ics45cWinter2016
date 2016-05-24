
/*(40 points) Write another program that reads a sequence of integers from a file rand_numbers.txt here  this file. It should sort them, then write the odd ones to odd.txt file (separated by a space), then write the even ones to even.txt file, one per line.
 */
#include <iostream>
#include <set>
#include <fstream>
#include <algorithm>
using namespace std;


int main()
{
	multiset<int> S;
	ifstream in("rand_numbers.txt");
	for_each (istream_iterator<int>(in),
			  istream_iterator<int>(),
			  [&](int num){S.insert(num);});
	ofstream odd;
	ofstream even;
	odd.open("odd.txt");
	even.open("even.txt");
	for (auto E: S)
	{
		if (E%2 == 0)
		{
			even << E << " ";
		}
		else
		{
			odd << E << " ";
		}
	}
	odd.close();
	even.close();
	return 0;

}
