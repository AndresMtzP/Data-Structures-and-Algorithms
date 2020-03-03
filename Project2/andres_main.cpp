/*///////////////////////////////////////////////////////////////////////////////////
//Project 2//////////////////////////////////////////////////////////////////////////
//COMPE 260//////////////////////////////////////////////////////////////////////////
//Date Program/////////////////////////////////////////////////////////////////
//This program creates and displays a default date, showing the month, the day,
//and the year, respectively, as 01-01-2000. After that, the program displays a menu
//for the user to select between entering a new date, changing the current date, or
//quitting the program. If the User wants to set a new date, the program calls the mutator
//function "set" on the Date object with unsigned int parameters for the month, day, and year
//Every time the menu is displayed, the current date is also displayed.
//Programmer: Andres Martinez Paz
//RedID: 819505668
///////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <iomanip>       //Include all the necessary libraries
#include "date.h"        //Include header "date.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

/*///////////////////////////////////////////////////////////////
Function "display1" outputs the header of the graphical interface
///////////////////////////////////////////////////////////////*/
void display1()
{
    cout <<setw(60)<< "/////////////////////////////////////////////"<<endl;
    cout <<setw(60)<< "//Date Program///////////////////////////////"<<endl;
}

/*/////////////////////////////////////////////////////////////////
Function "displayMenu" outputs the body of the graphical interface
where the user is prompted to choose a numerical option from a menu
/////////////////////////////////////////////////////////////////*/
void displayMenu(Date d)
{
    cout <<setw(60)<<"//                                         //"<<endl;
    cout <<setw(32)<<"// Current date: "<<d<<"                //"<<endl;
    cout <<setw(60)<<"//                                         //"<<endl;
    cout <<setw(60)<<"// Select an option:                       //"<<endl;
    cout <<setw(60)<<"// 1) Enter new date                       //"<<endl;
    cout <<setw(60)<<"// 2) Modify current date                  //"<<endl;
    cout <<setw(60)<<"// 3) Quit the program                     //"<<endl;
    cout <<setw(60)<<"//                                         //"<<endl;
    cout <<setw(18)<<"// ";
}

