#include <iostream>    //include library iostream
using namespace std;

#ifndef DATE_H  //run the following code if DATE_H has not been defined
#define DATE_H  //define DATE_H

/*///////////////////////////////////////////////////////////////////////////
Class Date has three private members, all of type unsigned.
The public members are: a default constructor, an explicit value constructor,
three accessor functions, a display function and a mutator function
///////////////////////////////////////////////////////////////////////////*/
class Date
{
    public:     //public members
        Date();  //default constructor

        Date(unsigned month, unsigned day, unsigned year);  //explicit value constructor with parameter of three unsigned ints

        unsigned getMonth(); //accessors
        unsigned getDay();
        unsigned getYear();

        void display(ostream & out); //display function with object of type ostream as parameter

        void set(unsigned month, unsigned day, unsigned year); //mutator function with three unsigned ints as parameters

    private:  //private members, all unsigned int
        unsigned myMonth,
                 myDay,
                 myYear;
};

ostream & operator<<(ostream & out, Date & d);   //operator overloading function, not a part of the class



#endif // DATE_H
