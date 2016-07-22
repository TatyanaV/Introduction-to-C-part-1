#include<iostream> //Macro that includes library
#include<cstdlib> // includes library with random numbers function
#include <ctime> //  include library to control time
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
    srand( (unsigned)time(NULL)); // each time program is run, different random  numbers will be displayed
    int prize = 1; // declaration and initialization of prize variable. There are total of 4 prizes.
    int contestant1, contestant2, contestant3, contestant4;
	contestant1 = (rand()% 25) + 1; // randomely choses the first winner
	// all other subsequence "winners" need to be checked
	do
	{
		contestant2 = (rand()% 25) + 1; // the second one needs to be checked against the first one
	} while( contestant2 ==contestant1); // get a new random number if the contestant2 was the same as contestant1
	do
	{
		contestant3 = (rand()% 25) + 1; // randomly chooses a contestant from a pool of 25
	} while ( contestant3 == contestant2 || contestant3 == contestant1) ; //get a new random number if the contestant3 									      //was the same as contestant2 OR contestant1
	do
	{
		contestant4 = (rand()% 25) + 1; // randomly chooses a contestant from a pool of 25
	} while ( contestant4 == contestant1 || contestant4 == contestant2 || contestant4 == contestant3 ) ;
	cout << "Prize number  1" << " goes to contestant " << contestant1 << endl; //console output
    cout << endl;//new line
	cout << "Prize number  2" << " goes to contestant " << contestant2 << endl; //console output
    cout << endl;//new line
	cout << "Prize number  3" << " goes to contestant " << contestant3 << endl; //console output
    cout << endl;//new line
	cout << "Prize number  4" << " goes to contestant " << contestant4 << endl; //console output
    cout << endl;//new line
}
