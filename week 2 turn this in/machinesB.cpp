/*******************************************************************
* Author: Tatyana Vlaskin
* Description:
*   Program asks a user to input the number of coupons and outputs
*   how many candies and ballgums they can get if coupons are redeemed.
*   Program also let the user know if there are any coupons left. 10
*   coupons is redeemable for candy bar and 3 coupons for gumball.
*   Program makses an assumption that user prefers candies over
*   gumballs.
* Input: User inputs number of coupons that they want to redeem
* Output:
How many coupons did you win? l
Your entry is invalid. Please make a valid entry.
How many coupons did you win? 20
You can get 2 candy(ies) and 0 gum(s).
You have 0 coupons left.
Process returned 0 (0x0)   execution time : 4.430 s
Press any key to continue.

OR

How many coupons did you win? 5
You can get 0 candy(ies) and 1 gum(s).
You have 2 coupons left.
Process returned 0 (0x0)   execution time : 1.310 s
Press any key to continue.



*
* Last Modification date: 04.13.2014
* File name: machinesB
********************************************************************/

#include <iostream> //Macro that includes librar
#include <math.h> // Includes math library
using namespace std; //Global statment

int main () //Main function
{

 int coupons, candy =0, gum=0, couponsLeft=0;
    cout << "How many coupons did you win? ";
    cin >> coupons;

    //this was not corered in the class. See http://www.cplusplus.com/forum/beginner/49969/
    if (!cin.good())
    {
        cout << "Your entry is invalid. Please make a valid entry. \n";
        cin.clear ();
        cin.sync ();
        cout << "How many coupons did you win? ";
        cin >> coupons;
    }
    //{
      //while loop to remove coupons for each candy
    //this loop is eneters if there are 10 or more coupons left
    while (coupons >= 10 )  //need at least 10 coupons to get a candy
    {
        coupons = (coupons - 10);   //removes coupons for each candy
        candy++;// counts candies
    }

    //while loop to remove coupons for each gum
    //loop is eneted when there are < 10, but >= 3 coupons
    while (coupons < 10 && coupons >= 3)
    {
        coupons = (coupons - 3);   //removes coupnons for each gum
        gum++;//    counts gums
    }

    cout << "You can get " << candy << " candy(ies) and "
    << gum << " gum(s).\n"
    << "You have " << coupons << " coupons left.";

    //while (!(cin >> (coupons));
   // cout << "Your entry is invalid. ";
    return 0;

}


