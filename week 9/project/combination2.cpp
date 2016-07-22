

#include <iostream>

#include <stdio.h>


using namespace std;

/*Broccoli

Tomato

Kiwi

Kale

Tomatillo*/
const int NUM_REVIEWERS = 4; //Number of rows in reviews array
const int NUM_MOVIES = 6; //Number of columns in reviews array

// A few sample function prototypes you may choose to use or create your own
void initialRatings(int reviews[][NUM_MOVIES]); //a function to be defined to set all elements to zero in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array
void getRatings(int reviews[][NUM_MOVIES]); //a function to be defined to set reviewer rating values in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array
void displayRatings(int reviews[][NUM_MOVIES]); //a function to be defined to display current values in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array
void showReviewersHighestRating(int reviews[][NUM_MOVIES]); //a function to be defined that finds the highest value for a row in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array
void showAverageRatings(int reviews[][NUM_MOVIES]); //a function to be defined that calculates the average for each column in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array
double getAverage(int reviews[][NUM_MOVIES],int movieNumber); //a function to be defined that calculates and returns the average for a column in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array
void showMovieLowestRating(int reviews[][NUM_MOVIES]); //a function to be defined that finds the lowest value for a column in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array

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
void integerCheck(int &integer);
void setPassword();
void selectBasket();
void reviewGoods();

int menu(){

    int input;
    cout << "Welcome to the Community Supported Agriculture (CSA) farm! " << endl;
    cout << "Please chose an option from the menu below. " << endl;
    cout << "Acceptale entries are 1, 2, 3, and 4. " << endl;
    cout << " 1. Set a password. " << endl;
    cout << " 2. Create a Box of Produce. " << endl;
    cout << " 3. Rate quality of the produce in the previouse purchases. " << endl;
    cout << " 4. Exit the menu. " << endl;
    cout << "Make your selection: ";
    cin >> input;
    integerCheck(input);

    switch(input)
    {
    case 1:
        cout << " Set a password. ";
        setPassword();
        break;
    case 2:
        cout << "Create a Box of Produce. ";
        selectBasket();
        break;
    case 3:
        cout << "Rate quality of the produce in the previouse purchases." ;
       reviewGoods();
        break;
    case 4:
        cout << "Have a nice day.\n";
        break;
    default:
        //this will reset back to menu
        cout << "Error, please pick 1, 2, 3 or 4." << endl;
        menu();
        break;
        }
}
int main()
{

    menu();
    return 0;
}

void integerCheck(int &integer){

    while(cin.fail() || integer!= static_cast<int>(integer) || integer <=0)
    {
        cout << "Error, invalid age enetered.  " << endl
             << "Pease make a different entry: ";
        cin.clear();
        cin.ignore(80,'\n');
        cin >> integer;
        }

}

void setPassword(){

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

menu();
}

void selectBasket(){
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
menu();
}

void initialRatings(int reviews[][NUM_MOVIES]){
//a function to be defined to set all elements to zero in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array
for(int i=0;i<NUM_REVIEWERS;i++){
for(int j=0;j<NUM_MOVIES;j++){
reviews[i][j]=0; //set to 0
}
}
return;
}


void getRatings(int reviews[][NUM_MOVIES]){
//a function to be defined to set reviewer rating values in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array
int rating;
cout<<endl;
for(int i=0;i<NUM_REVIEWERS;i++){
for(int j=0;j<NUM_MOVIES;j++){
//loop until valid rating entered
do{
cout<<"Enter rating for rater "<<i+1<<", Movie #10"<<j<<"(1-terrible to 5-excellent): ";
cin>>rating;
if(rating<1||rating>5){
cout<<"\nRating must be between 1 and 5.\n";
}
}while(rating<1||rating>5);


reviews[i][j]=rating; //set rating
}
}
cout<<endl<<endl;
return;

}
void displayRatings(int reviews[][NUM_MOVIES]){
//a function to be defined to display current values in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array
int i,j;
cout<<endl<<"\t";
for(i=0;i<NUM_MOVIES;i++){
cout<<100+i<<'\t';
}

for(i=0;i<NUM_REVIEWERS;i++){
cout<<endl<<i+1<<'\t';
for(j=0;j<NUM_MOVIES;j++){
cout<<reviews[i][j]<<'\t';
}
}

cout<<endl<<endl;
return;

}
void showReviewersHighestRating(int reviews[][NUM_MOVIES]){
//a function to be defined that finds the highest value for a row in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array
int reviewer;
int highest,i;

do{
cin>>reviewer;
if(reviewer>4||reviewer<1){
cout<<"Please enter a reviewer number between 1 and 4: ";
}
}while(reviewer>4||reviewer<1);

cout<<"Reviewer "<<reviewer<<"'s highest rating is a ";

highest=0;
i=reviewer-1;

for(int j=0;j<NUM_MOVIES;j++){
if(reviews[i][j]>reviews[i][highest])
highest=j;
}
cout<<reviews[i][highest]<<".\n";

return;
}
void showAverageRatings(int reviews[][NUM_MOVIES]){
//a function to be defined that calculates the average for each column in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array
cout<<"Movie\tAverage Rating";

for(int j=0;j<NUM_MOVIES;j++){
cout<<endl<<100+j<<'\t'<<getAverage(reviews,j);
}
cout<<endl<<endl;
return;

}
double getAverage(int reviews[][NUM_MOVIES],int movieNumber){
//a function to be defined that calculates and returns the average for a column in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array
double sum=0;
for(int i=0;i<NUM_REVIEWERS;i++){
sum+=reviews[i][movieNumber];
}
return sum/(double)NUM_REVIEWERS;
}

void showMovieLowestRating(int reviews[][NUM_MOVIES]){
//a function to be defined that finds the lowest value for a column in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array
int movie;
int lowest,j;

do{
cin>>movie;
if(movie<100||movie>105){
cout<<"Please enter a movie number between 100 and 105: ";
}
}while(movie<100||movie>105);

cout<<"Movie "<<movie<<"'s lowest rating is a ";

j=movie-100;
lowest=0;

for(int i=0;i<NUM_REVIEWERS;i++){
if(reviews[i][j]<reviews[lowest][j])
lowest=i;
}
cout<<reviews[lowest][j]<<".\n";
cout<<endl<<endl;
return;
}
void reviewGoods(){
    // Variable declarations
int reviews[NUM_REVIEWERS][NUM_MOVIES]; // Ratings for reviewers
int choice;

initialRatings(reviews); //function call
getRatings(reviews); //function call

do
{
cout<<"---------------------------------------------------"<<endl;
cout<<"2-D ARRAY PROCESSING MENU OPTIONS"<<endl;
cout<<"---------------------------------------------------"<<endl;
cout<<"1. Display current movie ratings"<<endl;
cout<<"2. Show the average rating for each movie."<<endl;
cout<<"3. Show a reviewers highest rated movie. (enter reviewer# 1-4)"<<endl;
cout<<"4. Show a movies lowest rating. (enter movie# 100-105)"<<endl;
cout<<"5. Quit program"<<endl;

cout<<endl<<"Enter your choice:";
cin>>choice;
switch (choice)
{
case 1:
displayRatings(reviews);
break;
case 2:
showAverageRatings(reviews);
break;
case 3:
showReviewersHighestRating(reviews);
break;
case 4:
showMovieLowestRating(reviews);
break;
case 5:
cout<<"\nThank you for using this program. Press any key to exit . . . ";
cin.get();
break;
default:
cout<<"You enter an invaild choice.\n";

}
}while(choice!=5);
menu();
}
