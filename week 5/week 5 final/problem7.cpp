
/*******************************************************************
* Author: Tatyana Vlaskin
* Description:
* First player enteres a word and second players guesses it one letter
at a time
* Input: First player enters a work. Second player enters one letter
at a time to guess a word.
* Output:
Player 1, enter a secret word for the other user to guess: mom

You can make only 3 incorrect guesses.
You missed 0 times.
Enter a letter in word --- : m

You can make only 3 incorrect guesses.
You missed 0 times.
Enter a letter in word m-m : m
m is already in the word.

You can make only 3 incorrect guesses.
You missed 0 times.
Enter a letter in word m-m : k
k is not int the word.

You can make only 2 incorrect guesses.
You missed 1 times.
Enter a letter in word m-m : o

Congratulation! You won! The word was mom.

You missed 1 times.
Would you like to play again? (y/n):

* Last Modification date: 05.04.2014
* File name: problem7.cpp
********************************************************************/
#include <iostream>  //library for input and output
#include <string>    //library for stings
#include <cctype>
using namespace std; //global statment
//Function to discard remaining characters in input line
void newLine();
// function to check if the word is valid
bool validWord(const string word);
// function to play the game
int playGame (string word);

bool alphabet_b [26]; //when a person guesses a letter the corresponding spot in the true false array becomes false

char alphabet_char [26]={ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                 'n', 'o', 'p', 'q', 'r', 's', 't','u', 'v', 'w', 'x','y', 'z' }; //used for keeping track of remaining letters not guessed

// main function
int main()
{
      char playAgain;

   do
   {
    cout << "Player 1, enter a secret word for the other user to guess: ";
    string word;
    playGame(word); // not sure if you need this

    cout << endl << "Would you like to play again? (y/n): ";
    cin >> playAgain;
    newLine();  //clear input stream
    } while (playAgain == 'y' || playAgain == 'Y');


   return 0;
}


// function to discart remaining characters in the input line
//taken from the book

void newLine()
{
   char symbol;
   do
   {
      cin.get(symbol);
   } while (symbol != '\n');
}

 // function to check that user 1 entered valid word
 // took this function from Ian Bender on discussion board
 // my initial function failed
bool validWord(const string word)
{
   for (int i = 0; i < word.length(); i++)// loop through the word
     {
      // checks if every single character is a letter
      if (isalpha(word.at(i)) == 0)
         return false;
   }
   return true;
}
// function of a game
int playGame (string word)
{

   do //loop until valid secret word is given
   {
      getline(cin, word);
      if (!validWord(word))
      {
         cout << "Invalid word!\n"
              << "Enter a word with no space, numbers or special characters: ";
      }
   } while (!validWord(word));

    int guesses =  3;// the user can make only 3 incorrect guesses.
    int exposed = 0;
    string display = word; // declaration of the display variable

    for (int i = 0; i < display.length(); i++)
    //word.at(i) = tolower(word.at(i)); // word will be replaced with '-' characters
        display [i] = '-'; //there will a '-' for each letter in the word
     // while there are still letters in the word that need to be quesses and there are guesses left
         	for (int k=0; k<25; k++)
	{
		alphabet_b[k]=true; //sets all values of alphabet tracking array to true
	}

    while(exposed < word.length() && guesses > 0) {
        cout <<endl << "You can make only " << guesses << " incorrect guesses. " ; // lets the user know now many gueeses they have
        cout << "Possible entries: ";
        for (int k=0; k<25; k++)
		{
			if (alphabet_b[k]==true) //shows what letters the person has not guessed yet
			{
               cout << alphabet_char[k] << ", ";
			}
		}
        cout << "\nEnter a letter in word "; // asks the user to enter a letter
        cout << display << " : ";
        char response; // declaration of the variable to user to enter a letter
        cin >> response; // console input, lets the user enter a letter
        bool goodGuess = false;// bool declaration for guess
        bool duplicate = false; // bool declaration for duplicate

        for(int i=0; i < word.length(); i++) // loop through the word that the play1 enetered

            if(response == word[i]) // if the letter that was entered by the player2 was already guessed
            if (display [i] == word [i]) // if the letter was guesses
            {
                cout << response << " is already in the word.\n"; // lets the user know that the letter was guesses already
                duplicate =true; //changed bool duplicte to 'true'
                break; // we will go to the top. Duplicate entries not be counted as a miss or wrong guess
            }
            else
            { // if entered letter is in the word and was not guessed previously
                cout << endl << "Correct guess.";
                display[i] = word [i]; // exposes the letters that was just eneterd
                exposed++; // counts the exposed letters
                goodGuess =true; // guess was good, so we change bool to good
            }
        if (duplicate) // if duplicate letter was gueesed we just keep looping
        continue; // we continue
        // if letter that was entered is not good
        if (!goodGuess)
        {
            cout << endl << "Incorrect guess."<< endl;
            guesses--;// decrementing guesses
            // let the user know that the letter is not in the word
            cout << response << " is not in the word." << endl;

        }
                		for (int k=0; k<26; k++)
		{
			if (alphabet_char[k]==response) //matches up alphabet character with the guess
			{
				alphabet_b[k]=false; //changes the value to false for the posotion of the letter of the guess. example b would be position 1
			}
		}
    }
    // if user runs out of guesses and does  not guess a word
    if (exposed < word.length() && guesses <= 0)
    {
        cout << "You lost. You are out of guesses."<< endl;
        cout << "The secret word was: " << word << endl;
        //return;
        cout << "You did not guess the following letters: ";
        for (int k=0; k<word.length(); k++) //this will show what letters the person was missing from the secret word when they ran out of guesses
		{
		    //cout << "You did not guess the following letters: ";
			if (display [k] != word [k])
			{
				cout << word[k] << ", ";
			}
			//cout << endl;
		}
    }
    // if wins
    else
    {
    cout << endl << "Congratulation! You won! The word was " << word << "." << endl;
    }

}
