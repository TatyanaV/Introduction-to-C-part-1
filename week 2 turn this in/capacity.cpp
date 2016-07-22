/*******************************************************************
* Author: Tatyana Vlaskin
* Description:
*   Program asks a user to input 2 numbers. One for room capacy and
*   second one for # of people that came to the meeting. If # of people
*   that came to the meeting is less than room capacity, the program anounces
*   that meeting is legal and if any additional people are allowed to come.
*   If # of people that came to the meeting exceeds room capacity, the
*   program accounces that meeting cannot be held unless specific #
*   of people leave the room.
* Input: User needs to input a number for room capacity and second number
*        for # of people that came to the meeting
* Output:
Enter maximum room capacity: 20
Enter number of people that will come to the meeting: 60
You are not allowed to have the meeting.
It violates the fire law regulations.
If you want to have a meeting, 40 guest(s) must be excluded.

OR

Enter maximum room capacity: 60
Enter number of people that will come to the meeting: 20
It is legal to hold the meeting!
40 additional guest(s) may leggally attand the meeting.

OR

Enter maximum room capacity: POP
Your entry is invalid. Please make a valid entry.
Enter maximum room capacity: 2
Enter number of people that will come to the meeting: 1
It is legal to hold the meeting!
1 additional guest(s) may leggally attand the meeting.
*
* Last Modification date: 04.11.2014
* File name: capacity
********************************************************************/

#include <iostream> //Macro that includes librar
#include <math.h> // Includes math library
using namespace std; //Global statment

int main () //Main function
{
    //declaration and initialization of variables
    int capacity, people; // capacity of the room
    //int people; // # of people who came to the meeting

    cout << "Enter maximum room capacity: ";    //Prints message to the console
    cin >> capacity;    //Allows use to make an entry.
    if (!cin.good())
    {
        cout << "Your entry is invalid. Please make a valid entry. \n";
        cin.clear ();
        cin.sync ();
        cout << "Enter maximum room capacity: ";
        cin >> capacity;
    }
    cout << "Enter number of people that will come to the meeting: ";    //Prints message to the console
    cin >> people;      //Allows use to make an entry.
    cout << people;
    if (!cin.good())
    {
        cout << "Your entry is invalid. Please make a valid entry. \n";
        cin.clear ();
        cin.sync ();
        cout << "Enter number of people that will come to the meeting: ";
        cin >> people;
    }

    // declares a variable, find the difference between room capacity and peopele at the meeting
    int difference = capacity - people;

    if(people <= capacity)  //indicates what action to take when # of people is less or equal room capacity
    {
       cout << "It is legal to hold the meeting! \n"; //Prints message to the console
       cout << difference << " additional guest(s) may leggally attand the meeting.\n";
    }
    else if (people > capacity) //indicates what to do if # of people exceed capacity of the room
    {
        cout << "You are not allowed to have the meeting. \n"   //prints message to the console
        << "It violates the fire law regulations. \n"   //prints message to the console
        //prints meggase to the console, takes absolute value of difference, to make sure that # is positive
        << "If you want to have a meeting, " << fabs (difference) << " guest(s) must be excluded." <<endl;

    }
    return 0;//end of the function, returns non-error status
}
