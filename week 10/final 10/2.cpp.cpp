#include <iostream>
#include <string>
using namespace std;

string reverse(string str_input);

int main()
{
     // declare variable
     string str_input="";
     cout<<"Please enter a string that you want to reverse: ";
     getline(cin,str_input);
     //cout << str_input.substr(1)<< endl;
    // cout << str_input.substr(2)<< endl;
     //cout << str_input.substr(3)<< endl;
    cout<< "\nOriginal string: " << str_input << endl;

     cout<<"\nThe reverse of the string using recursive method is: ";

     // function declaration
     reverse(str_input);
     cout<< endl;

     return 0;
}// end of main

string reverse(string str_input)
{
     if(str_input == "") // the base case
     {
         return str_input;
     }
     else // the recursive step
     {
          reverse(str_input.substr(1));
          cout<<str_input.at(0);
     }
     return str_input;
}
