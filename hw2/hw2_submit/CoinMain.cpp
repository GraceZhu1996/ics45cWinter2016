/*2. (20 points) Write a better main that does the following scenario:
Create two Coins objects: 
pocket:  5 q, 3 d, 6 n, 8 p
piggyBank:  50 q, 50 d, 50 n, 50 p


Buy a bag of chips that costs 68 cents taking the coins from your pocket. Display what's left in your pocket.
Transfer a bunch of coins from you piggyBank to your pocket. Display how much you now have in both.
While vacuuming, you find loose change in your sofa. Put it in your piggyBank. Display how much you now have in your piggyBank.
To enter the amount found in your sofa just create a new object with the number of coins found.
Turn in listings of Coins.h and your CoinMain.cpp files along with output from the test runs of your program.*/
#include "Coins.h"
const int CENTS_PER_CHIPS = 68;
const int CENTS_TO_POCKET = 500;
int main()
{
	Coins pocket(5, 3, 6, 8), piggyBank(50, 50, 50, 50);
	cout << "I started with " << pocket << " in my pocket" << endl;
	cout << "I started with " << piggyBank << " in my piggyBank"<< endl;
	Coins payforChips = pocket.extractChange( CENTS_PER_CHIPS);
	cout << "I bought a bag of chips for "<< CENTS_PER_CHIPS
		 << " cents using " << payforChips << endl;
	cout << " I have " << pocket << " left in my pocket" << endl;
	Coins toPocket = piggyBank.extractChange(520);
	pocket.depositChange(toPocket);
	cout << "I transfer " << toPocket << " to pocket" << endl;
	cout << "I have " << pocket << " in my pocket" << endl;
	cout << "I have " << piggyBank << " in my piggyBank" << endl;
	Coins FoundOnSofa(3,2,4,0);
	piggyBank.depositChange(FoundOnSofa);
	cout << "I found " << FoundOnSofa << " while vacuuming and put it in my piggy Bank" << endl;
	cout << "I have " << piggyBank << " in my piggyBank" << endl;
	return 0;
	
	
	
	
}
