/*******************************************************************
* Author: Tatyana Vlaskin
* Week 8, Problem 3
* Description: This program accepts 2 quiz scores, a midterm score and
a final score and calculates a grade based on the input. You can use
command line or run the program in a regular way.
* Input: 2 quiz scores, a midterm score and a final score
Output:
***********************************************************************
What is your first name? tatyana
How old are you? 28

Your name is: tatyana
You are 28 years old.

************************************************************************
* Last Modification date: 05.25.2014
* File name: 3.cpp
********************************************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
const double EXAM_WT = 0.5;
const double MIDTERM_WT = 0.25;
const double QUIZ_WT = 1.25;

struct studentRecord
{
    int quiz1;
    int quiz2;
    int midterm;
    int final;
    float courseAverage;
    char letterGrade;
} ;
studentRecord grades;
void normalizeGrades(studentRecord& record);
char letterGrade (double numericGrade);
void outputRecord (studentRecord &record);
void noArguments();
void quizCheck(int &quiz);
void testCheck(int &test);


int main(int argc, char* argv[])
{


//The integer, argc is the argument count. It is the number of arguments passed into the program from the command line, including the name of the program.
//the next argument is array of pointers. Consider argv as two dimensional array.
//Also here argv[0] is the name of the program, or an empty string if the name is not available. So if you want to pass two command line parameters then argc will be 3.
//So the values between each subsequent spaces are captured in argv[i]
//print the value of argv[0] ==> it will return the name ofprogram

//Also each argument that you have entered is always a string. So you have to parse it and convert into int or any data type that suits your requirement

// Check the number of parameters, so if the entred parameters is less than 5 then no proper detail of student is given
    if(argc == 1)
	{
		noArguments();
        normalizeGrades(grades);
        outputRecord(grades);
	}
    if (argc < 5) {
// Tell the user how to run the program
        std::cerr << "Not entered all details of student " << argv[0] << " NAME" << std::endl;
/* "Usage messages" are a conventional way of telling the user
* how to run a program if they enter the command incorrectly.
*/
    return 1;
    }

    else if(argc==5)
    {
        grades.quiz1=atoi(argv[1]);
        quizCheck(grades.quiz1);
        grades.quiz2=atoi(argv[2]);
        quizCheck(grades.quiz2);
        grades.midterm=atoi(argv[3]);
        testCheck(grades.midterm);
        grades.final=atoi(argv[4]);
        testCheck(grades.final);
        normalizeGrades(grades);
        outputRecord(grades);
    return 0;
}

    else if(argc>5)
{
    cout <<" Too many arguments supplied" <<endl;
}
}

void noArguments(){
  cout << "You see this message because you decided not to use command line arguments. " << endl;
  cout << "This program calculates students numeric score and assigns letter grade." <<endl;
  cout << "Please Enter Your Grades Below." << endl;
  cout<< "Please enter quiz scores. " << endl;
  cout << "Quiz score must be at least 0 and at most 10. "<< endl;
  cout << "Quiz #1 Score: ";
  cin >> grades.quiz1;
  quizCheck(grades.quiz1);
  cout << endl;
  cout << "Quiz #2 Score: ";
  cin >> grades.quiz2;
  quizCheck(grades.quiz2);
  cout << endl;
  cout<< "Please enter test scores. " << endl;
  cout << "Test score must be at least 0 and at most 100. "<< endl;
  cout << "Midterm Exam Score: ";
  cin >> grades.midterm;
  testCheck(grades.midterm);
  cout << endl;
  cout << "Final Exam Score: ";
  cin >> grades.final;
  testCheck(grades.final);
  cout << endl;
}

void quizCheck(int &quiz){

    while(cin.fail() || quiz <0||quiz>10)
    {
        cout << "Error, invalid quiz score was enetered.  " << endl
             << "Quiz grade must be at least 0 and at most 10. " << endl;
        cout << "If you are using command central, and got this error first time, press enter. ";
        //cout<<"Please reenter quiz grade: ";
        cin.clear();
        //cout<<"Please reenter quiz grade: ";
        cin.ignore(80,'\n');
        cout<<"Please reenter quiz grade: ";
        cin >> quiz;
        }

}

void testCheck(int &test){

    while(cin.fail() || test <0||test>100)
    {
        cout << "Error, invalid test score was enetered.  " << endl
             << "Test grade must be at least 0 and at most 100. " ;
        cout << "If you are using command central, and got this error first time, press enter. ";
        //cout<<"Please reenter test grade: ";
        cin.clear();
        cin.ignore(80,'\n');
        cout<<"Please reenter test grade: ";
        cin >> test;
        }

}

//convert the given marks into normalized marks.
//studentRecord& record
void normalizeGrades(studentRecord& record)


//float normalizeGrades(int quiz1,int quiz2,int midterm,int final)
{
    record.courseAverage = (((record.quiz1+record.quiz2)*QUIZ_WT)+(record.midterm*MIDTERM_WT)+(record.final*EXAM_WT));

    record.letterGrade = letterGrade (record.courseAverage);
}

//this method return grade according to given scheme
//char assign_grade(float average_marks)

char letterGrade (double numericGrade)
{
  char letter;

  if (numericGrade < 60)
    letter = 'F';
  else if (numericGrade < 70)
    letter = 'D';
  else if (numericGrade < 80)
    letter = 'C';
  else if (numericGrade < 90)
    letter = 'B';
  else
    letter = 'A';

  return letter;
}

void outputRecord (studentRecord &record)
{
  cout << endl;
  cout << "Quiz Scores: " << record.quiz1 << "  " << record.quiz2 << endl;
  cout << "Midterm Exam Score: " << record.midterm << endl;
  cout << "Final Exam Score: " << record.final << endl;
  cout << endl;
  //computeAverage (studentRecord& record)
  cout << "Course Average: " << record.courseAverage << endl;
  cout << "Final Letter Grade: " << record.letterGrade << endl;
  cout << endl;
}

