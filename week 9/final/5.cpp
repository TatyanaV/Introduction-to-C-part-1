#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

/*******************************************************************
* Author: Tatyana Vlaskin
* Week 9, Problem 5
* Description: This program explores how a pointer to an object works
* Input: name and age
Output:
***********************************************************************
Information that you enter below will be used to demonstrate
how pointers to an object work.
What is your name? tanya
Your name is: tanya
How old are you? 28
You are 28

The memory address to the class person is: 0x28ff20
Value stored in the member name can be accessed as: pointerPerson->getName():
tanya
Value stored in the member name can be accessed as: (*pointerPerson).getName():
tanya
Value stored in the member age can be accessed as: pointerPerson->getAge():
28
Value stored in the member age can be accessed as: (*pointerPerson).getAge():
28
Enter names and ages of 3 people who are nominated to the best TA award.
What is the name of the 1 TA? 1
How old is the 1 TA ? 20
What is the name of the 2 TA? 2
How old is the 2 TA ? 30
What is the name of the 3 TA? 3
How old is the 3 TA ? 40
ARRAY OF OBJECTS:
Accessing member variable values in the  person bestTA[3] array
using dot (.) operator.
1 TA, 1, is 20 year old
2 TA, 2, is 30 year old
3 TA, 3, is 40 year old
ARRAY OF POINTERS:
Accessing member variable values in the  person bestTA[3] array
using arrow ( -> ) operator.
1 TA, 1, is 20 year old
Pointer at index 0 of the array of pointers points to memory address: 0x28fec0
2 TA, 2, is 30 year old
Pointer at index 1 of the array of pointers points to memory address: 0x28fed8
3 TA, 3, is 40 year old
Pointer at index 2 of the array of pointers points to memory address: 0x28fef0

************************************************************************
* Last Modification date: 06.01.2014
* File name: 5.cpp
********************************************************************/

class person
{
    private:
        char name[20];// member 1
        int age;// member 2
    public:
        void *setName();// function will let user enter name
        char *getName();//function will return name
        void setAge();//function will let user enter age
        int getAge();//function will return age
        void results(person &person1);//function to display results
        void *setNameTA();//function to get name used in for loop
        void setAgeTA();//function to get age used in for loop
};
void integerCheck(int &age);// checks to make sure that integer was entere for age
void newLine();//function will let to make multiple entired in the for loop

int main(){

       person person1;//Creatperson *pointerPerson; // create pointer
       person *pointerPerson; // create pointer
    pointerPerson = &person1; //poes a variable called person1 that stores an object.
    cout << "Information that you enter below will be used to demonstrate " << endl;
    cout << "how pointers to an object work. " << endl;
    person1.results(person1);
   // inter that points to the memory address of the object person1.
    cout<<endl << "The memory address to the class person is: "<<pointerPerson<<endl;
    cout <<"Value stored in the member name can be accessed as: pointerPerson->getName(): " <<endl
         << pointerPerson->getName()<< endl;
    cout <<"Value stored in the member name can be accessed as: (*pointerPerson).getName(): " <<endl
         <<(*pointerPerson).getName()<< endl;
    cout <<"Value stored in the member age can be accessed as: pointerPerson->getAge(): " <<endl
         << pointerPerson->getAge()<< endl;
    cout <<"Value stored in the member age can be accessed as: (*pointerPerson).getAge(): " <<endl
            << (*pointerPerson).getAge()<< endl;


    cout<<"Enter names and ages of 3 people who are nominated to the best TA award."<<endl;
    person bestTA[3];// array of objects
    person *pointerBestTA[3];//array of pointers
    for(int i=0; i<3;i++){
        cout <<"What is the name of the " << i+1 << " TA? ";
        bestTA[i].setNameTA();// filling array of objects with name values
        pointerBestTA[i] = &bestTA[i];//filling array of pointers
        cout << "How old is the " << i+1 << " TA ? ";
        bestTA[i].setAgeTA();// filling array of objects with age values
      }

    cout << "ARRAY OF OBJECTS: " << endl;
    cout <<"Accessing member variable values in the  person bestTA[3] array "
        << endl << "using dot (.) operator. " << endl;
    for(int i=0; i<3;i++){
        cout << i+1 << " TA, " << bestTA[i].getName()
             << ", is " << bestTA[i].getAge() << " year old "  << endl;
    }
    cout << "ARRAY OF POINTERS: " << endl;
    cout <<"Accessing member variable values in the  person bestTA[3] array "
         << endl <<"using arrow ( -> ) operator. " << endl;
    for(int i=0; i<3;i++){
        cout << i+1 << " TA, " << pointerBestTA[i] -> getName()
             << ", is " << pointerBestTA[i] ->getAge() << " year old "  << endl;
        cout<<"Pointer at index "<<i <<" of the array of pointers points to memory address: "<<pointerBestTA[i]  <<endl;

    }
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

 void newLine( ){
    char symbol;
    do
    {
        cin.get(symbol);
    } while (symbol != '\n');
}

void *person::setName(){
    char name1 [20];
    cout << "What is your name? ";
	cin.get (name1, 20);
    cin.ignore(80,'\n');
    strcpy (name,name1);
}

char *person::getName(){
     return name;
}

void person::setAge(){
    cout << "How old are you? ";
	cin >> age;
	integerCheck(age);
    }

int person::getAge(){
    return age;
}

void person::setAgeTA(){
   	cin >> age;
	integerCheck(age);
    }

void *person::setNameTA(){
    char name1 [20];
    cin >> name1;
	newLine();
    strcpy (name,name1);
}

void person::results(person &person1){
    person1.setName();
    cout << "Your name is: " << person1.getName() << endl;
    person1.setAge();
    cout << "You are " << person1.getAge() << endl;
}
