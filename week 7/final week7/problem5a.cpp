#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


int gradeCheck(int grade, int count);// checks and makes sure that entry is valid for GRADES
const int SCORES = 6; //the scores from 0-5
void initiateArrayElementsToZero(int grades[]); // each array element in the 0-5 grade array is initialized to zero
int students;// = argc - 1; // number of enteries made. We need to subtract 1 cause argv[0] reserved for name of the program
void fillGrades( int *argv[], int size); // filles grades when user enteres them
void countGrade(int grades[], int *argv[], int k);//counts grades
int grades[SCORES];// declaration of array that to store scores are form 0 to 5

int main(int argc, char const * argv[])
{
    cout << "Nubmer of grades entered: " << argc-1;
    int students = argc - 1;
    initiateArrayElementsToZero(grades); // each array element in the grades 0-5 array is initialized to zero
    fillGrades(argv,students);// filles arary with the entry made by the user
    for ( int index = 0; index < argc; index++){
    countGrade(grades, argv, index);
    }

    cout << endl << "HISTOGRAM OF THE CLASS QUIZ SCORES" << endl << endl;

    for(int i = 0; i < SCORES; i++) // prints histogram
    {
        //cout << grades[i] << " grade(s) of " << i  << endl;
        cout << grades[i] << " grade(s) of " << i  << endl;
    }

    return (0);
    delete [] argv;
}

// each array element is initialized to zero GRADES 0-5 ARRAY
void initiateArrayElementsToZero(int grades[])
{
    int i;
    for(i = 0; i < 6; i++)
    {
        grades[i] = 0;
    }
}

 void fillGrades( char *array[], int size)
{
    for ( int index = 0; index < students; index++){
    }
}

/*
// check that each entry made for a grade is valid THIS DOES NOT WORK
int gradeCheck(int integer, int cout)
{
    for ( int index = 0; index < count; index++){
        if (integer != static_cast<int>(integer) || integer < 0 || integer > 5)
    {
        cout << "Error, your input was invalid for this student.  The quiz is graded on a scale from 0 to 5. " << endl
        cout << "Entry for " << argv [index] << " was not included in the histogram." << endl;
        //cin.clear();
        //cin.ignore(80,'\n');
        //cin >> integer;
    }
    //return integer;
}

*/
// counts grades. Whenever a grade is entered, the corresponding index in the array is incremented.
//this was a hint in the description of the problem
void countGrade(int grades[], int *entry[], int k)
{
    //int k;
    if (entry[k] == 0)
        grades[0]++;
    else if (entry[k] == 1)
        grades[1]++;
    else if (entry[k] == 2)
        grades[2]++;
    else if (entry[k] == 3)
        grades[3]++;
    else if (entry[k]== 4)
        grades[4]++;
    else if (entry[k] == 5)
        grades[5]++;
}

