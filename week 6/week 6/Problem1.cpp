/*******************************************************************
* Author: Tatyana Vlaskin
* Week 6, Problem 1
* Description:
* Program asks the use to enter ingeregs, which fill the array.
Once the array is filled completely, the sum if computed
* Input: User needs to input integers.
Output:
***********************************************************************
Enter 1 integer: ;
Error, your input is invalid.  Only INTEGERS are accepted.
Enter 1 integer: p
Error, your input is invalid.  Only INTEGERS are accepted.
Enter 1 integer: 1
Enter 2 integer: 2
Enter 3 integer: 3
Enter 4 integer: 4
Enter 5 integer: 5

The sum of 5 integers that you entered is: 15
************************************************************************
* Last Modification date: 05.11.2014
* File name: problem1.cpp
********************************************************************/

#include <iostream>  //library for input and output
#include <string>    //library for stings
using namespace std;

const int SIZE = 5; // array size will be 5

void populateArray(double array[],  int SIZE);// fills in the array with numbers

double sumArray(const double array[], int SIZE); // computes the sum of the values that were enteresd

int main()// main function
{
    double array[SIZE];// declaration of array
    populateArray(array, SIZE);
    int sum = sumArray(array, SIZE);

    cout << endl;
    cout << "The sum of " << SIZE << " integers that you entered is: "<< sum << endl;
    return 0;
}

//populates the array
void populateArray(double array[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {

        cout << "Enter " << i+1 << " integer: ";
        cin >> array[i];   // ith element receives value
        while (cin.fail() || (array[i] != static_cast<int>(array[i]))){//checks for valid input, special characters, doubles, spaces are not allowed        {
            cout << "Error, your input is invalid.  Only INTEGERS are accepted. " << endl;
            cin.clear();
            cin.ignore(80,'\n');
            cout << "Enter " << i+1 << " integer: ";
            cin >> array[i];
        }
    }
}
double sumArray(const double array[], int SIZE)// computes sum of the numbers that were entered
{
    int sum = 0;
    for (int i = 0; i < SIZE; i++)// loops through the array
    {
        sum += array[i];// adds numbers in the array one by one
    }
    return sum;

}
