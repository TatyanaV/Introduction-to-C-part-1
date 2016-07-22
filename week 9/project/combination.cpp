

#include <iostream>

#include <stdio.h>


using namespace std;

/*Broccoli

Tomato

Kiwi

Kale

Tomatillo*/


class BoxOfProduce{

private:

char i1[20];

char i2[20];

char i3[20];

public:

int static BoxCount;

public:
BoxOfProduce(char *f1, char*f2, char *f3){

BoxCount++;

strcpy(i1, f1);

strcpy(i2, f2);

strcpy(i3, f3);

}

void Display(void){

cout<<"\nBox Contents"<<endl;

cout<<"1. "<<i1<<endl;

cout<<"2. "<<i2<<endl;

cout<<"3. "<<i3<<endl;

}

void Replace (int i, char *f){

switch( i ){

case 1: strcpy(i1, f); break;

case 2: strcpy(i2, f); break;

case 3: strcpy(i3, f); break;

}

}

};

int BoxOfProduce::BoxCount=0;


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


int exit = 0;

char ch2;

char veg[][15] = { "Broccoli",

"Tomato",

"Kiwi",

"Kale",

"Tomatillo" };

do{

BoxOfProduce b1( veg[rand()%5], veg[rand()%5], veg[rand()%5] );

do{

b1.Display();

cout<<"Would you like to Replace any(Y/N)?";

cin >> ch2;

if( ch2 == 'y' || ch2=='Y'){

int rep=0, rep_with;

cout<<"Enter index of fruit to replace :";

cin>>rep;

for( int i=0; i<5; i++)

cout<<i+1<<". "<<veg[i]<<endl;

cout<<"Replace with : ";

cin >> rep_with;

b1.Replace(rep, veg[rep_with-1]);

}

}while( ch2 != 'n' && ch2!='N' );

cout<<"Final Delivery";

b1.Display();


cout<<"\n\nWould you like to create another box(Y/N)";

cin.get();

cin >> ch2;

}while(ch2=='y' || ch2=='Y') ;

cout<<"Total Boxes Created: "<<BoxOfProduce::BoxCount;

}

