/*////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OOP, Family Restaurant Program
//
// This program works with the concepts of polymorphism and inheritance
// by simulating a database for a family restaurant. The parent class for this
// program is the Employee class, this class has two derived classes, Salaryemployee
// and HourlyEmployee, and SalaryEmployee has one child class Chef.
// The idea for this program is to display the statistics of every employee in an organized manner
// To implement this program, two linked lists were used. One, Database, which holds nodes with their Data portions
// as pointers to objects of class employee. This way, The employees are stored in an organized way
// The nodes of this list also hold another linked list called MonthRecords. The nodes of this list hold data for a
// specific month, as well as the statistics of that month, including the total sales of the month, the tips earned,
// if the employee is a waiter, and the total salary paid to the employee. These nodes also hold a pointer to the
// to the same employee stored in that original node, so that each MonthRecords node has access to the data members
// of the employee. The navigation for this program is a complex series of menus which allow the user to display the
// current employees, and access their records to add or delete monthly records. Also, the user has the option to
// search for an employee by entering the Last name or the ID number, this also gives the user access to the desired
// employee's records. Finally, the user also has the option to add new employees or delete existing employees.
//
// COMPE 260
// Andres Martinez Paz
// 819505668
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>  //Include library for input/output stream
#include <iomanip>   //Include library for manipulation of input/output stream
#include "employee.h"  //Include parent class employee
#include "salaryemployee.h"  //include child class salaryEmployee
#include "chef.h"           // include child class chef
#include "hourlyemployee.h"  //include child class hourlyemployee
#include "database.h"       //include Linked list Database, which includes linked list MonthRecords


using namespace std;

/*//////////////////////////////////////////////////////////////////////////////////////////
// Void function displayH, displays the header part of the program frame with the title
//////////////////////////////////////////////////////////////////////////////////////////*/
void displayH()
{
    cout<<setw(70)<<"////////////////////////////////////////////////////////////////"<<endl;
    cout<<setw(70)<<"// Family Restaurant (OOP) Program  ////////////////////////////"<<endl;
    cout<<setw(70)<<"//                                                            //"<<endl;
}

/*//////////////////////////////////////////////////////////////////////////////////////////
// void function displayMain displays the main menu following the frame graphic interface
//////////////////////////////////////////////////////////////////////////////////////////*/
void displayMain()
{
    cout<<setw(70)<<"////////////////////////////////////////////////////////////////"<<endl;
    cout<<setw(70)<<"// Enter one of the choices below:                            //"<<endl;
    cout<<setw(70)<<"//                                                            //"<<endl;
    cout<<setw(70)<<"// 1. Display current employees.                              //"<<endl;
    cout<<setw(70)<<"// 2. Search employee by last name.                           //"<<endl;
    cout<<setw(70)<<"// 3. Search employee by ID number.                           //"<<endl;
    cout<<setw(70)<<"// 4. Add employee to the database.                           //"<<endl;
    cout<<setw(70)<<"// 5. Delete employee                                         //"<<endl;
    cout<<setw(70)<<"// 6. Quit program                                            //"<<endl;
    cout<<setw(70)<<"//                                                            //"<<endl;
    cout<<setw(17)<<"// Choice: ";
}

/*//////////////////////////////////////////////////////////////////////////////////////////
// Void function displayEmployees takes an object of type Database and displays the contents
// of the database, which in this case is the linked list holding all the employees
//////////////////////////////////////////////////////////////////////////////////////////*/
void displayEmployees(Database & d)
{
    cout<<setw(70)<<"////////////////////////////////////////////////////////////////"<<endl;
    cout<<setw(70)<<"// Employees:                                                 //"<<endl;
    cout<<setw(70)<<"// Enter number to access employee's records                  //"<<endl;
    cout<<setw(70)<<"// Or enter -1 to go back to main menu                        //"<<endl;
    cout<<setw(70)<<"//                                                            //"<<endl;
    cout<<setw(70)<<"//        Name                        ID             Type     //"<<endl;
    cout<<d;  //this calls the operator overloading function for class Database
}

