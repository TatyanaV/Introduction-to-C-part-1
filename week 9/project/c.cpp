#include <iostream>
#include <fstream>

using namespace std;

struct Board
{
    int values[81];             //Stores board values
    bool isFixedValue[81];      //Keeps track of what numbers can be modified
    bool isPossibleValue[81][9]; //decides what values are possible for certain square
    int coordinates;
};

void getFileName(char fileName[]);
bool getBoard(char fileName[], Board &mainBoard);
bool validateBoard(Board board);
void interact(Board &mainBoard);
void displayMenu();
void displayBoard(Board board);
char getOption();

int getCoordinates(bool isFixedValue[]);
int getNewValue(Board &board);
bool canChange(Board mainBoard, int coordinates, int value);
bool anyDuplicates(int board[], int coordinates, int value);
void editSquare(int board[], int coordinates, int value);
bool checkPossibles(Board &newBoard);
/*float solve(Board &newBoard);
bool bruteForce(Board &board);*/
bool isSolved(Board board);
void clearBoard(Board &board);


//gets the filename, loads board, and checks to see if opened properly then interacts with the user.
int main(int argc,char *argv[])
{
    char fileName[256];
    Board mainBoard;

    //Get FileName and read board
    getFileName(fileName);
    if (!getBoard(fileName, mainBoard))
        cout << "Error: Unable to open file " << fileName << endl;

    //Validate Board and show menu
    else
        if (validateBoard(mainBoard))
        {
            displayMenu();
            displayBoard(mainBoard);
            interact(mainBoard);
        }

    system("PAUSE");
    return 0;
}

//promt user for fileName then retrieves filename
void getFileName(char fileName[])
{
    cout << "Where is your board located? ";
    cin.getline(fileName, 255);
    return;
}


//get the board and decide which values are fixed and which user needs to input
//user cannot enter a negative number
bool getBoard(char fileName[], Board &mainBoard)
{
    ifstream fin(fileName);
    if (fin.fail())
        return false;

    //fill MainBoard from file
    for (int i = 0; i < 81; i++)
    {
        fin >> mainBoard.values[i];

        //original board values are greater than 0 and cannot be changed or modified
        if (mainBoard.values[i] > 0)
            mainBoard.isFixedValue[i] = true;

        //user input values are negative & must be changed to positive
        else
        {
            mainBoard.isFixedValue[i] = false;
            mainBoard.values[i] = (mainBoard.values[i] / -1);
        }

    }

    fin.close();
    return true;
}

/**********************************************************************
* validateBoard
*  WHILE i = 0 to 80
*        SET tempValue to current value on board
*        SET board value to 0 temporary
*        IF tempValue != 0 && anyDuplicates()
*           PUT Error duplicate value to screen
*           RETURN false
*        SET board value back to original value (tempValue)
*  RETURN true
***********************************************************************/
bool validateBoard(Board board)
{

    for (int i = 0; i < 81; i++)
    {
        //The value is temporarily changed to not check for self duplicates
        int tempValue = board.values[i];
        board.values[i] = 0;
        if (tempValue != 0 && anyDuplicates(board.values, i, tempValue))
        {
            cout << "ERROR: Duplicate value '"
                << tempValue
                << "' in inside square represented by '"
                << (char)toupper((i / 9) + 65)
                << ((i % 9) + 1)
                << "'";
            return false;
        }
        board.values[i] = tempValue; //Change back to original value
    }

    //Passed sudoku rules
    return true;
}

//allow user to choose menu option
void interact(Board &mainBoard)
{
    bool done = false;
    int value = -1;
    float time;

    //Interactive Menu
    while (!done)
        switch (getOption())
        {
            case '?'://Display menu
            displayMenu();
            break;
            case 'd'://Display board
            displayBoard(mainBoard);
            break;
            case 'e'://Edit square
            mainBoard.coordinates = getCoordinates(mainBoard.isFixedValue);
            if (mainBoard.coordinates != -1)
                value = getNewValue(mainBoard);
            if (value != -1)
                editSquare(mainBoard.values, mainBoard.coordinates, value);
            break;
            case 'c': //clear the board
            clearBoard(mainBoard);
            break;
            /*case 'f'://Finish Board
Board newBoard = mainBoard;//W will solve our board on new one
clearBoard(newBoard);
//Copy the solution back to mainBoard so it keeps fixed values
for (int i = 0; i < 81; i++)
mainBoard.values[i] = newBoard.values[i];
break;*/
            case 'q'://quit
            done = true;
            break;
            default:
            cout << "ERROR: Invalid command" << endl;
            displayMenu();
            break;
        }
    return;
}

