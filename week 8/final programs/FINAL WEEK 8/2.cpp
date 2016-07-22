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

Grade summarry of the student.
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
//The final exam counts for 50% of the grade, the midterm counts for 25%,
// and the two quizzes together count for a total of 25%.
//these 3 constants will be used in calculating course grade
const double EXAM = 0.5;
const double MIDTERM = 0.25;
const double QUIZ = 0.25;
// function that lets the user to enter grades
void getScores();
//function that checks that entered quiz score is valid (0-10)
void quizCheck(int &quiz);
//function that checks that entered test score is valid (0-100)
void testCheck(int &test);
struct studentRecord
{
    int quiz1;
    int quiz2;
    int midterm;
    int final;
    float gradesAverage;
    char letterGrade;
};
studentRecord grades;// creating a variable of type studentsReconds
//function that normalizes quiz scores and computes average %
void computeAverage (studentRecord& record);
//function that takes the average % from the void computeAverage fuction
//and converts it into letter grade
char letterGrade (double grade);
//function that outputs students record
void records (studentRecord &record);

int main()
 {
  getScores();
  computeAverage (grades);
  records(grades);
}
// function lets the user to enter grades
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

    // Convert the 10 point quizzes to a percent, then finds the average
    // we do not need to do the same thing for test scores because
    //tests are graded on the scale from 0-100
    quiz1Percent = 100 * record.quiz1 / 10.0;
    quiz2Percent = 100 * record.quiz2 / 10.0;
    double quizAverage = (quiz1Percent + quiz2Percent) / 2;
   // Compute the weighted average
    record.gradesAverage = quizAverage * QUIZ + record.midterm * MIDTERM +
    record.final * EXAM;
  //Find the letter grade
    record.letterGrade = letterGrade (record.gradesAverage);

}

char letterGrade (double grade)
{
  char letter;

  if (grade >= 90)
    letter = 'A';
  else if (grade >= 80)
    letter = 'B';
  else if (grade >= 70)
    letter = 'C';
  else if (grade >= 60)
    letter = 'D';
  else
    letter = 'F';

  return letter;
}


void records (studentRecord &record)
{
  cout << endl;
  cout << "Grade summarry of the student. " << endl;
  cout << "Quiz Scores: " << record.quiz1 << "  " << record.quiz2 << endl;
  cout << "Midterm Exam Score: " << record.midterm << endl;
  cout << "Final Exam Score: " << record.final << endl;
  cout << endl;
  cout << "Course Average: " << record.gradesAverage << endl;
  cout << "Final Letter Grade: " << record.letterGrade << endl;
  cout << endl;
}


