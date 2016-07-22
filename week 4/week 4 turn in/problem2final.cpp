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

* Last Modification date: 04.27.2014
* File name: problem2.cpp
********************************************************************/

#include <iostream> //Macro that includes library
using namespace std; //Global statment
#include <cstdlib> // inlcudes reandom numberes library
#include <string> //uncludes string libary

// Function Declaration. This function lets the user to enter a number, and checks to make sure
//that entered number is positive and not a character/string
double getNumber();
// Function declaration to display rando number between min and max
int randInput(int min, int max);

int main () //Main function
{
    // variable declaration. user will be able to enter floating-point
    //values or integers
    double max, min;
    // variable declaration, if the user enters floating-point
    // values , they will be changed to int type
    int max1, min1;
    char tryAgain;

do{
            cout << "Please enter a number that will be assigned to MINIMUM: "; // message to the user
            // if double is enteres it will be converted to int
            //please note that if floating-point type is entered, the number is truncated, not rounded
            min = getNumber();
            min1 = static_cast<int> (min); // type case, any time double is entered, it will be converted to int
            cout << endl;
        // this loop asks the user to enter max and makes sure that max value is valid
        while (true)
       {   //asks the user to enter a number that will be set to a maximum
            cout << "Please enter a number that will be assigned to MAXIMUM.\n";
            //lets the user know that max has to be at least (min +10)
            cout << "Maximum has to be at least " << (min1 +10 ) << " \n";
            cout << "Enter maximum: ";

            max = getNumber();
            max1 = static_cast<int> (max);// if double is entered, its converetd to integer
            if (max1 < (min1 +10))
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
        cout << endl;
        cout << "Random number between " << min1 << " and " << max1 << " is: ";
        srand(time(NULL)); // each time program is run, different randome will be displayed
        // fucntion call to dislay random number
        int randomNumber = randInput( min1,  max1);
        cout << randomNumber << endl << endl; // console output
        cout << "Do you want to choose another random numner? (Y/N)? "; // asks the user if they want to repeat the program
        cin >> tryAgain;
        cout << endl;
}while (tryAgain == 'Y' || tryAgain == 'y');
    return 0; // end of the program
}
// Function Definition. This function lets the user to enter a number, and checks to make sure
//that entered number is positive and not a character/string
double getNumber()
{
  for(;;)
  {
    double value;
    cin >> value;
    if(cin.fail())  // cin failed?
    {
      cin.clear();  // reset cin
      string garbage;
      getline(cin, garbage); // ignore rest of line
      cout << "\nINVALID ENTRY. That wasn't a number, try again. ";
    }
    else
    {
      return value;
      break;
    }
  }
}

// function definition to deisplay random number
int randInput(int min1, int max1){
    return rand() % (max1 - min1+ 1) + min1; // random will be in the range of min1-max1
    ////return myRand;
    cout <<endl; // console output of the random number
}

