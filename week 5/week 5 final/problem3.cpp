
/*******************************************************************
* Author: Tatyana Vlaskin
* Description:
*  User inputs three integers and they are sorted from smallers to largerst
* Input: 3 numbers
* Output:
This program will sort 3 integers.

You are allowed to enter a floating-point number.
However, please note that all digits after decimal point will be deleted.
For example if  you enter 2.8 it will be converted to 2.

You are allowed to enter same number twice.

Please enter 1st integer: 1
Please enter 2nd integer: 90
Please enter 3rd integer: 4

Sorted: 1, 4, 90
Do you want to sort another set? (Y/N)

* Last Modification date: 5.04.2014
* File name: problem3.cpp
********************************************************************/
#include <iostream>  //library for input and output
#include <string>    //library for stings
using namespace std; //global statment

// displays information about the game to the user
void message();
// Function Declaration. This function lets the user to enter a number, and checks to make sure
//that entered number
double getdouble();
// function to sort 2 values
void sort1(int &n, int &m);
// function to sort 3 values
void sort (int &value1, int &value2, int &value3);

int main()
{
    int temp=0;
    int value1, value2, value3;
    char tryAgain; //variable declaration
    do // if the user decides to repeat this calculation, this loop will be started
    {
        message(); // informs user what are the rules and what they need to do
        cout << "Please enter 1st integer: "; // console  output
        value1 = getdouble(); // value 1
        cout << "Please enter 2nd integer: "; // console output
        value2 = getdouble();// function call to enter 2nd value
        cout << "Please enter 3rd integer: "; // cobsole output
        value3 = getdouble(); // function call to enter 3rd value
        sort (value1, value2, value3); // function call to sort 3 values
        cout << endl << "Sorted: " << value1 << ", " << value2 << ", " << value3;
        cout << endl << "Do you want to sort another set? (Y/N) ";
        cin >> tryAgain; // console input
    } while (tryAgain == 'y' || tryAgain == 'Y');  // calculation will be repeated if the user answers Y
    return 0;
}
// function definition to display message to the user
void message(){
        cout << "This program will sort 3 integers. " << endl << endl;
        cout << "You are allowed to enter a floating-point number. " << endl;
        cout << "However, please note that all digits after decimal point will be deleted." <<endl;
        cout << "For example if  you enter 2.8 it will be converted to 2. " << endl << endl;
        cout << "You are allowed to enter same number twice. " << endl << endl;
       }
// function definition to check if the entry made by the user is valid
double getdouble()
{
    for(;;) // equivalent to while (true) loop
    {
        double value; // variable declaration
        cin >> value; // console input lets the use enter a number
        if(cin.fail()) // if cin is bad time or cin is a negative value.
        {  // if the user enters string, character.
        cin.clear();  // reset cin
        string garbage; // varible declaration to discard bad entry
        getline(cin, garbage); // ignore rest of line
        //console output. let the use know that entry is invalid
        cout << "\nINVALID ENTRY. Try again. ";
        }
    else // if the users input is valid, entered value is returned.
    {
        value = static_cast<int>(value);
        return value;
    }
  }
}
//function definition, where 2 unsorted values entered by the user are sorted
// if x > y values need to be swapped, if x<y, values are already sorted
void Sort1(int &x, int &y)
{
    int temp;
    if (x > y)
    {  // temp is initialized only if x > y; otherwise x < y ( values are already sorted)
        temp= x;
        x= y;
        y= temp;
    }
}
//functio definition to sort 3 values entered by the user
void sort (int &value1, int &value2, int &value3){

Sort1(value1, value2);
Sort1(value1, value3);
Sort1(value2, value3);
}
