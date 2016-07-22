/*******************************************************************
* Author: Tatyana Vlaskin
* Week 6, Problem 2
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
* File name: problem2.cpp
********************************************************************/
#include <iostream>
#include <string>
using namespace std;
const int SIZE = 100;
// asks the user to input strings
void userInput(char (&string1)[SIZE], char (&string2)[SIZE]);
//compares strings
void stringCompare (char (&string1)[SIZE], char (&string2)[SIZE]);

int main()
{
    char string1[SIZE];
    char string2[SIZE];
    userInput(string1, string2);
    stringCompare (string1, string2);
    return 0;
}

void userInput(char (&string1)[SIZE], char (&string2)[SIZE]) // lets the user input strings
{
        cout << "Input string # 1: ";
        cin.getline(string1, SIZE);
        cout<<endl;
        cout << "Input string # 2: ";
        cin.getline(string2, SIZE);//console output
        cout<<endl;
}

void stringCompare (char (&string1)[SIZE], char (&string2)[SIZE]){ // compares strings

     int comparison = 0;
     comparison = strcmp(string1, string2);
     if (comparison > 0){
        cout << "String : " << string1 << " is greater than string: " << string2;
     }
     else if (comparison == 0){
         cout << "String : " << string1 << " is equal to string: " << string2;
     }
     else{
        cout << "String : " << string1 << " is less than string: " << string2;
    }
}
