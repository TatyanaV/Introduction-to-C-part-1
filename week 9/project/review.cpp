#include <iostream>
#include <cstdlib>
using namespace std;

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

int main()
{
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
return 0;
}
//function definitions related to the above mentioned function prototypes should go here

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