//display menu
void displayMenu()
{
    cout << "Options:\n"
        << "   ?  Show these instructions\n"
        << "   D  Display the board\n"
        << "   E  Edit one square\n"
        << "   C  Clear the board\n"
        /*<< "   F  Finish the board!\n"*/
        << "   Q  Quit\n"
        << endl;
    return;
}


//board display
//put a header on the screen
//tell to put -----+-----+------ if row !=0 and row%3 =0
//tell to put a numbered row if i%9 =0
//tell to put a | if column !=0 and column%3 =0
//if not, put a space
//if the value of the square is 0, put a space
//if the value isn't 0, then display the value
void displayBoard(Board board)
{

    //header
    cout << "   A B C D E F G H I" << endl;

    //row = i / 9 and Column = i % 9
    for (int i = 0; i < 81; i++)
    {
        //divisor every 3rd row
        if ((i / 9) != 0 && (i / 9) % 3 == 0 && (i % 9) == 0)
        {
            cout << "   -----+-----+-----" << endl;
        }

        if (i % 9 == 0)//numbered rows
        {
            cout << ((i / 9) + 1) << " ";
        }

        //divisor every 3rd Column
        ((i % 9) != 0 && (i % 9) % 3 == 0) ? cout << "|" : cout << " ";

        //Space for each unknown value(every 0 value)
        if (board.values[i] == 0)
        {
            cout << " ";
        }

        if ((i + 1) % 9 == 0)
        {
            cout << endl;
        }
    }
    return;
}

//prompt user for an option, then get the option
char getOption()
{
    char option;
    cout << endl << "> ";
    cin >> option;
    return (tolower(option));
}


//getCoordinates
//SET coordinates = -1
//promt user for coordinates
//retrieve user input
/*  IF input[0] is not a letter
*     values[0] = input[1]
*  IF input[1] is not a digit
*     values[1] = input[0]
*  IF values[0] is not letter a-z || values[1] is not 1-9
*     PUT Error to screen invalid input
*  ELSE IF isFixedValue[values[0]-97][values[1]-49]
*           PUT Error to screen read only
*  ELSE
*     coordinates = (values[0]-97) + (values[1]-49)*9
*  RETURN coordinates*/
int getCoordinates(bool isFixedValue[])
{
    int coordinates = -1;
    char input[3];
    int values[2];

    cout << "What are the coordinates of the square: ";
    cin  >> input;

    //Change format to grid[0] lowercase letter , grid[1] number
    (isalpha(input[0])) ? values[0] = tolower(input[0])
        : values[0] = tolower(input[1]);
    (isdigit(input[1])) ? values[1] = input[1]
        : values[1] = input[0];

    //Check for valid input(a-z)(1-9)
    if (values[0] < 'a' || values[0] > 'z' || values[1] < 49 || values[1] > 57)
        cout << "ERROR: Square '" << input << "' is invalid" << endl;

    //Check cell if read only
    else if (isFixedValue[(values[0] - 97) + (values[1] - 49) * 9])
        cout << "ERROR: Square '"
        << (char)toupper(values[0])
        << values[1] - 48
        << "' is read-only" << endl;

        //Convert to coordinates(ex. (a2) = (97,50) = (10)
        else                 //Column      +        Row       * Column
            coordinates = ((values[0] - 97) + (values[1] - 49) * 9);
        return coordinates;
}


//promt user for new value and if value < 0 || value > 9 || !canChange(value)
//indicate error for invalid value
//return -1
//return value
int getNewValue(Board &board)
{
    //Get new value
    int value;
    cout << "What is the value at '"
        << (char)(board.coordinates % 9 + 65) //Letter
        << (board.coordinates / 9 + 1)        //Number
        << "': ";
    cin  >> value;

    //Check for valid input : 0 <= value <= 9
    //and if new value is allowed by sudoku rules
    if (value < 0 || value > 9 ||
        !canChange(board, board.coordinates, value))
    {
        cout << "ERROR: Value '" << value << "' in square '"
            << (char)(board.coordinates % 9 + 65)
            << (board.coordinates / 9 + 1)
            << "' is invalid" << endl;
        return -1;
    }
    return value;
}

