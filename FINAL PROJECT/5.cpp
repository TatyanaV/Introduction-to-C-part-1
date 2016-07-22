//tatyana vlaskin
//week 10 problem 5
//5.cpp
#include <iostream>
#include <string>
using namespace std;

void menu();
void integerCheck(int &integer);
void newLine();
void goToMenuFunction();
char goToMenu;
string reverseIterative(string str_input);
string reverseIterative2(string str_input);
string str_input;
void iterativeReverse();
string reverseRecursive(string str_input);
void recursiveReverse();
bool is_palindrome(string str_input);//iterative
void palindromIterative();
void palindromRecursive();
bool is_palindrome(string str_input, int start, int end);// function is overloaded


int main(){
    menu();
    return 0;
}

void menu()
{
    int input;

    cout<<"\n\n\n\t\t*********************************************\n"<<endl;
    cout << "\t\tPlease select which function you want to run.\n";
    cout << "\t\t1. Iterative function to reverse a string.\n";
    cout << "\t\t2. Recursive function to reverse a string.\n";
    cout << "\t\t3. Palindrome check using iterative function.\n";
    cout << "\t\t4. Palindrome check using recursive function.\n";
    cout << "\t\tAcceptale entries are 1, 2, 3, and 4. " << endl;
    cout<<"\n\t\t*********************************************"<<endl;
    cout << "Make your selection: ";
    cin >> input;
    integerCheck(input);
    switch(input)
    {
    case 1:
        iterativeReverse();
        break;
   case 2:
        recursiveReverse();
        break;
   case 3:
        palindromIterative();
        break;
    case 4:
        palindromRecursive();
        break;
    default:
        cout << "Acceptale entries are 1, 2, 3, and 4. " << endl;
        menu();
        break;
        }
}

void integerCheck(int &integer){

    while(cin.fail() ||!cin.good()|| integer!= static_cast<int>(integer) || integer <1 || integer >4)
    {
        cout << "Error, invalid entry.  " << endl;
        cout << "Acceptale entries are 1, 2, 3, and 4. " << endl;
        cout << "Pease make a different entry: ";
        cin.clear();
        cin.ignore(80,'\n');
        cin.sync ();
        cin >> integer;
       //cout << integer;
        }
}

void iterativeReverse(){
     // declare variable
     //string str_input;
     newLine();
     cout << "You've selected iterative function to reverse a string.\n";
     cout<<"\nPlease enter a string that you want to reverse: ";
     getline(cin,str_input);
     cout<< "\nOriginal string: " << str_input << endl;

     cout<<"\nThe reverse of the string using while loop is: ";

     // function declaration
     reverseIterative(str_input);
     cout<<endl;
     cout<<"\nThe reverse of the string using for loop is: ";
     reverseIterative2(str_input);
     cout<< endl;
     goToMenuFunction();
}

 void newLine()
 {
 char symbol;
 do
 {
 cin.get(symbol);
 } while (symbol != '\n');
 }

string reverseIterative(string str_input)
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

void goToMenuFunction(){
    cout << endl << "Would you like to go back to the MENU? (y/n): ";
    cin >> goToMenu;
    switch(goToMenu)
        {
        case 'y':
        case 'Y':
            menu();
            break;
        case 'n':
        case 'N':
            cout <<"\nThank you for using our program.\n";
            cout << "Have a nice day.\n";
            break;
        default:
            cout << "Error, please type Y for yes and N for no" << endl;
            cout << endl << "Would you like to go back to the MENU? (y/n): ";
            cin >> goToMenu;
            break;
        }
}


string reverseIterative2(string str_input){

    //loop to display string one character at a time in reverse direction
    for (int i = (str_input.length()-1); i >=0 ; i --)
    {
            cout << str_input.at(i); // console output
    }
    return str_input;
}

void recursiveReverse(){
    newLine();
    cout << "You've selected recursive function to reverse a string.\n";
    cout<<"\nPlease enter a string that you want to reverse: ";
     getline(cin,str_input);
     //cout << str_input.substr(1)<< endl;
    // cout << str_input.substr(2)<< endl;
     //cout << str_input.substr(3)<< endl;
    cout<< "\nOriginal string: " << str_input << endl;

     cout<<"\nThe reverse of the string using recursive method is: ";

     // function declaration
     reverseRecursive(str_input);
     cout<< endl;
     goToMenuFunction();
}

string reverseRecursive(string str_input)
{
     if(str_input == "") // the base case
     {
         return str_input;
     }
     else // the recursive step
     {
          reverseRecursive(str_input.substr(1));
          cout<<str_input.at(0);
     }
     return str_input;
}

void palindromIterative(){
    newLine();
    cout << "You've selected Palindrome check using iterative function.\n";
    cout << "Palindrome Detection Program" << endl;
	cout << "Enter a word or a sentence: " ;
    getline(cin, str_input);
    if (is_palindrome(str_input) == true)
        cout << endl << "Your entry is a palindrome.\n";
    else
        cout << endl << "Your entry is not a palindrome.\n";
    goToMenuFunction();
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

void palindromRecursive(){
    newLine();
    cout << "You've selected Palindrome check using recursive function.\n";
cout << "Palindrome Detection Program" << endl;
	cout << "Enter a word or a sentence: ";
    getline(cin, str_input);
    if ((is_palindrome(str_input, 0, str_input.length()-1)) == true){
        cout << endl << "Your entry is a palindrome.\n";
    }
    else{
        cout << endl << "Your entry is not a palindrome.\n";
    }
    goToMenuFunction();
}





bool is_palindrome(string str_input, int start, int end)
{
    if (start >= end)
        return true;
    if (str_input[start] != str_input[end])
        return false;
    return is_palindrome(str_input, ++start, --end);
}
