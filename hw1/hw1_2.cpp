/*
zhaohuaz 52082740
homework1
question2
*/

#include <iostream>
using namespace std;

double ans(int num)
{
    return num*6076/static_cast<double>(5280)/60;
}

int main()
{
    cout << "How many knots?\n";
    int num;
    cin >> num;
    cout << ans(num) <<" mile per minute\n";
}
