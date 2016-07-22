//tatyana vlaskin
//final project
//project.cpp
//last modified 06.08.2014

#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>
#include <cstring>
#include<stdio.h>
#include <cstdlib>

using namespace std;

///FUNCTIONS AND VARIABLES USED MANY TIMES:
//REQUIREMENT # 13. Demonstrates the different passing mechanisms
//PASS BY VALUE
//REQUIREMENT 14. Demonstrates function overloading,
int integerCheck (string INPUT);
//REQUIREMENT 14. Demonstrates function overloading,
void integerCheck(int &integer);
int menu();
void newLine();
void setprecision(int number);
//REQUIREMENT #12. Demonstrates how scope of variables works
//THIS IS A GLOBAL VARIABLE CAN BE ACCESSED BY ALL FUNCTIONS
char goToMenu;
void goToMenuFunction();
///FUNCTIONS AND VARIABLES USED IN THE SET A PASSWORD PROGRAM:
//REQUIREMENT #13. Demonstrates the different passing mechanisms
//PASS BY REFFERENCE
void validPassword(int &entry);
string response;
void checkPIN(string respons,int real_pin_array[5], int rand_array[10]);
void setPassword();
int real_pin_array[5];
int rand_array[10];
int Actual_PIN;
///FUNCTIONS AND VARIABLES USED IN THE CREATE A BOX OF PRODUCE PROGRAM
//REQUIREMENT #21. Demonstrates definition and use for at least one class and object,
class BoxOfProduce{
    // REQUIREMENT #12. Demonstrates how scope of variables works
    //THESE PRIVATE VARIABLES CAN BE ACCESSED ONLY BY CLASS FUCNTIONS
    private:
        char produce1[20];//3 products that will be randomly selected
        char produce2[20];
        char produce3[20];
     public:
    //REQUIREMENT # 13: Demonstrates the different passing mechanisms
    //passing the value of a pointer
    //REQUIREMENT #15: Demonstrates at least one string variable (c-style string),
        BoxOfProduce(char *selection1, char*selection2, char *selection3);//constructor
        void Display();//displays list of fruits and vegetables
        void Replace (int produce, char *selection);// function to replace fruit/veg
};
//REQUIREMENT #17. Demonstrates at least one multi-dimensional array,
char veg[][15] = { "Tomatillo", "Broccoli ","Tomato   ","Kiwi     ","Kale     "};
void selectBasket();

///FUNCTIONS AND VARIABLES RELATED TO THE REVIEW THE PRODUCE PROGRAM
int NUM_REVIEWERS; //4//Number of rows in reviews array
int NUM_PRODUCE = 5;
int **reviews;
//REQUIREMENT #17. Demonstrates at least one multi-dimensional array,
//REQUIREMENT #18. Demonstrates at least one dynamically declared array,
//SEE DECLARATION IN THE CODE
void reviewGoods();
int transactionNumber(int& transactions);
void initialRatings(int **reviews);
void getRatings(int **reviews);
void displayRatings(int **reviews);
void showAverageRatings(int **reviews);
double getAverage(int **reviews,int product);
void delete2D_ArrayPointer(int **reviews);
int transactions;

///FUNCTIONS AND VARIABLES USED IN THE BUY FLOWER SEEDS PROGRAM:
//REQUIREMENT #20. Demonstrates definition and use for at least one struct,
struct menuFlower{
    string flower;
    double flowerPrice;
};
//REQUIREMENT #10: Demonstrates at least one function that you define
//REQUIREMENT #11: Demonstrates general functional decomposition
void getFlowerOrder( menuFlower[],menuFlower[],int&);
void listFlowerSeeds( menuFlower[],int);
void printCheck(menuFlower[],int );
void orderSeeds();
int items=0;
menuFlower menuSeeds[]={
                          "Daffodills   ",10.45,
                          "Sunflower    ",17.45,
                          "Tulip        ",8.99,
                          "Zinnia       ",10.99,
                          "Lavender     ",24.49,
                          "Dahlia       ",10.69,
                          "Hyacinth     ",15.50,
                          "Crocus Vernus",11.75
                          };
menuFlower order[10];


