
/*******************************************************************
* Author: Tatyana Vlaskin
* Description:
*   Program asks a user to input a what number they want to retrive from
 Fibonacci sequence and returns what it is equal to.
* Input: User needs to input Fibonachi number
* Output:
Enter the Fibonacci Number you would like to retrieve: 15
The 15 Fibonacci Number is 610

Do you want to sort another set? (Y/N) y
Enter the Fibonacci Number you would like to retrieve: 10
The 10 Fibonacci Number is 55

Do you want to sort another set? (Y/N)

* Last Modification date: 05.04.2014
* File name: problem4.cpp
********************************************************************/

#include <iostream>
using namespace std;

int fibonacci(int n);// function declaration

int main(){

    char tryAgain; //variable declaration
    do // if the user decides to repeat this calculation, this loop will be started
    {
        int fibonacci_Number;
        cout << "Enter the Fibonacci Number you want to retrieve: "; // console output
        cin >> fibonacci_Number;// console input, variable declaration
        //console output, information about the fibonacci number
        cout << "The " << fibonacci_Number << " Fibonacci Number is " << fibonacci(fibonacci_Number) << "\n";
        // ask the user if they want to enter another number
        cout << endl << "Do you want to enter different Fibonacci Number (Y/N) ";
        cin >> tryAgain; // console input
    } while (tryAgain == 'y' || tryAgain == 'Y');  //system("Pause");

    return 0;
}
// function definition
int fibonacci(int n){
   if (n <= 1)// base call
      return n;
   return fibonacci(n-1) + fibonacci(n-2);// recursive function that will call untill n<=1
}
