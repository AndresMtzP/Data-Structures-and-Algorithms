/*/////////////////////////////////////////////////////////////////////////////////////
// Class MonthRecords is a linked list on which the nodes have two ints for month an
// year, doubles for total sales and total pay for the month, and if the employee is a
// waiter, a double for tips. The publci data members include an explicit value constructor
// a destructor, bool empty to check if the list is empty, an accesor to get the order
// of the employee, an accesor to get the employee to which the list is pointing to,
// a push function to add elemnt to the list, a pop function to delete elements from the list
// a display function to display the elements in an orderly manner. Class Node has two
// constructor, one for employees who are waiters and the other for every other employee
/////////////////////////////////////////////////////////////////////////////////////*/
using namespace std;

#ifndef MONTHRECORDS_H
#define MONTHRECORDS_H


class MonthRecords
{
    public:
        MonthRecords(Employee* e, int nEmployee);  //explicit value constructor
        virtual ~MonthRecords();    //destructor
        bool empty() const;     //boolean function empty
        int getNumOfEmploy(){return numberOfEmployee;};  //accesor to get employee's order
        Employee* getEmployee(){return emp;};   //accessor to get pointer to the employee in question
        void push(int month, int year, double total, double tips);  //push function to add elements
        void pop(int month, int year);  //pop function to delete elements
        void display(ostream & o) const;   //display function
    private:
        class Node  //declaration of class Node in private section of class MonthRecords
        {
            public:
                int month,  //ints to hold the date
                    year;
                double totalPay,  //doubles to hold the monthly data
                       waiterTips,
                       totalSales;
                Employee* monthRecEmp;  //pointer to the employee so each node has access to the employees data members
                Node* next;  //pointer to a Node
                //explicit value constructor takes in two pointers as parameters, as well as two ints and three doubles, for waiters
                Node(int m=1, int y=2000, double tips=0, double tot=0, Employee* e=NULL, Node* n=NULL)
                    :month(m), year(y), waiterTips(tips), totalSales(tot), monthRecEmp(e), next(n)
                    {
                        totalPay=monthRecEmp->calculateSalary(tips);  //totalPay is set by calling function calculateSalary
                    }
                //explicit value constructor for every other employee, this one does not take a parameter for tips
                Node(int m=1, int y=2000, double tot=0, Employee* e=NULL, Node* n=NULL)
                    :month(m), year(y), totalSales(tot), monthRecEmp(e), next(n)
                {
                    totalPay=e->calculateSalary(tot);
                }
        };
        typedef Node* nodepointer;  //type define every instance of nodepointer as a pointer to a Node
        nodepointer first;  //pointer to a Node, points to the first node in the list
        Employee* emp;   //pointer to an employee
        int numberOfEmployee;   //int holds the order of the employee
        int counterM;   //int counterM keeps a count of the Nodes in the list
};

//constructor takes in pointer to employee and int as parameters
inline MonthRecords::MonthRecords(Employee* e, int nEmployee)
    :first(NULL), emp(e), numberOfEmployee(nEmployee), counterM(0)
{}

//destructor traverses the list deleting every Node
inline MonthRecords::~MonthRecords()
{
    MonthRecords::nodepointer currptr=first, //declare new NodePointers currptr and nextptr, set currptr to first
                        nextptr;

    while (currptr!=0) //while loop to check if currptr points to NULL, which means it is the end of the list
    {
        nextptr = currptr->next;  //set "nextptr" to currptr's next
        delete currptr;     //delete whatever currptr is pointing to, freeing the memory previously allocated
        currptr = nextptr;  //set currptr to next ptr
        //This loop keeps deleting the Nodes in the list, starting with the last one
    }
}

//bool function empty returns true if the list is empty, returns false if it is not
inline bool MonthRecords::empty() const
{
    return (first==NULL);
}

