/*******************************************************************
* Author: Tatyana Vlaskin
* Description:
*   Program asks a user to input an inter
*   and then repeats the number that was entered back to the user.
* Input: User needs to input a number
* Output:
*   First the user will see a statement:
*       Please enter an integer:
*   Once the user enters a number, the user will see the following
*   statement on the screen:
*   You have entered an integer: NUMBER ENTERED BY THE USER.
*   The variable to hold the user input will be declared as
*   int type. If the user tries to enter word or sentence, "0" will be
*   echoed back. If floating point number is entered, only number
*   before the decimal point will be displayed back.
*   The output will be to the screen and will have the form:
*       Please enter an integer: NUMBER ENTERED BY THE USER
*       You have entered an integer: NUMBER ENTERED BY THE USER.
* Last Modification date: 04.05.2014
* File name: echo
********************************************************************/
#include <iostream>     // Macro that includes library
using namespace std;    //Global statement

int main()      //Main function
{
	int number = 1;     //Variable Declaration (integer type)
	cout << "Please enter an integer: ";    //Prints message to the console
	cin >> number;  //Allows use to make an entry. Try to enter, number, word, sentence.
	cout << "You have entered an integer: " << number << endl;  //Prints message to the console
	 return 0;  //end of the function, returns non-error status
}

