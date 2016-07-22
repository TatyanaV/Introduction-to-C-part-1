#include <iostream>
#include <string> // gives you sting funcition
using namespace std;

int main () {
    string my_str;
    cout << "Enter your favorite color: ";
    cin >> my_str;

        // loop that prints the string one character at a time
        for (int i = 0; i < my_str.length(); i++)
        {
            cout << my_str.at(i) << endl;
            //cout << my_str.length();
        }


        for (int i = (my_str.length()-1); i >=0 ; i --)
        {
            cout << my_str.at(i) << endl;
        }

        for(int i =0;i<my_str.size();i++)
        {
	    int lenth = i+1;
        cout<<lenth<<endl;
	}


}
