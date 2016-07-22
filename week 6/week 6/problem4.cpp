/*******************************************************************
* Author: Tatyana Vlaskin
* Week 6, Problem 4
* Description:
* Program asks for the names of two player and asks each player to indicate
move on the tic tac toe board
* Input: Names of the players and moves
Output:
***********************************************************************
Welcome to the Tic Tac Toe Game
Rules of the game:
There are 2 player playing on the board of 3x3
The winner needs to get a winning combination!

Enter a name of the 1st player. This player will use 'X' character : ivan
Enter a name of the 2st player. This player will use 'O' character.
Name has to be different from the 1st player: tatyana

Bord with possible moves:

-1-|-2-|-3-
-4-|-5-|-6-
-7-|-8-|-9-

Current situation. '---' indicates empty positions:

---|---|---
---|---|---
---|---|---

ivan, enter position number to make your move: 1

Bord with possible moves:

-1-|-2-|-3-
-4-|-5-|-6-
-7-|-8-|-9-

Current situation. '---' indicates empty positions:

-X-|---|---
---|---|---
---|---|---

tatyana, enter position number to make your move: 2

Bord with possible moves:

-1-|-2-|-3-
-4-|-5-|-6-
-7-|-8-|-9-

Current situation. '---' indicates empty positions:

-X-|-O-|---
---|---|---
---|---|---

ivan, enter position number to make your move: 9

Bord with possible moves:

-1-|-2-|-3-
-4-|-5-|-6-
-7-|-8-|-9-

Current situation. '---' indicates empty positions:

-X-|-O-|---
---|---|---
---|---|-X-

tatyana, enter position number to make your move: 3

Bord with possible moves:

-1-|-2-|-3-
-4-|-5-|-6-
-7-|-8-|-9-

Current situation. '---' indicates empty positions:

-X-|-O-|-O-
---|---|---
---|---|-X-

ivan, enter position number to make your move: 5

Bord with possible moves:

-1-|-2-|-3-
-4-|-5-|-6-
-7-|-8-|-9-

Current situation. '---' indicates empty positions:

-X-|-O-|-O-
---|-X-|---
---|---|-X-

ivan win! This player used 'X'. Congratulations!

************************************************************************
* Last Modification date: 05.11.2014
* File name: problem4.cpp
********************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

char PlayerName1[80];
char PlayerName2[80];
char cells[9] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};// array that will filled with '_'. the user will see board filled with '_'
void instructions();
void displayBoard();// displays board
void indicateYourMove(int num); // indicate the move
char checkWinner(); // checks if there is a winner
char win = '-'; // "-" -no winner, "Х" - first palyer, "О" - 2nd player
void result(); // displays result

int main (){
    instructions();
    do {
	      cout << "Enter a name of the 1st player. This player will use 'X' character : ";
	      cin.getline(PlayerName1,80);
	      cout << "Enter a name of the 2st player. This player will use 'O' character. " << endl;
	      cout << "Name has to be different from the 1st player: ";
	      cin.getline(PlayerName2,80);
	      cout << "\n";
	   } while (!strcmp(PlayerName1, PlayerName2));// makes sure that names are not the same

	   displayBoard();

	   for (int move = 1; move <= 9; move++) { // loops through moves
	      if (move % 2) {// player 1 will start first, so he/she will have odd moves,so move % 2 = 1 for player 1
	          indicateYourMove(1);// Player1 == 1
	      }
	      else {// if remainder is not 1
	          indicateYourMove(2);
	      }
	      displayBoard();
	      if (move >= 5){ // after move 5 we need to check for a winner
	          win=checkWinner();
	          if(win!='-'){ //is no '-' is detected, we know that there is a winner,
	             break; // we need to exit the loop if there is a winner
              }
	      }
    }
    result();
    return 0;
}

void instructions(){// self explanatory

    cout << "Welcome to the Tic Tac Toe Game" <<endl;
    cout << "Rules of the game:" << endl;
    cout << "There are 2 player playing on the board of 3x3" << endl;
    cout << "The winner needs to get a winning combination!" << endl<< endl;
}
void displayBoard() { // function to display board to the user
    cout << "Bord with possible moves:\n" << endl;
    //Numbers for positions on the board. Lets the player know what moves they can make
    cout << "-" << 1 << "-" << '|' << "-" << 2 << "-" << '|' << "-" << 3 << "-" << endl;
    cout << "-" << 4 << "-" << '|' << "-" << 5 << "-" << '|' << "-" << 6 << "-" << endl;
    cout << "-" << 7 << "-" << '|' << "-" << 8 << "-" << '|' << "-" << 9 << "-" << "\n" << endl;

    cout << "Current situation. '---' indicates empty positions:\n" << endl;
    //Current situation. If position is taken , user will see X or O.
    //If position is empty there user will see '---'
    cout << "-" << cells[0] << "-" << '|' << "-" << cells[1] << "-" << '|' << "-" << cells[2] << "-" << endl;
    cout << "-" << cells[3] << "-" << '|' << "-" << cells[4] << "-" << '|' << "-" << cells[5] << "-" << endl;
    cout << "-" << cells[6] << "-" << '|' << "-" << cells[7] << "-" << '|' << "-" << cells[8] << "-" << "\n" << endl;
}
// function asks a user to make a move
void indicateYourMove(int number) {
    if (number == 1){// player 1 will start 1st, so he/she will have odd moves, so move % 2 = 1 for player 1
        cout << PlayerName1;
    }
    else { // if remainder is any other number (not 1)
        cout << PlayerName2;
    }
    cout << ", enter position number to make your move: ";
    int cell;
    cin >> cell; // user indicates their entry
	  // while (cin.fail() || postion != static_cast<int>(position)||position > 9 || position < 1 || position[position-1] == 'O' || position[position-1] == 'X')
        while (cin.fail() || cell != static_cast<int>(cell)||cell > 9 || cell < 1 || cells[cell-1] == 'O' || cells[cell-1] == 'X')
       {
            cout << "Your entry is invalid.  " << endl;
            cout << "Enter postion 1-9 thas is empty '---'. Make a move: "<< endl;
            cin.clear();
            cin.ignore(80,'\n');
            cout << "Make a valid move : ";
            cin >> cell;
        }
	   cout << "\n";

	   if (number == 1){//fist player uses X, second one uses O
            cells[cell-1] = 'X';
        }
       else {
           cells[cell-1] = 'O';
        }
}
// checks if there is a winner
char checkWinner()
{
    for(int i = 0; i < 3; i++) //3 cells need to be filled in for winning
        if ((cells[i*3] == cells[i*3+1]) && (cells[i*3+1] == cells[i*3+2])) //horizontal combinations//0-1-2, 3-4-5 and 6-7-8
            return cells[i];
        else if (cells[i] == cells[i+3] && cells[i+3] == cells[i+6]) //vertical combination//0-3-6, 1-4-7 and 2-5-8
	         return cells[i];
        else if ((cells[0] == cells[4] && cells[4] == cells[8]) || (cells[2] == cells[4] && cells[4] == cells[6]))
	         return cells[i]; //diagonal combination // 0-4-8 and 2-4-6
        else
	      return '-'; //no winner
}
// displays results
void result() {
    if (win=='X') cout << PlayerName1 << " win! This player used 'X'. Congratulations! "  << endl;
    else if (win=='O') cout << PlayerName2 << " win! This player used 'O'. Congratulations! " << endl;
    else cout << "Nobody won." << endl;
}
