#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int arraySize;
void validEntry(int &entry, string sentence);
void fillArray( int array[], int size);
void sortArray(int array[], int size);
void swapValues( int *number1, int *number2);
void sortArray(int array[], int size);


int main (){

    cout << "How many integers do you want to enter? ";
    cin >> arraySize;
    validEntry(arraySize, "How many integers do you want to enter? ");

    int *inputArray = new int[arraySize];
    fillArray( inputArray, arraySize);
    sortArray(inputArray, arraySize);
    cout << endl << "The smallest value stored in the array is: " << inputArray[0] << endl;
    cout << endl << "The largest value stored in the array is: " << inputArray[arraySize-1] << endl;

    delete [] inputArray;
    return 0;

}

void validEntry(int &entry, string sentence){

    while (cin.fail() || (entry != static_cast<int>(entry))){
        cout << "Error, your input is invalid.  Only INTEGERS are accepted. " << endl;
        cin.clear();
        cin.ignore(80,'\n');
        cout << sentence;
        cin >> entry;
        }
}

 void fillArray( int array[], int size)
{
    for ( int index = 0; index < arraySize; index++){
    cout << "Enter an integer " << index +1 << ": ";
    cin >> array[index];
    validEntry(array[index], "Enter an integer: ");
    }
}

void sortArray(int array[], int size)
{
    for (int i = 0; i < size -1; i++){
        for (int j = i+1; j <size; j++){
            if (array[i] > array[j]){
                swap(array[i], array[j]);
            }
        }
    }
}

void swapValues( int *number1, int *number2)
 {
    int temp = *number1;
    *number1 = *number2;
    *number2 = temp;
 }


