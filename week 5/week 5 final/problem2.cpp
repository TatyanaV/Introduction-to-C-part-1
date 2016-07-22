/*******************************************************************
* Author: Tatyana Vlaskin
* Description:
* Program accepts 2 strings and compares them.
* Input: User inputs 2 string.
* Output:
Input string # 1: kjdasdja

Input string # 2: djdjdjdj

Strings are different.

ALPHABETIC DIFFERENCE:
Here are the strings that you've entered sortred alphabetically:
djdjdjdj
kjdasdja

LENGTH DIFFERENCE:
String 1: kjdasdja has 8 characters.
String 2: djdjdjdj has 8 characters.
String: djdjdjdj is longer than  string: kjdasdja

Would you like to use the program one more time?
Press Y to use the program again. Press N to end the game. y

Input string # 1: mom

Input string # 2: mom

Strings are the same.
Would you like to use the program one more time?
Press Y to use the program again. Press N to end the game.
* Last Modification date: 05.04.2014
* File name: problem2.cpp
********************************************************************/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
// function definition to accept input of 2 strings
void userInput(string& string1, string& string2);
//function declaration to compare strings
void stringCompare (string string1, string string2);

int main( )
{
    bool playAgain = true;
    //loop is entered if user # 2 decided to play again
    while (playAgain == true)
    {
        string string1 = "Initial1";
        string string2 = "Initial2";
        userInput(string1, string2);
        //declaration of the variable for a user to decide if
        //they want to play again
        char decision;
        //asks the user if they want to play a game one more time
        cout << "Would you like to use the program one more time?\n"
        //lets the user that they can either chose N or Y
        << "Press Y to use the program again. Press N to end the game. ";
        cin >> decision; // allows the user to make a decision
        cout << endl;

            //  executed only if  user does not want to play again need a n or no answer
        if ( toupper(decision) == 'N')
        {
            playAgain = false; // change the bool to false and paly again loop is not entered

        }
         //out << endl;
         cin.ignore();
    }
   //cout << endl;
    return 0; //closing
     //cout << endl;
}

void userInput(string& string1, string& string2)
{
        //string string1, string2;// strings declaration
        cout << "Input string # 1: "; // console output
        getline(cin, string1); // console input string 1
        cout << endl;
        cout << "Input string # 2: "; //console output
        getline(cin, string2); //console input string 2
        cout<<endl;
        stringCompare(string1, string2);
}
// function definition that compares strings
void stringCompare (string string1, string string2){

     if ((string1) == (string2))// if strings are identical. Please note that
     //if this comparison is case sensitive. MOM and mom will be considered as different strings
     {
        cout << "Strings are the same. \n";// console output
     }
     else // if strings are different
     {
        cout << "Strings are different. \n"; //comsole putput
        cout << endl;
        //Display strings in alphabetical order
        cout << "ALPHABETIC DIFFERENCE: \n";
        cout << "Here are the strings that you've entered sortred alphabetically: \n";
    if (string1 < string2) // if string 1 is shorter than string 2
    {
        cout << "1. " + string1 << endl << "2. " + string2 << "\n";
        cout << endl;
    }
    else if (string1 > string2)// if string 2 is shorter than string 1
    {
        cout << string2 << endl << string1 << "\n";
        cout << endl;
    }
// lets the user know how long are the strings
    cout << "LENGTH DIFFERENCE: \n";
    cout << "String 1: " << string1 + " has " << string1.length() << " characters." << endl;
    cout << "String 2: " << string2 + " has " << string2.length() << " characters." << endl;
   // lets the user know which string is longer
    if (string1.length() > string2.length())
    {
       cout << "String: " + string1 + " is longer than" + " string: " + string2 << "\n";
       cout << endl;
    }
    else
        cout << "String: " + string2 + " is longer than" +  " string: " + string1 << "\n";
        cout << endl;
     }

}
