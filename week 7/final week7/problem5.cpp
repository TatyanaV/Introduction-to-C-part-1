/*******************************************************************
* Author: Tatyana Vlaskin
* Week 7, Problem 5
* Description: Asks the user for the grades and output histogram. This
program is command line arguments friendly.
* Input:  grades
Output::
***********************************************************************

HISTOGRAM OF THE CLASS QUIZ SCORES

1 grade(s) of 0
2 grade(s) of 1
0 grade(s) of 2
0 grade(s) of 3
1 grade(s) of 4
2 grade(s) of 5

************************************************************************
* Last Modification date: 05.18.2014
* File name: problem3.cpp
********************************************************************/
#include <cstdlib>
#include <iostream>
#include <string>
#include<stdio.h>


using namespace std;
void countGrade(int *grades, int argc);
int gradesIncrementing[6]={-1,0,0,0,0,0}; // initialize array that counts grades to zero
int main(int argc, char const * argv[]) // see http://www.intechgrity.com/how-to-write-programs-using-command-line-arguments-in-a-few-easy-steps/
{
    int *grades=new int[argc];//declaration of array that will store grades, the size is equal to argc, which is the count of entries
    for(int entry =1; entry <argc; entry++){//loops through entries. first element is reserved for name
        grades[entry-1]=atoi(argv[entry]);//loops though the entries, need to changed entries to atoi per http://en.cppreference.com/w/cpp/string/byte/atoi
    }
    countGrade(grades, argc);// count grades
    return (0);
    delete [] argv;
}
// this was coppy and past from problem 3, only size is replaced to argc
void countGrade(int *entry, int argc)
{
    for(int k=0; k<argc; k++){
    if (entry[k] == 0)
        gradesIncrementing[0]++;
    else if (entry[k] == 1)
        gradesIncrementing[1]++;
    else if (entry[k] == 2)
        gradesIncrementing[2]++;
    else if (entry[k] == 3)
        gradesIncrementing[3]++;
    else if (entry[k]== 4)
        gradesIncrementing[4]++;
    else if (entry[k] == 5)
        gradesIncrementing[5]++;
    else if (entry[k] != 0 ||entry[k] != 1 || entry[k] != 2 ||entry[k] != 3 ||entry[k] != 4 || entry[k] != 5)
        printf("Invalid input! Entry is omitted.");
        cout << endl;
    }

    cout << "HISTOGRAM OF THE CLASS QUIZ SCORES" << endl << endl;
    for(int entry = 0; entry < 6; entry++) // prints histogram
    {
       cout << gradesIncrementing[entry] << " grade(s) of " << entry << endl;
    }
}

