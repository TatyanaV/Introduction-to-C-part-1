/*******************************************************************
* Author: Tatyana Vlaskin
* Description:
*   Program asks a user to input their first, middle and last name
*   and output the name in the following format: Last, First, Middle
*   initial.
* Input: User inputs their first, middle and last name
* Output:
Enter your first, middle and last name: tatyana vlaskin
Your name is: vlaskin, tatyana

OR

Enter your first, middle and last name: tatyana a. vlakin
Your name is: vlakin, tatyana a.

OR

Enter your first, middle and last name: tatyana anatoliya vlaskin
Your name is: vlaskin, tatyana a.

* Last Modification date: 04.20.2014
* File name: problem2.cpp
********************************************************************/
 #include <iostream>
 #include <string>
 using namespace std;
 int main( )
 {
    //variable declaration
    string firstEntry, secondEntry, thirdEntry, combinedName;
    // console output, user is asked to eneter their name
    cout << "Enter your first, middle and last name: ";
    // it is expected that firstEntry is first name and secondEntry is
    // middle name if it exists or last name is middle name was not entered
    cin >> firstEntry >> secondEntry; // fist and second word that will be entered
    // checkes whether 3rd word was entered
    // please note that if there is no middle name, only 2 words are entered
    // this if statment takes a look at the next character to be read by cin. If its not \n
    // this is an idication that there are 3 words, thus there is a middle name
    if (cin.peek()  != '\n')
    {
        cin >> thirdEntry; // third word that is entered ( last name)
	    combinedName = thirdEntry + ", " + firstEntry + " " + secondEntry.at(0) + ". ";
	    cout << "Your name is: "; // console output
	    cout << combinedName << endl; // console output
	  }
        // if 3rd word was not entered, we know that middle name does not exist.
        // thus, second word is the last name
	  else {
        combinedName = secondEntry + ", " + firstEntry;
	    cout << "Your name is: "; // console output
	    cout << combinedName << endl;
	  }

 return 0;// end of program
 }

