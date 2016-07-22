//tatyana vlaskin
//week 10 problem 8 project
//8.cpp

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <ctime>
#include<stdio.h>
#include <cstdlib>
using namespace std; //Global statement
int menu();
void stringToUpper(string &str_input_nocase);
void integerCheck(int &integer);
void generalGame();
char goToMenu;
int integerCheck (string INPUT);
void goToMenuFunction();
class number_Game{
	public:
		void numberGuess(number_Game &game);
		number_Game();// constructor with all variable
	private:
		int numberUser1;
        int guesses;
        int numberUser2;    //number that user 2 will enter
        int secretNumber;
        int playerGuess;
        int min;
        int max;
        bool correctGuess;
};
void newLine();
bool validWord(const string word);

class word_Game{
    public:
        //bool validWord(const string word);
        void wordGuess();
        //int playGame (string word);
        word_Game();
        //bool alphabet_b [26]; //when a person guesses a letter the corresponding spot in the true false array becomes false
    private:
       //char alphabet_char [];
        bool alphabet_b [26];
        int playGame (string word);
        string word;
        string display;
        char playAgain;
        int guesses;// the user can make only 3 incorrect guesses.
        int exposed;
        //string display; // declaration of the display variable
        char response;
};

char alphabet_char [26]={'a','b','c','d','e','f','g','h','i','j','k','l','m',
    'n','o','p','q','r','s','t','u','v','w','x','y','z'}; //used for keeping track of remaining letters not guessed
word_Game::word_Game(){

    guesses =  3;// the user can make only 3 incorrect guesses.
    exposed = 0;
    display = word; // declaration of the display variable
  }

class phrase_Game{
// main functionp
    public:
        void phraseGuess();
        int playGame (string word);
        phrase_Game();
    private:
        void swap (int &a, int &b);
        string pickWord(string phrase_array, int SIZE);
        char response;
        bool alphabet_b [26]; //when a person guesses a letter the corresponding spot in the true false array becomes false
        string phrase; //used to hold the phrase
        string temp;
        string selectedString;
        int words; //holds value of number of words in phrase
        int wordpick; //random variable used to determine which word in array gets added to phrase
        int guesses;
        int exposed;
        string word;
        string display;
	};
    const int SIZE = 12;
    void randomize (string phrase_array[], int n);
	string phrase_array[SIZE]={"garnet","amethyst","diamond","emerald",
                                "pearl","alexandrite","ruby","peridot",
                                "opal","topaz","citrine","turquise"};
///////////////////////////////////////////////
phrase_Game::phrase_Game(){

    guesses =  3;// the user can make only 3 incorrect guesses.
    exposed = 0;
    display = word; // declaration of the display variable
    //string display;
    //string word;
}
main(){
    cout << "Please chose an game from the menu below. " << endl;
    menu();
    return 0;
}

int menu(){

    int input;
    cout<<"\n\n\n\t\t*********************************************\n"<<endl;
    //cout << "Welcome to the Community Supported Agriculture (CSA) farm! " << endl;
    cout << " \t\t1. Number Guess \n" << endl;
    cout << " \t\t2. Word Guess \n" << endl;
    cout << " \t\t3. Phrase Guess\n " << endl;
    cout << " \t\t4. Exit Game Menu.\n" <<endl;
    cout << "\t\tAcceptale entries are 1, 2, 3, and 4. " << endl;
    cout<<"\n\t\t*********************************************"<<endl;
    cout << "Make your selection: ";
    string input1;
    getline(cin,input1);
    input = integerCheck(input1);
    //cin >> input;
    //integerCheck(input);

    switch(input)
    {
    case 1:
    {
        cout<<"\nYou've chosen GUESS A NUMBER GAME.\n";
        number_Game play;
        number_Game *pointerNumberGame= new number_Game; // create pointer//person person1;//Creatperson *pointerPerson; // create pointer
        pointerNumberGame->numberGuess(play);
        delete pointerNumberGame;
        break;
    }
    case 2:
    {
         cout<<"\nYou've chosen GUESS A WORD GAME.\n";
         //number_Game play1;
         word_Game *pointerWordGame= new word_Game; // create pointer//person person1;//Creatperson *pointerPerson; // create pointer
         pointerWordGame->wordGuess();
         delete pointerWordGame;
         break;
    }
    case 3:
    {
        cout<<"\nYou've chosen GUESS A PHRASE GAME.\n";
        phrase_Game *pointerPhraseGame= new phrase_Game; // create pointer//person person1;//Creatperson *pointerPerson; // create pointer
        pointerPhraseGame->phraseGuess();
        delete pointerPhraseGame;
        break;
    }
    case 4:
    {
       cout << "Have a nice day.\n";
       break;
    }
    default:
    {
        //this will reset back to menu
        cout<<"Error, invalid entry.\n";
        cout << "Please pick 1, 2, 3, or 4." << endl;
        menu();
        break;
    }
        }
}

