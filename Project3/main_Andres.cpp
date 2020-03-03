/*/////////////////////////////////////////////////////////////////////////////////////////////
// Staque Program
//
// This program implements class Staque, which is a combination of a stack and a sueue. The program
// displays a menu with the current staque, and several options asking the user what he/she wants to do
// to the staque. The choices for the user are: 1. Add a number or numbers to the staque,
// 2. Delete an even number from the staque, 3. Delete an odd number from the staque, or 4. Exit the program.
// If the user chooses option 1, he or she is asked to input the number or numbers he or she wants to add to the
// staque. The algorithm used stores a whole line input into a string, analyzes and uses the acceptable inputs
// and ignores the rest. The staque accepts any integer, negative or positive. The staque follos the LIFO
// (Last In First Out) rule, if the number is an even number, the staque behaves like a stack and pushes and pops
// numbers form the front of the staque, if it is odd, the staque will act as queue and push and pop numbers from
// the back of the staque.
//
// COMPE 260
// Project 3
// Programmer: Andres Martinez Paz
// RedID: 819505668
////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>   //Library for input/output streams
#include <iomanip>    //Library for input/output manipulators
#include <stdio.h>    //Library to perform input/output operations
#include <string>     //Library for string manipulations
#include <cstdlib>    //Library for general purpose functions
#include "staque.h"   //Include Staque class header

using namespace std;

/*/////////////////////////////////////////////////////////
// Function displayHeader displays the title of the program
// and sets the top part of the graphic interface frame
/////////////////////////////////////////////////////////*/
void displayHeader()
{
    cout << setw(70) << "///////////////////////////////////////////////////////////" << endl;
    cout << setw(70) << "//Staque Program //////////////////////////////////////////" << endl;
}

/*//////////////////////////////////////////////////////////
// Function displayMenu takes an object of type Staque as a
// parameter, it then outputs the main menu of
// the program with the current staque first. The function
// is able to output the object of type Staque because of
// the operator overloading function in class staque
//////////////////////////////////////////////////////////*/
void displayMenu(Staque & s)
{
    cout << setw(70) << "//                                                       //" << endl;
    cout << setw(70) << "// Current Staque:                                       //" << endl;
    cout << setw(14) << "// " << s;                           //calls operator overloading function
    cout << setw(70) << "//                                                       //" << endl;
    cout << setw(70) << "// Choose an option from below:                          //" << endl;
    cout << setw(70) << "// 1.- Add number to staque.                             //" << endl;
    cout << setw(70) << "// 2.- Delete even number from staque.                   //" << endl;
    cout << setw(70) << "// 3.- Delete odd number from staque.                    //" << endl;
    cout << setw(70) << "// 4.- Quit program                                      //" << endl;
    cout << setw(70) << "//                                                       //" << endl;
    cout << setw(21) << "// Option:";
}

/*/////////////////////////////////////////////////////////////////////////////
// main function implements class Staque
/////////////////////////////////////////////////////////////////////////////*/
int main()
{
    int choice;          //declare int to hold choice input by user
    string  numbers;     //declare string to hold the user's input if they choose to add a number(s)
    bool isnegative=false;  //declare bool to use as flag in algorithm to accept negative numbers as input
    bool run = false;      //declare bool to keep program running.
    Staque myStaque;       //call default constructor for a new object of type Staque called myStaque

    displayHeader();     //calls function displayHeader to display the top part of the program just once

    while(!run) //main "while" loop, will keep running as long as bool "run" remains negative
    {
        displayMenu(myStaque);  //call function displayMenu with myStaque as parameter, call it every time main while loop repeats

        while(!(cin>>choice) || !(choice== 1 || choice == 2 || choice ==3 || choice==4))
        {     //While loop used to analyze the user's choice input, only acceptable input is an int from 1-4
            cerr<<setw(70)<<"//              ***Not a correct option***               //"<<endl;
            //display error message and prompt user to enter input again
            cout<<setw(70)<<"// Enter option again:                                   //"<<endl;
            cout<<setw(14)<<"// ";
            cin.clear();  //clear and ignore any trailing errors to prevent them from ruining the graphic interface
            cin.ignore(1000, '\n');
        }
        cin.ignore(1000, '\n'); //ignore any trailing errors
        switch (choice)  //switch statement used to run a different algorithm for every option
        {
            //if user chooses option 1, run the following code
            case 1: cout <<setw(70)<< "// What number do you want to add?                       //"<<endl;
                    cout <<setw(70)<< "// (Enter numbers separated by a space)                  //"<<endl;
                    cout <<setw(14) << "// ";
                    //prompt user to input any amount of numbers they want to add, separated by a space
                    getline(cin, numbers);  //read a whole line of input and store it in a string

                    for(unsigned int i=0, n; i<numbers.length(); i++) //for loop to manipulate the input char by char
                    {
                        if(isdigit(numbers.at(i))){ //if the current character is a number, run the following,
                            n=0; //set dummy variable 'n' to zero

                            while(isdigit(numbers.at(i)))  //while loop to analyze the following characters after a number, to see if it is a multidigit number
                            {
                                if(isdigit(numbers.at(i))) //if the character is a number, use algorithm to convert into an int
                                    n=n*10 + (numbers.at(i)-'0');  //converts char to int, and if it is a multiple digit number, reads the whole int

                                i++; //increment 'i' for every succesive integer it reads
                                if(i>=numbers.length()) //if 'i' exceeds or equals the length of the input line, break the while loop
                                    break;
                            }
                            if(isnegative) //if boolean "isnegative" is true, convert int to its negative counterpart
                            {
                                n=-n;
                                isnegative=false;  //set bool "isnegative" back to false
                            }
                            myStaque.push(n); //after while loop breaks, call function push in myStaque with number n as parameter
                        }else if(numbers.at(i)=='-') //if the character read is not a digit, but a negative sign, set bool "isnegative" to true and read next char
                            isnegative=true;
                    }

                    break; //break switch statement

            case 2: myStaque.popEven(); //if user inputs choice 2, call function "popEven" in myStaque
                    break; //break switch statement

            case 3: myStaque.popOdd();  //if user inputs choice 3, call function "popOdd" in myStaque
                    break; //break switch statement

            case 4: run=true; //if user inputs choice 4, set bool flag "run" to true, in order to break the main "while" loop
                    break;  //break switch statement
            default:   //switch case default breaks statement
                break;
        }
        cout<<setw(70)<<"///////////////////////////////////////////////////////////"<<endl; //display division frame for end of program
    }

    //display bottom part of frame, with programmer's info
    cout <<setw(70)<< "//                                                       //"<<endl;
    cout <<setw(70)<< "// Programmer: Andres Martinez Paz ////////////////////////"<<endl;
    cout <<setw(70)<< "// RedID 819505668 ////////////////////////////////////////"<<endl;
    cout <<setw(70)<< "// COMPE 260 //////////////////////////////////////////////"<<endl;
    cout <<setw(70)<< "///////////////////////////////////////////////////////////"<<endl;
    return 0;
}
