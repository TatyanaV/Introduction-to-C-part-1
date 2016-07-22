#include <iostream>
	#include <string>

	using namespace std;

	int main()
	{
	 	  string first, second, third, total_name;
	  char ch;

	  cout << endl;
	  cout << "Enter your name (first middle last): ";
	  cin >> first >> second;

	  if (cin.peek()  != '\n') {
	    cin >> third;
	    total_name = third + ", " + first + " " + second.at(0) + ". ";
	    cout << "Your name is: ";
	    cout << total_name << endl;
	  }

	  else {
	    total_name = second + ", " + first;
	    cout << "Your name is: ";
	    cout << total_name << endl;
	  }

	    return 0;
	}
