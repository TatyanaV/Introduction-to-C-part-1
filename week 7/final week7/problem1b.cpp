#include <iostream>  //library for input and output
#include <string>    //library for stings
using namespace std;

void validEntry(int entry);// function to make sure that user entered int type
void directVariable(int value);
void referenceOperator(int &value);
void pointerValue (int *pointer2);
int* valuePointeeDereference(int *pointer2);
int* pointerAddress(int *pointer2);


int main(){

        int variable; // creating a variable of int data type
        int *pointer = &variable; //creating a pointer that points to the variable

        cout << "Enter an integer: ";
        cin >> variable;
        validEntry(variable); // making sure that user entered int type

        directVariable(variable); // accessing variable virectly

        referenceOperator(variable);// accessing address using reference operator

        pointerValue (pointer); // accesssing address using pointer

        valuePointeeDereference(pointer); // accessing value using pointer and dereference operator

        pointerAddress(pointer); // accessing address of a pointer

}

void validEntry(int entry){

    while (cin.fail() || (entry != static_cast<int>(entry))){//checks for valid input, special characters, doubles, spaces are not allowed        {
        cout << "Error, your input is invalid.  Only INTEGERS are accepted. " << endl;
        cin.clear();
        cin.ignore(80,'\n');
        cout << "Enter an integer: ";
        cin >> entry;
        }
}

void directVariable(int value){
        cout << endl << "1. To access the value of a variable directly, type: " << endl;
        cout << "cout << variable." << endl;
        cout << "You will get: " << value << endl;
  }

void referenceOperator(int &value){
        cout << endl << "2. To access the address of a variable with the reference operator, type: " << endl;
        cout << "cout << &variable." << endl;
        cout << "You will get: " << &value << endl;
}

void pointerValue (int *pointer2){
        cout << endl << "3. To access a pointer's value by accessing it directly, type: " << endl;
        cout << "cout << pointer." << endl;
        cout << "This is equivalent to accessing the address of the variable with the pointer." << endl;
        cout << "You will get: " << pointer2 << endl;
}

// we can do void valuePointeeDereference(int *pointer2).
int* valuePointeeDereference(int *pointer2){
        cout << endl << "4. To access the value of the pointee by dereferencing a pointer, type: " << endl;
        cout << "cout << *pointer." << endl;
        cout << "This is equivalent to accessing the value of a variable." << endl;
        cout << "You will get: " << *pointer2 << endl;
        return pointer2;
}

int* pointerAddress(int *pointer2){
        cout << endl << "5. To access the address of a pointer, type: " << endl;
        cout << "cout << &pointer." << endl;
        cout << "You will get: " << &pointer2 << endl;
        return pointer2;
}
