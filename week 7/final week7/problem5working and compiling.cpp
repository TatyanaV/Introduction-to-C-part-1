#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
void countGrade(int *grades, int argc);
int main(int argc, char const * argv[])
{
    int *grades=new int[argc];//got it from
    cout << "Nubmer of grades entered: " << argc-1;

    for(int entry =1; entry <argc-1; entry++){//Start counting at element 1, Last element is a null pointer. 0 Is reserved for the file name or path.
	grades[entry-1]=atoi(argv[entry]);// NEED THIS
	cout<<grades[entry-1]<<"  "<<endl;// NEED THIS
	}
    countGrade(grades, argc);
    return (0);
    delete [] argv;
}

void countGrade(int *entry, int argc)
{
    int gradesIncrementing[6]={0,0,0,0,0,0};
    //int k;
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
        printf("Invalid input! This entry is not counted. ");
        cout << endl;

    }

    cout << endl << endl << "HISTOGRAM OF THE CLASS QUIZ SCORES" << endl << endl;

    for(int entry = 0; entry < 6; entry++) // prints histogram
    {
        //cout << grades[i] << " grade(s) of " << i  << endl;
        cout << gradesIncrementing[entry] << " grade(s) of " << entry << endl;
    }
}

