/*******************************************************************
* Author: Tatyana Vlaskin
* Week 9, Problem 3
* Description: user is asked for a name and age. Entries are echoed
back to the user. Entered age is incremented and the user is notified
how old they will be next year. This program uses class called person .
All class variables are private
* Input: name and age
Output:
***********************************************************************
What is your name? tanya
Your name is: tanya
How old are you? 12
You are 12
Next year you will turn 13

************************************************************************
* Last Modification date: 06.01.2014
* File name: 3.cpp
********************************************************************/

#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

class person // newperson is the tag
{
    private:
        char name[20];// member 1
        int age;// member 2
    public:
        char *getName();// function will ask user to enter name
        int getAge();// function will ask user to enter age
        void results(person &person1);// function will display age and name back to the user
        void having_birthday(person & person1);// function will increment age by 1
};

void integerCheck(int &age);// checks to make sure that integer was entere for age

int main(){

    person person1;
    person1.results(person1);
    person1.having_birthday(person1);

    return 0;
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
//function asks the user to enter name
char *person::getName(){
    char name1 [20];
    cout << "What is your name? ";
	cin.get (name1, 20);
    cin.ignore(80,'\n');
    strcpy (name,name1);
    return name;
}
//function asks the user enter age
int person::getAge(){
    cout << "How old are you? ";
	cin >> age;
	integerCheck(age);
    return age;
}
//function displays age and name back to the user
void person::results(person &person1){

    cout << "Your name is: " << person1.getName() << endl;
    cout << "You are " << person1.getAge() << endl;
}
//function increments age by 1
void person::having_birthday(person & person1)
{
    age = age + 1;
    cout << "Next year you will turn " << person1.age;
}
