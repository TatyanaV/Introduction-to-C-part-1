


#include<iostream>
using namespace std;
int main()
{
int count=0;
    double x;
    cout << "Enter a number: ";
    cin >> x;
    x /= 10;
    while(x > 1)
    {
      count++;
      x = x/10;
    }
    cout<<count+1;
}

