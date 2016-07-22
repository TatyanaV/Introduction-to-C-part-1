

#include <iostream>
#include <algorithm>
#include<math.h>

using namespace std;

int main()
{
int a[10]={1,2,3,4,5,6,7,8,9,0};
int i,pin,entry,index,npin=0,temp=0;

cout<<"Enter PIN: ";
cin>>pin;

cout<<"PIN: ";
for(i=0; i<10; i++)
cout<<a[i]<<' ';

cout<<endl
<<endl;

random_shuffle(&a[0],&a[9]);

cout<<"NUM: ";
for(i=0; i<10; i++)
cout<<a[i]<<' ';

cout<<"\nEnter the passcode: ";
cin>>entry;

for(i = 4; i>=0; i--){
temp = entry/pow(10,i);
entry = fmod(entry,pow(10,i));
cout<<'\n'<<temp<<' '<<entry;
index = std::distance(a, std::find(a, a + 10, temp));
npin = (npin*10)+index+1;
cout<<' '<<npin;
}

if(pin == npin)
cout<<"Access granted";
else
cout<<"Access not granted";
}
