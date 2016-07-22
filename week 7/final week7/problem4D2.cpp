/*******************************************************************
* Author: Tatyana Vlaskin
* Week 7, Problem 4 2D Dynamic Arrays TicTacToeProblem
* Description: tictactoe game that uses 2d array. A user need to input,
size of the traditional tictactoe game, 2 names of the players and
* Tic tac toe game
* Program asks for the names of two player and asks each player to indicate
move on the tic tac toe board
* Input: Names of the players and moves
Output::
***********************************************************************

************************************************************************
* Last Modification date: 05.11.2014
* File name: 2Dproblem4.cpp
********************************************************************/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cstring>
#include <string>

using namespace std;

char PlayerName1[1000];
char PlayerName2[1000];
void playerOneandTwo(char player1[1000], char player2[1000]);
char rows;
char columns;
char **table;// declaration of the 2d dynamic array;
// [00] [01] [02]
// [10] [11] [12]
// [20] [21] [22]
bool step;   // varibale to determine who will do the next move
bool win(); // check for winning combination
void board();// displays board to the user
bool input();// takes the input from the user
int cell;// positions on the board

int main()
{
    cout << "Welcome to the Tic Tac Toe Game" <<endl;
    cout << "Rules of the game:" << endl;
    cout << "The winner needs to get a winning combination!" << endl<< endl;
    cout << "How many rows does a standard tictactoe board have?"  << endl;
	do{
	    cout << "Insert number of rows: " ;
        cin >> rows;
		int temp;
        temp = rows;
        columns = temp;
      }while(rows!='3');
	cout << "You are playing on a board: " << rows << " x " << columns << endl;
 	table = new char *[rows];
	int i, j;
	for (i=0; i < rows; i++)
		table[i] = new char [columns];
    board();// display board to the user
    playerOneandTwo(PlayerName1,PlayerName2);// askes for the names of the players
    // we will randomly decide who will make first move
    srand(time(NULL));
    if (rand() & 1)
        step = true;
    else step = false;

    int count = 0; // this will count moves

    while (!win())  // if we do not have a winner
    {
        if (count == 9) // if count is 1 display a message that there is not winner
        {
            cout << "Nobody won";
            return -1;
        }
        if (!input())    // if enry is invalid, display invalid message
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Invalid entry! Try one more time" << endl;
        }
        count--;    //count entries
    }

    if (step){           // display the name of the winner on the screen.
         cout <<"Congratulations! " << PlayerName2 << " win!";}
    else{
         cout <<"Congratulations! " <<PlayerName1<< " win!" <<endl;}
    delete [] table;
    return 0;
}
// gets the names of the players
void playerOneandTwo(char player1[1000], char player2[1000]){
    do {
	      cout << "Enter a name of the 1st player: ";
	      cin >> player1;
	      cout << "Enter a name of the 2st player: " << endl;
	      cout << "Name has to be different from the 1st player: ";
	      cin >> player2;
	      cout << "\n";
	   } while (!strcmp(player1, player2));
    }
// fill the board array with the numbers 1-9
void board()
{
    int l = 0;
    cout << endl;
    for (int i(0); i < 3; i++)        // row
    {
        for (int j(0); j < 3; j++)    // columns
        {
            table[i][j] = char(49+ l);   // filling in board from 1-9
            l++;
        }
    }
}
// displays board to the screen after X and O make their moves
bool input()
{
    for (int i(0); i < 3; i++)
    {
        for (int j(0); j < 3; j++)
        {
            cout << "| " << table[i][j] << " ";
        }
        cout << "|";
        cout << endl;
    }
    cout << endl;
    if (step)
        cout << "Turn " << PlayerName1 << ": ";
    else cout <<"Turn " << PlayerName2<< ": ";
    int move;
    cin >> move; // lets the user enter a move
    if (move < 1 || move > 9)
        return false;    // invalid entry

    int i, j;            // if the entry is correct we put a character on the board
    if (move % 3 == 0)        //looking at the column 3: numbers 3, 6 or 9
    {
        i = move / 3 - 1;    // 9/3-1=2; 6/3-1=1; 3/3-1=0
        j = 2;            //  j=2 is the second row
    }
    else
    {
        j = move % 3 - 1;
        // 1%3=1-1=0; 2%3=2-1=1; 4%3=1-1=0; 5%3=2-1=1; 7%3=1-1=0; 8%3=2-1=1; if we enter numbers 1, 4 or 7 they will
        // go to the first column, if we enter 2, 5 or 8 they will go the 2nd column.
        i = move / 3;
        // 1/3 и 2/3 = 0; 4/3 и 5/3 = 1; 7/3 и 8/3 = 2;
        // if we enter 1 or 2 it will be 1st row, 4 or 5 it will be 2rnd row, ect
    }
    if (table[i][j] == '0' || table[i][j] == 'X') // if we make a duplicate entry
        return false;

    if (step)                // if entry is made by X
    {
        table[i][j] = 'X';    // put X in the array
        step = false;        //change step to false to let the other user make an entry
    }
    else { table[i][j] = '0'; step = true; }// put O in the array and change step to true, to let the other user make an entry
    return true;
}

//checks for winning combination
bool win()
{
    for (int i(0); i < rows; i++)
    {
        if ((table[i][0] == table[i][1]) && (table[i][0] == table[i][2]))//check horizontally
            return true;
        else if ((table[0][i] == table[1][i]) && (table[0][i] == table[2][i]))// check vertically
            return true;
        else if ((table[0][0] == table[1][1] && table[0][0] == table[2][2]) || (table[2][0] == table[1][1] && table[2][0] == table[0][2]))
            return true; //check diagonally
    }
    return false; // if there is no winning combination
}

