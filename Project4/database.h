/*/////////////////////////////////////////////////////////////////////////////////////
// Class Database is a linked list on which the nodes have pointers to an object of
// employee, an object of type monthRecords, which is another linked list, and an int
// order, to keep the nodes organized. Class Database also has a counter variable of
// type int to keep giving nodes the correct value for their order variable.
// The list includes a default constructor, a destructor, a bool function empty to
// check if the list is empty, a push function to add new elements to the list
// a pop function to delete elements from the list, a get counter accessor, an increase
// counter and decrease counter functions to modify the value of the counter from
// outside the class, two bool functions searchListbyLast and searchlistbyID, which return
// true if they find a match within the list, as well as displaying those matches, a
// function searchListbyOrder which return a pointer to a MonthRecords list if it finds
// a match, and a display function to display the contents of the list in an organized
// manner.
/////////////////////////////////////////////////////////////////////////////////////*/
#include "monthrecords.h"   //include MonthRecords header
using namespace std;

#ifndef DATABASE_H
#define DATABASE_H

typedef Employee* ListElement;   //type define every instance of ListElement as a pointer to an employee
typedef MonthRecords* recordsPtr;  //type define every instance of recordsptr as a pointer to MonthRecords

class Database
{
    public:
        Database();  //constructor
        ~Database();  //destructor
        bool empty() const;   //bool to check if empty
        void push(const ListElement & newEmploy);  //push function to add new elements
        void pop(int p);    //pop function to delete elements from the list
        int getCounter(){return counter;};   //accessor getCounter
        void increaseCount();    //modify the count
        void decreaseCount();
        bool searchListbyLast(string last);   //search list and return a boolean
        bool searchListbyID(int id);
        recordsPtr searchListbyOrder(int o);   //search list and return a pointer to MonthRecords
        void display(ostream & out) const;   //display function
    private:
        class Node   //declaration of class Node in private section of Database
        {
            public:
                ListElement employ;   //pointer to employee
                Node* next;          //pointer to Node
                recordsPtr records;   //pointer to monthRecords
                int order;            // int order
                Node(ListElement employee, Node* n, int o)  //explicit value constructor
                    :employ(employee), next(n), records(new MonthRecords(employee, o)), order(o)
                {
                }
                int getOrder(){return order;}   //accesor to getOrder
                void setOrder(int o){order=o;}  //mutator to setOrder
        };
        typedef Database::Node* nodeptr;  //type def every instance of nodeptr as a pointer to a Node
        nodeptr first;   //pointer to a node, first
        int counter;     //int counter
};

//default constructor, set first to Null and Counter to 0
inline Database::Database()
    :first(NULL), counter(0)
{
}

//destructor, goes through the list, deleting every pointer
inline Database::~Database()
{
    Database::nodeptr currptr=first, //declare new NodePointers currptr and nextptr, set currptr to first
                        nextptr;

    while (currptr!=0) //while loop to check if currptr points to NULL, which means it is the end of the list
    {
        nextptr = currptr->next;  //set "nextptr" to currptr's next
        delete currptr;     //delete whatever currptr is pointing to, freeing the memory previously allocated
        currptr = nextptr;  //set currptr to next ptr
        //This loop keeps deleting the Nodes in the list, starting with the last one
    }
}

//bool function Empty, returns true if list is empty, false if it isn't
inline bool Database::empty() const
{
    return (first==NULL);
}

//function push takes a pointer to an employee as parameter
inline void Database::push(const ListElement & newEmploy)
{
   if(empty())
    {
        //if list is empty, add new employee at beginning of list
        first = new Database::Node(newEmploy, first, counter+1);
        Database::increaseCount();
    }else{
        //add new employee at the end of the list
        Database::nodeptr prevptr=first;
        while(prevptr->next!=NULL)
        {
            prevptr=prevptr->next;
        }
        Database::nodeptr newptr=new Database::Node(newEmploy, NULL, counter+1);
        prevptr->next=newptr;
        Database::increaseCount();  //increase count every time new employee is added

    }
}

