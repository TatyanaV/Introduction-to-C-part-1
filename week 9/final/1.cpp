/*******************************************************************
* Author: Tatyana Vlaskin
* Week 9, Problem 1
* Description: user is asked for a name and age. Entries are echoed
back to the user. This program uses class called person . All class
variables are public
* Input: name and age
Output:
***********************************************************************
What is your first name? tatyana
How old are you? 28

Your name is: tatyana
You are 28

************************************************************************
* Last Modification date: 06.01.2014
* File name: 1.cpp
********************************************************************/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class person // newperson is the tag
{
    public:
        char name[20];// member 1
        int age;// member 2

};

person new_person();// function that asks for name and age
void integerCheck(int &age);// checks to make sure that integer was entere for age

int main(){

    new_person();
    return 0;
}

// function that asks for name and age
person new_person()
{
	person person1; // creating a variable of type person
	cout << "What is your first name? ";
	cin.get (person1.name, 20);
   	cout << "How old are you? ";
	cin >> person1.age;
	integerCheck(person1.age);

    cout << endl << "Your name is: " << person1.name << endl;
	cout << "You are " << person1.age << endl;

	return person1;

}
//function that checks that integer was entered for age
void integerCheck(int &age){

    while(cin.fail() || age!= static_cast<int>(age) || age <=0)
    {
        cout << "Error, invalid age enetered.  " << endl
             << "Pease make a different entry: ";
        cin.clear();
        cin.ignore(80,'\n');
        cin >> age;
        }

}