number_Game::number_Game()// constructor with all variable
    {
        min =1;
        max =100;
        correctGuess = false;
        guesses = 5;
    }
void number_Game::numberGuess(number_Game &game)
{

    do {
        cout << "USER 1. \n";
        cout << "Enter a number from  " << min << " to " << max
        << " for other user to guess: ";
        string input1;
        getline(cin,input1);
        numberUser1 = integerCheck(input1);
        //cin >> numberUser1;
        //integerCheck(numberUser1);
        cout << "\n";
        if(numberUser1 > max){
            cout<< numberUser1 <<" is higher than the range of this game. Try again."<<endl;
            cout << "\n";
         }
        else if(numberUser1 < min){
            cout<< numberUser1<<" is lower than the range of this game. Try again."<<endl;
            cout << "\n";
        }
        }  while ( (numberUser1 > max) || (numberUser1 < min));
    int numberUser2;    //number that user 2 will enter
    cout << "USER 2 \n";
    cout << "Guess a number  from " << min <<" to " << max << " entered by 1st user.\n"
    << "You can have " << guesses << " guesses. Enter a number: ";
    //cin >> numberUser2; // asks the user #2 to make a guess
    string input1;
    getline(cin,input1);
    numberUser2 = integerCheck(input1);
        //integerCheck(numberUser2);
    cout << "\n";
    bool correctGuess = false; //variable declaration
        // executed until user guees a number
    while (correctGuess == false){
        cout << "USER 2 \n";
        //LOOP IS ENTERD IF THE USER GUESSED THE NUMBER
        if (numberUser2 == numberUser1 && guesses >= 0){
            cout << "Congratulations!!! You guessed the number. Game is over! \n";
            correctGuess = true; //Changes bool value to true , indication not to enter while loop any more
            cout << "\n";// new line
        }
           //If the number is not guessed, this loop is entered
        else{
            guesses--; // keeps track how many guesses are left
            //EXECUTED IF THE GUESS IS TOO HIGH
            if(numberUser2 > max && guesses > 0){
                cout << "INVALID ENTRY! ";
                cout<< numberUser2 <<" is higher than the allowed range. Try again.\n "
                << "You have " << guesses  <<" guesses left. \n"
                << "Please enter a number from " <<min <<" to " << max <<". "
                << "Enter a number: ";//asks user # to enter the number
                    string input2;
                    getline(cin,input2);
                    numberUser2 = integerCheck(input2);
                    cout << "\n";
            }
            else if (numberUser2 > numberUser1 && guesses > 0){
                cout << "Your guess is too high. You have " << guesses
                << " guesses left.\n"; // lets the user know that guess is too high
                max = (numberUser2-1); // change the maximum of the range
                //lets the user know what is the new range
                cout << "Please enter a number from " <<min <<" to " << max <<". "
                << "Enter a number: ";//asks user # to enter the number
                   string input3;
                   getline(cin,input3);
                   numberUser2 = integerCheck(input3);
                   cout << "\n"; //new line
            }
            else if(numberUser2 < min && guesses > 0){
                cout << "INVALID ENTRY! "; // lets the user know that invalid entry was made
                //lets the user know what was the problem with the number entered
                cout<< numberUser2<<" is lower than the allowed range. Try again.\n "
                << "You have " << guesses  <<" guesses left. \n" ;
                //range is not changed when invalid entry is made
                cout << "Please enter a number from " <<min <<" to " << max <<". ";
                cout << "Enter a number: ";//asks user # to enter the number
                string input4;
                getline(cin,input4);
                numberUser2 = integerCheck(input4);
                cout << "\n"; //new line
            }
            //EXECUTED WHEN THE GUEES IF TOO LOW
            else if ((numberUser2 < numberUser1) && guesses > 0){
                //lets the user know that the guess was too low
                //lets them know how many guesses they have left
                cout << "Your guess is too low. You have " << guesses
                << " guesses left.\n";
                min = numberUser2 + 1; //adjust the range
                //lets the user know what is the range
                cout << "Please enter a number from " <<min << " to " << max <<". "
                << "Enter a number: "; //asks the user to enter a number
                string input5;
                getline(cin,input5);
                numberUser2 = integerCheck(input5);
                cout << "\n";
                }
                //EXECUTED WHEN THERE ARE NO MORE GUEESES LEFT
            else{
                //lets the user know that they are out of guesses and
                //that they've lost. lets them know what was the secret
                //number
                cout << "You lost! You do not have any guesses left. \n"
                << "The secret number was: " << numberUser1
                << ". Game is over.\n";
                //goToMenuFunction();
                //when the use make the last wrong entry, I want to change
                // range. these two loops are required because
                if ((max > numberUser2) && (numberUser2 > numberUser1)){
                    max = (numberUser2-1);
                }
                else if ( (min > numberUser2) && ((numberUser2 < numberUser1))){
                    min = numberUser2 + 1;
                }

            if  ((fabs(max - numberUser1) > fabs(min-numberUser1))&& (numberUser2 = (min -1 )))
                    {
                       cout << "Your closes guess was: " << (min -1) << " \n";
                    }
                     //if difference between new min (which reflects lowest number that
                        //the use have enters) and true number is larger than
                        //difference between new max (which reflects highest number user 2
                        //entered and if max/min was changed by the user this loop is enterd
                    else if ((fabs(max - numberUser1) < fabs(min-numberUser1))&& (numberUser2 = (max +1)))
                    {
                        cout << "Your closes guess was: " << (max + 1) << " \n";
                    }
        correctGuess = true; // OUT OF GUESES, SO WE DO NOT WANT TO ENTER LOOP
                       }
        }
    }
        goToMenuFunction();

        }