//pop function takes an int as parameter which will be compared to each Node's order
inline void Database::pop(int p)
{
    if(!empty()) //check if list is not empty
    {

            if(p!=1){  //if element to be deleted is not the first one
                Database::nodeptr delptr = first,   //declare necessary pointers
                                nextptr = first,
                                prevptr = first;

                while(delptr->order!=p && delptr->next!=NULL)  //keep checking the list until the order is found or until end of list
                {
                    delptr=delptr->next;  //keep setting the nodepointer to the next portion of the node
                }

                if(delptr->next!=NULL){  //check if it reached the end of the list
                    while(nextptr->order!=(p+1) && nextptr->next!=NULL)
                    {
                        nextptr=nextptr->next;//keep traversing the list until nextptr points to the node after delptr
                    }
                }else
                    nextptr=NULL; //if it is the end, set the nextptr to NULL

                while(prevptr->next!=delptr)
                {
                    prevptr=prevptr->next;  //keep moving prevptr until it points to the pointer which points to the pointer to be deleted
                }
                prevptr->next=nextptr;   //point prevptr's next to nextptr
                delete delptr;   //delete delptr
                if(nextptr!=NULL){
                    if(nextptr->next==NULL){
                        nextptr->setOrder(nextptr->getOrder()-1); //change the order of the following Nodes
                    }else{
                        while(nextptr->next!=NULL){
                            nextptr->setOrder(nextptr->getOrder()-1); //change the order of the following nodes
                            nextptr=nextptr->next;
                        }
                        nextptr->setOrder(nextptr->getOrder()-1);
                    }
                }
            }else{ //if element to be deleted is the first one
                Database::nodeptr delptr=first,
                                changeOrder=first->next;
                first=first->next;  //change first to point to the second node in the list
                delete delptr;   //delete the first node

                if(changeOrder!=NULL){   //use changeOrder to travers the list and change the order of each of the nodes following
                    if(changeOrder->next==NULL){
                        changeOrder->setOrder(changeOrder->getOrder()-1);
                    }else{
                        while(changeOrder->next!=NULL){
                            changeOrder->setOrder(changeOrder->getOrder()-1);
                            changeOrder=changeOrder->next;
                        }
                        changeOrder->setOrder(changeOrder->getOrder()-1);
                    }
                }
            }
            Database::decreaseCount();  //every time a Node is deleted, decrease the count by one
    }else{
        cout<<setw(70)<<"//               ***No employees to delete***                 //"<<endl;
        //if list is empty, display the following message
    }
}

inline void Database::increaseCount()
{
    counter++;  //increase count by one
}

inline void Database::decreaseCount()
{
    counter--;   //decrease count by one
}

inline bool Database::searchListbyLast(string last)
{
    //check if list is empty
    if(!empty())
    {
        Database::nodeptr returnptr = first;  //declare new nodeptr variable
        bool foundEmployee=false;  //keep this variable as false, unless a match is found
        while(returnptr!=NULL)  //keep traversing the list until the very end
        {
            if(returnptr->employ->getLast()==last) //if the current node is a match, display it
            {
                cout<<setw(9)<<"// ";
                if(returnptr->order<10)
                    cout<<returnptr->order<<"  ";
                else
                    cout<<returnptr->order<<" ";
                cout<<returnptr->employ;
                foundEmployee=true; //change foundEmployee to true
            }
            returnptr=returnptr->next;  //change returnptr to point to th next node
        }
        if(!foundEmployee) //If no employees were found, display error message
            {
                cout<<setw(70)<<"//              ***Employee could not be found***             //"<<endl;
                cout<<setw(70)<<"////////////////////////////////////////////////////////////////"<<endl;
                return false;  //return false
            }
        return true;//return true
    }else{ //if database is empty, display error message and return false
        cout <<setw(70)<< "//                 ***Database is empty***                    //" << endl;
        cout<<setw(70)<<"////////////////////////////////////////////////////////////////"<<endl;
        return false;
    }
}

