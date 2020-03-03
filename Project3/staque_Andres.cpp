/*//////////////////////////////////////////////////////////////////////////////////////
// Class Staque is a combination between a stack and a queue. If the number to be pushed
// is even, the staque acts like a stack and pushes the number to the front of the staque.
// If the number to be push is odd, the staque behaves as a queue and pushes the number
// to the end of the Staque. In the implementation of the class Staque, the user is asked
// if they want to delete an even number or an odd number, the staque follows the LIFO
// following the same instructions from below.
//////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>   //Include input/output stream library
#include <stdio.h>    //Include Std input/output manipulation library
#include <stdlib.h>   //Include std general library
#include <iomanip>    //Include Input/output manipulation library
#include "staque.h"   //Include header of class Staque

Staque::Staque()   //Default constructor, sets NodePointer variable "first" to NULL
    : first(NULL)
{}

/*/////////////////////////////////////////////////////////////////////////////////////////////
// Copy Constructor. Not implemented in main function, however, it is fully functional and
// serves to copy Objects of type Staque into another object of type Staque
/////////////////////////////////////////////////////////////////////////////////////////////*/
Staque::Staque(const Staque & original)  //takes object of type Staque as parameter
{
    first = 0;   //set NodePointer "first" to Null
    if(!(original.empty())) //check if parameter staque is empty
    {
        first = new Staque::Node(original.top());   //set "first" to point to a new object of type Node, with the top data of parameter original
        Staque::NodePointer lastptr = first,   //declare new pointer variables of type NodePointer, set "lastptr" to first
                            origptr = original.first->next;   //set "origptr" to point to the same Node as the next pointer which original's first points to

        while (origptr!=0)   //while loop checks if "origptr" is pointing to NULL, which means it's the end of the Staque
        {
            lastptr->next = new Staque::Node(origptr->data); //set lastptr's next to a new Node with origptr's data as parameter
            lastptr=lastptr->next; //keep cycling through the Staque until program reaches the last pointer
            origptr=origptr->next;
        }
    }
}

/*///////////////////////////////////////////////////////
// Destructor
///////////////////////////////////////////////////////*/
Staque::~Staque()
{
    Staque::NodePointer currptr=first, //declare new NodePointers currptr and nextptr, set currptr to first
                        nextptr;

    while (currptr!=0) //while loop to check if currptr points to NULL, which means it is the end of the Staque
    {
        nextptr = currptr->next;  //set "nextptr" to currptr's next
        delete currptr;     //delete whatever currptr is pointing to, freeing the memory previously allocated
        currptr = nextptr;  //set currptr to next ptr
        //This loop keeps deleting the Nodes in the Staque, starting with the last one
    }
}

/*/////////////////////////////////////////////////////////////////////////////////
// Assignment operator overloading function
/////////////////////////////////////////////////////////////////////////////////*/
const Staque & Staque::operator=(const Staque & rightHand) //takes an object of type Staque as parameter
{
    if(this != &rightHand)  //check if both objects on each side of the assignment operator are the same
    {
        this->~Staque();  //call destructor on left hand side object, which deletes all of its nodes
        if(rightHand.empty()) //check if object on right hand side of operator is empty
        {
            first=0; //set lefthandside's first point to NULL if Righthandside is empty
        }else{
            first=new Staque::Node(rightHand.top());  //set lefthandside's first point to a new Node with Righthandside's first node's data as parameter
            Staque::NodePointer lastptr=first,  //declare new NodePointers "lastptr" and "rightHandptr", set lastptr to first
                                rightHandptr= rightHand.first->next; //set rightHandptr to righthand's first node's next

            while(rightHandptr!=0)  //while loop to keep cycling through staque
            {
                //keep creating new nodes with their respective values as parameters for as many times as there are righthand's nodes
                lastptr->next= new Staque::Node(rightHandptr->data);
                lastptr=lastptr->next;
                rightHandptr=rightHandptr->next;
            }
        }
    }
    return *this; //return the object which "this" points to, which is the lefthandside object
}

