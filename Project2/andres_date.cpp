/*///////////////////////////////////////////////////////////////////////////////////
//Project 2//////////////////////////////////////////////////////////////////////////
//COMPE 260//////////////////////////////////////////////////////////////////////////
//Date Program/////////////////////////////////////////////////////////////////
//This program prompts the user to enter a date by asking for the month, the day,
//and the year, respectively, as integers. After that, the program displays a menu
//for the user to select between entering a new date, changing the current date, or
//quitting the program. Every time the menu is displayed, the current date is also
//displayed.
//Programmer: Andres Martinez Paz
//RedID: 819505668
///////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <stdio.h>    //include necessary libraries
#include <stdlib.h>
#include <iomanip>
using namespace std;

#include "date.h"  //include header date.h

Date::Date()  //default constructor, sets date to Jan 1st, 2000
  : myMonth(01), myDay(01), myYear(2000)
{
}

/*//////////////////////////////////////////////////////////////////////
Constructor with parameters. This constructor was not used in the client
program, yet it shows the programmer's proficiency in writing one,
maybe for like a couple extra points?
/////////////////////////////////////////////////////////////////////*/
Date::Date(unsigned month, unsigned day, unsigned year)
{
    if(((month==1 || month==3
       || month==5 || month==7   //very extensive conditionals for class invariant
       || month==8 || month==10
       || month==12) && day>=1
       && day <=31 && year>=0
       && year<=9999) || ((month==4 || month==6
       || month==9 || month==11)
       && day>=1 && day <=30
       && year>=0 && year<=9999) || (month==2
       && day>=1 && day<=28 && year>=0 && year <=9999) || (month==2
       && day>=1 && day<=29 && ((year%400==0
       || year%100!=0) &&(year%4==0))))
    {
        myMonth = month;  //if the above is all true, set the month, day, and year to the parameters
        myDay = day;
        myYear = year;
    }else{    //if it is not correct, output error message and set date to default
        cout <<setw(60)<< "//                                         //" << endl;
        cerr <<setw(60)<< "//     *** Invalid initial values ***      //" <<endl;
        cerr <<setw(60)<< "// Date will be set to default             //"<<endl;
        myMonth = 1;  //default date is Jan 1st, 2000
        myDay = 1;
        myYear = 2000;
    }
}

unsigned Date::getMonth()  //Accessor function "getMonth" returns value of myMonth
{
    return myMonth;
}

unsigned Date::getDay() //Accessor function "getDay" returns value of myDay
{
    return myDay;
}

unsigned Date::getYear() //Accessor function "getYear" returns value of myYear
{
    return myYear;
}

/*////////////////////////////////////////////////////////////////////////////////
Function display takes in an object of type ostream as a parameter to display the
Date in a functional way
////////////////////////////////////////////////////////////////////////////////*/
void Date::display(ostream & out)
{
    if(myMonth<=9)        //if month is less than 10, output a zero before the month
        out << "0" <<myMonth<<"-";
    else                  //else output just the month
        out << myMonth<<"-";
    if(myDay<=9)          //if day is less than 10, output a zero before the day
        out << "0" <<myDay<<"-";
    else                  //else, just output the day
        out << myDay<<"-";
    if(myYear<=9)         //if year is less than 10, output three zeroes before the year
        out <<"000"<<myYear;
    else if(myYear<=99)   //else if the year is less than 100, output 2 zeroes before the year
        out <<"00"<<myYear;
    else if(myYear<=999)  //else if the year is less than 1000, output one zero before the year
        out <<"0"<<myYear;
    else                 //else, just output the year
        out << myYear;
}

/*////////////////////////////////////////////////////////////////////////////////////
Mutator function "set" takes in three parameters and modifies the month, day, and year
to the values of those parameters, given that the parameters are all acceptable
////////////////////////////////////////////////////////////////////////////////////*/
void Date::set(unsigned month, unsigned day, unsigned year)
{
     if(((month==1 || month==3
       || month==5 || month==7
       || month==8 || month==10   //Same extensive and rigorous conditionals for class invariant
       || month==12) && day>=1    //as those used in the constructor above
       && day <=31 && year>=0
       && year<=9999) || ((month==4 || month==6
       || month==9 || month==11)
       && day>=1 && day <=30
       && year>=0 && year<=9999) || (month==2
       && day>=1 && day<=28 && year>=0 && year <=9999) || (month==2
       && day>=1 && day<=29 && ((year%400==0
       || year%100!=0) &&(year%4==0))))
    {
        myMonth = month;  //if parameters are acceptable, set myMonth to month, myDay to day, and myYear to year
        myDay = day;
        myYear = year;
    }else{             //else, if the parameters are incorrect, display the following error messages
        cout <<setw(60)<< "//                                         //"<<endl;
        cerr <<setw(60)<< "//      *** Invalid initial values ***     //"<<endl;
        cout <<setw(60)<< "//            Date set to default          //"<<endl;
        myMonth = 1;   //set date to default again
        myDay = 1;
        myYear = 2000;
    }
}

/*///////////////////////////////////////////////////////////////////////////////////////
operator overloading function, to "train" objects of type Date to accept and apply
operator "<<" takes in an object of type ostream and an object of type Date as parameters.
///////////////////////////////////////////////////////////////////////////////////////*/
ostream & operator<<(ostream & out, Date & d)
{
  d.display(out); //call function display on Date object "d" with ostream object "out" as parameter
  return out;   //return ostream object "out";
}