//checking for user to change input
bool canChange(Board mainBoard, int coordinates, int value)
{
    //check for fixed values on board
    if (mainBoard.isFixedValue[coordinates])
    {
        return false;
    }

    //check for resetting user input values to 0
    if (value == 0)
    {
        return true;
    }

    //check if there are duplicates in row, column, block
    if (anyDuplicates(mainBoard.values, coordinates, value))
    {
        return false;
    }

    //passed all checks
    else
    {
        return true;
    }
}


/*check for any duplicates in the rows, columns, and blocks
*  SET row = coordinates / 9
*  SET column = coordinates % 9
*  WHILE c = 0 to 8
*     IF value == mainBoard[coordinates / 9][c]
*        RETURN false
*  WHILE r = 0 to 8
*     IF value == mainBoard[r][coordinates % 9]
*        RETURN false
*  WHILE r = beginning row to r+3
*     WHILE c = beginning column to c+3
*        IF value == mainBoard[r][c]
*           RETURN false
*/
bool anyDuplicates(int board[], int coordinates, int value)
{
    int row = coordinates / 9;
    int column = coordinates % 9;

    //Check if value already exists in row or column
    for (int i = row * 9; i < ((row * 9) + 9); i++)
    {
        if (value == board[i])
        {
            return true;
        }
    }

    //Check if value already exists in column
    for (int i = column; i < 81; i+=9)
    {
        if (value == board[i])
        {
            return true;
        }
    }

    //Check if value already exists in 3 X 3 block
    while (column % 3 != 0)   //Move to first column in block
    {
        column--;
    }
    while (row % 3 != 0)//Move to first row in block
    {
        row--;
    }
    for (int r = row; r < (row + 3); r++)
    {
        for (int c = column; c < (column + 3); c++)
        {
            if (value == board[((r * 9) + c)])
            {
                return true;
            }
        }
    }

    //if gets here and there are no duplicates in that row, column, or block
    return false;
}

//editSquare
//set board[coordinates] = value
//return
void editSquare(int board[], int coordinates, int value)
{
    //Update Board
    board[coordinates] = value;
    return;
}