void integerCheck(int &integer){
    while(cin.fail() ||!cin.good()|| integer!= static_cast<int>(integer))
    {

        cout << "Error, invalid entry. Only integers are allowed.  " << endl
             << "Pease make a different entry: ";
        cin.clear();
        cin.ignore(80,'\n');
        cin.sync ();
        cin >> integer;
        cout << integer;
        }
}

void word_Game::wordGuess(){// used to be main method in the original game
    newLine();
    cout << "Player 1, enter a secret word for the other user to guess: ";
    word_Game game;
    game.playGame(word); // not sure if you need this
    goToMenuFunction();
}
void newLine()
{
   char symbol;
   do
   {
      cin.get(symbol);
   } while (symbol != '\n');
}

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
int word_Game::playGame (string word)
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
    stringToUpper(word);
    display = word;
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
        //char response; // declaration of the variable to user to enter a letter
        cin >> response;
        //cout<< response;
        response = toupper(response);

         // console input, lets the user enter a letter
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
               // cout << endl << "Correct guess.";
                display[i] = word [i]; // exposes the letters that was just eneterd
                exposed++; // counts the exposed letters
                goodGuess =true; // guess was good, so we change bool to good
            }
        if (duplicate) // if duplicate letter was gueesed we just keep looping
        continue; // we continue
        // if letter that was entered is not good
        if (!goodGuess)
        {
           //cout << endl << "Incorrect guess."<< endl;
            guesses--;// decrementing guesses
            // let the user know that the letter is not in the word
            cout << response << " is not in the word." << endl;

        }
        if (goodGuess)
        cout << "\n\nGood guess!\n\n";
        else
        cout << "No luck with that letter!\n\n";
                		for (int k=0; k<25; k++)
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

