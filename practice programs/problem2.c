 #include <iostream>
 #include <string>
 using namespace std;
 void newLine( );
 int main( )
 {
 string firstName, lastName, middleName, totalName; // initialize first name, last name and middle name

cout << "Enter your first, middle and last name:\n";
 getline(cin, firstName, ' ');
 getline (cin, lastName, ' ');
 getline (cin, middleName, ' '); //>> firstName >> middleName >> lastName;//user enters name
 newLine( ); //The function get allows your program to read in one character of input and store it
//in a variable of type char .

   if (cin.peek()  != '\n') {
	    cin >> middleName;
	    totalName = lastName + ", " + firstName + " " + middleName.at(0) + ". ";
	    cout << "Your name is: ";
	    cout << totalName << endl;
	  }

	  else {
	    totalName = lastName + ", " + firstName;
	    cout << "Your name is: ";
	    cout << totalName << endl;
	  }

 return 0;
 }

//Uses iostream:
 void newLine( )
 {
    char nextChar;
    do
    {
        cin.get(nextChar);
    } while (nextChar != '\n');
 }

/*#include <iostream>
#include <string>

using namespace std;


int main()
{

  string a,b,c;

  cout<<"Please type in your first name, middle name or initial, and then last name:"<<endl;
  cin >> a >> b >> c;
  cout <<"Your name is:"<<endl<< c <<", " << a <<" " << b[0] <<"." << endl;
return 0;
}*/
