#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
struct menuItemType
{string menuItem;
double menuPrice;
};
void getdata( menuItemType[],menuItemType[],int&);
void showMenu( menuItemType[],int);
void printCheck(menuItemType[],int );
int main()
{
int items=0;
    menuItemType menuList[]={"plain egg",1.45,
                          "bacon and egg",2.45,
                          "muffin",0.99,
                          "french toast",1.99,
                          "fruit basket",2.49,
                          "cereal",0.69,
                          "coffee",0.50,
                          "tea",0.75
                          };
menuItemType order[10];
cout<<"Welcome to my Restaurant\nMy menu\n     Item\t     price\n";
showMenu(menuList,8);
getdata(menuList,order,items);
printCheck(order,items);
system("pause");
return 0;
}


void printCheck(menuItemType order[],int items)
{
    int i;
    double total=0,tax;
        cout<<"Your Check\nOrdered Items\n     Item\t     price\n";
        showMenu(order,items);
    for(i=0;i<items;i++)
         total+=order[i].menuPrice;
    cout<<"\nItem total    \t"<<"$"<<setprecision(2)<<fixed<<total<<endl;
    tax=total*.05;
    cout<<"Tax\t\t"<<"$"<<setprecision(2)<<fixed<<tax<<endl;
    cout<<"Amount Due    \t"<<"$"<<setprecision(2)<<fixed<<total+tax<<endl;
}


void getdata(menuItemType menu[],menuItemType order[],int& items)
{char yesno='Y';
int n;
while(toupper(yesno)=='Y')
{cout<<"Enter your order item number: ";
cin>>n;
while(n<1||n>8)
    {cout<<"invalid item number\n";
     cout<<"Enter your order item number: ";
     cin>>n;
     }
order[items].menuItem=menu[n-1].menuItem;
order[items].menuPrice=menu[n-1].menuPrice;
items++;
cout<<"Would you like another item?(y/n)? ";
cin>>yesno;
}
}
void showMenu(menuItemType a[],int n)
{int i;

    for(i=0;i<n;i++)
         cout<<i+1<<". "<<setw(16)<<left<<a[i].menuItem<<"$"<<setprecision(2)<<fixed<<a[i].menuPrice<<endl;
}
