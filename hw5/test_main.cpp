#include "String.h"
int main(){
	String firstString("First");
	String secondString("Second");
	String thirdString(firstString);
	String fourthString("Fourth");
	String fifthString = String();

	cout << "+: " << firstString + secondString << endl;
	cout << "+=: " << (firstString += secondString) << endl;
	cout << "indexOf(char): " << firstString.indexOf('t') << endl;
	cout << "LT: " << (secondString < firstString) << endl;
	cout << "<<: "<< fifthString << endl;
	cout << "<<: "<< fourthString << endl;
	cout << "==: " << (fifthString == fourthString) << endl;
	cout << "[]: "<< thirdString[1] << endl;
	fifthString = thirdString;
	cout << "<<: " << fifthString << " " << thirdString << endl;
	cout << "[]: "<< fifthString[1] << endl;
	cout << "[]: "<< fifthString[10] << endl;

	cout << "Enter a test string: ";
	cin >> firstString;
	cout << firstString << endl;

	cout << (firstString < secondString) << endl;
	cout << (firstString == thirdString) << endl;
	cout<< "test DeleteNode";
	cout << firstString;
	firstString.deleteNode(3);
	cout  << firstString;


	return 0;
}
//g++ -std=c++0x String.cpp test_main.cpp -o test
//valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./test