int main(int argc, char* argv[])
{
    if(argc == 1)// if user decided not to use command line
	{
    //REQUIREMENT #1. Demonstrates simple output (cout or printf is fine),
    cout << "Welcome to the Community Supported Agriculture (CSA) farm! " << endl;
    cout << "Please chose an option from the menu below. " << endl;
    menu();
	}
    //REQUIREMENT #19. Demonstrates at least one command line argument
    //YOU NEED TO ENTER RATING FOR PRODUCE IN THE BASKET FOR YOUR LAST TRANSACTION
    // THERE ARE 5 POSSIBLE PRODUCTS IN THE BASKET, SO YOU NEED TO ENTER 5 VALUES
    else if(argc==6)
    {
        for(int entry =1; entry <argc; entry++){//loops through entries. first element is reserved for name
        NUM_REVIEWERS = 1;
        reviews[NUM_REVIEWERS ][entry-1]=atoi(argv[entry]);//loops though the entries, need to changed entries to atoi per http://en.cppreference.com/w/cpp/string/byte/atoi
        }
        displayRatings(reviews);
    }
    //REQUIREMENT #5: Demonstrates logical or bitwise operator (more specifically &, |, ^, &&, ||, !, ==),
        else if(argc>6)
    {
        cout <<" Too many arguments supplied" <<endl;
    }
    return 0;
}
int menu(){
    // REQUIREMENT #12. Demonstrates how scope of variables works
    //THESE VARIABLES ARE LOCAL TO THIS FUNCTION
    //AND CAN BE ACCESSED ONLY BY THIS FUNCTION
    string entered;
    int input;

    cout << "Acceptale entries are 1, 2, 3, 4, and 5. " << endl;
    cout<<"\n\n\n\t\t*********************************************\n"<<endl;
    //cout << "Welcome to the Community Supported Agriculture (CSA) farm! " << endl;
    cout << " \t\t1. Set a password. \n" << endl;
    cout << " \t\t2. Create a Box of Produce. \n" << endl;
    cout << " \t\t3. Rate quality of the produce in the previouse purchases.\n " << endl;
    cout << " \t\t4. Order Flower Seeds.\n" <<endl;
    cout << " \t\t5. Exit the menu. \n" << endl;
    cout<<"\n\t\t*********************************************"<<endl;
    cout << "Make your selection: ";
    //REQUIREMENT #2: Demonstrates simple input (cin)
    getline(cin,entered);// >> input;
    input = integerCheck(entered);
    //REQUIREMENT #4:Demonstrates conditional SWITCH
    switch(input)
    {
    case 1:
        setPassword();
        break;
    case 2:
        selectBasket();
        break;
    case 3:
        cout << "Rate quality of the produce in the previouse purchases." ;
        reviewGoods();
        break;
    case 4:
        orderSeeds();
        break;
    case 5:
        cout << "Have a nice day.\n";
        break;
    default:
        //this will reset back to menu
        //REQUIREMENT #9: THIS WILL PREVENT RUN TIME ERROR
        //LETS THE USER KNOW THAT INCORRECT ENTRY WAS MADE
        cout << "Error, please pick 1, 2, 3, 4 or 5." << endl;
        menu();
        break;
        }
}

