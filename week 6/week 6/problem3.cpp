/*******************************************************************
* Author: Tatyana Vlaskin
* Week 6, Problem 3
* Description:
* Program asks the use to enter number of students, who took the quiz
and grade for each student. At the end the histogram of the grades is
displayed.
* Input: User needs to input number of students, who took the quiz
and grade of each student
Output:
***********************************************************************
How many students took the quiz: 3
Please enter students 1 grade: 5
Please enter students 2 grade: 0
Please enter students 3 grade: ;
Error, your input is invalid.  The quiz is graded on a scale from 0 to 5.
Reenter a grade for this student: 1

HISTOGRAM OF THE CLASS QUIZ SCORES

1 grade(s) of 0
1 grade(s) of 1
0 grade(s) of 2
0 grade(s) of 3
0 grade(s) of 4
1 grade(s) of 5

************************************************************************
* Last Modification date: 05.11.2014
* File name: problem3.cpp
********************************************************************/

#include <cstdlib>
#include <iostream>
using namespace std;

int studentsEntry(int &students);// gets the number of students who took the quiz
int studentCheck(int &integer);// checks and makes sure that entry is valid for STUDENTS
int gradeCheck(int &entry);// checks and makes sure that entry is valid for GRADES
const int SCORES = 6; //the scores from 0-5
void initiateArrayElementsToZero(int grades[]); // each array element is initialized to zero
void countGrade(int grades[], int grade);// makes histogram and displays it to the user

int main()
{
    int students = 0;
    studentsEntry(students);// get the # of students who took the test
    int grades[SCORES];// declaration of array that to store scores are form 0 to 5
    int grade;// will be used to cin input
    initiateArrayElementsToZero(grades); // each array element is initialized to zero
    for(int students1 = 0 ; students1 < students; students1++)// asks the user to enter grade for each student
    {
        cout << "Please enter students " << students1 + 1 << " grade: ";
        cin >> grade;
        grade = gradeCheck(grade);// is entry valid?
        countGrade(grades, grade);// counts each grade
    }
     cout << endl << "HISTOGRAM OF THE CLASS QUIZ SCORES" << endl << endl;

    for(int i = 0; i < SCORES; i++) // prints histogram
    {
        cout << grades[i] << " grade(s) of " << i  << endl;
    }
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
 int studentCheck(int &integer)
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
void countGrade(int grades[], int grade)
{
    if (grade == 0)
        grades[0]++;
    else if (grade == 1)
        grades[1]++;
    else if (grade == 2)
        grades[2]++;
    else if (grade == 3)
        grades[3]++;
    else if (grade == 4)
        grades[4]++;
    else if (grade == 5)
        grades[5]++;
}

