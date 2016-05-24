/*
zhaohuaz 52082740
homework1
question4
*/

/*
while not end of file
      read a line of input
      push the characters from the input line onto a stack
      while the stack is not empty
           print the character removed from the stack
      print a new line
      */

#include "Stack.h"
#include <iostream>
using namespace std;
int main(){

	std:: string input = " ";
	bool exit = true;
	while ( exit != false){
		Stack stk;
		cout << "Please enter a char string: \n";
		exit = getline(cin, input);
		for (int n = 0; n < input.length(); n++){
			stk.push(input.at(n));
		}
		while (! stk.isEmpty()){
			cout << stk.pop();
		}
		cout << endl;

	}
	return 0;
}
