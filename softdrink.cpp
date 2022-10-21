// File Name: assign7_pmg45.cpp
//
// Author: Priscilla Garza
// Co-Author: Vivian Lopez, Nicole Beltran
// Date: 12/4/2017
// Assignment Number: 7
// CS 1428.006 Fall 2017
// Instructor: Jill Seaman
//
// The code outputs a simulation of a soft drink machine and lets the user input values in order to
// access the information about each drink.

#include <iostream>
#include <stdlib.h>
#include <iomanip>


using namespace std;


// This function definition contains the information of the soft drinks that are displayed for the user.
void drinkMenu(){

cout << "1. Coke (can)"<< endl;
cout << "2. Coke (bottle)"<< endl;
cout << "3. Mountain Dew (can)"<< endl;
cout << "4. Water"<< endl;
cout << "5. Full Throttle"<< endl;
cout << "6. Quit the Program"<< endl;
}

// This struct contains members that represent the soft drink name, cost and the total number of them.
struct drinkMachine
{
    string Name;
    double Cost;
    int numUnits;
};

// Function prototypes and parameters that allows an array to be accessed and information to be displayed later on.
void init(drinkMachine[]);
int menu(drinkMachine[]);
void payment(double);
int main()


//The array is initialized and contains the information for each soft drink. The
{
    const int ARRAY_SIZE =5;
    drinkMachine drink[ARRAY_SIZE]= {{"Coke (can)", 0.75,6}, {"Coke (bottle)", 1.25,6}, {"Mountain Dew (can)",  .75,  6},
    {"Water", 1.75,6},{"Full Throttle", 2.00,6}};
    int choice;
    int numUnits=0;
    double made=0;
    choice=menu(drink);
    while(choice!=6)
    {
        while (drink[choice].numUnits==0)
        {
            cout << "Soldout, choose another drink:"<<endl;
            choice=menu(drink);
        }
        if(choice == 6)
            break;
        payment(drink[choice].Cost);
        made+=drink[choice].Cost;
        drink[choice].numUnits--;
        choice=menu(drink);
        if(choice == 6)
            break;
    }

    cout<<"Amount Earned: $"<<setprecision(2)<<fixed<<made<<endl;
    system("process");
    return 0;
}

void payment(double p)
{
    cout<<"Your drink costs $"<<setprecision(2)<<fixed<<p<<endl;
}

int menu(drinkMachine d[])
{
    int choice,i;
    bool soldout;
    do
    {
        for(i=0;i<5;i++)
        {
            cout<<i+1<<". "<<d[i].Name;
            cout << endl;
        }
        cout << "6. Quit the Program" << endl ;
        cout<<"Enter Choice:";
        cin>>choice;
        cout << endl;
    }
    while((choice<1||choice>6));
    return choice-1;
}
