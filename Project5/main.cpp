/*////////////////////////////////////////////////////////////////////////////////////////////////
// Program 5 BST
//
// This program consists of a Binary Search Tree which holds an integer as an element in each Node.
// The header file "bst.h" includes the declarations of class BST's public and private members,
// as well as the output operator ovrloading function. These public and private members'
// descriptions are included in the file "bst.cpp". BST is a friend class of class TreeNode, which
// members are declared and described in the file "treenode.h" by means of the inline keyword.
// Driver.cpp is the implementation file of the class BST and TreeNode. It is made up of a main
// menu where the user can choose what to do with the BST. The functions declared in driver.cpp
// are the following:
//
// displayHeader().- Contains two output lines which make up the top part of the Graphic interface frame
// displayMenu(BST & b).- Takes in an object of type BST as parameter. Displays the current BST by
//                          calling the output operator overloading function. It then outputs the main menu
// checkChoice(int maxChoice).- Takes in an int as parameter. This function is used to prompt the user
//                              for an int input, and checking that the user's input is between 1 and the
//                              the number entered as parameter. This is used for menus where the user
//                              must choose a number from a menu given.
// main().- Main function, where the implementation of BST and TreeNode takes place.
//
// COMPE 260
// Programmer: Andres Martinez Paz
// RedID: 819505668
///////////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>    //Library for input/output streams
#include <iomanip>     //library for input/output manipulations
#include <string>      //Library for string manipulations
#include "bst.h"       //Include header file "bst.h", which includes class BST


using namespace std;

/*//////////////////////////////////////////////////////////////////////////////////////////
// Void function displayHeader, displays the top part of the program frame with the title
//////////////////////////////////////////////////////////////////////////////////////////*/
void displayHeader(){
    cout<<setw(70)<<"////////////////////////////////////////////////////////////"<<endl;
    cout<<setw(70)<<"// Binary Search Tree Program      /////////////////////////"<<endl;
}

/*//////////////////////////////////////////////////////////////////////////////////////////
// void function displayMenu takes in an object of type BST as parameter. Displays the BST
// object by calling the output operator overloading function and displays the main menu
// following the frame graphic interface
//////////////////////////////////////////////////////////////////////////////////////////*/
void displayMenu(BST & b){
    cout<<setw(70)<<"//                                                        //"<<endl;
    cout<<setw(70)<<"//  Current BST:                                          //"<<endl;
    cout<< b;
    cout<<setw(70)<<"//                                                        //"<<endl;
    cout<<setw(70)<<"// Choose an option from below:                           //"<<endl;
    cout<<setw(70)<<"//                                                        //"<<endl;
    cout<<setw(70)<<"// 1. Insert item(s) in the BST                           //"<<endl;
    cout<<setw(70)<<"// 2. Remove an item in BST                               //"<<endl;
    cout<<setw(70)<<"// 3. Search for an item                                  //"<<endl;
    cout<<setw(70)<<"// 4. Traverse BST inorder                                //"<<endl;
    cout<<setw(70)<<"// 5. Traverse BST preorder                               //"<<endl;
    cout<<setw(70)<<"// 6. Traverse BST postorder                              //"<<endl;
    cout<<setw(70)<<"// 7. Graph the BST                                       //"<<endl;
    cout<<setw(70)<<"// 8. Exit program                                        //"<<endl;
    cout<<setw(70)<<"//                                                        //"<<endl;
    cout<<setw(13)<<"// ";
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
        cerr<<setw(70)<<"//         ***Error. Not an acceptable choice***          //"<<endl; //error message
        cout<<setw(21)<<"// Choice: ";

    }
    cin.ignore(1000, '\n');
    return choice; //once the choice is correct, return the value
}

