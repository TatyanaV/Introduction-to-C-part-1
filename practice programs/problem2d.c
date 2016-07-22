 #include <iostream>
 #include <string>
 using namespace std;
 void newLine( );
 string name (string x);
 int main( )
 {

     string firstName, lastName, middleName, totalName;
    string a = name (first, firstName);
     name (middle, middleName);
     name (last, lastName);

 //string firstName, lastName, middleName, totalName; // initialize first name, last name and middle name


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


string name (string y, string x)
 {
    cout << "Enter your " << y << " name " << x;
    getline(cin,x);
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