/*//////////////////////////////////////////////////////////////////////////////////////////
// Void function displayDeleteEmployees takes in an object of type Database as parameter
// and prompts the user to select from the list of employees the one that they want to delete
//////////////////////////////////////////////////////////////////////////////////////////*/
void displayDeleteEmployees(Database & d)
{
    cout<<setw(70)<<"////////////////////////////////////////////////////////////////"<<endl;
    cout<<setw(70)<<"// Employees:                                                 //"<<endl;
    cout<<setw(70)<<"// Enter number to delete employee                            //"<<endl;
    cout<<setw(70)<<"// Or enter -1 to go back to main menu                        //"<<endl;
    cout<<setw(70)<<"//                                                            //"<<endl;
    cout<<setw(70)<<"//        Name                        ID             Type     //"<<endl;
    cout<<d;  //calls operator overloading function
}

/*//////////////////////////////////////////////////////////////////////////////////////////
// Void function displayEmployeesFound sets the Graphic Interface to list all the employees
// found after the user chose to search the list by Last name or by ID
//////////////////////////////////////////////////////////////////////////////////////////*/
void displayEmployeesFound()
{
    cout<<setw(70)<<"////////////////////////////////////////////////////////////////"<<endl;
    cout<<setw(70)<<"// Employees:                                                 //"<<endl;
    cout<<setw(70)<<"// Enter number to access employee's records                  //"<<endl;
    cout<<setw(70)<<"// Or enter -1 to go back to main menu                        //"<<endl;
    cout<<setw(70)<<"//                                                            //"<<endl;
    cout<<setw(70)<<"//        Name                        ID             Type     //"<<endl;
}

/*//////////////////////////////////////////////////////////////////////////////////////////
// Void function displayEmpRecords takes in an object of type employee and an object of type
// MonthRecords as parameters to display the employee's information and its respective
// monthly records
//////////////////////////////////////////////////////////////////////////////////////////*/
void displayEmpRecords(Employee & emp, MonthRecords & m)
{
    cout<<setw(70)<<"////////////////////////////////////////////////////////////////"<<endl;
    cout<<setw(70)<<"// Employee's records                                         //"<<endl;
    cout<<setw(70)<<"//                                                            //"<<endl;
    cout<<setw(9)<<"// ";
    cout<<emp;  //calls operator overloading function on class employee
    cout<<setw(70)<<"//                                                            //"<<endl;
    cout<<setw(70)<<"// Available records for Employee:                            //"<<endl;
    cout<<setw(70)<<"//                                                            //"<<endl;
    cout<< m;   //calls operator overloading function of class MonthRecords
}

/*//////////////////////////////////////////////////////////////////////////////////////////
// Int function checkChoice takes in an integer as a parameter. This function is called
// every time the user has to input a choice, it checks if the choice is correct and returns
// the value of the choice. If it is not correct, it will keep asking the user to enter a
// correct choice.
//////////////////////////////////////////////////////////////////////////////////////////*/
int checkChoice(int maxChoice)  //parameter maxChoice tells the function what the highest value of the choice can be
{
    int choice;  //declare new variable called choice

    //keep running the while loop until the input is correct
    while(!(cin>>choice) || !((choice>=1 && choice<=maxChoice) || choice==-1))
    {
        cin.clear();  //clear and ignore the previous incorrect input so the while loop doesn't get stuck
        cin.ignore(1000, '\n');
        cerr<<setw(70)<<"//           ***Error. Not an acceptable choice***            //"<<endl; //error message
        cout<<setw(17)<<"// Choice: ";

    }
    return choice; //once the choice is correct, return the value
}

