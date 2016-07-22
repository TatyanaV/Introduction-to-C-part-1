//tatyana vlaskin
//week 10 problem 3
//3.cpp

#include <sstream>
#include <string>
#include <iostream>
using namespace std;

bool is_palindrome(string str_input);

int main()
{
     string str_input;

	cout << "Palindrome Detection Program" << endl;
	cout << "Enter a word or a sentence: " << endl;
    getline(cin, str_input);
    if (is_palindrome(str_input) == true)
        cout << endl << "Your entry is a palindrome.\n";
    else
        cout << endl << "Your entry is not a palindrome.\n";
}

bool is_palindrome(string str_input)
{
    int stringLength = str_input.length()-1;
   for (int i =0; i < (stringLength); i ++)
    {
        if (str_input.at(i) == str_input.at(stringLength))
        {
            stringLength--;
            return true;
        }
        else if (str_input.at(i) != str_input.at(stringLength))
        {
            return false;
        }
    }

}