void integerCheck(int &integer){
    //REQUIREMENT #3: Demonstrates explicit type casting
    //REQUIREMENT #9:DEBUGGING: VERIFIES USERS INPUT, LETS THEM KNOW
    //IF INCORRECT ENTRY WAS MADE
    while(cin.fail() ||!cin.good()|| integer!= static_cast<int>(integer) || integer <=0)
    {
        cout << "Error, invalid  enetered.  " << endl
             << "Pease make a different entry: ";
        cin.clear();
        cin.ignore(80,'\n');
        cin.sync ();
        cin >> integer;
        cout << integer;
        }
}
void setPassword(){
    srand(time(NULL));
    //REQUIREMENT #9:DEBUGGING: PROVIDIS INFORMATION
    //TO THE USER WHAT ARE THE REQUIREMENTS FOR THE
    //VALID PASSWORD. IF THE USER IS COMLIENT AND FOLLOWS
    //THIS REQUIREMENTS, THIS MESSAGE ACTS AS A DEBUGGER
    // IF THE USER DOES NOT CARE ABOUT READING THE MESSAGE
    //AND DECIDES TO ENTER NONSENSE, WE NEED TO VERIFY INPUT
    //USING ERROR VERIFICATION FUNCTION-SEE BELOW
    cout << endl<<"PLEASE CREATE NEW PASSWORD." << endl;
    cout<< "Password must consists of a five-digit PIN number (1-9). " <<endl;
    cout <<"please note, that 0 (zero) is not an acceptable number. " <<endl;
    cout <<"Once your password is accepted, you will be prompted to reenter " << endl
        << "you password using our randomized challenge-response system"<<endl
        << "In these systems, the user enters different information every "<<endl
        << "time based on a secret in response to a randomly generated challenge. "<<endl
        << "This system protects your password from 'shoulder surfing.'" << endl;
    cout <<endl<<"Please create a new PIN Number :";
    cin >>Actual_PIN;
    //REQUIREMENT #8: IF I OMIT VALIDPASSWORD FUNCTION THAT
    //CHECKS AND MAKES SURE THAT INT WAS ENTERED AND TRY
    //TO ENTER STRING, THIS WILL RESULT IN INFINIT LOOP
    //THIS IS AN EXAMPLE OF RUN-TIME ERROR
    validPassword(Actual_PIN);
    cout << endl;
   // REQUIREMENT # 6: Demonstrates at least one loop,
    for(int i=0; i<5; i++){
        real_pin_array[4-i] = Actual_PIN%10;
        Actual_PIN = Actual_PIN/10;
    }
    //int rand_array[10];
    //REQUIREMENT #7. Demonstrates at least one random number,
    for(int i=0; i<10; i++){
        rand_array[i] = rand()%3 + 1;
    }
    cout << "To confirm your password and to practice using our" << endl
        <<  "randomized challenge-response system, please enter your" << endl
        <<  "password using random number key displayed on the screen." << endl;
//cout <<Actual_PIN <<endl;// this is here for debugging
    cout <<"Numbers in the PIN :        0 1 2 3 4 5 6 7 8 9"<< endl;
    //REQUIREMENT #8: Demonstrates understanding of the SYNTAX ERROR
    //IF I FORGET SEMICOLON, LIKE SHOWN ON THE NEXT LINE
    //PROGRAM WILL NOT COMPILE DUE TO SYNTAX ERRO
    //cout << "Corresponing random NUM :   "--MISSING SEMICOLON
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
void validPassword(int &entry){
   //REQUIREMENT #5: Demonstrates logical or bitwise operator (more specifically &, |, ^, &&, ||, !, ==),
      while(!cin.good() || entry > 99999 || entry < 11111||entry != static_cast<int>(entry)){
        cout << "Error, invalid entry.  " << endl
           << "Password must consist of a five digit pin number." <<endl
             << "Pease make a different entry: ";
        cin.clear();
        cin.sync ();
        cin >> entry;
        cout <<entry << "I am here" << endl;
  }
}
//REUIREMENT #16. Demonstrates some form of recursion,
void checkPIN(string respons,int real_pin_array[5], int rand_array[10]){
    bool is_password_match = true;
    for(int i=0; i<response.length(); i++){
        //REQUIREMENT #4:Demonstrates conditional IF statement
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
        //REQUIREMENET #16. Demonstrates some form of recursion,
        checkPIN(response,real_pin_array, rand_array);//RECURSIVE CALL
        //checkPIN(response);
     }
}
void goToMenuFunction(){
    cout << endl << "Would you like to go back to the MENU? (y/n): ";
    cin >> goToMenu;
    // newLine();
    switch(goToMenu)
    {
        case 'y':
        case 'Y':
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
    BoxOfProduce box(veg[rand()%5], veg[rand()%5], veg[rand()%5] );

    cout << "\nCommunity Supported Agriculture farm delivers a box of fresh fruits\n"
        << "and vegetables to your house once a week.\n";
    cout <<"Each box of produce must contain 3 items. Dublicate produce is allowed.\n";
    cout << "\nA box of produce with three items was randomly generated for you.\n";
    do{
        cout << "\nContents of the box: \n";
        box.Display();
        cout <<"\nWe hope that you are satisfied with the randomely generated box of produce\n";
        cout <<"If you are not satisfied with the randomly generate box of produce\n"
             <<"you have an option to replace items in the box.\n";
        cout <<"\nWould you like to Replace any items(Y/N)?";
        cin  >> ch2;
       //REQUIREMENT #15. Demonstrates at least one string variable (std::string ),
        string rep1, rep_with1;
        int rep, rep_with;
        if( ch2 == 'y' || ch2=='Y'){
            cout <<"\nHere is the contents of the current box: \n\n";
            box.Display();
            cout<<"\nEnter index of fruit or vegetable that you want to replace :";
            newLine();
            getline(cin,rep1);
            cout <<endl<< rep1;// REQUIREMENT #9: THIS WAS USED FOR DEBUGGIN. PROGRAM WAS SKIPPINT GENLINE();
            rep = integerCheck(rep1);
            cout << "\nHere is the list of fruts and veggies that you can chose from: \n\n";
           ////////write a function for this;
           //listProduce(veg[], 5);
            for( int i=0; i<5; i++)
                cout<<i+1<<". "<<veg[i]<<endl;
                cout<<"\nChose the index of the frut or vegetable that you want to chose : ";
                //newLine();
                getline(cin,rep_with1);
                rep_with = integerCheck(rep_with1);
                box.Replace(rep, veg[rep_with-1]);
            }
        }while( ch2 != 'n' && ch2!='N' );// REQUIREMENT # 6: Demonstrates at least one loop,
    cout<<"\nYou placed an order for the following box of produce:\n\n";
    box.Display();
    goToMenuFunction();
}
BoxOfProduce::BoxOfProduce(char *selection1, char*selection2, char *selection3){
    strcpy(produce1, selection1);
    strcpy(produce2, selection2);
    strcpy(produce3, selection3);
}
void BoxOfProduce::Display(){
    cout<<"1. "<<produce1<<endl;
    cout<<"2. "<<produce2<<endl;
    cout<<"3. "<<produce3<<endl;
}
void BoxOfProduce::Replace (int choice, char *selection){
    switch(choice){
        case 1: strcpy(produce1, selection); break;
        case 2: strcpy(produce2, selection); break;
        case 3: strcpy(produce3, selection); break;
    }
}

void reviewGoods(){
    transactionNumber(NUM_REVIEWERS);
   //REQUIREMENT # 18. Demonstrates at least one dynamically declared array,
   //REQUIREMENT #22. Attempts to demonstrate a pointer to an array
    reviews = new int *[NUM_REVIEWERS];
	int i, j;
	for (i=0; i < NUM_REVIEWERS; i++)
		reviews[i] = new int [NUM_PRODUCE];
    int choice;
    string choice1;
    initialRatings(reviews); //function call
    getRatings(reviews); //function call
    cout<<"---------------------------------------------------"<<endl;
    cout<<"DO YOU WANT TO SEE SUMMARY OF YOUR REVIEW?"<<endl;
    cout<<" Chose an option below (1, 2 or 3).\n";
    cout<<"---------------------------------------------------"<<endl;
    cout<<"1. Display current produce ratings"<<endl;
    cout<<"2. Show the average rating for each fruit and vegetable."<<endl;
    cout<<"3. Go back to the MAIN menu"<<endl;
    cout<<endl<<"Enter your choice:";
    getline(cin,choice1);
    choice = integerCheck(choice1);
    switch (choice)
    {
        case 1:
            displayRatings(reviews);break;
        case 2:
            showAverageRatings(reviews); break;
        case 3:
            menu(); break;
        default:
            cout<<"You enter an invaild choice.\n";break;
        }
       delete2D_ArrayPointer(reviews);
}

int transactionNumber(int& transactions)
{
    string transactions1;
    cout << "\nHow many transactions do you want to grade: ";
    getline(cin,transactions1);
    transactions = integerCheck(transactions1);
    return transactions;
}
//Deletes pointer to 2d array
void delete2D_ArrayPointer(int **reviews){
    for(int i=0;i<NUM_REVIEWERS;i++){
        for(int j=0;j<NUM_PRODUCE;j++){
            //delete reviews[i][j]; //set to 0
            delete[]reviews[i];
        }
    }
    delete[] reviews;
}
void initialRatings(int **reviews){
    for(int i=0;i<NUM_REVIEWERS;i++){
        for(int j=0;j<NUM_PRODUCE;j++){
            reviews[i][j]=0; //set to 0
        }
    }
    return;
}
void getRatings(int **reviews){
    int rating;
    string rating1;
    cout<<endl;
        for(int i=0;i<NUM_REVIEWERS;i++){
            cout << "ENTER RATING FOR TRANSACTION #: " << i+1 << endl<<endl;
            for( int j=0; j<NUM_PRODUCE; j++)
               {
                do{
                    cout<<"Enter rating for " << veg[j]<<" (1-terrible to 5-excellent, 0 -never ordered): ";
                    getline(cin,rating1);
                    rating = integerCheck(rating1);
                    if(rating<0||rating>5){
                        cout<<"\nRating must be between 0 and 5.\n";
                    }
                }while(rating<0||rating>5);
                reviews[i][j]=rating; //set rating
            }
        }
    cout<<endl<<endl;
    return;
}
void displayRatings(int **reviews){
    int i,j;
    cout<<endl<<"\t";
    for(i=0;i<NUM_PRODUCE;i++){
        cout << veg[i]<<" ";
    }
    for(i=0;i<NUM_REVIEWERS;i++){
        cout<<endl <<i+1<<'\t';
        for(j=0;j<NUM_PRODUCE;j++){
            cout<<reviews[i][j]<<"         ";
        }
}
    cout<<endl<<endl;
    return;
}

void showAverageRatings(int **reviews){
    cout<<"Product\tAverage Rating";
    for(int j=0;j<NUM_PRODUCE;j++){
        cout<<endl<<veg[j]<<'\t'<<getAverage(reviews,j);
    }
    cout<<endl<<endl;
    return;
}
double getAverage(int **reviews,int product){
    double sum=0;
    for(int i=0;i<NUM_REVIEWERS;i++){
        sum+=reviews[i][product];
    }
    return sum/(double)NUM_REVIEWERS;
}
// REQUIREMENT # 11:Demonstrates general functional decomposition
//I THIK in this program THIS IS THE BEST DEMONSTATION OF FUNCTION DECOMPOSTION
void orderSeeds(){
    cout<<"\nTry our new annual flower seeds.  \n";
    cout << "WE SELL THE FOLLOWING SEEDS:\n";
    cout << "     Item\t     price\n";
    listFlowerSeeds(menuSeeds,8);
    getFlowerOrder(menuSeeds,order,items);
    printCheck(order,items);
    //newLine();
    goToMenuFunction();
}
//displays list of flower seeds
//REQUIREMENT #23. Attempts to demonstrate a pointer to a struct (could be a bit tough),
void listFlowerSeeds(menuFlower flowers[],int n){
    menuFlower *pointers[n];
    for( int i=0;i<n;i++){
        pointers[i]=&flowers[i];
        cout<<i+1<<". "<<pointers[i]->flower<<"  $";
        cout<<pointers[i]->flowerPrice<<endl;
    }
}
//asks the user to enter the flowers order
void getFlowerOrder(menuFlower menu[],menuFlower order[],int& items){
    char yesno='Y';
    int item;
    while(toupper(yesno)=='Y'){
        cout<<"Enter your order item number: ";
        cin>>item;
        integerCheck(item);
        while(item<1||item>8){
            cout<<"Invalid item number\n";
            cout<<"Enter your order item number: ";
            cin>>item;
            integerCheck(item);
        }
        order[items].flower=menu[item-1].flower;
        order[items].flowerPrice=menu[item-1].flowerPrice;
        items++;
        cout <<"You've chosen: " << menu[item-1].flower << endl;
        cout<<"Would you like another item?(y/n)? ";
        cin>>yesno;

        }
   }
// displays order summary and check to the user
void printCheck(menuFlower order[],int items){
    double total=0,tax;
    cout<<"Here is the Check for the seeds\nYou have ordered the following flower seeds\n     Item\t     price\n";
    listFlowerSeeds(order,items);
    for(int i=0;i<items;i++){
         total+=order[i].flowerPrice;
    }
    cout<< "\nItem total     \t  " << "$";
    cout <<total<<endl;
    //REQUIREMENT #8: Demonstrates understanding of the LOGIC ERROR
    //IF I TRY TO CALCULATE TAX USING tax=total/.05; THIS WILL BE A LOGIC ERROR
    tax=total*.05;
    cout<<"Tax    \t\t  "<<"$";
    setprecision(2);
    cout <<tax<<endl;
    cout<<"Amount Due    \t  "<<"$";
    setprecision(2);
    cout<<total+tax<<endl;
}

void setprecision(int number){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(number);
}
// I GOT THIS FUNCTION FROM Terry Lauer
//MY ERROR CHECK FUNCTION HAD ONE PROBELM
//WHEN I TRIED TO ENTER 1 ;jkkhjggf (number, splace and some randome characters)
//IT WAS ACCEPTING IT AS A VALID ENTRY
int integerCheck (string INPUT)
{
	int isanint = 'n'; // is it an integer loop condition
	int x; // used in the loop
	int isok ; // used to test for integer
	int NUM; // the integer to be returned

// test to yes if it is an int
				isanint = 'n';

				while (isanint == 'n')
					{
						isok = 1;
						for (x=0; x < INPUT.length(); x=x+1)
							{
// check for digits
								if (((INPUT.at(x) >= '0' && INPUT.at(x) <= '9')))
									{
										isok = 1;
									}
								else
								 	{
// flag as bad and set exit
								 		isok = 0;
								 		x = INPUT.length();
								 	}
							}

/// if it did not pass the test for integer
				if ( isok == 0)
					{
						cout << " That was NOT an integer >0" << endl;
						cout << " Please enter an integer " ;
						getline(cin,INPUT);
						cout << endl;
					}
				else
					{
						NUM = atoi(INPUT.c_str());
						isanint = 'y';
						isok = 1;
					}
			}
 	return NUM;
}

void newLine()
{
   char symbol;
   do
   {
      cin.get(symbol);
   } while (symbol != '\n');
}