/*///////////////////////////////////////////////////////////////
Function "incrementMonth" performs an extensive operation to
increase the current date by an n number of 31 day months
///////////////////////////////////////////////////////////////*/
void incrementMonth(Date &d, int n)
{
    int mon=d.getMonth();      //Use accessors to store the current month, day, and year
    int days=d.getDay();       //into variables that will be modified
    int years=d.getYear();

    for(int i=0; i<n; i++)     //Use "for" loop to run the algorithm as many times
    {                          //as the months that the user wants to increase the date
        if(mon==1 || mon==3 || mon==5    //First "if" statement checks if the month is any month with 31 days
            || mon==7 || mon==8 || mon==10 || mon==12)
        {
            if(mon==12)      //First nested "if" statement checks if the month is particularly December
            {
                mon=1;     //if the month is December, set the new month to January and increase the year by one
                years++;
            }else if((mon==1 && days>=29) || (days==31 && mon!=7) )    //"Else if" checks if the month is Jan and
            {                                                          //the day is between 29 and 31 or if the month
                                                                       //is anything but July and the day is 31
                if(mon==1 && days==29 && !((years%400==0        //Another nested "if" checks if the month is Jan, and
                  || years%100!=0) &&(years%4==0)))             //the day is 29, and if the year is not a leap year
                {
                    mon=3;       //If all these conditions are met, change the month to march and the day to 1;
                    days=1;
                }else if(mon==1 && days==30)  //nested "else if" checks if the month is Jan and the day is 30th
                {
                    if((years%400==0          //nested "if" then checks if it is a leap year
                        || years%100!=0) &&(years%4==0))
                    {
                        mon=3;  //if the month is Jan, the day is the 30th, and it is a leap year, change month to march
                        days=1;  //and the day to the 1st
                    }else{
                        mon=3;  //if the month is Jan, the day is the 30th, but it is not a leap year, change month to march
                        days=2; //and change the day to the 2nd
                    }
                }else if(mon==1 && days==31)  //nested "else if" checks if the month is Jan and the day is 31st
                {
                    if((years%400==0           //nested "if" then checks if it is a leap year
                        || years%100!=0) &&(years%4==0))
                        {
                            mon=3;   //if the month is Jan, the day is the 31st, and it is a leap year,
                            days=2;      //change month to march and change day to 2nd
                        }else{
                            mon=3;  //if the month is Jan, the day is the 31st, but it is not a leap year,
                            days=3;     // change month to march and day to 3rd
                        }
                }
                if(days==31 && mon!=7) //"if" checks if the month is not July and if the day is the 31st
                {
                    mon=mon+2;  //if conditions are met, increase the month by two, and set the day to 1st
                    days=1;
                }
            }else{    //finally, if the month has 31 days, but none of the other conditions are true,
                mon++; //increase the month by one and keep the day as the same
            }

        }else if(mon==4 || mon==6     //"Else if" checks if the month is instead one of the 30 day months,
                || mon==9 || mon==11)
        {
            mon++;   //if it is, increase both the month and the day by one
            days++;
        }else if(mon==2 && !((years%400==0      //"Else if checks if month is February and it is not a leap year"
                || years%100!=0) &&(years%4==0)))
        {
            mon++;         //If these are true, increase month by one and increase day by 3;
            days=days+3;
        }else{            //Final "else" only runs if the month is February and the year is a leap year
            mon++;        //if this is the case, increase month by one and increase the day by 2
            days=days+2;
        }

    }
    d.set(mon, days, years);  //call set function on Date object "d" with new month, day, and year as parameters
}

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////
"main" function implements the class date and the display functions, as well as storing and managing user input
/////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
int main()
{
    bool runagain = true;    //bool variable "runagain" declared and set to true. this is used to keep the program running
    while (runagain)         //as long as the user wants
    {
        string again;   //Declare all the variables to be used, including strings and inputs for inputs
        int inMonth;    // and booleans for error checking
        int inDay;
        int inYear;
        int choice;
        int increase;
        int smonth,
            sday,
            syear;
        bool correctInc = false;
        string  m,
                d,
                y;
        bool menu = true;
        bool correctChoice = false;

        display1();    //call function "display1"
        Date myDate;   //declare new object of type Date, runs default constructor

        while(menu)   //"While" with bool "menu" loop to keep running the menu, until user inputs 3 to quit"
        {
            inMonth=0;  //set variables to 0 in order to manipulate them further ahead
            inDay=0;
            inYear=0;


            displayMenu(myDate); //call function displayMenu with the newly created Date object as a parameter
            do   //"do while" loop used to keep asking the user to prompt a choice, if they enter incorrect input
            {
                choice=0;
                cin>>choice;   //store users input into int variable "choice"
                if(!(choice==1 || choice == 2 || choice == 3))  //if input is anything but one of these three numbers,
                {                                              //output an error message and ask user to input again
                    cerr <<setw(60) << "//       ******Invalid Input*******        //"<<endl;
                    cerr <<setw(60) << "// Please enter an appropriate choice:     //"<<endl;
                    cout <<setw(19) << "//  ";
                    cin.clear();       //clear cin and ignore the next line of input, this is to ignore the remaining
                    cin.ignore(100, '\n');  // input, in case the it is still stored in the input buffer
                }else  //if choice is an acceptable one, change bool "correctChoice" to true in order to exit the loop
                    correctChoice=true;
            }while(!correctChoice);  //run while correctChoice is false
            correctChoice=false;  //after exiting the loop, change correctChoice back to false, for the next time we run the menu

            switch(choice)  //"switch statement with int "choice"
            {
                case 1:  //if user entered choice 1, run the following:
                    cin.clear();
                    cin.ignore(100, '\n');   //prompt user to input the new month
                    cout <<setw(60)<< "// Enter month(mm):                        //"<<endl;
                    cout <<setw(19)<< "//  ";
                    cin>>smonth;    //store input in int "smonth"
                    cin.clear();    //clear cin and ignore next line, in case the user enters a correct input, with a trailing error
                    cin.ignore(100, '\n');  //prompt user to enter new day
                    cout <<setw(60)<< "//                                         //"<<endl;
                    cout <<setw(60)<< "// Enter day(dd):                          //"<<endl;
                    cout <<setw(19)<< "//  ";
                    cin >> sday;  //store input in int "sday"
                    cin.clear();
                    cin.ignore(100, '\n');  //prompt user to enter new year
                    cout <<setw(60)<< "//                                         //"<<endl;
                    cout <<setw(60)<< "// Enter year(yyyy):                       //"<<endl;
                    cout <<setw(19)<< "//  ";
                    cin >> syear;   //store input in int "syear"
                    cin.clear();
                    cin.ignore(100, '\n');

                    myDate.set(smonth, sday, syear);  //call function set on Date object "myDate" with
                    break;                            //smonth, sday, and syear as parameters
                case 2:       //if users chooses option 2, run the following
                            //prompt user to input the number of months that they want to increase
                    cout <<setw(60)<<"// By how many months(31 days) would       //"<<endl;
                    cout <<setw(60)<<"// you like to increase the date?          //"<<endl;
                    cout <<setw(19)<<"//  ";

                    do  //"do while" loop to keep asking user for a correct input
                    {
                        if(!(cin>>increase) || increase<0)  //if input is not acceptable, show error message
                        {
                            cerr<<setw(60)<<"//            ***Invalid Input***          //"<<endl;
                            cerr<<setw(60)<<"// Enter number of months to increase:     //"<<endl;
                            cout <<setw(19)<<"//  ";
                            cin.clear();
                            cin.ignore(100, '\n');
                        }else{
                            correctInc=true;   //if input is correct, change correctInc to true to stop running loop
                        }

                    }while(!correctInc);  //keep running if bool "correctInc" is false
                    correctInc=false;     //after loop, set correctInc back to false to run loop next time
                    incrementMonth(myDate, increase);  //call function "incrementMonth" with Date object myDate and user's input as parameter
                    break;  //break switch statements
                case 3:  //if user chooses option 3, change menu to false, to stop menu loop from running
                    menu = false;
                    break;  //break switch statement
            }

        }

        cin.clear();  //clear cin and ignore next line to prevent any unwanted content in buffer to disrupt the program
        cin.ignore(100, '\n');
        cout <<setw(60)<< "//  Do you wish to run Date Program again? //"<<endl;   //asks user if they want to run the program again
        cout <<setw(24)<< "// (Y/N) " ;
        cin >> again;  //store input in string variable "again"

        /*Error checking for repetition*/
        //if input was incorrect, run the following loop
        while(!(toupper(again.at(0)) == 'Y' || toupper(again.at(0)) == 'N') || again.length()!=1){
             cerr << setw(60) << "//    ***Not an acceptable input***        //" << endl; //output error message
             cout << setw(60) << "// Do you wish to run Date Program again?  //" << endl;
             cout << setw(24) << "// (Y/N) ";  //prompt user to enter input again
             cin.clear();
             cin.ignore(100, '\n');
             cin >> again;  //store input in string variable "again" again
        }

        if(toupper(again.at(0)) == 'N'){   //If statement to read users input
            runagain = false;            //if the user inputs no, runagain becomes false, and therefore breaks the main while loop
        }
    }
    /*///////////////////////////////////////////////////////////////////////////////
    if user wants to quit the program, display the foot of the graphical interface, and
    display the name of the programmer, who happens to be a super chill guy
    ///////////////////////////////////////////////////////////////////////////////*/
    cout<<setw(60)<<"//                                         //"<<endl;
    cout<<setw(60)<<"// Programmer: Andres Martinez Paz //////////"<<endl;
    cout<<setw(60)<<"/////////////////////////////////////////////"<<endl;
    cout<<setw(60)<<"/////////////////////////////////////////////"<<endl;
    return 0;
}
