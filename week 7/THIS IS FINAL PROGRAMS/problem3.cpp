/*******************************************************************
* Author: Tatyana Vlaskin
* Week 7, Problem 3
* Description: Asks the user for the grades and output histogram
* Input: number of students and grades
Output::
***********************************************************************
How many students took the quiz: 5
Enter students 1 grade: 2
Enter students 2 grade: 2
Enter students 3 grade: 2
Enter students 4 grade: 0
Enter students 5 grade: 1

HISTOGRAM OF THE CLASS QUIZ SCORES

1 grade(s) of 0
1 grade(s) of 1
3 grade(s) of 2
0 grade(s) of 3
0 grade(s) of 4
0 grade(s) of 5

Process returned -1073741819 (0xC0000005)   execution time : 11.089 s
Press any key to continue.

************************************************************************
* Last Modification date: 05.18.2014
* File name: problem3.cpp
********************************************************************/


#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int studentsEntry(int &students);// gets the number of students who took the quiz
int studentCheck(int integer);// checks and makes sure that entry is valid for STUDENTS
int gradeCheck(int &grade);// checks and makes sure that entry is valid for GRADES
const int SCORES = 6; //the scores from 0-5
void initiateArrayElementsToZero(int grades[]); // each array element is initialized to zero
void fillGrades( int array[], int size); // filles grades when user enteres them
void countGrade(int grades[], int entry[], int k);//counts grades
int students;
int grades[SCORES];// declaration of array that to store scores are form 0 to 5
int *entry  =  new int[students];

int main()
{

    studentsEntry(students);// get the # of students who took the test
    initiateArrayElementsToZero(grades); // each array element in the 0-5 array is initialized to zero

    fillGrades(entry,students);
    for ( int index = 0; index < students; index++){
        countGrade(grades, entry, index);
    }


    cout << endl << "HISTOGRAM OF THE CLASS QUIZ SCORES" << endl << endl;

    for(int i = 0; i < SCORES; i++) // prints histogram
    {
        cout << grades[i] << " grade(s) of " << i  << endl;
    }
    delete [] entry;
    return (0);

}

// got this idea from Frank L Brasington
// asks the user to enter how many grades they need to enter
int studentsEntry(int& students)
{
    cout << "How many students took the quiz: ";
    cin >> students;
    students = studentCheck(students);
    return students;
}

// function to check if the entery is valid. No doubles, strings or special characters allowed
 int studentCheck(int integer)
{
    while(cin.fail() || integer != static_cast<int>(integer) || integer <=0)
    {
        cout << "Error, your input is invalid.  Only positive integers are accepted. " << endl
             << "Number of students, who took the quiz: ";
        cin.clear();
        cin.ignore(80,'\n');
        cin >> integer;
        }
    return integer;
}
// each array element is initialized to zero
void initiateArrayElementsToZero(int grades[])
{
    int i;
    for(i = 0; i < 6; i++)
    {
        grades[i] = 0;
    }
}

 void fillGrades( int array[], int size)
{
    for ( int index = 0; index < students; index++){
    cout << "Enter students " << index +1 << " grade: ";
    cin >> array[index];
    gradeCheck(array[index]);

}
}
// check that each entry made for a grade is valid
int gradeCheck(int &integer)
{
    while(cin.fail() || integer != static_cast<int>(integer) || integer < 0 || integer > 5)
    {
        cout << "Error, your input is invalid.  The quiz is graded on a scale from 0 to 5. " << endl
             << "Reenter a grade for this student: ";
        cin.clear();
        cin.ignore(80,'\n');
        cin >> integer;
    }
    return integer;
}

// counts grades. Whenever a grade is entered, the corresponding index in the array is incremented.
//this was a hint in the description of the problem
void countGrade(int grades[], int entry[], int k)
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

