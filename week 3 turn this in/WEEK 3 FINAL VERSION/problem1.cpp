
/*******************************************************************
* Author: Tatyana Vlaskin
* Description:
*   Program asks a user to input a word and prints that word in forward,
and reverse direction as well as the number of characters in the word is
given.
* Input: User inputs one string
* Output:
Please type in a string: Hello World!
String is printed in forward direction:
H
e
l
l
o

W
o
r
l
d
!
String is printed in reverse direction:
!
d
l
r
o
W

o
l
l
e
H
Number of charactes, INCLUDING whitespace: 12
Number of charactes, EXCLUDING whitespace: 11
* Last Modification date: 04.20.2014
* File name: problem1.cpp
********************************************************************/
#include <iostream>
#include <string> // gives a sting funcition
using namespace std;

int main () {
    int length; // declares variable lenght
    string my_str; // declares variable string
    cout << "Please type in a string: "; // console output
    getline (cin, my_str); //console input
        // asks the user to enter a string
        cout << "String is printed in forward direction: \n";
        // loop that prints a string one character at a time
        for (int i = 0; i < my_str.length(); i++)
        {
            cout << my_str.at(i) << endl;
        }

        cout << "String is printed in reverse direction: \n";// console output
        // loop to display string one character at a time in reverse direction
        for (int i = (my_str.length()-1); i >=0 ; i --)
        {
            cout << my_str.at(i) << endl; // console output
        }
        // loop determines how many charactes are there in the string
        // PLEASE NOTE WHITESPACE IS COUNTED AS A CHARACTER AS WELL
        //WHITESCAPE INCLUSIVE LENGTH
        for(int i =0; i < my_str.size();i++)
        {
	    length = i+1;
        }
        cout << "Number of charactes, INCLUDING whitespace: " << length << endl;
        // loop to determine how many characters are in the string
        // WHITE SPACE IS EXTCLUDED. ONLY LETTERS ARE COUNTED
        int numberOfChars = my_str.length (); // declare and initialize number of charactres variable

        for (unsigned int i =0; i < my_str.length(); i++) // loops through the string
        {
            if (my_str.at(i) == ' ') // if the character is a whitespace
            {
                numberOfChars--; // decrement numberOfCharse each time whitespace is encountered.
            }
        }

        //lets the user know how many character are there in as string
         cout << "Number of charactes, EXCLUDING whitespace: " << numberOfChars << endl;
    return 0;
}
