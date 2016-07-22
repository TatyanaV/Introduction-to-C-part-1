/*******************************************************************
* Author: Tatyana Vlaskin
* Description:
* This is a 2 player guess game. Player 1 enters a number and Player 2
* tries to guess it. Programmer defines acceptable range of numbers.
* If the number is outside the range User 1 is asked to reenter the number.
* Once the entered number is within the acceptable range Player 2 is
* asked to guess a number. Program tells the Player 2 how many guesses
* they have left. Player 2 is given a range of possible numbers.
* The range of numbers is changed if the Player 2 does not make correct
* guess to reflect the effect of the Player 2 newest guess. If Player 2
* enters a number that is not in the possible range, the range is not changed,
* they get a warning that INVALID entry was made and they use up guesses
* by making invalid entries. Once the number is guessed user 2 get congratulation
* message. If the number is not guessed, user 2, finds out what was correct
* number, how far they were from that number. At the end of the game either
* if the user guesses a number or runs out of guesses, they have an option
* to start the game over.
* Input: One user inputs a number to guess and second user guesses a number
* Output:
USER 1.
Enter a number from  1 to 100 for other user to guess: 200

200 is higher than the range of this game. Try again.

USER 1.
Enter a number from  1 to 100 for other user to guess: 50

USER 2
Guess a number  from 1 to 100 entered by 1st user.
You can have 5 guesses. Enter a number: 6

USER 2
Your guess is too low. You have 4 guesses left.
Please enter a number from 7 to 100. Enter a number: 80

USER 2
Your guess is too high. You have 3 guesses left.
Please enter a number from 7 to 79. Enter a number: -9

USER 2
INVALID ENTRY! -9 is lower than the allowed range. Try again.
 You have 2 guesses left.
Please enter a number from 7 to 79. Enter a number: 500

USER 2
INVALID ENTRY! 500 is higher than the allowed range. Try again.
 You have 1 guesses left.
Please enter a number from 7 to 79. Enter a number: 50

USER 2
Congratulations!!! You guessed the number. Game is over!

Would you like to play one more time?
Press Y to play again. Press N to end the game.

OR

USER 1.
Enter a number from  1 to 100 for other user to guess: 50

USER 2
Guess a number  from 1 to 100 entered by 1st user.
You can have 5 guesses. Enter a number: 90

USER 2
Your guess is too high. You have 4 guesses left.
Please enter a number from 1 to 89. Enter a number: 8

USER 2
Your guess is too low. You have 3 guesses left.
Please enter a number from 9 to 89. Enter a number: 35

USER 2
Your guess is too low. You have 2 guesses left.
Please enter a number from 36 to 89. Enter a number: 80

USER 2
Your guess is too high. You have 1 guesses left.
Please enter a number from 36 to 79. Enter a number: 56

USER 2
You lost! You do not have any guesses left.
The secret number was: 50. Game is over.
Your closes guess was: 56
Would you like to play one more time?
Press Y to play again. Press N to end the game.
* Last Modification date: 04.13.2014
* File name: guessf.cpp
********************************************************************/

#include <iostream> //Macro that includes librar
#include <math.h> // Includes math library
using namespace std; //Global statement