/*//////////////////////////////////////////////////////////////////////////////////////////
// void function fillDatabase takes in an object of type Database. This function's purpose
// is to fill the database with predetermined employee objects. This function is only used
// as a demonstration of how the program works.
//////////////////////////////////////////////////////////////////////////////////////////*/
void fillDatabase(Database & d)
{
    //keep adding new objects of type Employee to the Database, and add a single monthly record to each of the MonthRecords list
    d.push(new Salaryemployee("Richard", "Thompson", 6005, 'O', 15000, 60));
    MonthRecords* records=d.searchListbyOrder(1);
    records->push(1, 2005, 6000, 0);
    d.push(new Chef("James", "Oliver", 7006, 10000, 20, "Italian"));
    records=d.searchListbyOrder(2);
    records->push(1, 2005, 6000, 0);
    d.push(new Chef("Gordon", "Ramsey", 7008, 10000, 20, "French"));
    records=d.searchListbyOrder(3);
    records->push(1, 2005, 6000, 0);
    d.push(new HourlyEmployee("Isaac", "Newton", 8006, 3000, 3));
    records=d.searchListbyOrder(4);
    records->push(1, 2005, 6000, 1000);
    d.push(new HourlyEmployee("Rod", "Stewart", 8007, 3000, 5));
    records=d.searchListbyOrder(5);
    records->push(1, 2005, 6000, 1500);
    d.push(new HourlyEmployee("John", "Travolta", 8008, 3000, 7));
    records=d.searchListbyOrder(6);
    records->push(1, 2005, 6000, 1700);

}

