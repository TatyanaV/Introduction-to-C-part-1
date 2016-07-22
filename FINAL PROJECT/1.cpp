//Tatyana Vlaskin
//week 10
//problem 1
//1.cpp
#include <iostream>
#include <string>
using namespace std;


string reverse(string str_input);
string reverse2(string str_input);

int main()
{

     string str_input;
     cout<<"Please enter a string that you want to reverse: ";
     getline(cin,str_input);
     cout<< "\nOriginal string: " << str_input << endl;

     cout<<"\nThe reverse of the string using while loop is: ";

      reverse(str_input);
     cout<<endl;
     cout<<"\nThe reverse of the string using for loop is: ";
     reverse2(str_input);
     cout<< endl;

     return 0;
}

string reverse(string str_input)
{

     // get the length of the string
     int nameLength = str_input.length()-1;

     while(nameLength >= 0)
     {
          cout<<str_input[nameLength];
          --nameLength;
     }
     return str_input;
}

string reverse2(string str_input){

    //loop to display string one character at a time in reverse direction
    for (int i = (str_input.length()-1); i >=0 ; i --)
    {
            cout << str_input.at(i);
    }
    return str_input;
}