int main () //Main function
{
    bool playAgain = true;
    //loop is entered if user # 2 decided to play again
    while (playAgain == true)
    {
    int numberUser1 = 0;
    int min =1, max =100;
    //cout << "USER 1. \n";
    do {
        cout << "USER 1. \n";
    cout << "Enter a number from  " << min << " to " << max
    << " for other user to guess: ";
    cin >> numberUser1;
    cout << "\n";

        if(numberUser1 > max)
        {
            cout<< numberUser1 <<" is higher than the range of this game. Try again."<<endl;
            cout << "\n";
            //good_guess = false;
        }
        else if(numberUser1 < min)
        {
            cout<< numberUser1<<" is lower than the range of this game. Try again."<<endl;
            cout << "\n";
            //good_guess = false;
        }
        }  while ( (numberUser1 > max) || (numberUser1 < min));
// this part is for the user 2 to guess the number that was entered
//by user #1

            int guesses = 5;
            int numberUser2;    //number that user 2 will enter
            cout << "USER 2 \n";
            cout << "Guess a number  from " << min <<" to " << max << " entered by 1st user.\n"
            << "You can have " << guesses << " guesses. Enter a number: ";
            cin >> numberUser2; // asks the user #2 to make a guess
            cout << "\n";

//int differenceMin;
 // int differenceMax;

        bool correctGuess = false; //variable declaration
        // executed until user guees a number
        while (correctGuess == false)
        {
            cout << "USER 2 \n";
            //LOOP IS ENTERD IF THE USER GUESSED THE NUMBER
            if (numberUser2 == numberUser1 && guesses >= 0)
            {
                cout << "Congratulations!!! You guessed the number. Game is over! \n";
                correctGuess = true; //Changes bool value to true , indication not to enter while loop any more
                cout << "\n";// new line
            }
           //If the number is not guessed, this loop is entered
           else
            {
                guesses--; // keeps track how many guesses are left

                //EXECUTED IF THE GUESS IS TOO HIGH
                if(numberUser2 > max && guesses > 0)
                {
                    cout << "INVALID ENTRY! ";
                    cout<< numberUser2 <<" is higher than the allowed range. Try again.\n "
                    << "You have " << guesses  <<" guesses left. \n"
                    << "Please enter a number from " <<min <<" to " << max <<". "
                    << "Enter a number: ";//asks user # to enter the number
                    cin >> numberUser2;
                    cout << "\n";
                }

                // IF THE USER ENTERS A NUMBER THAT IS TOO HIGH
                // and there are still guesses left
                //AND THE GUESS IS IN ACCAPTABLE RANGE
                else if (numberUser2 > numberUser1 && guesses > 0)
                {
                    cout << "Your guess is too high. You have " << guesses
                    << " guesses left.\n"; // lets the user know that guess is too high
                    max = (numberUser2-1); // change the maximum of the range
                    //lets the user know what is the new range
                    cout << "Please enter a number from " <<min <<" to " << max <<". "
                    << "Enter a number: ";//asks user # to enter the number
                    cin >> numberUser2; //lets the user make an entry
                    cout << "\n"; //new line
                }

                //IF THE USER ENTERS NUMBER THAT IS HIGHER THAN MIN
                // and there are still guesses left
                else if(numberUser2 < min && guesses > 0)
                {
                    cout << "INVALID ENTRY! "; // lets the user know that invalid entry was made
                    //lets the user know what was the problem with the number entered
                    cout<< numberUser2<<" is lower than the allowed range. Try again.\n "
                    << "You have " << guesses  <<" guesses left. \n" ;
                    //range is not changed when invalid entry is made
                    cout << "Please enter a number from " <<min <<" to " << max <<". ";
                    cout << "Enter a number: ";//asks user # to enter the number
                    cin  >> numberUser2; // alows the user to enter a number
                    cout << "\n"; //new line
                }

                //EXECUTED WHEN THE GUEES IF TOO LOW
                else if ((numberUser2 < numberUser1) && guesses > 0)
                {
                    //lets the user know that the guess was too low
                    //lets them know how many guesses they have left
                    cout << "Your guess is too low. You have " << guesses
                    << " guesses left.\n";
                    min = numberUser2 + 1; //adjust the range
                    //lets the user know what is the range
                    cout << "Please enter a number from " <<min << " to " << max <<". "
                    << "Enter a number: "; //asks the user to enter a number
                    cin >> numberUser2; //allows the user to enter a number
                    cout << "\n";
                }

                //EXECUTED WHEN THERE ARE NO MORE GUEESES LEFT
                else
                {
                    //lets the user know that they are out of guesses and
                    //that they've lost. lets them know what was the secret
                    //number
                    cout << "You lost! You do not have any guesses left. \n"
                    << "The secret number was: " << numberUser1
                    << ". Game is over.\n";

                    //when the use make the last wrong entry, I want to change
                    // range. these two loops are required because
                    if ((max > numberUser2) && (numberUser2 > numberUser1))
                    {
                        max = (numberUser2-1);
                    }
                    else if ( (min > numberUser2) && ((numberUser2 < numberUser1)))
                    {
                        min = numberUser2 + 1;
                    }
                      //LETS THE USER KNOW HOW CLOSE THEY WERE
                      //if difference between new min (which reflects lowest number that
                        //the use have enters) and true number is smaller than
                        //difference between new max (which reflects highest number user 2
                        //entered and if min/max was changed by the user this loop is enterd
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

                    // IF EVERY SINGLE ENTRY THAT THE USER MADDE IS INVALID
                    //IT DOES NOT WORK IF USER KEEPS ENERING NEGATIVE VALUES
                    //ALL THE TIME, BUT IT WORKS FOR POSITIVE ABOVE MAX
                    //i'VE DECIDED TO DELET THIS LAST MINUTE
                   /*else if((numberUser2 < 1) || (numberUser2 > max))
                    {
                        cout << "All your entries were invalid. \n";
                        cout << "\n";
                    }
*/

        correctGuess = true; // OUT OF GUESES, SO WE DO NOT WANT TO ENTER LOOP
             }
        }
    }

        //declaration of the variable for a user to decide if
        //they want to play again
        char decision;
        //asks the user if they want to play a game one more time
        cout << "Would you like to play one more time?\n"
        //lets the user that they can either chose N or Y
        << "Press Y to play again. Press N to end the game. ";
        cin >> decision; // allows the user to make a decision
        cout << endl;

            //  executed only if  user does not want to play again need a n or no answer
        if ( decision == 'n' || decision == 'N' )
        {
            playAgain = false; // change the bool to false and paly again loop is not entered

        }
    }

    return 0; //closing
}


