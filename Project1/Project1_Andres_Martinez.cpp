/*///////////////////////////////////////////////////////////////////////////////////
//Project 1//////////////////////////////////////////////////////////////////////////
//COMPE 260//////////////////////////////////////////////////////////////////////////
//Calculator Program/////////////////////////////////////////////////////////////////
//This program prompts the user to select one of four possible arithmetic operations,
//along with two operands. The program performs the operation with the given operands
//and outputs the result.
//This program was written using only pointers for variables.
//Programmer: Andres Martinez Paz
//RedID: 819505668
///////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <iomanip>     //Include the necessary libraries
#include <string.h>
#include <stdio.h>
#include <math.h>

using namespace std;

/*Function "add" takes two variables of type double as parameters
 and returns the sum of both numbers as a double variable*/
double add(double x, double y)
{
    return x+y;
}

/*Function "subs" takes two variables of type double as parameters
 and returns the difference of both numbers as a double variable*/
double subs(double x, double y)
{
    return x-y;
}

/*Function "mult" takes two variables of type double as parameters
 and returns the product of both numbers as a double variable*/
double mult(double x, double y)
{
    return x*y;
}

/*Function "divide" takes two variables of type double as parameters
 and returns the division of both numbers as a double variable*/
double divide(double x, double y)
{
    return x/y;
}

/*Void function "displayMenu" serves only to output the menu in a way
that is understandable for the user. It does not return anything*/
void displayMenu()
{
    cout << endl;
    cout << setw(60) << "////////////////////////////////////////////////////" << endl;
    cout << setw(60) << "//Calculator Program////////////////////////////////" << endl;
    cout << setw(60) << "////////////////////////////////////////////////////" << endl;
    cout << setw(60) << "//Choose the operation you want to perform:       //" << endl;
    cout << setw(60) << "//                                                //" << endl;
    cout << setw(60) << "// 1) +                                           //" << endl;
    cout << setw(60) << "// 2) -                                           //" << endl;
    cout << setw(60) << "// 3) x                                           //" << endl;
    cout << setw(60) << "// 4) /                                           //" << endl;
    cout << setw(60) << "//                                                //" << endl;
    cout << setw(11) << "// ";
}

/*Void function "display1" serves only to output the prompt for the first operand, regardless of the operation.
 It does not return anything*/
void display1()
{
    cout << setw(60) << "//                                                //" << endl;
    cout << setw(60) << "//Enter the first operand:                        //" << endl;
    cout << setw(60) << "//                                                //" << endl;
    cout << setw(60) << "//                                                //" << endl;
    cout << setw(60) << "//                                                //" << endl;
    cout << setw(60) << "//                                                //" << endl;
    cout << setw(11) << "// ";
}

/*Void function "display2" serves only to output the prompt for the second operand, regardless of the operation.
 It does not return anything*/
void display2()
{
    cout << setw(60) << "//                                                //" << endl;
    cout << setw(60) << "//Enter the second operand:                       //" << endl;
    cout << setw(60) << "//                                                //" << endl;
    cout << setw(11) << "// ";
}

/*Void function "displayOut" serves only to output the the result of the operation.
 It takes three double variables and one char variable as parameters. parameters "x" and "y"
 are the two operands, parameter "z" is the sign of the operation and parameter "result" is
 the result of the operation. It does not return anything*/