//function push to add new element to the list
inline void MonthRecords::push(int month, int year, double total, double tips=0)
{
    //class invariant checks that the date is correct, accepts month from 1 to 12 and year from 0 to 9999
    if(month>=1 && month<=12 && year>=0 && year<=9999){
        if(empty()) //check if list is empty
        {
            //check if the employee is a waiter
            if(toupper(emp->getType())=='W')
                first=new MonthRecords::Node(month, year, tips, total, emp, first);
                //create new node with the information given in the parameters and a parameter for tips
            else  //if it is not a waiter, new node will not be constructed with a tips parameter
                first=new MonthRecords::Node(month, year, total, emp, first);
            counterM++;  // increment counterM
        }else{ //if list is not empty
            bool repeatDate=false; //boolean will be used to check if the date being added doesn't exist already
            MonthRecords::nodepointer checkDate=first;  //declare new nodepointer to check the date

            if(checkDate->month==month && checkDate->year==year) //check if the first node has the same date
                repeatDate=true; //if it does, set repeatDate to true
            while(checkDate->next!=NULL){ //traverse the list until the end is reached
                if(checkDate->month==month && checkDate->year==year){  //if any of the dates is the same as the new date, repeatDate is set to true
                    repeatDate=true;
                }
                checkDate=checkDate->next;   //keep setting checkDate to point to the next node
            }

            if(!repeatDate){  //check if the date does not exist yet
                MonthRecords::nodepointer newptr;  //declare new nodepointer
                if(toupper(emp->getType())=='W')  //check if employee is a waiter, to see how to construct the new node
                    newptr=new MonthRecords::Node(month, year, tips, total, emp, NULL);
                else
                    newptr=new MonthRecords::Node(month, year, total, emp, NULL);
                MonthRecords::nodepointer nextptr=first,  //declare new nodepointers to traverse the list
                                            prevptr=first;
                if(nextptr->year>year ||(nextptr->year==year && nextptr->month>month))  //check if the first node's date is greater than the new node's
                {
                    //if it is, the new node will be pushed at the beginning of the list
                    first=newptr;
                    newptr->next=nextptr;
                    counterM++;
                }else{  //else, traverse the list until the new node is between an earlier date and a later date to push the new node there
                    while(nextptr->year<year && nextptr->next!=NULL)  //traverse list by checking the year first
                    {
                            nextptr=nextptr->next;  //set nextptr to point to the next pointer
                    }
                    if(nextptr->year==year && nextptr->next!=NULL) //after year is reached, traverse the list to find the correct position for the month
                    {
                        while(nextptr->month<month || nextptr->next!=NULL)
                        {
                            nextptr=nextptr->next;  //keep setting nextptr to point to the next node
                        }
                    }
                    if(nextptr->next==NULL && nextptr->year<=year && nextptr->month<month) //if the position was not found, push new node at the end of list
                    {
                        nextptr->next=newptr; //setting the nextptr's next to point to the new node
                        counterM++;  //increment counterM
                    }else{  //if the correct position was found, push new node at that position
                        while(prevptr->next!=nextptr)  //keep traversing the list with prevptr so that it points to the node before the nextptr
                        {
                            prevptr=prevptr->next;  //keep setting prevptr to point to the next node
                        }
                        prevptr->next=newptr;  //set prevptr's next to point to the new node
                        newptr->next=nextptr;  //set the new node's next to point to the nextptr
                        counterM++;  //increment counterM
                    }
                }
            }else{  //if the same date was found in the list, display error message
                cout<<setw(70)<<"////////////////////////////////////////////////////////////////"<<endl;
                cout<<setw(70)<<"//   ***There is already a record with the date entered***    //"<<endl;
            }
        }
    }else{  //if the date entered is not acceptable, display error message
        cout<<setw(70)<<"////////////////////////////////////////////////////////////////"<<endl;
        cout<<setw(70)<<"//           ***Date entered is not acceptable***             //"<<endl;
    }
}

