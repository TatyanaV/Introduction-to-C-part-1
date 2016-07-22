#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string str_input, int start, int end);

int main()
{
     string str_input;

	cout << "Palindrome Detection Program" << endl;
	cout << "Enter a word or a sentence: " << endl;
    getline(cin, str_input);
    if ((is_palindrome(str_input, 0, str_input.length()-1)) == true){
        cout << endl << "Your entry is a palindrome.\n";
    }
    else{
        cout << endl << "Your entry is not a palindrome.\n";
    }
}





bool is_palindrome(string str_input, int start, int end)
{
    if (start >= end)
        return true;
    if (str_input[start] != str_input[end])
        return false;
    return is_palindrome(str_input, ++start, --end);
}
