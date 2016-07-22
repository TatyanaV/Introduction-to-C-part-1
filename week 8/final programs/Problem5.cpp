/*******************************************************************
* Author: Tatyana Vlaskin
* Week 8, Problem 5
* Description: Creates  an array of structs, uses pointers to access the
* member variables.
* Input: Not required
Output:
***********************************************************************
Pointer at index 0 of the array of pointers points to memory address: 0x28ff10
The value/member stored in that address is: Katerina

Pointer at index 1 of the array of pointers points to memory address: 0x28ff14
The value/member stored in that address is: Violeta

Pointer at index 2 of the array of pointers points to memory address: 0x28ff18
The value/member stored in that address is: Svetlana

Pointer at index 3 of the array of pointers points to memory address: 0x28ff1c
The value/member stored in that address is: Lyubov

Pointer at index 4 of the array of pointers points to memory address: 0x28ff20
The value/member stored in that address is: Snezhana

************************************************************************
* Last Modification date: 05.25.2014
* File name: 5.cpp
********************************************************************/
#include <iostream>
#include <string>

using namespace std;

struct person
{
    string name;
};


int main (){

    person people[5];

    people[0].name = "Katerina";
    people[1].name = "Violeta";
    people[2].name = "Svetlana";
    people[3].name = "Lyubov";
    people[4].name = "Snezhana";

    person *pointers[5]; // creating an array of pointer

    for(int i = 0; i < 5; i++)
    {
        pointers[i]=&people[i];
		cout<<"Pointer at index "<<i <<" of the array of pointers points to memory address: "<<pointers[i] <<endl;
		cout <<"The value/member stored in that address is: "<<pointers[i]->name <<endl <<endl;

    }

}
