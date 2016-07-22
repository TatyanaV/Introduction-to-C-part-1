/*******************************************************************
* Author: Tatyana Vlaskin
* Week 8, Problem 2
* Description: This program accepts 2 quiz scores, a midterm score and
a final score and calculates a grade based on the input.
* Input: 2 quiz scores, a midterm score and a final score
Output:
***********************************************************************
This program calculates students numeric score and assigns letter grade.
Please Enter Your Grades Below.
Please enter quiz scores.
Quiz score must be at least 0 and at most 10.
Quiz #1 Score: 10

Quiz #2 Score: 10

Please enter test scores.
Test score must be at least 0 and at most 100.
Midterm Exam Score: 100

Final Exam Score: 100

Quiz Scores: 10  10
Midterm Exam Score: 100
Final Exam Score: 100

Course Average: 100
Final Letter Grade: A

***********************************************************************
* Last Modification date: 05.25.2014
* File name: 2.cpp
********************************************************************/

#include <iostream>
#include <cmath>
#include <string>
#include <math.h>
#include<stdlib.h>
using namespace std;
const double EXAM_WT = 0.5;
const double MIDTERM_WT = 0.25;
const double QUIZ_WT = 0.25;
void getScores();
void quizCheck(int &quiz);
void testCheck(int &test);

struct studentRecord
{
    int quiz1;
    int quiz2;
    int midtermExam;
    int finalExam;
    float courseAverage;
    char letterGrade;
};
studentRecord grades;// creating a variable of type studentsReconds
void computeAverage (studentRecord& record);
char letterGrade (double numericGrade);
void outputRecord (studentRecord &record);

int main()
 {
  getScores();
  computeAverage (grades);
  outputRecord(grades);
}

void getScores(){
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
  cin >> grades.midtermExam;
  testCheck(grades.midtermExam);
  cout << endl;
  cout << "Final Exam Score: ";
  cin >> grades.finalExam;
  testCheck(grades.finalExam);
  cout << endl;
}

void quizCheck(int &quiz){

    while(cin.fail() || quiz <0||quiz>10)
    {
        cout << "Error, invalid quiz score was enetered.  " << endl
             << "Quiz grade must be at least 0 and at most 10. "<< endl;
        cin.clear();
        cin.ignore(80,'\n');
        cout<<"Please reenter quiz grade: ";
        cin >> quiz;
        }

}

void testCheck(int &test){

    while(cin.fail() || test <0||test>100)
    {
        cout << "Error, invalid test score was enetered.  " << endl
             << "Test grade must be at least 0 and at most 100. " << endl;
        cin.clear();
        cin.ignore(80,'\n');
        cout<<"Please reenter test grade: ";
        cin >> test;
        }

}

void computeAverage (studentRecord& record)
{
  double quiz1Percent, quiz2Percent;

    // Convert the 10 point quizzes to a percent, then find the average
    // we do not need to do the same thing for test scores because
    //tests are graded on the scale from 0-100
    quiz1Percent = 100 * record.quiz1 / 10.0;
    quiz2Percent = 100 * record.quiz2 / 10.0;
    double quizAvg = (quiz1Percent + quiz2Percent) / 2;


   // Compute the weighted average to get the numeric course grade
    record.courseAverage = quizAvg * QUIZ_WT + record.midtermExam * MIDTERM_WT +
    record.finalExam * EXAM_WT;

  // Call the letterGrade function to find the corresponding letter grade
    record.letterGrade = letterGrade (record.courseAverage);

}

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
  cout << "Grade summarry of the student. " << endl;
  cout << "Quiz Scores: " << record.quiz1 << "  " << record.quiz2 << endl;
  cout << "Midterm Exam Score: " << record.midtermExam << endl;
  cout << "Final Exam Score: " << record.finalExam << endl;
  cout << endl;
  //computeAverage (studentRecord& record)
  cout << "Course Average: " << record.courseAverage << endl;
  cout << "Final Letter Grade: " << record.letterGrade << endl;
  cout << endl;
}


