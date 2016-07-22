/*******************************************************************
* Author: Tatyana Vlaskin
* Description:Program prints 10 pseudorandom numbers and 10 random numbers.
* Program accepts 2 strings and compares them.
* Input: not required
* Output:
Pseudorandom numberes:
41
18467
6334
26500
19169
15724
11478
29358
26962
24464
Random numberes:
16945
20062
8182
1919
16357
32228
12738
8778
27449
17415
* Last Modification date: 04.20.2014
* File name: problem3.cpp
********************************************************************/
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;
int main( )
{
    //Pseudorandom numbers
    int i;
    cout << "Pseudorandom numbers: \n";
    for (i = 0; i < 10; i++){
    int random1 = rand ();
    cout << random1 << endl;}

    //Random numbers
    int j;
    srand(time(NULL));
    cout << "Random numberes: \n";
    for (j = 0; j < 10; j++)
    {
        int random2 = rand();
        cout << random2 << endl;
    }
    return 0;

}