//function searchListbyID follows the same algorithm as the previous function
inline bool Database::searchListbyID(int id)
{
    //check if list is empty
    if(!empty())
    {
        nodeptr returnptr=first;   //declare new nodeptr variable
        bool foundEmployee=false;   //keep this variable as false, unless a match is found
        while(returnptr!=NULL)   //keep traversing the list until the very end
        {
            if(returnptr->employ->getID()==id)   //if the current node is a match, display it
            {
                cout<<setw(9)<<"// ";
                if(returnptr->order<10)
                    cout<<returnptr->order<<"  ";
                else
                    cout<<returnptr->order<<" ";
                cout<<returnptr->employ;
                foundEmployee=true;   //change foundEmployee to true
            }
            returnptr=returnptr->next;    //change returnptr to point to th next node

        }
        if(!foundEmployee)  //If no employees were found, display error message
        {
            cout<<setw(70)<<"//              ***Employee could not be found***             //"<<endl;
            cout<<setw(70)<<"////////////////////////////////////////////////////////////////"<<endl;
            return false;   //return false
        }
        return true;  //return true
    }else{   //if list is empty, display error message and return false
        cout <<setw(70)<< "//                 ***Database is empty***                    //" << endl;
        cout<<setw(70)<<"////////////////////////////////////////////////////////////////"<<endl;
        return false;
    }
}

//Function searhcListbyOrder takes an int as parameter and return a pointer to a MonthRecords object
inline recordsPtr Database::searchListbyOrder(int o)
{
    recordsPtr garbage=NULL;  //declare a garbage pointer, in case no employee is found
    if(!empty())  //check if list is empty
    {
        Database::nodeptr returnptr=first;   //declare nodeptr to traverse the list

        while(returnptr->order!=o)  //keep traversing the list while the node is not a match
        {
            returnptr=returnptr->next;  //keep setting the returnptr to point to the next node
            if(returnptr==NULL)    //check if Returnptr reached the end of the list, if it did display error message and return the garbage
            {
                cout<<setw(70)<<"//            ***Employee could not be found***               //"<<endl;
                cout<<setw(70)<<"////////////////////////////////////////////////////////////////"<<endl;
                return garbage;
            }
        }
        return returnptr->records; //else, return the nodes pointer to MonthRecords object
    }else{  //if list is empty, display error message and return garbage
        cout <<setw(70)<<"//                 ***Database is empty***                    //"<< endl;
        cout<<setw(70)<<"////////////////////////////////////////////////////////////////"<<endl;
        return garbage;
    }
}

//void function uses an algorithm to traverse the list while displaying every element in an orderly fashion
inline void Database::display(ostream & out) const
{
     if(!empty())  //check tha list isn't empty
     {
        Database::nodeptr disptr=first;  //declare and set a nodeptr variable to first
        while(disptr!=NULL)   //keep traversing the list until disptr is NULL
        {
            out<<setw(9)<<"// ";
            if(disptr->order<10)
            {
                out<<disptr->order<<"  "<<disptr->employ; //calls operator overloading function on employee
            }
            else{
                out<<disptr->order<<" "<<disptr->employ;
            }
            disptr=disptr->next;  //set disptr to point to the next node
        }
     }else{  //if list is empty, display error message
        out<<setw(70)<<"//                 ***Database is empty***                    //"<<endl;
        out<<setw(70)<<"////////////////////////////////////////////////////////////////"<<endl;
     }
}

//operator overloading function for Database, takes an object of type Database and an object of type ostream as parameters
ostream & operator<<(ostream & o, Database & d)
{
    d.display(o);   //call function display on object d with ostream object as parameter
    return o;  //return ostream object
}


#endif // DATABASE_H