/*//////////////////////////////////////////////////////////////////////////////////////////
// Main function
//////////////////////////////////////////////////////////////////////////////////////////*/
int main()
{
    bool run=true; //bool variable to keep running the program until user decides to exit
    displayH(); //call displayH function
    Database myData;  //declare new Database called "myData". Default constructor is called
    fillDatabase(myData);   //call function "fillDatabase" with newly declared myData as parameter
    while(run){     //keep running while run is true;
        int choice,
            recordsChoice,
            searchOrder,    //declare the different variables that will be used in the driver program
            typeChoice,
            ID,
            years,
            month,
            year,
            totalPay;
        char type;        //more variables
        string lastName,
                firstName,
                specialty;
        double salary,      //even more variables
                salesPercentage,
                tips;
        bool runRecords=true;    //declare and assign new bool variable for the nested menu on each employee
        MonthRecords* empRecords;   // declare new pointer variable of type employee
        displayMain();    //call function displayMain, to display the main menu
        choice=checkChoice(6);   //call function checkChoice with parameter 6, which is the maximum int that the choice can be
        cin.clear();        //clear and ignore any trailing errors on the input
        cin.ignore(1000, '\n');
        switch(choice)     //switch statement to take different actions based on the user's choice
        {
            //if user input 1, run the following
            case 1: displayEmployees(myData);  //call function displayEmployees with myData as parameters to display the current employees
                    if(!myData.empty())  //check if the database is not empty
                    {
                        cout<<setw(17)<<"// Choice: ";  //prompt the user to make another choice
                        searchOrder=checkChoice(myData.getCounter());  //to get the max number of choices that the user can take, check the counter variable of myData
                        //if the user entered -1 as a choice, go back to main menu, else run the following
                        if(searchOrder!=-1){
                            empRecords=myData.searchListbyOrder(searchOrder); //call function searchListbyOrder on myData with the user's choice
                                if(empRecords!=NULL)  //check if the records list for the employee is not empty
                                {
                                    //run while loop until user decides to go back to the main menu
                                    while(runRecords){
                                        //call function displayEmpRecords
                                        displayEmpRecords(*(empRecords->getEmployee()), *empRecords);
                                        //to know what employee to display, program access it through the linked list empRecords
                                        cout<<setw(70)<<"// Choose an option from below:                               //"<<endl;
                                        cout<<setw(70)<<"// 1. Add a monthly record.                                   //"<<endl;
                                        cout<<setw(70)<<"// 2. Delete a monthly record.                                //"<<endl;
                                        cout<<setw(70)<<"// 3. Go back to main menu.                                   //"<<endl;
                                        cout<<setw(70)<<"//                                                            //"<<endl;
                                        cout<<setw(17)<<"// Choice: ";
                                        //call function check choice with maxchoice as 3
                                        recordsChoice=checkChoice(3);
                                        //switch statement to decide what action to take based on user's input
                                        switch(recordsChoice)
                                        {
                                            case 1: cout<<setw(22)<<"// Enter Month: ";
                                                    cin>>month;
                                                    //prompt user to enter a month
                                                    cout<<setw(21)<<"// Enter Year: ";
                                                    cin>>year;
                                                    //prompt user to enter a year
                                                    cout<<setw(46)<<"// Enter the total sales for the month: ";
                                                    //ask for the total sales of the month
                                                    while(!(cin>>totalPay) || totalPay<0)
                                                        cout<<setw(70)<<"//       ***Incorrect input Sales must be more than 0***      //"<<endl;
                                                    //check if the employee is a waiter, if so, program also needs tips
                                                    if(toupper(empRecords->getEmployee()->getType())=='W')
                                                    {
                                                        cout<<setw(48)<<"// Enter the waiter's tips for the month: ";
                                                        while(!(cin>>tips) || tips<0)
                                                            cout<<setw(70)<<"//       ***Incorrect input tips must be more than 0***       //"<<endl;
                                                        //prompt user to enter the total tips for the month
                                                    }
                                                    empRecords->push(month, year, totalPay, tips);
                                                    //add a new monthly record to the Employee's Month Records list with the info from above
                                                break;
                                                    //break switch statement
                                            //if user chose option 2
                                            case 2: cout<<setw(32)<<"// Enter month of record: ";
                                                    cin>>month;
                                                    //ask user to input month
                                                    cout<<setw(31)<<"// Enter year of record: ";
                                                    cin>>year;
                                                    //ask user to input year
                                                    empRecords->pop(month, year);
                                                    //delete the records that the user chose
                                                break; //break switch statement
                                            default:    runRecords=false; //if user inputs a different choice, set runRecords to false to break while loop
                                                break; //break switch statement
                                        }
                                    }
                                }
                            }
                    }
                break; // break main swithc statement
            case 2: cout<<setw(38)<<"// Enter last name of employee: ";
                    cin>>lastName;
                    //prompt user to enter last name of employee
                    displayEmployeesFound();
                    //call function displayEmployeesFound
                    //check if there are any employees with that last name
                    if(myData.searchListbyLast(lastName))
                    {
                        //if there are, ask the user to choose one of them
                        cout<<setw(17)<<"// Choice: ";
                        searchOrder=checkChoice(myData.getCounter());
                        //checkchoice
                        //check if user chose -1 to go back to main menu
                        if(searchOrder!=-1){
                            //search list by order which user chose
                            empRecords=myData.searchListbyOrder(searchOrder);
                            if(empRecords!=NULL) //check if the Employee exists
                            {

                                while(runRecords)//keep running while runRecords is true
                                {
                                    //display the employee's records
                                    displayEmpRecords(*(empRecords->getEmployee()), *empRecords);
                                    cout<<setw(70)<<"// Choose an option from below:                               //"<<endl;
                                    cout<<setw(70)<<"// 1. Add a monthly record.                                   //"<<endl;
                                    cout<<setw(70)<<"// 2. Delete a monthly record.                                //"<<endl;
                                    cout<<setw(70)<<"// 3. Go back to main menu.                                   //"<<endl;
                                    cout<<setw(17)<<"// Choice: ";
                                    recordsChoice=checkChoice(3);
                                    //Prompt user to make a choice
                                    switch(recordsChoice) //switch statement to decide what to do
                                    {
                                        case 1: cout<<setw(22)<<"// Enter Month: ";
                                                cin>>month;
                                                //prompt user for month
                                                cout<<setw(21)<<"// Enter Year: ";
                                                cin>> year;
                                                //prompt user for year
                                                cout<<setw(46)<<"// Enter the total sales for the month: ";
                                                while(!(cin>>totalPay) || totalPay<0)
                                                    cout<<setw(70)<<"//       ***Incorrect input Sales must be more than 0***      //"<<endl;
                                                //check if employee is waiter to ask for tips
                                                if(toupper(empRecords->getEmployee()->getType())=='W')
                                                    {
                                                        cout<<setw(48)<<"// Enter the waiter's tips for the month: ";
                                                        //ask for waiter's tips for the month
                                                        while(!(cin>>tips) || tips<0)
                                                             cout<<setw(70)<<"//       ***Incorrect input tips must be more than 0***       //"<<endl;
                                                    }
                                                empRecords->push(month, year, totalPay, tips);
                                                //add the monthly record with the information form above
                                            break; //break switch statement
                                        case 2: cout<<setw(32)<<"// Enter month of record: ";
                                                cin>>month;
                                                //prompt user for month
                                                cout<<setw(31)<<"// Enter year of record: ";
                                                cin>>year;
                                                //prompt user for year
                                                empRecords->pop(month, year);
                                                //delete the monthly record
                                            break; //break switch statement
                                        default: runRecords=false;  // set runRecords to false to break while loop
                                            break;  //break switch statement
                                    }
                                }
                            }
                        }
                    }
                break;  //break main switch statement
            case 3: cout<<setw(38)<<"// Enter ID number of employee: ";
                    cin>>ID;
                    //ask user to input the id number they want to search
                    displayEmployeesFound();
                    //display the employees found
                    //check if any employee in the list has the ID entered
                    if(myData.searchListbyID(ID))
                    {
                        cout<<setw(17)<<"// Choice: ";
                        searchOrder=checkChoice(myData.getCounter());
                        //prompt user for a choice
                        //check if user input a -1 to go back to main menu
                        if(searchOrder!=-1){
                            empRecords=myData.searchListbyOrder(searchOrder);
                            //search the list for the order input by the user
                            if(empRecords!=NULL) //check if the employee exists
                            {
                                //keep running while runRecords is true
                                while(runRecords){
                                        //diplay employee's records
                                    displayEmpRecords(*(empRecords->getEmployee()), *empRecords);
                                    cout<<setw(70)<<"// Choose an option from below:                               //"<<endl;
                                    cout<<setw(70)<<"// 1. Add a monthly record.                                   //"<<endl;
                                    cout<<setw(70)<<"// 2. Delete a monthly record.                                //"<<endl;
                                    cout<<setw(70)<<"// 3. Go back to main menu.                                   //"<<endl;
                                    cout<<setw(17)<<"// Choice: ";
                                    recordsChoice=checkChoice(3);
                                    //check choice
                                    switch(recordsChoice) //switch statement to decide course of action
                                    {
                                        case 1: cout<<setw(22)<<"// Enter Month: ";
                                                cin>>month;
                                                //ask user for month
                                                cout<<setw(21)<<"// Enter Year: ";
                                                cin>> year;
                                                //ask user for year
                                                cout<<setw(46)<<"// Enter the total sales for the month: ";
                                                //ask user for the total Sales for the month
                                                while(!(cin>>totalPay) || totalPay<0)
                                                    cout<<setw(70)<<"//       ***Incorrect input Sales must be more than 0***      //"<<endl;
                                                //check if the employee is a waiter to ask for tips
                                                if(toupper(empRecords->getEmployee()->getType())=='W')
                                                {
                                                    cout<<setw(48)<<"// Enter the waiter's tips for the month: ";
                                                    while(!(cin>>tips) || tips<0)
                                                             cout<<setw(70)<<"//       ***Incorrect input tips must be more than 0***       //"<<endl;
                                                    //ask user for waiter's tips for the month
                                                }
                                                empRecords->push(month, year, totalPay, tips);
                                                //add a new monthly record with the info from above
                                            break;  //break switch statement
                                        case 2: cout<<setw(32)<<"// Enter month of record: ";
                                                cin>>month;
                                                //ask user for month
                                                cout<<setw(31)<<"// Enter year of record: ";
                                                cin>>year;
                                                //ask user for year
                                                empRecords->pop(month, year);
                                                //delete the monthly record with that date
                                            break; //break switch statement
                                        case 3: runRecords=false;  //set runRecords to false to break while loop
                                            break; //break switch statement
                                        default:   //case default
                                            break;//break switch statement
                                    }
                                }
                            }
                        }
                    }
                break; //break main switch statement
            case 4: //ask user what kind of employee they want to add
                    cout<<setw(70)<<"////////////////////////////////////////////////////////////////"<<endl;
                    cout<<setw(70)<<"// Enter an option from below:                                //"<<endl;
                    cout<<setw(70)<<"//                                                            //"<<endl;
                    cout<<setw(70)<<"// 1. Employee is a Manager/Owner.                            //"<<endl;
                    cout<<setw(70)<<"// 2. Employee is a Chef.                                     //"<<endl;
                    cout<<setw(70)<<"// 3. Employee is a Waiter/Hourly employee                    //"<<endl;
                    cout<<setw(70)<<"// 4. Return to main menu.                                    //"<<endl;
                    cout<<setw(70)<<"//                                                            //"<<endl;
                    cout<<setw(17)<<"// Choice: ";
                    typeChoice=checkChoice(4);
                    //check user's choice
                    switch(typeChoice)  //switch statement to decide what action to take
                    {
                        case 1: cout<<setw(31)<<"// Manager's first name: ";
                                cin>>firstName;
                                //ask for employee's first name
                                cout<<setw(30)<<"// Manager's last name: ";
                                cin>>lastName;
                                //ask for employee's last name
                                cout<<setw(30)<<"// Manager's ID number: ";
                                cin>>ID;
                                //ask for employee's ID
                                cout<<setw(35)<<"// Manager's monthly Salary: ";
                                cin>>salary;
                                //ask for Employee's monthly Salary
                                cout<<setw(42)<<"// Manager's sales percentage take: ";
                                cin>>salesPercentage;
                                //ask for employee's percentage take
                                myData.push(new Salaryemployee(firstName, lastName, ID, 'O', salary, salesPercentage));
                                //add new employee with the information from above
                            break;  //break switch statement
                        case 2: cout<<setw(28)<<"// Chef's first name: ";
                                cin>>firstName;
                                //ask for first name
                                cout<<setw(27)<<"// Chef's last name: ";
                                cin>>lastName;
                                //ask for last name
                                cout<<setw(27)<<"// Chef's ID number: ";
                                cin>>ID;
                                //ask for ID
                                cout<<setw(32)<<"// Chef's monthly Salary: ";
                                cin>>salary;
                                //ask for Salary
                                cout<<setw(39)<<"// Chef's sales percentage take: ";
                                cin>>salesPercentage;
                                //ask for the percentage take
                                cout<<setw(35)<<"// Chef's specialty cooking: ";
                                cin>>specialty;
                                //ask for chef's specialty
                                myData.push(new Chef(firstName, lastName, ID, salary, salesPercentage, specialty));
                                //add new employee with info from above
                            break;
                        case 3: cout<<setw(30)<<"// Waiter's first name: ";
                                cin>>firstName;
                                //ask for first name
                                cout<<setw(29)<<"// Waiter's last name: ";
                                cin>>lastName;
                                //ask for last name
                                cout<<setw(29)<<"// Waiter's ID number: ";
                                cin>>ID;
                                //ask for ID
                                cout<<setw(34)<<"// Waiter's monthly Salary: ";
                                cin>>salary;
                                //ask for Waiter's salary
                                cout<<setw(39)<<"// Waiter's years of experience: ";
                                cin>>years;
                                //ask for waiter's years of experience
                                myData.push(new HourlyEmployee(firstName, lastName, ID, salary, years));
                                //add new employee with info from above
                            break; //break switch statement
                        default:  //case default
                            break;  //break switch statement
                    }
                break; //break main switch statement
            case 5: //display the current employees and prompt user to select the one they want to delete
                displayDeleteEmployees(myData);
                if(!myData.empty()) //check if Database is not empty
                {
                    cout<<setw(17)<<"// Choice: "; //prompt user to choose
                    searchOrder=checkChoice(myData.getCounter());
                    //check the user's input
                    //check if the user chose -1 to go back to main menu
                    if(searchOrder!=-1){
                        myData.pop(searchOrder); //delete the employee with the user's choice as order
                    }
                }else{
                    //display if Database is empty
                    cout<<setw(70)<<"//         ***Database is empty, nothing to delete***         //"<<endl;
                }


                break;  //break switch statement
            default:  //case default
                run=false; //set run to false to break main While loop
                break; //break switch statement
        }

    }
    //Display the programmer's info with the bottom part of the graphic interface frame
    cout<<setw(70)<<"//                                                            //"<<endl;
    cout<<setw(70)<<"// Programmer: Andres Martinez Paz /////////////////////////////"<<endl;
    cout<<setw(70)<<"////////////////////////////////////////////////////////////////"<<endl;
    cout<<setw(70)<<"////////////////////////////////////////////////////////////////"<<endl;

    return 0;
}
