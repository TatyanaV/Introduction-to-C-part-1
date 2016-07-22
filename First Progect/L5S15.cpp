#include <iostream>     // Macro that includes library
using namespace std;    //Global statement

int main()      //Main function
{

char x;
//int count;
for(int count = 10, bool abort = false; count >= 0 && abort == false; count--)
{
    cout << "countdown is at: " << count << ", would you like to abort? (y/n)" << endl;
    cin >> x;
        if(x == 'y')
        {
            abort = true;
            cout << "Countdown aborted\n, I repeat, countdown aborted!" << endl;
        }
}
}
