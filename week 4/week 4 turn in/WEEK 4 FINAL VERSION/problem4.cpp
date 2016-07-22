/*******************************************************************
* Author: Tatyana Vlaskin
* Description:
* This program computes hat, jacket and waist size.
* Input: User needs to input age, weight and height
Output:
You've Launched Clothing Size Calculator.
Please enter your weight in pounds: 120
Please enter your height in inches: 5.3
Please enter your age: 28
Your hat size: 66.
Your jacket size:  2.
Your waist size: 21.05 inches.
Do you want to calculate your cloath size one more time? (Y/N) y
Please enter your weight in pounds:
* Last Modification date: 04.27.2014
* File name: problem4.cpp
*******************************************************************/
#include <iostream>
using namespace std;

// Function Declaration. This function lets the user to enter a number, and checks to make sure
//that entered number is positive and not a character/string
double getdouble();
//function declaration to compute hat size
double hat_size(double weight, double height);
//function declaration to compute jacket size
double jacket_size(double weight, double height, int age);
//function declaration to compute waist size
double waist_in_inches(double weight, int age);
//function declaration to set precision
void precision(int precision);

int main()
{
    double weight, height, age; // variable declaration
    char tryAgain; //variable declaration
    cout << "You've Launched Clothing Size Calculator." << endl;
    do // if the user decides to repeat this calculation, this loop will be started
    {
        cout << "Please enter your weight in pounds: "; // console  output
        weight = getdouble(); // function call to enter weight
        cout << "Please enter your height in inches: "; // console output
        height = getdouble(); // function call to enter height
        cout << "Please enter your age: "; // cobsole output
        age = getdouble(); // function call to enter age
        //console output to let the user know their hat, jacket and waist size
        cout << "Your hat size: " << hat_size(weight, height) << endl;
        cout << "Your jacket size:  " << jacket_size(weight, height, age)<< endl;
        cout << "Your waist size: " << waist_in_inches(weight, age) << " inches." << endl;
        // asks the user if they want to repeat calculations
        cout << "Do you want to calculate your cloath size one more time? (Y/N) ";
        cin >> tryAgain; // console input
    } while (tryAgain == 'y' || tryAgain == 'Y');  // calculation will be repeated if the user answers Y
    return 0;
}
//function definition. This function lets the user to enter a number, and checks to make sure
//that entered number is positive and not a character/string
// function definition to compute waist size in inches
// waist age comes into play as well.
double waist_in_inches(double weight, int age)
{
    double waist = weight/5.7; // variable declation and initialization, waist size is omputed
    // if the user is over 28, there is an adjustment that need to be done every 2 years
    if (age >= 28 && ((age % 2) == 00))
    {
        double adjustment  = ((age - 28)/2.0)*(1/10.0); // adjustment is calculated
        waist = waist + adjustment; // adjusted waist size
    }
    precision (2); // for waist size, Ill set precision to 2
    return (waist); // waist size is returned
    }
// function definition to calculate precision
void precision(int precision){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(precision);
}


