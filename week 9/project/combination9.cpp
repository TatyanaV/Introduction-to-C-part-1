#include <iostream>
#include <stdio.h>

using namespace std;
char goToMenu;
void goToMenuFunction();
int countNumbers;
void validPassword(int &entry);
string response;
void checkPIN(string respons,int real_pin_array[5], int rand_array[10]);
int real_pin_array[5];
int rand_array[10];
int Actual_PIN;
char veg[][15] = { "Tomatillo", "Broccoli ","Tomato   ","Kiwi     ","Kale     "};

int NUM_REVIEWERS; //4//Number of rows in reviews array
//int NUM_MOVIES; //Number of columns in reviews array
int **reviews;
// A few sample function prototypes you may choose to use or create your own
void initialRatings(int **reviews); //a function to be defined to set all elements to zero in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array
void getRatings(int **reviews); //a function to be defined to set reviewer rating values in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array
void displayRatings(int **reviews); //a function to be defined to display current values in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array
void showReviewersHighestRating(int **reviews); //a function to be defined that finds the highest value for a row in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array
void showAverageRatings(int **reviews); //a function to be defined that calculates the average for each column in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array
double getAverage(int **reviews,int movieNumber); //a function to be defined that calculates and returns the average for a column in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array
void showMovieLowestRating(int **reviews); //a function to be defined that finds the lowest value for a column in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array
int NUM_MOVIES = 5;
class BoxOfProduce{
    private:
        char i1[20];
        char i2[20];
        char i3[20];
    public:
        int static BoxCount;
    public:
        BoxOfProduce(char *f1, char*f2, char *f3){
        strcpy(i1, f1);
        strcpy(i2, f2);
        strcpy(i3, f3);
        }
    void Display(void);
    void Replace (int i, char *f);
};

int BoxOfProduce::BoxCount=0;
void integerCheck(int &integer);
void setPassword();
void selectBasket();
void reviewGoods();
int transactions;
int transactionNumber(int& transactions)
{
    cout << "\nHow many transactions do you want to grade: ";
    cin >> transactions;
//    transactions = integerCheck(transactions);
    return transactions;
}

int produceNumber(int& produce)
{
    cout << "\nHow many different produce items do you want to grade?: ";
    cin >> produce;
//    transactions = integerCheck(transactions);
    return produce;
}


