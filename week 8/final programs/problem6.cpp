#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

struct person
{
    string name;
};


int main(int argc, char* argv[])
{
    if (argc ==1 ) {
        std::cerr << "Not entered all details to run the program " <<endl;
        return 1;
    }
    else
    {
        person * people; // creates dynamic array to enter first names
        people = new person [argc];
        // fills in array with the names that are entered by the user
        for(int index = 1; index<argc; index++)
        {
            people[index].name = (argv[index]);
        }

        person *pointers[argc]; // Allocates for an array of argc pointers

        for(int i=1;i<argc;i++) // please note that we start at 1 because 0 is reserved for name of the program
        {
            pointers[i]=&people[i];
            cout<<"Pointer at index "<<i <<" of the array of pointers points to memory address: "<<pointers[i] <<endl;
            cout <<"The entered name stored in that address is: "<<pointers[i]->name <<endl <<endl;
        }

    delete [] people;

    return 0;
    }
}

