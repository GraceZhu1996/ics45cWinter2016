/*
zhaohuaz 52082740
homework1
question3
*/
#define STACK_CAPACITY 1000
#include <iostream>
using namespace std;
class Stack
{
private:
	char stk[STACK_CAPACITY];
	int tp;

public:
Stack(){
	tp = 0;
}

void push( char c ){
	if (isFull()){
		cout << "Error: the stack is full";
		}
	else{
		stk[tp++] = c;
		}
	}

char pop(){
if (tp >0) {
	tp--;
	}
return top();
}
char top()
{
	return stk[tp];
}

bool isEmpty()
{
	if (tp == 0){
		return true;
	}
	else{
		return false;
	}
}

bool isFull()
{
	if (tp == STACK_CAPACITY){
		return true;
	}
	else{
		return false;
	}
}
~Stack(){}; // destructor for a stack
};
