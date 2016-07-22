/*******************************************************************
* Author: Tatyana Vlaskin
* Description:
* This program computes the number of miles per gallon.
* Input: User needs to input 2 numbers, one for miles travelled and
* second one for litters of gas used.
Output:
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
#include<iostream>
using namespace std;

const double GALLONS_PER_LITER = 0.264179; // globally defined constant
// Function Declaration. This function lets the user to enter a number, and checks to make sure
//that entered number is positive and not a character/string
double getdouble();
// Function Decleration. This function converts litters to gallons.
double convert_liters_to_gallons(double liters);
// Function declaration. This function computes the number of miles per gallon delived by the car.
double mpg(double liters, double miles);

int main() // main function
{
    double liters, miles, gallons, milesPerGallon; // declaration of variables
    char tryAgain;
    do// if the user decides to repeat this calculation, this loop will be started
    {
        cout << "Please enter liters of gas consumed by the car: "; // console output
        liters = getdouble (); // function call to enter liters

        cout << "Please enter miles traveled: ";// console output
        miles = getdouble (); // function call to enter miles travelled
        // function call to compute miles per gallon delived by the car
        double milesPerGallon = mpg(liters, miles);
        // console output. lets the use know how many miles per gallon were delived by the car
        cout << "In this trip, your car delivered " << milesPerGallon << " miles/gallon." <<endl;
        // console output. Asks the user if they want to repeat calculations one more time
        cout << "Do you want to do the calculation one more time (Y/N)? ";
        cin >> tryAgain; // console input
    }while (tryAgain == 'Y' || tryAgain == 'y'); // calculation will be repeated if the user answers Y
return 0;
}

//function definition. This function lets the user to enter a number, and checks to make sure
//that entered number is positive and not a character/string
double getdouble()
{
    for(;;) // equivalent to while (true) loop
    {
        double value; // variable declaration
        cin >> value; // console input lets the use enter a number
        if(cin.fail() || value < 0 ) // if cin is bad time or cin is a negative value.
        {  // if the user enters string, character.
        cin.clear();  // reset cin
        string garbage; // varible declaration to discard bad entry
        getline(cin, garbage); // ignore rest of line
        //console output. let the use know that entry is invalid
        cout << "\nINVALID ENTRY. Try again. ";
        cout << " You are allowed to enter only positive numbers. ";
        }
    else // if the users input is valid, entered value is returned.
    {
        return value;
    }
  }
}
// Function Definition. This function converts litters to gallons.
//returns gallons
double convert_liters_to_gallons(double liters)
    {
        return (liters * GALLONS_PER_LITER);
    }
// Function definition. This function computes the number of miles per gallon delived by the car.
double mpg(double liters, double miles)
{
    double miles_per_gallon; //variable declaration
    // function call to conver miles to gallons
    double gallons = convert_liters_to_gallons(liters);
    // miles_per_gallon is calculated
    miles_per_gallon = (miles/gallons);
    //sets precision to 2
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    return (miles_per_gallon); // retuns miles per gallon
 }

