#include<iostream>
#include<string>
#include<cstdlib>
#include <time.h>
using namespace std;
int main()
{
int Actual_PIN;
srand(time(NULL));
string response;
cout <<"Enter Actual PIN Number :";
cin >>Actual_PIN;
cout << endl;
int real_pin_array[5];
for(int i=0; i<5; i++)
{
real_pin_array[4-i] = Actual_PIN%10;
Actual_PIN = Actual_PIN/10;
}
int rand_array[10];
for(int i=0; i<10; i++)
{
rand_array[i] = rand()%3 + 1;
}
cout <<" PIN : 0 1 2 3 4 5 6 7 8 9"<< endl;
cout << " NUM : ";
for (int i=0; i<10; i++)
cout << rand_array[i] << " ";
cout <<endl;
cout <<"Enter your response :";
cin >> response;
cout << endl;
bool is_password_match = true;
for(int i=0; i<response.length(); i++)
{
if((response[i]-'0') != rand_array[real_pin_array[i]])
is_password_match = false;
}
if(is_password_match)
cout << "Your Response correctly matches the PIN Number " <<endl;
else
cout << "Your Response Not matches the PIN Number " <<endl;
system("pause");
return 0;
}
