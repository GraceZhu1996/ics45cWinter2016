/*
zhaohuaz 52082740
Coins.h

*/
#ifndef COINS_H_
#define COINS_H_

// Coins.h		///  The name of this file.
#include <iostream>
using namespace std;
const int CENTS_PER_QUARTER = 25, CENTS_PER_DIME = 10, CENTS_PER_NICKEL = 5;
class Coins
{
public:
  Coins( int q, int d, int n, int p ){
	  quarters = q;
	  dimes = d;
	  nickels = n;
	  pennies = p;
  }
  void depositChange( Coins & c ){
	  // note you can pass c by reference
	  quarters += c.quarters;
	  dimes += c.dimes;
	  nickels += c.nickels;
	  pennies += c.pennies;
  }
  bool hasSufficientAmount( int amount ){
	  return amount <= quarters*CENTS_PER_QUARTER + dimes*CENTS_PER_DIME + nickels*CENTS_PER_NICKEL + pennies;
  }
  Coins extractChange( int amount ){
	  // note a few tricky issues
	  if (! hasSufficientAmount(amount)){
		  //cout << "Sorry, cannot extract change because there is no sufficient amount in your pocket.";
		  return Coins(quarters, dimes, nickels, pennies);
	  }
	  else{
		  if(amount - pennies <= 0){//number of pennies in the pocket is sufficient
			  pennies -= amount;
			  return Coins(0, 0, 0, amount);
		  }
		  else if(amount - nickels * CENTS_PER_NICKEL - pennies <= 0){
              //only pennies, insufficient; with nickles, sufficient
			  int nickels_used = amount/CENTS_PER_NICKEL;
			  if (nickels_used > nickels){
				  nickels_used = nickels;
			  }
			  int pennies_used = amount - nickels_used * CENTS_PER_NICKEL;
			  nickels -= nickels_used;
			  pennies -= pennies_used;
			  return Coins(0, 0, nickels_used, pennies_used);
		  }
		  else if(amount - dimes * CENTS_PER_DIME - nickels * CENTS_PER_NICKEL - pennies <= 0){
              //only nickles and pennies, insufficient; dimes, sufficient
			  int dimes_used = amount/CENTS_PER_DIME;
			  if (dimes_used > dimes){
				  dimes_used = dimes;
			  }
			  int nickels_used = (amount - dimes_used * CENTS_PER_DIME)/CENTS_PER_NICKEL;
			  if (nickels_used > nickels){
				  nickels_used = nickels;
			  }
			  int pennies_used = amount - dimes_used * CENTS_PER_DIME - nickels_used * CENTS_PER_NICKEL;
			  dimes -= dimes_used;
			  nickels -= nickels_used;
			  pennies-= pennies_used;
			  return Coins(0, dimes_used, nickels_used, pennies_used);
		  }
		  else{
			  //only dimes, nickles, pennies, insufficient; quarters, sufficient
			  int quarters_used = amount/CENTS_PER_QUARTER;
			  if (quarters_used > quarters){
				  quarters_used = quarters;
			  }
			  int dimes_used = (amount - quarters_used * CENTS_PER_QUARTER)/CENTS_PER_DIME;
			  if (dimes_used > dimes){
				  dimes_used = dimes;
			  }
			  int nickels_used = (amount -quarters_used * CENTS_PER_QUARTER -  dimes_used*CENTS_PER_DIME)/CENTS_PER_NICKEL;
			  if (nickels_used > nickels){
				  nickels_used = nickels;
			  }
			  int pennies_used = (amount - quarters_used * CENTS_PER_QUARTER - dimes_used * CENTS_PER_DIME - nickels_used * CENTS_PER_NICKEL);
			  quarters -= quarters_used;
			  dimes -= dimes_used;
			  nickels -= nickels_used;
			  pennies -= pennies_used;
			  return Coins(quarters_used, dimes_used, nickels_used, pennies_used );
		  }			 
		  }		  
		
  }
  void print( ostream & out ){
	  out << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, " << pennies <<" pennies ";
  }
private:
  int quarters, dimes, nickels, pennies;
};
ostream & operator << ( ostream & out, Coins & c ){
	c.print(out);
	return out;
}
#endif /* COINS_H_ */