//function pop, traverses the list until it finds the node with that date in it, and it deletes it
inline void MonthRecords::pop(int month, int year)
{
    if(!empty())  //check that list isn't empty
    {
        if(first->month==month && first->year==year){   //check if the first node has the same date
                MonthRecords::nodepointer delptr=first;  //if it does, declare new nodepointer
                first=first->next; //set first to point to the second node in the list
                delete delptr;   //delete first node in the list
                counterM--;   //decrease counterM by one
        }else{   //if the first Node does not have the same date,
            MonthRecords::nodepointer delptr=first, //use two new nodepointers to traverse the list
                                    prevptr=first;
            //keep running while loop until a node with the same date is reached, or until the end of the list
            while((delptr->year!=year && delptr->month!=month) || delptr->next!=NULL )
            {
                delptr=delptr->next;
            }
            if((delptr->year!=year || delptr->month!=month) && delptr->next==NULL) //check the final node to see if it has the same date
            {
                //if not, display error message
                cout<<setw(70)<<"//     ***The record you want to delete does not exist***     //"<<endl;
                cout<<setw(70)<<"////////////////////////////////////////////////////////////////"<<endl;
            }else{ //traverse the list with prevptr until it points to the node before the pointer to be deleted
                while(prevptr->next!=delptr)
                {
                    prevptr=prevptr->next;  //keep setting prevptr to point to the next node
                }
                prevptr->next=delptr->next; //set prevptr's next to point to the node after the pointer to be deleted
                delete delptr;  //delete the pointer with the matching date
                counterM--;   //decrese counterM by one
            }

    }
    }else{  //if list is empty, display error message
        cout <<setw(70)<< "//                ***No records to delete***                  //"<<endl;
        cout<<setw(70)<<"////////////////////////////////////////////////////////////////"<<endl;
    }
}

//display function will traverse the list in order, displaying every node in an organized manner
inline void MonthRecords::display(ostream & out) const
{
     if(!empty()) //check that list is not empty
     {
         MonthRecords::nodepointer disptr=first;   //declare new nodepointer
        for(int i=1; i<=counterM; i++)
        {
            int length,
            c=disptr->totalSales;
            if(disptr->totalSales<10)
                length=1;
            else{
                for(length=0; c>1; length++)  //calculate length of total sales
                {
                    c=c/10;
                }
            }
            out<<setw(9)<<"// ";
            out<<i<<".- ";
            if(disptr->month<10)
                out<<"0";
            out<<disptr->month<<"/";
            if(disptr->year<10)
                out<<"000";
            else if(disptr->year<100)
                out<<"00";
            else if(disptr->year<1000)
                out<<"0";
            out<<disptr->year<<"    Total Sales: "<<disptr->totalSales;
            for(int i=0; i<(28-length); i++)  //display the necessary spaces to complete the graphic interface
            {
                out<<" ";
            }
            out<<"//"<<endl;

            c=disptr->totalPay;
            if(disptr->totalPay<10){
                length=1;
            }else{
                for(length=0; c>1; length++){  //calculate length of totalpay
                    c=c/10;
                }
            }
            out<<setw(9)<<"// ";
            if(toupper(emp->getType())=='W'){
                out<<"Tips: "<<disptr->waiterTips;
                length=length+9;
                c=disptr->waiterTips;
                if(disptr->waiterTips<10){
                    length++;
                }else{
                    for(length; c>1; length++){  //calculate length of tips
                        c=c/10;
                    }
                }
            }
            out<<"    Total Pay: "<<disptr->totalPay;
            for(int i=0; i<(40-length); i++){  //display the necessary spaces for the graphic interface
                out<<" ";
            }
            out<<"//"<<endl;
            out<<setw(70)<<"//                                                            //"<<endl;
            if(disptr->next!=NULL)
                disptr=disptr->next;  //keep cycling through the list
        }
     }else{  //if list is empty, display error message
        out<<setw(70)<<"//            ***No records for this employee***              //"<<endl;
        out<<setw(70)<<"////////////////////////////////////////////////////////////////"<<endl;
     }
}

//operator overloading function
ostream & operator<<(ostream & o, MonthRecords & m)
{
    m.display(o);  //call display function on object m, with ostream object as parameter
    return o;  //return ostream object
}

#endif // MONTHRECORDS_H
