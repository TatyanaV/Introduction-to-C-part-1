/*******************************************************************
* Author: Tatyana Vlaskin
* Description:
* The program asks a user for 2 numbers (one for the minimum and one for
* the maximum). After the user enters min and max, a random
* number is generated and dispalyed to the user. Onece the random number is
* displayed the user has an option to start the "random game" over.
* Input: User needs to input 2 numbers, one for min and one for max
* Output:
Please enter a number that will be assigned to MINIMUM: dfjskfjsldfslf

Your entry is INVALID. No more letters or random characters, please!
Please enter a number that will be assigned to MINIMUM: 5

Please enter a number that will be assigned to MAXIMUM.
Maximum has to be at least 15
Enter maximum: 2

Number that you've entered is too small to be a maximum.
Please enter a number that will be assigned to MAXIMUM.
Maximum has to be at least 15
Enter maximum: kdsjdhaskjfasjkfsfasfa

Your entry is INVALID. No more letters or characters, please!
Please enter a number that will be assigned to MAXIMUM.
Maximum has to be at least 15
Enter maximum: 29.888888

Random number between 5 and 29 is: 8

Does the user want to do this again?
Press Y to use the program again. Press N to end the game. y

Please enter a number that will be assigned to MINIMUM:

* Last Modification date: 04.20.2014
* File name: problem5.cpp
********************************************************************/

#include <iostream> //Macro that includes library
using namespace std; //Global statment
#include <cstdlib> // inlcudes reandom numberes library
#include <string> //uncludes string libary
int main () //Main function
{
    // variable declaration. user will be able to enter floating-point
    //values or integers
    double max, min;
    // variable declaration, if the user enters floating-point
    // values , they will be changed to int type
    int max1, min1;
    bool playAgain = true; // once the program is over, lets the user start it over
    //loop is entered if user decides to play again
    while (playAgain == true)
    {
        // this loop asks the user to enter min and makes sure that mix value is valid
        while (true)
        {
            cout << "Please enter a number that will be assigned to MINIMUM: "; // message to the user
            cin >> min; // lets the user make an etry
            // if double is enteres it will be converted to int
            //please note that if floating-point type is entered, the number is truncated, not rounded
            min1 = static_cast<int> (min); // type case, any time double is entered, it will be converted to int
            cout << endl;// new line
            // if the user makes invalid entry (letter, string, character, etc)
            if (cin.fail())
            {
                cin.clear();
                string junk;
                cin >> junk;
                cout << "\nYour entry is INVALID. No more letters or random characters, please! \n"; // message to the user
            }
            else // if users entry is accepted, we can leave the loop
            {
                break;
            }
        }// min loop is closed

        // this loop asks the user to enter max and makes sure that max value is valid
        while (true)
        {   //asks the user to enter a number that will be set to a maximum
            cout << "Please enter a number that will be assigned to MAXIMUM.\n";
            //lets the user know that max has to be at least (min +10)
            cout << "Maximum has to be at least " << (min1 +10 ) << " \n";
            cout << "Enter maximum: ";
            cin >> max; //console input
            max1 = static_cast<int> (max);// if double is entered, its converetd to integer
            // if the user makes invalid entry (letter, string, character, etc)
            if (cin.fail())
            {
                cin.clear();
                string junk;
                cin >> junk;
                cout << endl;
                //lets the user know that entry was invalid
                cout << "Your entry is INVALID. No more letters or characters, please!" << endl;
            }
            // I am setting a condition that maximum has to be at least (min +10)
            //If the user enters a number that is too small, invalid entry message
            // will be displayed and user will be asked to reeneter a maximum
            else if (max1 < (min1 +10))
            {
                cout << endl;
                //lets the user know that number enterd for maximum is too low.
                cout << "\Number that you've entered is too small to be a maximum. \n";
            }
            else // if the entry made for max is valid and  at least {min +10), we can leave the loop
            {
                break;
            }
        } // max loop is closed

        // when both min and max value are accepted:
        cout << endl;
        //message to the user
        cout << "Random number between " << min1 << " and " << max1 << " is: ";
        srand(time(NULL)); // each time program is run, different randome will be displayed
        int myRand = rand() % (max1 - min1+ 1) + min1; // random will be in the range of min1-max1
        cout << myRand <<endl; // console output of the random number
        //declaration of the variable for a user to decide if
        //they want to play again
        char decision;
        cout << endl;
        //asks the user if they want to play a game one more time
        cout << "Does the user want to do this again? \n";
        //lets the user know that they can either chose N or Y
        cout << "Press Y to use the program again. Press N to end the game. ";
        cin >> decision; // allows the user to make a decision
        cout << endl;
        //  executes only if user does not want to play again need a n or no answer
        if ( toupper(decision) == 'N' || toupper(decision) == 'Not' )
        {
            playAgain = false; // change the bool to false and paly again loop is not entered
        }
        //cin.ignore(); // for some reason when I did not have this
    }
    return 0; // end of the program
}
