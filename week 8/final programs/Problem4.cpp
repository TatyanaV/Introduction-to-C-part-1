/*******************************************************************
* Author: Tatyana Vlaskin
* Week 8, Problem 4
* Description: Demonstrates using pointers with structs and
* arrays with structs.
* Input: not required
Output:
***********************************************************************
The memory address to the struct rectangle is: 0x28ff28
Value stored in member variable called length is: 20
Value stored in member variable called width is: 10
The memory address to stuct rectangle member length is: 0x28ff28
The memory address to stuct rectangle member width is: 0x28ff2c

Katerina is member 1 of the struct array people.
Violeta is member 2 of the struct array people.
Svetlana is member 3 of the struct array people.
Lyubov is member 4 of the struct array people.
Snezhana is member 5 of the struct array people.

************************************************************************
* Last Modification date: 05.25.2014
* File name: 4.cpp
********************************************************************/

#include <iostream>
#include <cmath>
#include <string>
#include <math.h>
#include<stdlib.h>
using namespace std;

//This struct will demonstrate that struct
//pointer works similiar to a normal pointer.
struct rectangle
{
    int length;
    int width;
};

//This struct will demonstrate how to access member
//variables from an array of a struct.
struct person
{
    string name;
};

int main()
{
    rectangle rect1 = {20,10};// declare an instance of type rectangle
    struct rectangle *pointerRectangle = 0; // declare rectangle and initialize it to zero
    pointerRectangle = &rect1; // initialize a pointer to rect1
    //cout << variable;

    cout<<"The memory address to the struct rectangle is: "<<pointerRectangle<<endl;
    cout<<"Value stored in member variable called length is: "<<pointerRectangle->length<<endl;
    cout<<"Value stored in member variable called width is: "<<pointerRectangle->width<<endl;
    cout << "The memory address to stuct rectangle member length is: " <<&rect1.length <<endl;
    cout << "The memory address to stuct rectangle member width is: " <<&rect1.width <<endl;
    cout << endl;

    person people[5];

    people[0].name = "Katerina";
    people[1].name = "Violeta";
    people[2].name = "Svetlana";
    people[3].name = "Lyubov";
    people[4].name = "Snezhana";
    person *pointerName;
    for(int i = 0; i < 5; i++)
        {
            pointerName = &people[i];
            cout << pointerName->name << " is member " << i + 1 << " of the struct array people." << endl;
        }
    return 0;
}
