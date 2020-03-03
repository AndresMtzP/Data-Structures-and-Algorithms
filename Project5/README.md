# Project 5 - Calculator Program

## Computer Engineering 260 (Data Structures and Algorithms) at San Diego State University

This program consists of a Binary Search Tree which holds an integer as an element in each Node.
The header file "bst.h" includes the declarations of class BST's public and private members,
as well as the output operator ovrloading function. These public and private members'
descriptions are included in the file "bst.cpp". BST is a friend class of class TreeNode, which
members are declared and described in the file "treenode.h" by means of the inline keyword.
Driver.cpp is the implementation file of the class BST and TreeNode. It is made up of a main
menu where the user can choose what to do with the BST. The functions declared in driver.cpp
are the following:

displayHeader().- Contains two output lines which make up the top part of the Graphic interface frame
displayMenu(BST & b).- Takes in an object of type BST as parameter. Displays the current BST by
                         calling the output operator overloading function. It then outputs the main menu
checkChoice(int maxChoice).- Takes in an int as parameter. This function is used to prompt the user
                             for an int input, and checking that the user's input is between 1 and the
                             the number entered as parameter. This is used for menus where the user
                             must choose a number from a menu given.
main().- Main function, where the implementation of BST and TreeNode takes place.