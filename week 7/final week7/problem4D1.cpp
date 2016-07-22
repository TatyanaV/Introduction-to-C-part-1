/*******************************************************************
* Author: Tatyana Vlaskin
* Week 7, Problem 4 1D Dynamic Arrays TicTacToeProblem
* Description: tictactoe game that uses 2d array. A user need to input,
size of the traditional tictactoe game, 2 names of the players and moves
* Input: Names of the players and moves
Output:
***********************************************************************
Welcome to the Tic Tac Toe Game
Rules of the game:
You need to chose dimentions of the board on which you will play.
After the board is chosen, 2 players will be playing the game.
The winner needs to fill in the whole row or column!

What size of board do you want?
Insert number of rows: 3
You are playing on a boad: 3 x 3
Enter a name of the 1st player. This player will use 'X' character : x
Enter a name of the 2st player. This player will use 'O' character.
Name has to be different from the 1st player: o

Bord with possible moves:

|-1-||-2-||-3-|
|-4-||-5-||-6-|
|-7-||-8-||-9-|
x, enter position number to make your move: 1

0
 move number: 1
Bord with possible moves:

|-X-||-2-||-3-|
|-4-||-5-||-6-|
|-7-||-8-||-9-|
o, enter position number to make your move:
ETC
************************************************************************
* Last Modification date: 05.18.2014
* File name: problem4D2.cpp
********************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

char PlayerName1[80];
char PlayerName2[80];
void instructions();
void displayBoard();// displays board
void indicateYourMove(int num); // indicate the move
void checkWinner(); // checks if there is a winner
bool resultWiner();// displays result
int rows, columns;
void initiateArray(char array[], int rows, int columns);// all elements in the array are initiated to Z
int cell;// variable to look at each cells/position on the board
char *cells = new char[rows*rows];// array to store board
int numberCheck(int &integer);// makes sure that entry is valid
int *r1 = new int[rows];// array to count X on each row
int *c1 = new int [columns];// array to count X in each column
int *r2 = new int [rows]; // array to count O on each row
int *c2 = new int [columns];// array to count O in each column


int main (){

    instructions();
    int move = 0;
    initiateArray(cells, rows, columns);// all elements in the array are initiated to Z

    while (!resultWiner()){
		displayBoard();
		for ( move = 1; move <= (rows*columns); move++) { // loops through moves
            if (move % 2) {// player 1 will start first, so he/she will have odd moves,so move % 2 = 1 for player 1
                indicateYourMove(1);// Player1 == 1
                cout << resultWiner()<< endl;
            }
		else{// if remainder is not 1
            indicateYourMove(2);
		}
		cout << " move number: " << move << endl; // kept for debugging purposes
		checkWinner();
		if (move == (rows*columns)) // if we are out of moves display a message that there is no winner
		{
            cout << "Out of moves. It is a tie game! " << endl;
            cout << "Nobody won";
            return -1;
		}
		displayBoard();
		}
    }
		delete [] r1;
		delete [] r2;
		delete [] c1;
		delete [] c2;
		delete [] cells;

		return 0;
    //}
}

void instructions(){// self explanatory

    cout << "Welcome to the Tic Tac Toe Game" <<endl;
    cout << "Rules of the game:" << endl;
    cout << "You need to chose dimentions of the board on which you will play. " << endl;
    cout << "After the board is chosen, 2 players will be playing the game. " << endl;
    cout << "The winner needs to fill in the whole row or column!" << endl<< endl;
    cout << "What size of board do you want?" << endl;
    cout << "Insert number of rows: " ;
    cin >> rows;
    numberCheck(rows);// makes sure that input is integer
    int temp;
    temp = rows;
    columns = temp; // colums is eaqual to rows
    cout << "You are playing on a boad: " << rows << " x " << columns << endl;
    do {
		cout << "Enter a name of the 1st player. This player will use 'X' character : ";
		cin >> PlayerName1;
		cout << "Enter a name of the 2st player. This player will use 'O' character. " << endl;
		cout << "Name has to be different from the 1st player: ";
		cin >> PlayerName2;
		cout << "\n";
		} while (!strcmp(PlayerName1, PlayerName2));// makes sure that names are not the same
}

// all elements in the array are initiated to Z, it does not have to be Z, anything other than X and O
void initiateArray(char array[], int row, int column)
{
    int d;
    for(d = 0; d < row*column; d++)
    {
        array[d] = 'Z';
    }
}
void displayBoard() { // function to display board to the user
    cout << "Bord with possible moves:\n" << endl;
    for (int k = 0; k < rows; k++){
		for (int i = 0; i < columns; i++){
            if ( cells[k*rows + i] == 'Z')
            {
            cout << '|' << "-"<< k * rows + i + 1 << "-" << '|';
            }
		// If it's not a Z however, display whatever letter happens to be stored there
            else
            {
            cout << '|' << "-"<< cells[k*rows + i]<< "-" << '|';
            }
		}
        cout << endl;
		}
}

void indicateYourMove(int number) {
    if (number == 1){// player 1 will start 1st, so he/she will have odd moves, so move % 2 = 1 for player 1
        cout << PlayerName1;
    }
    else { // if remainder is any other number (not 1)
        cout << PlayerName2;
    }
    cout << ", enter position number to make your move: ";
    cin >> cell; // user indicates their entry
    numberCheck(cell);// checks to make sure that the use made a valid entry
    cout << endl;
    if (number == 1){//fist player uses X, second one uses O
		cells[cell-1] = 'X';
    }
    else {
		cells[cell-1] = 'O';
    }
}

// checks if there is a winner

void checkWinner(){
     for(int i=0;i<rows;i++)
    {
        r1[i]=c1[i]=r2[i]=c2[i]=0;// at the beggining of each row and each column, array it initialized to zero
    }
       //checking rows
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            if(cells[i*rows+j]=='X')
                r1[i]++;// increment if you see x
            if(cells[i*rows+j]=='O')
                r2[i]++;// increment if you see o
		}
    }
		//check columns, similar to check for rows
    for (int i = 0; i< columns; i++){
		 for (int k = 0; k < rows; k++){
            if ((cells[i+ k*rows] == 'X'))
                c1[i]++;
            if ((cells[i+ k*rows] == 'O'))
                c2[i]++;
		}
    }
    resultWiner();
}

// displays results
bool resultWiner() {
// if X is the winner
    for(int i=0;i<rows;i++)
    {
        if(r1[i]==rows ||c1[i]==rows)
        {
			cout <<PlayerName1 << "\n Winner! This player used 'X'. Congratulations!";
			return true;
        }

    }
    for(int i=0;i<rows;i++)
    {
        if(r2[i]==rows ||c2[i]==rows)
        {
			cout <<PlayerName1 << " \n Winner! This player used 'O'. Congratulations!";
			return true;
        }

    }
    return false;


}
// function to check if the entery is valid. No doubles, strings or special characters allowed
int numberCheck(int &integer)
{
    while (cin.fail() || integer != static_cast<int>(integer)||integer > (rows*rows) || integer < 1 || cells[integer-1] == 'O' || cells[integer-1] == 'X')
    {
		if (cells[integer-1] != 'Z'){
		cout << "Your entry is invalid. This position is ocupied already. " << endl;
		}
		else{
            cout << "Your entry is invalid. " << endl;
            cout << "Make a move: "<< endl;
		}
            cin.clear();
            cin.ignore(80,'\n');
            cout << "Make a valid move : ";
            cin >> integer;
    }
    return integer;
}
