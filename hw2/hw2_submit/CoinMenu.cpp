/*3. (30 points) Write a third main that presents a (text-based) menu interface to your program that
  allows the user to deposit change, extract change, and to print the balance in a single coins object
  called myCoins. Be sure you don't allow someone to extract more money than they have. (Yes, I know
  this is probably trivial for most of you, but I want you to get some practice with the C++ while and switch).*/

#include "Coins.h"
int main (){
	char  command = '\0';
	cout << "Welcome to the Coin program!";
	Coins myCoins(0,0,0,0);
	while(command != 'q' ){
		cout << "Enter Deposit change(d), Extract change(e), Quit(q): "<< endl;
		cin >> command;
		switch(command){
		case ('d'):{
			int q, d, n, p;
			cout << "Please enter the amount you want to deposit "<< endl;
			cout << "quarters: ";
			cin >> q;
			cout << "dimes: ";
			cin >> d;
			cout << "nickels: ";
			cin >> n;
			cout << "pennies: ";
			cin >> p;
			Coins TOmyCoins(q, d, n, p);
			myCoins.depositChange(TOmyCoins);
			cout << "current balance in myCoins is " << myCoins << endl;
			break;
		}
		case ('e'):{
			cout << "Please enter the amount you want to extract: " << endl;
			int amount;
			cin >> amount;
			if (myCoins.hasSufficientAmount(amount)){
				Coins OUTmyCoins = myCoins.extractChange(amount);
				cout << "to extract amount " << amount << ",  extract "<< OUTmyCoins << " from myCoins"<< endl;
				cout << "current balance in myCoins is " << myCoins << endl;
			}
			else{
				cout << "Sorry, there is no sufficient amount in myCoins, can't extract."<< endl;
			}
			break;
		}
		case ('q'):
			cout << "Thank you, bye.";
			break;

		default:
			cout << "Sorry, the command \"" << command << "\" is not exisit, please try again."<< endl;
			break;
		}
	}
	return 0;
}