/*////////////////////////////////////////////////////////////////////////////////////////////
// function main includes the implementation of classes BST and TreeNode. It consists of a
// single menu and switch statement to explore the different functions in class BST.
////////////////////////////////////////////////////////////////////////////////////////////*/
int main()
{
    bool run=true;   //boolean variable run is set to true, this will keep the main while loop running
    displayHeader();   //calls function displayHeader, do it outside of main while loop so that it is only displayed once
    BST myBST;   //declare new BST object called myBST, calls default constructor in class BST
    while(run)  //main while loop will keep running as long as run is true
    {
        int choice,  //int choice will store the user's choice from the main menu
            searchNum,  //int searchNum will be used for choice 3, where BST's search function will be explored
            delNum;    //int delNum will be used for choice 2, where BST's function deleteNode will be explored
        bool isnegative=false;   //bool is negative will be used to check if any number in the input string in choice 1 is negative
        string numbers;     //string numbers will store the user's input in choice 1, this allows the user to enter multiple  numbers at once
        displayMenu(myBST);   //calls function displayMenu with myBST as parameter, displays myBST and the main menu
        choice=checkChoice(8);  //calls function checkChoice with maxChoice 8 as parameter
        switch(choice)     //switch statement with int choice as argument
        {
            //if user inputs 1:
            case 1: cout <<setw(70)<< "// What number do you want to add?                        //"<<endl;
                    cout <<setw(70)<< "// (Enter numbers separated by a space)                   //"<<endl;
                    cout <<setw(25)<< "// Add number: ";
                    //prompt user to input any amount of numbers they want to add, separated by a space

                    getline(cin, numbers); //read a whole line of input and store it in a string

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
                            myBST.insertNode(n); //after while loop breaks, call function insertNode on myBST with number n as parameter
                        }else if(numbers.at(i)=='-') //if the character read is not a digit, but a negative sign, set bool "isnegative" to true and read next char
                            isnegative=true;
                    }
                break; //break switch statement
            //if user inputs 2:
            case 2: cout <<setw(70)<< "// Enter the number you want to delete:                   //"<<endl;
                    cout <<setw(28)<< "// Delete number: ";
                    while(!(cin>>delNum)) //keep running while user's input is not correct
                    {
                        cin.clear();  //clear cin
                        cin.ignore(1000, '\n');  //ignore next line of input, if there is one
                        //output error message
                        cout <<setw(70)<< "//       ***Incorrect input. Enter number again***        //"<<endl;
                        cout<<setw(28)<<"// Delete Number: ";
                    }
                    myBST.deleteNode(delNum);  //call function deleteNode on myBST with delNum as parameter
                break;  //break switch statement
            //if user inputs 3:
            case 3: cout <<setw(70)<< "// Enter the number you want to search for:               //"<<endl;
                    cout <<setw(28)<< "// Search number: ";
                    while(!(cin>>searchNum)) //run while user's input is not correct
                    {
                        cin.clear();  //clear cin
                        cin.ignore(1000, '\n');   //ignore next line of input, if there is one
                        cout <<setw(70)<< "//       ***Incorrect input. Enter number again***        //"<<endl;
                        cout<<setw(28)<<"// Search Number: ";
                    }
                    cout <<setw(70)<< "////////////////////////////////////////////////////////////"<<endl;
                    myBST.search(searchNum);  //call function search on myBST with searchNum as parameter
                    cout <<setw(70)<< "////////////////////////////////////////////////////////////"<<endl;
                break;  //break switch statement
            //if user inputs 4:
            case 4: cout<<setw(70)<<"// Inorder:                                               //"<<endl;
                    myBST.inorder(cout); //call function inorder on myBST with cout as parameter
                break; //break switch statement
            //if user inputs 5:
            case 5: cout<<setw(70)<<"// Preorder:                                              //"<<endl;
                    myBST.preorder(cout);//call function preorder on myBST with cout as parameter
                break;  //break switch statement
            //if user inputs 6:
            case 6: cout<<setw(70)<<"// Postorder:                                             //"<<endl;
                    myBST.postorder(cout);  //call function postorder on myBST with cout as parameter
                break;   //break switch statement
            //if user inputs 7:
            case 7: cout <<setw(70)<< "////////////////////////////////////////////////////////////"<<endl;
                myBST.graph(cout);   //call function graph on myBST with cout as parameter
                    cout <<setw(70)<< "////////////////////////////////////////////////////////////"<<endl;
                break; //break switch statement
            //if user inputs 8:
            case 8: run=false;  //set run to false to stop the main while loop
                break; //break switch statement
        }

    }

    //Display the programmer's info with the bottom part of the graphic interface frame
    cout<<setw(70)<<"//                                                        //"<<endl;
    cout<<setw(70)<<"// COMPE 260                       /////////////////////////"<<endl;
    cout<<setw(70)<<"// Programmer: Andres Martinez Paz /////////////////////////"<<endl;
    cout<<setw(70)<<"// RedID: 819505668                /////////////////////////"<<endl;
    cout<<setw(70)<<"////////////////////////////////////////////////////////////"<<endl;
    cout<<setw(70)<<"////////////////////////////////////////////////////////////"<<endl;
    return 0;
}