/*//////////////////////////////////////////////////////////////////////
// Function "empty()" returns true if Staque is empty, false if it isn't
//////////////////////////////////////////////////////////////////////*/
bool Staque::empty() const
{
    return (first==0);  //return true if first points to NULL, false if points to anything
}

/*//////////////////////////////////////////////////////////////////////////////
// Function "push" takes a StackElement object as parameter and checks if it's
// even or odd, if it is even, call function pushEven, else call pushOdd
//////////////////////////////////////////////////////////////////////////////*/
void Staque::push(const StackElement & value)
{
    if(value%2==0)  //checks if variable Value is an even number
        pushEven(value); //call "pushEven" if value is even
    else
        pushOdd(value); //else call "pushOdd"
}

/*////////////////////////////////////////////////////////////////////////
// Function pushEven pushes StackElement parameter to the front of Staque
////////////////////////////////////////////////////////////////////////*/
void Staque::pushEven(const StackElement & value)
{
    first = new Staque::Node(value, first); //set first to a new Node object, constructor with value and previous first as parameters
}

/*///////////////////////////////////////////////////////////////////////
// Function pushOdd pushes StackElement parameter to the back of Staque
///////////////////////////////////////////////////////////////////////*/
void Staque::pushOdd(const StackElement & value)
{
    if(empty()) //check if Staque is empty
        first = new Staque::Node(value);  //if it is, push the parameter to the front of the staque
    else{
        Staque::NodePointer newptr=new Staque::Node(value), //declare new NodePointers newptr and lastptr and set them
                            lastptr=first;    //to their respective values
        while(lastptr->next!=0) //while loop to cycle through the Staque in order to get to the end of the Staque
        {
                lastptr=lastptr->next; //keep setting lastptr to lastptr's next, until you reach the end of Staque
        }
        lastptr->next=newptr; //once we reach the end, point lastptr's next to the new Node created
    }
}

/*//////////////////////////////////////////////////////////////////////////
// Function top() returns the StackElement stored in the first node's data
//////////////////////////////////////////////////////////////////////////*/
StackElement Staque::top() const
{
    if(!empty())  //check if staque is empty
        return first->data;  //if it isn't, return first Node's data
    else{
        cerr<<setw(70)<< "//               ****Staque is empty****                //" <<endl;  //if it's empty, display error message
        cerr<<setw(70)<< "//                **Returning Garbage**                 //" << endl;
        StackElement *temp=new(StackElement);  //declare new StackElement pointer object and allocate memory to it
        StackElement garbage = *temp;   //declare StackElement object and set it to the previous StackElement object created
        delete temp;   //delete the StackElement object which temp was pointing to
        return garbage;   //return StackElement "garbage"
    }
}

/*////////////////////////////////////////////////////////////////////////////////////
// Function popEven pops a Node from the front of the Staque
////////////////////////////////////////////////////////////////////////////////////*/
void Staque::popEven()
{
    if(!empty())  //check if Staque is empty
    {
        if((first->data)%2 != 0) //check if the Node at the front of the Staque holds an even number
        {
            cout<<setw(70) << "//          ***No more even numbers remain***            //" <<endl; //if it isn't even, output error message
        }else{
            Staque::NodePointer ptr = first;  //Declare new NodePointer variable and set it to first
            first = first->next;   //set first to first's next
            delete ptr; //delete whatever ptr points to
        }
    }else  //if it is empty, output error message
        cout<<setw(70) << "//   ***Staque is empty, there is nothing to delete***   //" <<endl;
}

