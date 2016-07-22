#include<iostream> //Macro that includes library
#include<cstdlib> // includes library with random numbers function
#include <ctime> //  include library to control time
//#include <dos.h>
//#include <stdio.h>
//#include <conio.h>
using namespace std;//Global statement

//function declaration to desplay 4 winners out of pool of 25
void winner();

int main() //main method
{
    srand( (unsigned)time(NULL)); // each time program is run, different randome will be displayed
    char chooseAgain;// variable declaration in case the user want to choose different finalists

    do // loop will be executed if the user answers Y for repeat prompt
    {
        //console output
        cout << "LIST OF 4 FINALISTS THAT WILL RECEIVE A PRIZE: \n " << endl;
        winner(); // call the winner function, see end of the program for more information about the winner function;
        cout << "Do you want to choose another 4 finalists (Y/N) "; //console output
        cin >> chooseAgain; // console input
        cout << endl; //new line, fomating purpose
    } while(chooseAgain == 'y' || chooseAgain == 'Y');//Allow the user to repeat the program
    return 0; //end of program
}
// function definition
void winner ()
{
    //srand( (unsigned)time(NULL)); // each time program is run, different random will be displayed
    int prize = 1; // declaration and initialization of prize variable. There are total of 4 prizes.
    // loops thought each contestant one at a time. There are total of 25 contestants.
    srand(time(NULL));
     //srand(time(0));
    for (int contestant = 1; contestant <= 25; contestant ++)
    {
       // srand(time(NULL));
        while(prize >=1 && prize <=4) // loop to distribute prizes, there are total of 4 prizes
        {
        int contestant = (rand()% 25) + 1; // randomly chooses a contestant from a pool of 25
        cout << "Prize number " << prize << " goes to contestant " << contestant << endl;
        cout << endl;//new line
        prize ++; // increments prize number
        }
    }
 }
