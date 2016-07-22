/*******************************************************************
* Author: Tatyana Vlaskin
* Week 6, Problem 6
* Description:
* Program asks the usee to enter two strings and compares them
* Input: User needs to enter 2 strings
Output:
***********************************************************************
Input string # 1: today is mothers day

Input string # 2: lets celebrate

String : today is mothers day is greater than string: lets selebrate


************************************************************************
* Last Modification date: 05.11.2014
* File name: problem6.cpp
********************************************************************/
#include <iostream>  //library for input and output
#include <string>    //library for stings
#include <cctype>
using namespace std; //global statment
//Function to discard remaining characters in input line
void newLine();
// function to check if the word is valid
void randomize (string phrase_array[], int n);
bool validWord(const string word);
// function to play the game
int playGame (string word);
void swap (int &a, int &b);
string pickWord(string phrase_array, int SIZE);
const int SIZE = 12;
char response;
bool alphabet_b [27]; //when a person guesses a letter the corresponding spot in the true false array becomes false

char alphabet_char [27]={ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                 'n', 'o', 'p', 'q', 'r', 's', 't','u', 'v', 'w', 'x','y', 'z' }; //used for keeping track of remaining letters not guessed

	string phrase; //used to hold the phrase
	string temp;
    string selectedString;
	int words; //holds value of number of words in phrase
	int wordpick; //random variable used to determine which word in array gets added to phrase
	string phrase_array[SIZE]={"garnet","amethyst","diamond","emerald","pearl","alexandrite","ruby","peridot","opal","topaz","citrine","turquise"};
///////////////////////////////////////////////
// main function
int main()
{

char playAgain;

   do
   {
   srand(time(0));
       words=rand()%(3-2+1) +2; //basically I am using a rand() % (max1 - min1+ 1) + min1; formula to select a phrase.
              // phrase randomly be made minimum from 3 word from array and maximum from 4 words.
        int i;
        int wordNumber =1;
		while(wordNumber>=1 && wordNumber<=words)
		{
		    srand(time(0));
		    int n = sizeof(phrase_array)/ sizeof(phrase_array[0]);
            randomize (phrase_array, n);// randomize array, see http://www.geeksforgeeks.org/shuffle-a-given-array/
			//wordpick=rand()%12;//RANDOMLY PICKS A WORD FROM THE ARRAY
            wordpick = rand()%SIZE;
            temp=phrase_array[wordpick];
            phrase=phrase+temp;
			wordNumber++;
		}
        cout << "I DECIDED TO KEEP THIS IN THE CODE." << endl;
        cout << "THIS WILL SHOW HOW MANY WORDS WILL BE SELECTED FROM THE ARRAY" << endl;
        cout << "AND THE STRING THAT NEEDS TO BE GUESSED." << endl;
		cout << phrase<< endl;
		cout << words << endl;
		//cout <<phrase;
            playGame(phrase); // not sure if you need this

    cout << endl << "Would you like to play again? (y/n): ";
    cin >> playAgain;
    newLine();  //clear input stream
    } while (playAgain == 'y' || playAgain == 'Y');


   return 0;
}

// A utility function to swap to integers
void swap (int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// A function to generate a random permutation of arr[]
void randomize ( string phrase_array[], int n )
{
    // Use a different seed value so that we don't get same
    // result each time we run this program
    srand ( time(NULL) );

    // Start from the last element and swap one by one. We don't
    // need to run for the first element that's why i > 0
    for (int i = n-1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);

        // Swap arr[i] with the element at random index
        swap(phrase_array[i], phrase_array[j]);
    }
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

bool validWord(char word)
{

     {
      // checks if every single character is a letter
      if (isalpha(word) == 0)
         return false;
   }
   return true;
}
// function of a game
int playGame (string word)
{

    int guesses =  3;// the user can make only 3 incorrect guesses.
    int misses = 0;
    int exposed = 0;
    int i =0;
    string display = word; // declaration of the display variable

    for (i = 0; i < display.length(); i++)
          display [i] = '-'; //there will a '-' for each letter in the word
     // while there are still letters in the word that need to be quesses and there are guesses left

     	for (i=0; i<26; i++)
	{
		alphabet_b[i]=true; //sets all values of alphabet tracking array to true
	}

    while(exposed < word.length() && guesses > 0) {
        cout <<endl << "You can make only " << guesses << " incorrect guesses. " ; // lets the user know now many gueeses they have
        cout <<endl<< "You missed " << misses << " times. " << endl; // lets the user know how many time they missed
        ////cout << "Possible entries: " << alphabet_char << endl;
         cout << "Possible entries: ";
        		for (i=0; i<26; i++)
		{
			if (alphabet_b[i]==true) //shows what letters the person has not guessed yet
			{
               cout << alphabet_char[i] << ", ";
			}
		}
		cout << endl;



        cout << "Enter a letter in a string of words" << endl; // asks the user to enter a letter
        cout << display << " : ";
        char response; // declaration of the variable to user to enter a letter

   do //loop until valid secret word is given
   {
      //getline(cin, response);
      cin>>response;
      if (!validWord(response))
      {
         cout << endl << "Invalid entry!\n"
              << "Enter a letter. No space, numbers or special characters allowed " << endl
              << "This entry is not counted as a wrong guess. " << endl;
                       cout << "Possible entries: ";
        		for (i=0; i<26; i++)
		{
			if (alphabet_b[i]==true) //shows what letters the person has not guessed yet
			{
               cout << alphabet_char[i] << ", ";
			}
		}
		cout << endl << "Enter a letter please: ";

      }
   } while (!validWord(response));//checks to see if user 2 entered one char and that char is a letter
        bool goodGuess = false;// bool declaration for guess
        bool duplicate = false; // bool declaration for duplicate
         for(int i=0; i < word.length(); i++) // loop through the word that the play1 enetered

       // cout << alphabet_char[i] << ", " << endl; // DEBUGGING PURP

            if(response == word[i]) // if the letter that was entered by the player2 was already guessed
            if (display [i] == word [i]) // if the letter was guesses
            {
                cout << endl << response << " is already in the word.\n"; // lets the user know that the letter was guesses already
                cout << "This is not conted as a wrong guess. " << endl;
                duplicate =true; //changed bool duplicte to 'true'
                break; // we will go to the top. Duplicate entries not be counted as a miss or wrong guess
            }
            else
            { // if entered letter is in the word and was not guessed previously
                cout << endl << "Correct guess.";
                display[i] = word [i]; // exposes the letters that was just eneterd
                //alphabet_char
                exposed++; // counts the exposed letters

                goodGuess =true; // guess was good, so we change bool to good

                	            }
        if (duplicate) // if duplicate letter was gueesed we just keep looping
        continue; // we continue
        // if letter that was entered is not good
        if (!goodGuess)
        {
            cout << endl << "Incorrect guess."<< endl;
            misses++; // increment misses
            guesses--;// decrementing guesses

            // let the user know that the letter is not in the word
            cout << response << " is not in the word." << endl;

        }

        		for (i=0; i<26; i++)
		{
			if (alphabet_char[i]==response) //matches up alphabet character with the guess
			{
				alphabet_b[i]=false; //changes the value to false for the posotion of the letter of the guess. example b would be position 1
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
    cout <<endl<< "You missed " << misses << " times. " << endl;

    }

}
