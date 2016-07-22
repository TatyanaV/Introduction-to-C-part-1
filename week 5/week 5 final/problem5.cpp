
/*******************************************************************
* Author: Tatyana Vlaskin
* Description:
*   Program asks a user to input number of rows in the piramid and outputs
how many pis will be in the pyramid.
* Input: User needs to input number of rows
* Output:
 How many rows do you want to have in a triangle: 10
 A triangle with 10 rows has 55 pins.
         *
        * *
       * * *
      * * * *
     * * * * *
    * * * * * *
   * * * * * * *
  * * * * * * * *
 * * * * * * * * *
* * * * * * * * * *
Do you want to play again? (Y/N)
* Last Modification date: 05.04.2014
* File name: problem5.cpp
********************************************************************/
#include <iostream>  //library for input and output
#include <string>    //library for stings
using namespace std; //global statment
//function declaration to let the user know how many pins are there in the pyramid
int countPins(int row);
// function to draw the pyramid. I refered to Frank L Brasington code to design this function
// please note that this is not requirement for this problem
// but I decided to understand his code and incorporate it in my program
void displayPins(int rows, int pin);

int main()
{
    char tryAgain; //variable declaration
    do {// if the user decides to repeat this calculation, this loop will be started
    int rows;
    int pin = 1; // 1 is the minimum number of rows. If there is 1 row there is 1 pin/star
    cout << " How many rows do you want to have in a triangle: "; // console output
    cin >> rows; // console input
    cout << " A triangle with " << rows << " rows has " << countPins(rows) << " pins." << endl;// console output
    displayPins(rows, pin); // function call to let the user know how many pins are the in the pyramid and draws the piramid
    cout << endl << "Do you want to paly again (Y/N) "; // asks the user is they want to play again
    cin >> tryAgain; // console input
    } while (tryAgain == 'y' || tryAgain == 'Y');  // calculation will be repeated if the user answers Y
    return 0;

}
//function declaration to let the user know how many pins are there in the pyramid
int countPins(int row)
         {
            if (row == 1) // base call
            {
              return 1;
            }
            else // if there is more than 1 row
            {
              return (countPins(row-1)+row);// recursive function
            }
        }

// function to draw the pyramid. I refered to Frank L Brasington code for this function
// please note that this is not requirement for this problem
// but I decided to understand his code and incorporate it in my program
void displayPins(int rows, int pin)
{
    int spaces = rows - 1;// declaration and definition of spaces
    //draw my spaces
for (int i = 0; i < spaces; i++)// cout spaces
	{
	 cout << " ";
	}
//cout pins
for (int i = 0; i < pin; i++)
	{
	cout << "* ";
	}
//this is used for the paragraph and to change pins by one
//and lower rows by 1 and recall the function if needed.
if (rows > 1)
	{
    cout << endl;
    pin = pin +1;
    rows = rows -1;
    displayPins(rows, pin);
	}
}