/*////////////////////////////////////////////////////////////////////////////////////
// Function popOdd pops a Node from the back of the Staque
////////////////////////////////////////////////////////////////////////////////////*/
void Staque::popOdd()
{
    if(!empty())  //check if Staque is empty
    {
        if(first->next!=NULL)  //check if there is only one Node in the Staque
        {
            Staque::NodePointer ptr = first,  //declare NodePointers ptr and ptrLast, set both to first
                                ptrLast = first;
            while(ptr->next!=0) //while loop to cycle through Staque, so ptr points to last Node
            {
                ptr = ptr->next; //Keep setting ptr to ptr's next, until end of Staque
            }

            while(ptrLast->next!=ptr) //while loop to cycle through Staque, so ptrLast points to second to last Node
            {
                ptrLast=ptrLast->next; //keep setting ptrLast to ptrLast's next until ptrLast's next points to ptr
            }

            if((ptr->data)%2!=0)  //check if the last Node holds an odd number
            {
                ptrLast->next=0;  //set ptrLast's next to Null, making it the last Node of Staque
                delete ptr;  //delete the last Node which is being pointed at by ptr
            }else    //if the number is even, output error message
                cerr<<setw(70)<<"//            ***No more odd numbers remain***           //"<<endl;
        }else{   //if there is only one Node in Staque
            if((first->data)%2 != 0)  //check if the Node holds an odd number
            {
                Staque::NodePointer ptr = first;  //declare new Nodeptr and set it to first
                first=first->next;    //set first to first's next, which points to NULL
                delete ptr;     //delete the Node, which is being pointed at by ptr
            }else   //if number is even, output error message
                cerr<<setw(70)<<"//            ***No more odd numbers remain***           //"<<endl;
        }
    }else   //if Staque is empty, output error message
        cerr <<setw(70)<< "//   ***Staque is empty, there is nothing to delete***   //" << endl;
}

/*///////////////////////////////////////////////////////////////////////////
// Function display takes ostream object as parameters, tells program how to
// display the Staque in order to keep the graphic interface intact
///////////////////////////////////////////////////////////////////////////*/
void Staque::display(ostream & out) const
{
    if(empty()) //check if Staque is empty, if it is diplay the following:
    {
        out << "Staque is empty                                       //"<< endl;
    }else{          //if Staque is not empty
        Staque::NodePointer ptr; //declare new NodePointer ptr
        int size,    //declare new int size and nextsize, size holds the length of the Staque, nextsize holds the lebgth of each element in the staque
            nextsize=0; //set nextsize to zero
        for(ptr=first, size=0; ptr!=0; ptr = ptr->next )  //for loop to calculate the length of Staque by cycling through Staque
        {

            int i=ptr->data; //set int i to the data in each node
            if(i<0){    //check if int i is negative
               i=-i;    //change i back to positive
               nextsize++;   //increase the length of the element by one, which is the negative sign "-"
            }
            while(i>=1)  //while loop to keep counting the number of digits in each element
            {
                i=i/10;    //keep dividing 'i' by ten, until 'i' is less than or equal to 1
                nextsize++;  //increment nextsize by 1 every time
            }
            nextsize++;  //increment nextsize by one to take into account the space between numbers
            if(nextsize>54-size)   //if the size of the element is greater than 54(width of frame) minus the length of
            {                      //the current length of the Staque, then wrap around the frame, to start in the next line
                for(int i=0; i<54-size; i++)  //for loop to output the correct number of spaces to wrap around the frame
                {
                    out <<" ";
                }
                out << "//" <<endl;   //after displaying the corresponding spaces, display the right hand side of the frame and endline
                out <<setw(14)<< "// " << ptr->data << " ";  //display the left hand side of the frame to keep displaying the numbers
                size=nextsize; //set the new current size to the size of the element about to be displayed
            }else{    //if the next element fits in the frame,
                out << ptr->data << " ";   //display the number followed by a space
                size=size+nextsize;    //set the new size to the last size plus the size of the element displayed
            }
            nextsize=0;  //before analyzing the next element, set nextsize to zero again
        }
        for(int w=0; w<54-size; w++)  //for loop to display the rest of the frame after the last element has been displayed
        {
            out << " ";   //display the necessary number of spaces
        }
        out << "//" <<endl;  //display the right hand side of the frame and end line
        }
}

/*////////////////////////////////////////////////////////////////////////////////////////////
// Output operator overloading function takes objects of type ostream and Staque as parameters
////////////////////////////////////////////////////////////////////////////////////////////*/
ostream & operator<<(ostream & o, Staque & s)
{
    s.display(o);  //call function display on Staque parameter 's', with ostream parameter as parameter
    return o;  //return ostream parameter
}
