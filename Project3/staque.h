/*//////////////////////////////////////////////////////////////////////////////////////////////
// Header file for class Staque, includes prototypes for all functions of class Staque, as well
// as operator overloading function for output operator.
//
// Functions included in class Staque:
// Default constructor, copy constructor, destructor, assignment operator overloading function,
// boolean function "empty", void functions "push", "pushEven", "pushOdd", "popEven", "popOdd",
// and "display", typedef StackElement function "top".
//
// Private members of class Staque:
// Typedef NodePointer variable "first", as well as class "Node"
//
// Public elements for class Node:
// Typedef StackElement variable "data", Pointer of type Node "next", explicit value constructor
///////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>  //include input/output stream library
using namespace std;

#ifndef STAQUE_H   //if Staque header has not been defined, define it
#define STAQUE_H

typedef int StackElement;  //Define every instance of StackElement as an int

class Staque
{
 public:  //public members of class Staque
    Staque();  //default constructor
    Staque(const Staque & original);  //copy constructor, with an object of type Staque as parameter
    ~Staque();   //destructor
    const Staque & operator= (const Staque & rightHand);  //assignment operator overloading function, object of type Staque as parameter
    bool empty() const;   //boolean function "empty"
    void push(const StackElement & value);  //void function "push" with object of type StackElement as parameter
    void pushEven(const StackElement & value);  //void function "pushEven" with object of type StackElement as parameter
    void pushOdd(const StackElement & value);  //void function "pushOdd" with object of type StackElement as parameter
    StackElement top() const;  //StackElement function "top"
    void popEven();  //void function "popEven"
    void popOdd();   //void function "popOdd"
    void display(ostream & out) const;   //display function to use in output operator overloading function
 private:   //private members of class Staque
    class Node   //definition of class Node, made accesible to class Staque
    {
     public: //Public members of class "Node"
        StackElement data;  //variable "data" of type StackElement
        Node *next;   //pointer variable of type Node "next"
        Node(StackElement value, Node * link = 0)  //explicit value constructor, sets data to parameter value, and next to NULL
            :data(value), next(link)
        {}
    };
    typedef Node* NodePointer; //define every instance of NodePointer as pointer variable of type Node
    NodePointer first; //NodePointer variable "first"
};

ostream & operator<<(ostream & out, Staque & s);  //output operator overloading function with ostream object and Staque object as parameters
#endif // STAQUE_H
