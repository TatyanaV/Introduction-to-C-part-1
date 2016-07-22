 #include <iostream>
 #include <string>
 using namespace std;
 //void newLine( );
 int main( )
 {
    string firstEntry, secondEntry, thirdEntry, combinedName; // initialize first name, last name and middle name
    cout << "Enter your first, middle and last name: ";
    cin >> firstEntry >> secondEntry; // fist and second word that will be entered

   if (cin.peek()  != '\n') {
        cin >> thirdEntry; // third word that will be entered
	    combinedName = thirdEntry + ", " + firstEntry + " " + secondEntry.at(0) + ". ";
	    cout << "Your name is: ";
	    cout << combinedName << endl;
	  }

	  else {
        combinedName = secondEntry + ", " + firstEntry;
	    cout << "Your name is: ";
	    cout << combinedName << endl;
	  }

 return 0;
 }

//Uses iostream:
/* void newLine( )
 {
    char nextChar;
    do
    {
        cin.get(nextChar);
    } while (nextChar != '\n');
 }

*/

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