void displayOut(double x, double y, char z, double result)
{
    cout << setw(60) << "//                                                //" << endl;
    cout << setw(11) << "// " << x << " " << z << " " << y << " = " << result << endl;
    cout << setw(60) << "//                                                //" << endl;
    cout << setw(60) << "//                                                //" << endl;
    cout << setw(60) << "//                                                //" << endl;
    cout << setw(11) << "// ";
}
/*//main function////////////////////////////////////////////////////////////////*/
int main()
{
    bool *ptrbool = new bool;
    *ptrbool = true;      //declaration and assignment of boolean pointer variable that points
                          //to anonymous variable of type bool to hold a "true" value.
                          //This will be used to ask the user if they want to keep running the program at the end
       //while loop that will keep running as long as ptrbool points to a "true" value
    while(*ptrbool){
        double *ptr1 = new double;
        double *ptr2 = new double;
        int *ptrc = new int;
        char *ptragain = new char;
        bool *ptrcorrect = new bool; //Declaration of all the variables that will be used in the program, as pointers pointing to anonymous variables
        *ptrcorrect = false;
        *ptrc = 0;                   //assigning initial values to pointers ptrcorrect and ptrc
        displayMenu();  //calls function "displayMenu" to output first menu

        while(!*ptrcorrect){  //while loop used to check the useres input for error, ptrcorrect is a bool variable that changes to true if the input is correct
            while(!(cin >> *ptrc)){  //first step of error checking, if ptrc (int pointer) gets assigned anything other than an int, the loop will run
                cout << setw(60) << "// *Error: not a correct input.                   //" << endl;
                cout << setw(31) << "// Enter option again: ";  //output error message for the user
                cin.clear();  //clear the input stream
                cin.ignore(100, '\n');   //ignore the first 100 characters of the input
            }
            if(*ptrc == 1 || *ptrc == 2 || *ptrc == 3 || *ptrc == 4){  //second step of error checking, if the input is the same as either one of the first options, the input is correct
                *ptrcorrect = true;  //if input is correct, change value of ptrcorrect to true to stop running the loop
            }else{
                cout << setw(60) << "// *Error: not a correct input.                   //" << endl;
                cout << setw(31)<< "// Enter option again: ";      //error messages for the user
            }
        }
        *ptrcorrect = false;   //change pointer ptrcorrect back to false to use in next error checking

        /*Use of switch statement instead of If/elseif statements to select the correct operation to perform*/
        switch (*ptrc)
        {
            case 1:   //if pointer ptrc is integer 1, run the following code
                display1();   //call function "display1"
                while(!(cin >> *ptr1)){  //error checking, if ptr1 (int pointer) gets assigned anything other than an int, the loop will run
                        cout << setw(60) << "// *Error: not a correct input.                   //" << endl;
                        cout << setw(31) << "        // Enter first operand again: ";  //output error message for the user
                        cin.clear();             //clear the input stream
                        cin.ignore(100, '\n');   //ignore the first 100 characters of the input
                }
                display2();  //call function "display2"
                 while(!(cin >> *ptr2)){  //error checking, if ptr2 (int pointer) gets assigned anything other than an int, the loop will run
                        cout << setw(60) << "// *Error: not a correct input.                   //" << endl;
                        cout << setw(31) << "        // Enter second operand again: ";  //output error message for the user
                        cin.clear();              //clear the input stream
                        cin.ignore(100, '\n');   //ignore the first 100 characters of the input
                }
                displayOut(*ptr1, *ptr2 , '+', add(*ptr1, *ptr2)); //call function "displayOut" with function "add" to output the operation and result
                break;
            case 2:
                display1();  //call function "display1"
                 while(!(cin >> *ptr1)){  //error checking, if ptr1 (int pointer) gets assigned anything other than an int, the loop will run
                        cout << setw(60) << "// *Error: not a correct input.                   //" << endl;
                        cout << setw(31) << "        // Enter first operand again: ";  //output error message for the user
                        cin.clear();              //clear the input stream
                        cin.ignore(100, '\n');   //ignore the first 100 characters of the input
                }
                display2();   //call function "display2"
                 while(!(cin >> *ptr2)){  //error checking, if ptr2 (int pointer) gets assigned anything other than an int, the loop will run
                        cout << setw(60) << "// *Error: not a correct input.                   //" << endl;
                        cout << setw(31) << "        // Enter second operand again: ";  //output error message for the user
                        cin.clear();             //clear the input stream
                        cin.ignore(100, '\n');   //ignore the first 100 characters of the input
                }
                displayOut(*ptr1, *ptr2 , '-', subs(*ptr1, *ptr2));  //call function "displayOut" with function "subs" to output the operation and result
                break;
            case 3:
                display1();   //call function "display1"
                 while(!(cin >> *ptr1)){  //error checking, if ptr1 (int pointer) gets assigned anything other than an int, the loop will run
                        cout << setw(60) << "// *Error: not a correct input.                   //" << endl;
                        cout << setw(31) << "        // Enter second operand again: ";  //output error message for the user
                        cin.clear();             //clear the input stream
                        cin.ignore(100, '\n');   //ignore the first 100 characters of the input
                }
                display2();   //call function "display2"
                 while(!(cin >> *ptr2)){  //error checking, if ptr2 (int pointer) gets assigned anything other than an int, the loop will run
                        cout << setw(60) << "// *Error: not a correct input.                   //" << endl;
                        cout << setw(31) << "        // Enter second operand again: ";  //output error message for the user
                        cin.clear();              //clear the input stream
                        cin.ignore(100, '\n');   //ignore the first 100 characters of the input
                }
                displayOut(*ptr1, *ptr2 , 'x', mult(*ptr1, *ptr2));   //call function "displayOut" with function "mult" to output the operation and result
                break;
            case 4:
                display1();   //call function "display1"
                while(!(cin >> *ptr1)){  //error checking, if ptr1 (int pointer) gets assigned anything other than an int, the loop will run
                        cout << setw(60) << "// *Error: not a correct input.                   //" << endl;
                        cout << setw(31) << "        // Enter first operand again: ";  //output error message for the user
                        cin.clear();             //clear the input stream
                        cin.ignore(100, '\n');   //ignore the first 100 characters of the input
                }
                display2();   //call function "display2"
                 while(!(cin >> *ptr2)){  //error checking, if ptr2 (int pointer) gets assigned anything other than an int, the loop will run
                        cout << setw(60) << "// *Error: not a correct input.                   //" << endl;
                        cout << setw(31) << "        // Enter second operand again: ";  //output error message for the user
                        cin.clear();              //clear the input stream
                        cin.ignore(100, '\n');   //ignore the first 100 characters of the input
                }
                displayOut(*ptr1, *ptr2 , '/', divide(*ptr1, *ptr2));   //call function "displayOut" with function "divide" to output the operation and result
                break;
            default:  //Default case is unnecessary due to the highly effective error checking
                break;
        }

        /*The following segment asks the user if they want to run the program again*/
        cout << "Do you wish to run Calculator Program again?   //"<<endl;
        cout << setw(17) << "// (Y/N) " ;
        cin >> *ptragain;

        /*Error checking for repetition*/
        while(!(toupper(*ptragain) == 'Y' || toupper(*ptragain) == 'N')){
             cout << setw(60) << "// *Error. Not an acceptable input.               //" << endl;
             cout << setw(60) << "        // Do you wish to run Calculator Program again?   //" << endl;
             cout << setw(17) << "// (Y/N) ";
             cin >> *ptragain;
        }

        if(toupper(*ptragain) == 'N'){   //If statement to read users input
            *ptrbool = false;            //if the user inputs no, ptrbool becomes false, and therefore breaks the main while loop
        }


    }
    /*Final output, when program ends, display name of programmer*/
    cout << setw(60) << "//                                                //" << endl;
    cout << setw(60) << "// Programmer: Andres Martinez Paz                //" << endl;
    cout << setw(60) << "////////////////////////////////////////////////////" << endl;
    cout << setw(60) << "////////////////////////////////////////////////////" << endl;

    return 0;
}
