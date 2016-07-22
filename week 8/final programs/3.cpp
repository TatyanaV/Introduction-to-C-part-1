/*******************************************************************
* Author: Tatyana Vlaskin
* Week 8, Problem 3
* Description: This program accepts 2 quiz scores, a midterm score and
a final score and calculates a grade based on the input. You can use
command line or run the program in a regular way.
* Input: 2 quiz scores, a midterm score and a final score
Output:
***********************************************************************
Calculates grade based on scores.

************************************************************************
* Last Modification date: 05.25.2014
* File name: 3.cpp
********************************************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
const double EXAM = 0.5;
const double MIDTERM = 0.25;
const double QUIZ = 1.25;

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
char letterGrade (double grade);
void outputRecord (studentRecord &record);
void noArguments();
void quizCheck(int &quiz);
void testCheck(int &test);

int main(int argc, char* argv[])
{
  if(argc == 1)// if user decided not to use command line
	{
		noArguments();
        normalizeGrades(grades);
        outputRecord(grades);
	}
    if (argc < 5 && argc !=1) {

        cerr << "Not entered all details of student " << endl;

   return 1;
    }

    else if(argc==5)
    {
        cout<< "You decided to use command line. " << endl;
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
// if the user decided not to use command line, this function will be called
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
//makes sure that quiz grade is valid
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
//makes sure that test grades is valid
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
//normalizes grades and computes average
void normalizeGrades(studentRecord& record)
{
    record.courseAverage = (((record.quiz1+record.quiz2)*QUIZ)+(record.midterm*MIDTERM)+(record.final*EXAM));

    record.letterGrade = letterGrade (record.courseAverage);
}
//displayes grade letter
char letterGrade (double grade)
{
  char letter;

  if (grade >= 90)
    letter = 'A';
  else if (grade >= 80)
    letter = 'B';
  else if (grade >=70)
    letter = 'C';
  else if (grade >=60)
    letter = 'D';
  else
    letter = 'F';

  return letter;
}
//outputs message to the user
void outputRecord (studentRecord &record)
{
  cout << endl;
  cout << "Quiz Scores: " << record.quiz1 << "  " << record.quiz2 << endl;
  cout << "Midterm Exam Score: " << record.midterm << endl;
  cout << "Final Exam Score: " << record.final << endl;
  cout << endl;
  cout << "Course Average: " << record.courseAverage << endl;
  cout << "Final Letter Grade: " << record.letterGrade << endl;
  cout << endl;
}

