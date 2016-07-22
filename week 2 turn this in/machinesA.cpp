/*******************************************************************
* Author: Tatyana Vlaskin
* Description:
*   Program asks a user to input the number of coupons and outputs
*   how many candies and ballsgums they can get if coupons are redeemed.
*   Program also let the user know if there are any coupons left. Program
*   is written by making an assumption that user prefers candies over
*   gumballs.
* Input: User inputs number of coupons that they want to redeem
* Output:
How many coupons did you win? 20
You can get 2 candy(ies) and 0 gumball(s).
You still have 0 coupons left.
Process returned 0 (0x0)   execution time : 2.839 s
Press any key to continue.

OR

How many coupons did you win? p
Your entry is invalid. Please make a valid entry.
How many coupons did you win? 5
You can get 0 candy(ies) and 1 gumball(s).
You still have 2 coupons left.
Process returned 0 (0x0)   execution time : 9.016 s
Press any key to continue.

OR

How many coupons did you win? 20
You can get 2 candy(ies) and 0 gumball(s).
You still have 0 coupons left.
Process returned 0 (0x0)   execution time : 1.700 s
Press any key to continue.
* Last Modification date: 04.13.2014
* File name: coupa.cpp
********************************************************************/

#include <iostream> //Macro that includes librar
#include <math.h> // Includes math library
using namespace std; //Global statment

int main () //Main function
{
    int coupons =0, candy =0, gum=0, couponsLeft=0;//declaration and init.
    cout << "How many coupons did you win? "; //console output
    cin >> coupons; // console input
      //this was not covered in the class. See http://www.cplusplus.com/forum/beginner/49969/
    if (!cin.good())
    {
        cout << "Your entry is invalid. Please make a valid entry. \n";//lets the user know that entry is invalid
        cin.clear ();
        cin.sync ();
        cout << "How many coupons did you win? "; //if the entry is invalid console output
        cin >> coupons; //console input
    }
    //do
    //{
    candy = coupons/10; // number of candies that user can get
    gum = (coupons - candy*10)/3; // number of gums that user can get
   //CALCULATES HOW MANY coupons left
    couponsLeft = (coupons - (candy*10 + gum*3));
    //lets the user know how many candies and gums they can get
    cout << "You can get " << candy << " candy(ies) and " << gum << " gumball(s).\n"
    << "You still have " << couponsLeft << " coupons left.";
    //}
    // while (cin.good);
    return 0;
}