int menu(){

    int input;

    cout << "Acceptale entries are 1, 2, 3, and 4. " << endl;
    cout<<"\n\n\n\t\t*********************************************\n"<<endl;
    //cout << "Welcome to the Community Supported Agriculture (CSA) farm! " << endl;
    cout << " \t\t1. Set a password. \n" << endl;
    cout << " \t\t2. Create a Box of Produce. \n" << endl;
    cout << " \t\t3. Rate quality of the produce in the previouse purchases.\n " << endl;
    cout << " \t\t4. Exit the menu. \n" << endl;
    cout<<"\n\t\t*********************************************"<<endl;
    cout << "Make your selection: ";
    cin >> input;
    integerCheck(input);

    switch(input)
    {
    case 1:
        //cout << " Set a password. ";
        setPassword();
        break;
    case 2:
        //cout << "Create a Box of Produce. ";
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
    cout << "Welcome to the Community Supported Agriculture (CSA) farm! " << endl;
    cout << "Please chose an option from the menu below. " << endl;
    menu();
    return 0;
}

void validPassword(int &entry){

      while(!cin.good() || entry > 99999 || entry < 11111||entry != static_cast<int>(entry)){
        cout << "Error, invalid age enetered.  " << endl
             << "Pease make a different entry: ";
        cin.clear();
       // cin.ignore(80,'\n');
        cin.sync ();
        cin >> entry;
        cout <<entry << "I am here" << endl;
  }
}
void integerCheck(int &integer){

    while(cin.fail() ||!cin.good()|| integer!= static_cast<int>(integer) || integer <=0)
    {
        cout << "Error, invalid age enetered.  " << endl
             << "Pease make a different entry: ";
        cin.clear();
        cin.ignore(80,'\n');
        cin.sync ();
        cin >> integer;
        cout << integer;
        }


}

void setPassword(){

//int Actual_PIN;
srand(time(NULL));
//string response;
cout << endl<<"PLEASE CREATE NEW PASSWORD." << endl;
cout<< "Password must consists of a five-digit PIN number (11111 to 99999). " <<endl;
cout <<"Once your password is accepted, you will be prompted to reenter " << endl
    << "you password using our randomized challenge-response system"<<endl
    << "In these systems, the user enters different information every "<<endl
    << "time based on a secret in response to a randomly generated challenge. "<<endl
    << "This system protects your password from 'shoulder surfing.'" << endl;
    cout <<endl<<"Please create a new PIN Number :";
    cin >>Actual_PIN;
    validPassword(Actual_PIN);
    cout << endl;
    //int real_pin_array[5];
    for(int i=0; i<5; i++)
    {
        real_pin_array[4-i] = Actual_PIN%10;
        Actual_PIN = Actual_PIN/10;
    }
    //int rand_array[10];
    for(int i=0; i<10; i++)
    {
        rand_array[i] = rand()%3 + 1;
    }
    cout << "To confirm your password and to practice using our" << endl
        <<  "randomized challenge-response system, please enter your" << endl
        <<  "password using random number key displayed on the screen." << endl;
//cout <<Actual_PIN <<endl;// this is here for debugging
    cout <<"Numbers in the PIN :        0 1 2 3 4 5 6 7 8 9"<< endl;
    cout << "Corresponing random NUM :   ";
    for (int i=0; i<10; i++)
        cout << rand_array[i] << " ";
        cout <<endl<< endl;
        cout <<"Enter your PIN using random numbers:";
        cin >> response;
        cout << endl;
        cout << response<< endl;
   // bool is_password_match = true;
         checkPIN(response,real_pin_array, rand_array);
}

    void checkPIN(string respons,int real_pin_array[5], int rand_array[10]){
       // int rand_array[10];

         bool is_password_match = true;
    for(int i=0; i<response.length(); i++)
    {
        if((response[i]-'0') != rand_array[real_pin_array[i]])
            is_password_match = false;
    }
    if(is_password_match){
        cout << "Your Response correctly matches the PIN Number. " <<endl;
        cout << endl;
    goToMenuFunction();

    }
    else{
        cout << real_pin_array[5] << endl;
         cout << rand_array[real_pin_array[5]]<< endl;
        // cout << response<< endl;
         cout << Actual_PIN <<endl;

        cout << "Your Response Not matches the PIN Number " <<endl;
        cout << "Please reenter your PIN. " <<endl;
        cin >> response;
        checkPIN(response,real_pin_array, rand_array);
        //checkPIN(response);
     }
}

void goToMenuFunction(){
    //char goToMenu;
           cout << endl << "Would you like to go back to the MENU? (y/n): ";
            cin >> goToMenu;
             switch(goToMenu)
        {
        case 'y':
        case 'Y':
        //case 'yes':
        //cout << " Set a password. ";
        menu();
        break;

        case 'n':
        case 'N':
            cout <<"\nThank you for using our program.\n";
            cout << "Have a nice day.\n";
        break;

        default:
            cout << "Error, please type Y for yes and N for no" << endl;
            cout << endl << "Would you like to go back to the MENU? (y/n): ";
            cin >> goToMenu;
            break;
        }
}


void selectBasket(){
    int exit = 0;
    char ch2;
    //char veg[][15] = { "Broccoli","Tomato","Kiwi","Kale","Tomatillo" };
    BoxOfProduce b1( veg[rand()%5], veg[rand()%5], veg[rand()%5] );
    cout << "\nCommunity Supported Agriculture farm delivers a box of fresh fruits\n"
        << "and vegetables to your house once a week.\n";
    cout <<"Each box of produce must contain 3 items. Dublicate produce is allowed.\n";
    cout << "\nA box of produce with three items was randomly generated for you.\n";
    do{
        cout << "\nContents of the box: \n";
        b1.Display();
        cout <<"\nWe hope that you are satisfied with the randomely generated box of produce\n";
        cout <<"If you are not satisfied with the randomly generate box of produce\n"
            <<"you have an option to replace items in the box.\n";
        cout<<"\nWould you like to Replace any items(Y/N)?";
        cin >> ch2;
        if( ch2 == 'y' || ch2=='Y'){
            int rep=0, rep_with;
            cout <<"\nHere is the contents of the current box: \n\n";
            b1.Display();
            cout<<"\nEnter index of fruit or vegetable that you want to replace :";
            cin>>rep;
            cout << "\nHere is the list of fruts and veggies that you can chose from: \n\n";
            for( int i=0; i<5; i++)
                cout<<i+1<<". "<<veg[i]<<endl;
                cout<<"\nChose the index of the frut or vegetable that you want to chose : ";
                cin >> rep_with;
                b1.Replace(rep, veg[rep_with-1]);
            }
        }while( ch2 != 'n' && ch2!='N' );
    cout<<"\nYou placed an order for the following box of produce:\n\n";
    b1.Display();
    goToMenuFunction();

}

void BoxOfProduce::Display(void){

    cout<<"1. "<<i1<<endl;

    cout<<"2. "<<i2<<endl;

    cout<<"3. "<<i3<<endl;

}

void BoxOfProduce::Replace (int i, char *f){

    switch( i ){

        case 1: strcpy(i1, f); break;

        case 2: strcpy(i2, f); break;

        case 3: strcpy(i3, f); break;
    }
}

void initialRatings(int **reviews){
//a function to be defined to set all elements to zero in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array
    //int**ary = new int*[sizeX];
    //for(int i = 0; i < sizeX; ++i)
    //ary[i] = new int[sizeY];

    for(int i=0;i<NUM_REVIEWERS;i++){
        for(int j=0;j<NUM_MOVIES;j++){
            reviews[i][j]=0; //set to 0
    }
    }
    return;
}

void getRatings(int **reviews){
//a function to be defined to set reviewer rating values in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array
    int rating;
    cout<<endl;
        for(int i=0;i<NUM_REVIEWERS;i++){
            cout << "ENTER RATING FOR TRANSACTION #: " << i+1 << endl<<endl;
            for( int j=0; j<NUM_MOVIES; j++)
               {
    //loop until valid rating entered
                do{
                    cout<<"Enter rating for " << veg[j]<<" (1-terrible to 5-excellent, 0 -never ordered): ";
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
void displayRatings(int **reviews){
//a function to be defined to display current values in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array
    int i,j;
    cout<<endl<<"\t";
    for(i=0;i<NUM_MOVIES;i++){
        cout << veg[i]<<" ";
   //cout<<100+i<<'\t';
    }
    for(i=0;i<NUM_REVIEWERS;i++){
        cout<<endl <<i+1<<'\t';
        for(j=0;j<NUM_MOVIES;j++){
            cout<<reviews[i][j]<<"         ";
        //cout << "----------------------------------";
        }

}
//cout << "----------------------------------";
    cout<<endl<<endl;
    return;
}

void showAverageRatings(int **reviews){
//a function to be defined that calculates the average for each column in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array
    cout<<"Product\tAverage Rating";

    for(int j=0;j<NUM_MOVIES;j++){
        cout<<endl<<veg[j]<<'\t'<<getAverage(reviews,j);
    }
    cout<<endl<<endl;
    return;
}
double getAverage(int **reviews,int movieNumber){
//a function to be defined that calculates and returns the average for a column in the int reviews[NUM_REVIEWERS][NUM_MOVIES] array
    double sum=0;
    for(int i=0;i<NUM_REVIEWERS;i++){
        sum+=reviews[i][movieNumber];
    }
    return sum/(double)NUM_REVIEWERS;
}

void showMovieLowestRating(int **reviews){
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
    //int **reviews;
    transactionNumber(NUM_REVIEWERS);
   // produceNumber(NUM_MOVIES);
    reviews = new int *[NUM_REVIEWERS];
	int i, j;
	for (i=0; i < NUM_REVIEWERS; i++)
		reviews[i] = new int [NUM_MOVIES];

    //int reviews[NUM_REVIEWERS][NUM_MOVIES]; // Ratings for reviewers
    int choice;
    initialRatings(reviews); //function call
    getRatings(reviews); //function call
    do
    {
        cout<<"---------------------------------------------------"<<endl;
        cout<<"2-D ARRAY PROCESSING MENU OPTIONS"<<endl;
        cout<<"---------------------------------------------------"<<endl;
        cout<<"1. Display current produce ratings"<<endl;
        cout<<"2. Show the average rating for each fruit and vegetable."<<endl;
        cout<<"3. Go back to the MAIN menu"<<endl;

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
        menu();

        break;

        default:
        cout<<"You enter an invaild choice.\n";

        }
    }while(choice!=5);
    menu();
}
