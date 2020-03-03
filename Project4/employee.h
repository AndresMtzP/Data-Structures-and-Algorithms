/*//////////////////////////////////////////////////////////////////////////////////////
// Parent class Employee header includes the prototype and declarations of the class'
// data members. The class includes an explicit value constructor, accesors getFirst,
// getLast, getID, and getType. Mutators, setName, setID, and setType. A virtual function
// calculateSalary of type double, a virtual void display function, and a void displayPtr
// function. The private data members are two strings, myFirstName and myLastName, an int
// myID, and a char myType. Class employee also has two operator overloading function,
// one takes an object of type Employee as parameter, the other takes a pointer to an
/ Employee as parameter
//////////////////////////////////////////////////////////////////////////////////////*/
#include <string>   //include library for string
#include <iostream>  //include library for input/output stream
using namespace std;

#ifndef EMPLOYEE_H  //if not defined, define it
#define EMPLOYEE_H


class Employee
{
    //Public data members
    public:
        //explicit value constructor
        Employee(string firstName="", string lastName="", int id=0, char type=' ');
        string getLast(){return myLastName;}; //get Last accesor
        string getFirst(){return myFirstName;};  // getFirst accesor
        int getID(){return myID;};   // getID acceasor
        char getType(){return myType;};  // getType accessor
        void setName(string firstName, string lastName);  //setName mutator
        void setID(int id);   // setID mutator
        void setType(char type);  //setType mutator
        virtual double calculateSalary(double nothing) {return 0;};  //virtual function calculate salary
        virtual void display(ostream & out) const;   //virtual display function
        void displayPtr(ostream & out) const;  //void display function
    //private data members
    private:
        string myFirstName,
               myLastName;
        int myID;
        char myType;
};

ostream & operator<<(ostream & o, Employee & e);  //operator overloading function


//default constructor takes two strings, an int and a char as parameters
inline Employee::Employee(string firstName, string lastName, int id, char type)
    :myFirstName(firstName), myLastName(lastName), myType(type)
{
    //check if ID is between 1 and 5 digits long, if not, set the ID to zero
    if(id>0 && id<100000){
        myID=id;
    }else{
        cout<<setw(70)<<"////////////////////////////////////////////////////////////////"<<endl;
        cout<<setw(70)<<"//        ***ID has to be between 1 and 5 digits long***      //"<<endl;
        cout<<setw(70)<<"//                     Setting ID to 0                        //"<<endl;
        myID=0;
    }
}

inline void Employee::setName(string firstName, string lastName)
{
    myFirstName=firstName;  //set first name
    myLastName=lastName;   //set last name
}

inline void Employee::setID(int id)
{
    myID=id;  //setID
}

inline void Employee::setType(char type)
{
    myType=type;  //setType
}

//virtual display function of type void
inline void Employee::display(ostream & out) const
{
    int nameLength=myFirstName.length()+myLastName.length()+1;  //calculate length of first name and last name
    //do the following algorithm to display the information in an organized way, following the graphic interface
    out<<myFirstName<<" "<<myLastName;
    for(int i=0; i<25-nameLength; i++)
    {
        out<<" ";
    }
    int IDLength,
        c=myID;
    for(IDLength=0; c!=0; IDLength++)  //for loop to calculate the length of ID
    {
        c=c/10;
    }
    out<<"  ID#: "<<myID;
    for(int i=0; i<8-IDLength; i++)
    {
        out<<" ";
    }
    out<<"      Type: "<<myType<<"      //"<<endl;
}

//function displayPtr follows the same algorithm as display
inline void Employee::displayPtr(ostream & out) const
{
    int nameLength=myFirstName.length()+myLastName.length()+1;

    out<<myFirstName<<" "<<myLastName;
    for(int i=0; i<25-nameLength; i++)
    {
        out<<" ";
    }
    int IDLength,
        c=myID;
    if(myID<10)
    {
        IDLength=1;
    }else{
        for(IDLength=0; c!=0; IDLength++)
        {
            c=c/10;
        }
    }
    out<<"     "<<myID;
    for(int i=0; i<8-IDLength; i++)
    {
        out<<" ";
    }
    out<<"           "<<myType<<"      //"<<endl;
}

//operator overloading fnction for object of type employee
ostream & operator<<(ostream & o, Employee & e)
{
    e.display(o);  //call function display on object e, with ostream object as parameter
    return o;  //return ostream object
}

//operator overloading function for pointer to Employee
ostream & operator<<(ostream & o, Employee* e)
{
    e->displayPtr(o);  //call function diplayPtr on pointer e with ostream object as parameter
    return o;    //return ostream object
}


#endif // EMPLOYEE_H
