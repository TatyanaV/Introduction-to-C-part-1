
/*******************************************************************
* Author: Tatyana Vlaskin
* Description:
*  Program calculates how much money will be in the bank account after
specified number of years
* Input: User needs to principle, interest and number of years
* Output:
Please enter how much money you planning to deposit:  1000

Please enter anual interest: 10

Please enter number of years the money will accrue compound interst : 2

At the end of 2 years, you will have 1331 dollars.

Do you want to do another calculation? (Y/N)

* Last Modification date: 05.04.2014
* File name: problem6.cpp
********************************************************************/

#include <iostream>  //library for input and output
#include <string>    //library for stings
using namespace std; //global statment
// function decaltaion. lets the user enter a number and checks if its valid
double getdouble();
// function declaration. calculate how much money will be in the bank
double amount( double &principle, double rate, double years );

int main()
{
    double rate, years, principle; // variable declaration
    char tryAgain; //variable declaration
     do // if the user decides to repeat this calculation, this loop will be started
    {
        cout << "Please enter how much money you planning to deposit:  " ; // console  output
        principle = getdouble(); // function call to enter principle
        cout << endl << "Please enter anual interest: "; // console output
        rate = getdouble(); // function call to enter rate
        cout << endl << "Please enter number of years the money will accrue compound interst : "; // cobsole output
        years = getdouble(); // function call to enter years
        //lets the user know how much money will be in the bank at the end
        cout<<endl <<"At the end of "<< years << " years, you will have "<< amount(principle, rate, years ) <<" dollars." << endl;;
        cout << endl << "Do you want to do another calculation? (Y/N) ";// ask the use if they want to repeat calculation one more time
        cin >> tryAgain; // console input
    } while (tryAgain == 'y' || tryAgain == 'Y');  // calculation will be repeated if the user answers Y
    return 0;
}
// function definition. lets the user enter a number and check to make sure that its valid
double getdouble()
{
    for(;;) // equivalent to while (true) loop
    {
        double value; // variable declaration
        cin >> value; // console input lets the use enter a number
        if(cin.fail() || value < 0) // if cin is bad time or cin is a negative value.
        {  // if the user enters string, character.
        cin.clear();  // reset cin
        string garbage; // varible declaration to discard bad entry
        getline(cin, garbage); // ignore rest of line
        //console output. let the use know that entry is invalid
        cout << "\nINVALID ENTRY. Try again. ";
        }
    else // if the users input is valid, entered value is returned.
    {
                return value;
    }
  }
}
// calculates how much money will be in the end at the end of the term
double amount( double &principle, double rate, double years )
{
    // calculates new principle
     principle = principle + (principle* (rate/ 100)); //Incremented interest for the year
            if(years > 0.0)
           {
                // call the function if the there are more years left
               principle =  amount( principle, rate, (years-1.0));
            }
            return principle; // once years <=0, total amount is calculated.
                   }