//fills in all values where the possible values for that cell is one number
//returns true if board was solved
//returns false if board was not solved
bool checkPossibles(Board &newBoard)
{
    bool noChanges;

    //loop until the only one possible value is filled in
    do
    {
        noChanges = true;
        for (int i = 0; i < 81; i++)
        {
            int possibles = 0;
            int value;

            //if fixed value set all other possible values to false
            if (newBoard.isFixedValue[i])
            {
                for (int num = 0; num < 9; num++)
                    newBoard.isPossibleValue[i][num] = false;
                newBoard.isPossibleValue[i][newBoard.values[i] - 1] = true;
            }

            else
            {
                //test numbers 1 through 9 if they are possible values
                for (int guess = 1; guess <= 9; guess++)
                {
                    if (canChange(newBoard, i, guess))
                    {
                        value = guess;
                        newBoard.isPossibleValue[i][guess - 1] = true;
                        possibles++;
                    }
                    else
                    {
                        newBoard.isPossibleValue[i][guess - 1] = false;
                    }
                }
            }

            if (possibles == 1)  //only one possible value so fill in
            {
                newBoard.values[i] = value;
                newBoard.isFixedValue[i] = true;
                noChanges = false;
            }
        }
    }
    while(noChanges == false);

    //Check to see if solved
    if (isSolved(newBoard))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*adds the total number of possibles for each number in each row, column, and blcok.
//if the total is 1 it will fill that number in and update the possibles in
//each square with the function checkPossibles
float solve(Board &newBoard)
{
int coordinates = 0;
bool noChanges;
do
{
noChanges = true;

//Fill in one possible answer squares and exit if solved
//We will do this after each Row, Column, and Block check
if (checkPossibles(newBoard))
return true;

//Fill in the known numbers for each ROW
for (int i = 0; i < 81; i += 9)
for(int guess = 1; guess <= 9; guess++)//Numbers 1 to 9
int total = 0;

//Test the number on the row
for(int iRow = i; iRow < (i + 9); iRow++)
if(!newBoard.isFixedValue[iRow])
total += newBoard.isPossibleValue[iRow][guess - 1];

if (total == 1)//We have found an answer!
for(int iRow = i; iRow < (i + 9); iRow++)
if (newBoard.isPossibleValue[iRow][guess - 1] && !newBoard.isFixedValue[iRow])
{
newBoard.values[iRow] = guess;
newBoard.isFixedValue[iRow] = true;
noChanges = false;
}
}
}


//Fill in one possible answer squares and exit if solved
if (checkPossibles(newBoard))
return true;

//This will fill in the known numbers for each COLUMN
int i;
for (i = 0; i < 9; i++)
int guess;
for(guess = 1; guess <= 9; guess++)//Numbers 1 to 9
int total = 0;

//Test the number on the column
int iColumn;
for(iColumn = i; iColumn < 81; iColumn += 9)
if(!newBoard.isFixedValue[iColumn])
total += newBoard.isPossibleValue[iColumn][guess - 1];

if (total == 1)//We have found an answer!
for(int iColumn = i; iColumn < 81; iColumn += 9)
if (newBoard.isPossibleValue[iColumn][guess - 1] && !newBoard.isFixedValue[iColumn])
{
newBoard.values[iColumn] = guess;
newBoard.isFixedValue[iColumn] = true;
noChanges = false;
}


//Fill in one possible answer squares and exit if solved
if (checkPossibles(newBoard))
return true;

//fill in the known numbers for each block
int r;
for (r = 0; r < 81; r += 27)
int c;
for (c = 0; c < 9; c += 3)
int i;
i = r + c;//puts me at the beginning of each block
int guess;
for(guess = 1; guess <= 9; guess++)//Numbers 1 to 9
int total = 0;

//Test the number on the column
int iBlockR;
int iBlockC;
for(iBlockR = i; iBlockR < (i + 27); iBlockR += 9)
for (int iBlockC = iBlockR; iBlockC < (iBlockR + 3); iBlockC++)
if(!newBoard.isFixedValue[iBlockC])
total += newBoard.isPossibleValue[iBlockC][guess - 1];

if (total == 1)//We have found an answer!
int iBlockR;
int iBlockC;
for(iBlockR = i; iBlockR < (i + 27); iBlockR += 9)
for (iBlockC = iBlockR; iBlockC < (iBlockR + 3); iBlockC++)
if (newBoard.isPossibleValue[iBlockC][guess - 1] && !newBoard.isFixedValue[iBlockC])
newBoard.values[iBlockC] = guess;
newBoard.isFixedValue[iBlockC] = true;
noChanges = false;

//fill in one possible answer squares and exit if solved
if (checkPossibles(newBoard))
{
return true;
}

while(noChanges == false);

//if it's not solved by now, then it's time to use the big guns
if (!isSolved(newBoard))
bruteForce(newBoard);
}


//This will go to the first empty square and fill it in with the first
//valid number and then advance to the next square. If it finds a square
//where all numbers fail it backtracks and fills in the last square with
//the next valid number and will continue until the Board is solved.
bool bruteForce(Board &board)
{
    int coordinates = 0;
    int guess = 1;

    for (int i = 0; i < 81;i++)
    {
        //Check for solved if on last square
        if (i == 81 && isSolved(board))
            return true;

        //Go to next non fixed cell
        while (board.isFixedValue[i])
            i++;

        //Set guess to 1 more than current value in cell and reset value
        guess = board.values[i] + 1;
        board.values[i] = 0;

        for (; board.values[i] == 0 && guess <= 9; guess++)
            if (board.isPossibleValue[i][guess -1] &&
                canChange(board, i , guess))
                board.values[i] = guess;

            //If ALL #s fail go back to previously changed value
            else
                if (guess == 9)
                {
                    //Step one back
                    i--;

                    //Continue to previous cell until value isn't fixed or 9 or
                    //has only one possible value
                    while(board.isFixedValue[i] || board.values[i] == 9)
                    {
                        //If value is 9 needs to be set back to zero
                        if (board.values[i] == 9 && !board.isFixedValue[i])
                            board.values[i] = 0;
                        i--;
                    }
                    i--; //Will be incremented after loop
                }
    }
    return true;
}
*/

    //loops through to see if the board is solved/all values filled in
    bool isSolved(Board board)
{
    //if at least one value is zero the board is not solved
    for (int i = 0; i < 81; i++)
        if (board.values[i] == 0)
        {
            return  false;
        }
    else
    {
        return true;
    }
}


//Clears all values that aren't fixed values
void clearBoard(Board &board)
{

    for (int i = 0; i < 81; i++)
        if (!board.isFixedValue[i])
        {
            board.values[i] = 0;
            return;
        }
}