int phrase_Game::playGame (string word){
    stringToUpper(word);
    display = word;
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
        //char response; // declaration of the variable to user to enter a letter
        cin >> response; // console input, lets the user enter a letter
        response = toupper(response);
        bool goodGuess = false;// bool declaration for guess
        bool duplicate = false; // bool declaration for duplicate
        //////////////////
             ////////////
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
               // cout << endl << "Correct guess.";
                display[i] = word [i]; // exposes the letters that was just eneterd
                exposed++; // counts the exposed letters
                goodGuess =true; // guess was good, so we change bool to good
            }
        if (duplicate) // if duplicate letter was gueesed we just keep looping
        continue; // we continue
        // if letter that was entered is not good
        if (!goodGuess)
        {
           //cout << endl << "Incorrect guess."<< endl;
            guesses--;// decrementing guesses
            // let the user know that the letter is not in the word
            cout << response << " is not in the word." << endl;

        }
        if (goodGuess)
        cout << "\n\nGood guess!\n\n";
        else
        cout << "No luck with that letter!\n\n";
                		for (int k=0; k<25; k++)
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

void phrase_Game::phraseGuess()
{

char playAgain;

     srand(time(0));
       words=rand()%(4-2+1) +2; //basically I am using a rand() % (max1 - min1+ 1) + min1; formula to select a phrase.
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

            goToMenuFunction();
}

// A utility function to swap to integers
void phrase_Game::swap (int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// A function to generate a random permutation of arr[]
void randomize ( string phrase_array[], int n )
{
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

void goToMenuFunction(){
    //char goToMenu;
           cout << endl << "Would you like to go back to the MENU and choose another game? (y/n): ";
            cin >> goToMenu;
             switch(goToMenu)
        {
        case 'y':
        case 'Y':
        //case 'yes':
        //cout << " Set a password. ";
        menu();
        break;

        case 'n':
        case 'N':
            cout <<"\nThank you for using our program.\n";
            cout << "Have a nice day.\n";
        break;

        default:
            cout << "Error, please type Y for yes and N for no" << endl;
            cout << endl << "Would you like to go back to the MENU? (y/n): ";
            cin >> goToMenu;
            break;
        }
}

void stringToUpper(string &str_input_nocase)
{
   for(unsigned int i = 0; i < str_input_nocase.length(); i++)
  {
    str_input_nocase[i] = toupper(str_input_nocase[i]);
  }
  //cout << str_input_nocase;
}

int integerCheck (string INPUT)
{
	int isanint = 'n'; // is it an integer loop condition
	int x; // used in the loop
	int isok ; // used to test for integer
	int NUM; // the integer to be returned

// test to yes if it is an int
				isanint = 'n';

				while (isanint == 'n')
					{
						isok = 1;
						for (x=0; x < INPUT.length(); x=x+1)
							{
// check for digits
								if (((INPUT.at(x) >= '0' && INPUT.at(x) <= '9')))
									{
										isok = 1;
									}
								else
								 	{
// flag as bad and set exit
								 		isok = 0;
								 		x = INPUT.length();
								 	}
							}

/// if it did not pass the test for integer
				if ( isok == 0)
					{
						cout << " That was NOT an integer >0" << endl;
						cout << " Please enter an integer " ;
						getline(cin,INPUT);
						cout << endl;
					}
				else
					{
						NUM = atoi(INPUT.c_str());
						isanint = 'y';
						isok = 1;
					}
			}
 	return NUM;
}
