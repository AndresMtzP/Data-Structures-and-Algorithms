/*////////////////////////////////////////////////////////////////////////////////////////////////////////
// Class BST
//
// Public members of Class BST:
// -BST().- Default constructor
// -~BST().- Destructor
// -empty().- returns true if myRoot points to NULL, false otherwise
// -insertNode(const TreeElement & data).- takes in an object by reference of type TreeElement, which is int
//                  in this case, as parameter. Inserts a new Node with the parameters data into the tree
// -deleteNode(const TreeElement & data).- takes in an object by reference of type TreeElement, which is int
//                  in this case, as parameter. Searches for and deletes the node with the parameter's data
// -search(const treeElement & data).- takes in an object by reference of type TreeElement, which is int
//                  in this case, as parameter. searches for the node with the parameter's data. outputs
//                  "item was found" or "item was not found"
// -inorder, preorder, postorder(ostream & out).- Traverses the tree and outputs each element in three different
//                  orders.
// -display(ostream & o).- displays the elements in the BST by calling function "Inorder"
// -graph(ostream & out) const.- Displays the elements of the BST in an organized manner, to show a graphical
//                  representation of the Binary Search Tree
//
//  Private members:
// -tNodePtr myRoot.- declaration of pointer variable myRoot. tNodePtr is typedef to TreeNode*
// -destructAux.- aids the destructor.
// -searchAux.- Aids the search function
// -inorderAux, preorderAux, and postorderAux.- aid each of the traversal functions respectively
// -graphAux.- aids the function graph
//
// Class BST also has an output operator overloading function
//
// Program 5 BST
// COMPE 260
// Programmer: Andres Martinez Paz
// RedID: 819505668
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>   //Include input/output stream library
#include <stdio.h>    //Include Std input/output manipulation library
#include <stdlib.h>   //Include std general library
#include <iomanip>    //Include Input/output manipulation library
#include "bst.h"      //include header file "bst.h"

/*///////////////////////////////////////////////////////////
//BST() - Default constructor
///////////////////////////////////////////////////////////*/
BST::BST()
    :myRoot(NULL)  //initialize myRoot to point to NULL
{
}

/*///////////////////////////////////////////////////////////
//~BST() - Destructor
///////////////////////////////////////////////////////////*/
BST::~BST()
{
    if(!empty())   //check if the tree is empty
        destructAux(myRoot);   //if so, call destructAux() with myRoot as parameter
}

/*///////////////////////////////////////////////////////////
//empty() - returns true if myRoot points to NULL, false otherwise
///////////////////////////////////////////////////////////*/
bool BST::empty() const
{
    return myRoot==NULL;
}

/*///////////////////////////////////////////////////////////
//insertNode(const TreeElement & data).- takes in an object
//by reference of type TreeElement, which is int in this case,
//as parameter. Inserts a new Node with the parameters data
//into the tree
///////////////////////////////////////////////////////////*/
void BST::insertNode(const treeElement & data)
{
    tNodePtr locptr=myRoot,   //declare new objects of type tNodePtr, set first to myRoot, second to NULL
             parent=NULL;
    bool found=false;     //new boolean object found set to false
    while(!found && locptr!=0)    //keep running while found is false, and while locptr is not pointing to NULL
    {
        parent=locptr;   //set parent to point to same node as locptr
        if(locptr->myData==data)   //check if the data in locptr is equal to the parameter
            found=true;           //if so, set found to true
        else if(locptr->myData>data)  //else, check if the data in locptr is greater than the parameter
            locptr=locptr->leftChild;   //if so, set locptr to point to its leftchild
        else if(locptr->myData<data)   //else, check if the data in locptr is less than the parameter
            locptr=locptr->rightChild;   //if so, set locptr to point to its rightchild
    }
    if(!found)   //check if found is still false
    {
        locptr=new TreeNode(data);  //if so, construct new node with the parameter as parameter and set locptr to point to it

        if(parent==NULL)  //check if parent ptr is pointing to NULL, if so, locptr has no parent, meaning it should be the main root
        {
            myRoot=locptr;   //if so, set myRoot to locptr
        }else if(data<parent->myData){  //else, check if the parameter is less than the data in parent
            parent->leftChild=locptr;  //if so, set parent's leftchild to point to newly created node
        }else
            parent->rightChild=locptr;  //else, set parent's rightchild to point to newly created node

    }else{   //if found is true, then the node already exists, therefore display error message
        cout<<setw(70)<<"//           ***Item already exists in tree***            //"<<endl;
    }
}

/*///////////////////////////////////////////////////////////
//deleteNode(const TreeElement & data).- takes in an object
//by reference of type TreeElement, which is int in this case,
//as parameter. Searches for and deletes the node with the
//parameter's data
///////////////////////////////////////////////////////////*/
void BST::deleteNode(const treeElement & data)
{
    tNodePtr delptr,   //declare new tNodePtr variables, one called delptr, which will point to the object to be deleted,
              parent;   //the other parent, will point to that node's parent node
    bool found;  //declare new bool found

    BST::searchAux(data, found, delptr, parent);  //call function searchAux, to set variable found to either true or false

    if(found){   //check if found is true
        if(delptr->leftChild!=NULL && delptr->rightChild!=NULL){  //check if delptr has both children nodes

            tNodePtr succDelPtr=delptr->rightChild;   //if so, dcelare new tNodePtr and set it to point to delptr's rightchild
            parent=delptr;   //set parent to point to delptr
            while(succDelPtr->leftChild!=NULL)   //Traverse the tree until the leftchild points to NULL
            {
                parent=succDelPtr;   //set parent to point to succDelPtr
                succDelPtr=succDelPtr->leftChild;  //set succDelPtr to point to its left child
            }

            delptr->myData=succDelPtr->myData;  //copy down the data from succdelPtr into delptr's mydata
            delptr=succDelPtr;  //set delptr to point to suuDelPtr
        }
        tNodePtr subtree=delptr->leftChild;   //declare new tNodePtr subtree and set it to point to delptr's left child

        if(subtree==NULL)   //check if subtree points to NULL
            subtree=delptr->rightChild;  //if so, set subtree to point to delptr's leftchild
        if(parent==NULL)   //check if parent points to NULL
            myRoot=subtree;  //if so, set myRoot to point to subtree
        else if(parent->leftChild==delptr)   //else, check if delptr is parent's leftChild
            parent->leftChild=subtree;   //if so, set parent's leftchild to point to subtree
        else
            parent->rightChild=subtree;  //else, set parent's rightchild to point to subtree
        delete delptr;   //delete the node which delptr id pointing to
        //display confirmation that the node has been deleted
        cout<<setw(70)<<"//               Element has been deleted                 //"<<endl;
    }else{
        //if found is false, the element doesn't exist, so display error message
        cout<<setw(70)<<"//   ***The element you wish to delete does not exist***  //"<<endl;
    }
}

/*///////////////////////////////////////////////////////////
//search(const treeElement & data).- takes in an object by
//reference of type TreeElement, which is int in this case,
//as parameter. searches for the node with the parameter's
//data. outputs "item was found" or "item was not found"
///////////////////////////////////////////////////////////*/
bool BST::search(const treeElement & data)
{
    tNodePtr locptr,   //declare new tNodePtr variable locptr and parent
              parent;
    bool found;     //bool variable found
    searchAux(data, found, locptr, parent);  //call function search Aux to set found to true or false
    if(found)  //check if found id true, if so displya message saying object was found
        cout<<setw(70)<<"//                     Item was found!                    //"<<endl;
    else   //else display message saying it was not found
        cout<<setw(70)<<"//                   Item was not found.                  //"<<endl;
    return found;   //return the value of found
}

/*///////////////////////////////////////////////////////////
//inorder(ostream & out) - Traverses the tree and outputs
//each element in inorder fashion
///////////////////////////////////////////////////////////*/
void BST::inorder(ostream & out)
{
    if(!empty())  //check if tree is empty
    {
        out<<setw(13)<<"// ";
        int count=0;   //set new int variable count to zero, this is used for display purposes
        inorderAux(out, count, myRoot);  //call inorderAux with the appropriate data
        for(int i=0; i<55-count; i++)  //for loop to keep the graphic interface organized
            out<<" ";   //keep outputting the necessary spaces
        out<<"//"<<endl;
    }else   //if tree is empty, output error message
        out<<setw(70)<<"//                ***The tree is empty***                 //"<<endl;
}

/*///////////////////////////////////////////////////////////
//preorder(ostream & out) - Traverses the tree and outputs
//each element in preorder fashion
///////////////////////////////////////////////////////////*/
void BST::preorder(ostream & out)
{
    if(!empty())   //check if tree is empty
    {
        out<<setw(13)<<"// ";
        int count=0;   //set new int variable counter to zero
        preorderAux(out, count, myRoot);   //call function preorderAux with the appropriate info
        for(int i=0; i<55-count; i++)    //for loop to keep graphic interface organized
            out<<" ";  //keep outputting the necessary spaces
        out<<"//"<<endl;
    }else   //if tree is empty, output error message
        out<<setw(70)<<"//                ***The tree is empty***                 //"<<endl;
}

/*///////////////////////////////////////////////////////////
//postorder(ostream & out) - Traverses the tree and outputs
//each element in postorder fashion
///////////////////////////////////////////////////////////*/
void BST::postorder(ostream & out)
{
    if(!empty())   //check if tree is empty
    {
        out<<setw(13)<<"// ";
        int count=0;   //set new int variable count to zero
        postorderAux(out, count, myRoot);   //call function postorderAux with appropriate data
        for(int i=0; i<55-count; i++)  //for loop to keep graphic interface organized
            out<<" ";
        out<<"//"<<endl;
    }else   //if tree is empty, output error message
         out<<setw(70)<<"//                ***The tree is empty***                 //"<<endl;
}

/*///////////////////////////////////////////////////////////
//display(ostream & o) - displays the elements in the BST by
//calling function "Inorder"
///////////////////////////////////////////////////////////*/
void BST::display(ostream & out)
{
    if(!empty())  //check if tree is empty
    {
        out<<setw(13)<<"// ";
        int count=0;   //set new int variable to zero
        inorderAux(out, count, myRoot);   //call function inorderAux with the appropriate data
        for(int i=0; i<55-count; i++)   //for loop to keep graphic interface organized
            out<<" ";   //keep outputting the necessary spaces
        out<<"//"<<endl;
    }else    //if tree is empty, output error message
         out<<setw(70)<<"//                ***The tree is empty***                 //"<<endl;
}

/*///////////////////////////////////////////////////////////
//graph(ostream & out) const - Displays the elements of the
//BST in an organized manner, to show a graphical
//representation of the Binary Search Tree
///////////////////////////////////////////////////////////*/
void BST::graph(ostream & out) const
{
    graphAux(out, 11, myRoot);  //call function graphAux with the appropriate parameters
}

/*///////////////////////////////////////////////////////////
//destructAux(tNodePtr destNode) - To be used by destructor
///////////////////////////////////////////////////////////*/
void BST::destructAux(tNodePtr destNode)
{
    if(destNode->leftChild!=NULL)   //check if parameter node has a left child
    {
        destructAux(destNode->leftChild);  //if it does, recursively call function destAux with the node's leftChild as parameter
    }

    if(destNode->rightChild!=NULL)  //check if parameter node has a rightChild
    {
        destructAux(destNode->rightChild);  //if it does, recursively call function destAux with the node's rightChild as parameter
    }

    delete destNode;   //delete the node that is being pointed to by parameter node, destNode

}

 /*///////////////////////////////////////////////////////////
//searchAux(const treeElement & data, bool & found,
//            tNodePtr & locptr, tNodePtr & parent)
//To be used by search function
///////////////////////////////////////////////////////////*/
void BST::searchAux(const treeElement & data, bool & found,
                                  tNodePtr & locptr, tNodePtr & parent)
{
    locptr=myRoot;   //set parameter tNodePtr object locptr to myRoot
    parent=NULL;   //set parameter tNodePtr object parent to point to NULL
    found=false;   //set parameter bool object to false

    while(!found && locptr!=NULL)  //keep running while found is false and locptr is not pointing to NULL
    {

        if(locptr->myData>data){    //check if locptr's myData is greater than parameter data
            parent=locptr;   //if so, set parent to point to locptr
            locptr=locptr->leftChild;  //set locptr to point to its leftChild
        }else if(locptr->myData<data){   //check if locptr's myData is less than parameter data
            parent=locptr;   //if so, set parent to point to locptr
            locptr=locptr->rightChild;    //set locptr to point to its rightChild
        }else
            found=true;  //else, if locptr's myData is equal to parameter data, set found to true
    }
}


/*///////////////////////////////////////////////////////////
//inorderAux(ostream & out, int & currentCount, tNodePtr subRoot)
//To be used by inorder function
///////////////////////////////////////////////////////////*/
void BST::inorderAux(ostream & out, int & currentCount, tNodePtr subroot)
{
    if(subroot->leftChild!=NULL)   //check if subroot's leftChild is pointing to NULL
        inorderAux(out, currentCount, subroot->leftChild);   //if so, recursively call inorderAux with subroot's left child as parameter

    //the following if statement is used for display purposes
    if(currentCount>53-subroot->getDig())  //check if the next number will be longer than the established width of the frame
    {
        for(int i=0; i<55-currentCount; i++)   //if so, for loop will finish displaying the frame
            out<<" ";   //keep displaying spaces
        out<<"//"<<endl;    //display right end of frame and wrap around to next line of display
        out<<setw(13)<<"// ";   //display left part of frame
        currentCount=0;   //reset the count to zero
    }
    out<<subroot->myData<<" ";    //display the node's data
    currentCount=currentCount+subroot->getDig()+1;    //add the number of digits of the number displayed to the current count
    if(subroot->rightChild!=NULL)    //check if subroot has a rightChild
        inorderAux(out, currentCount, subroot->rightChild);   //if so, recursively call function inorderAux with subroot's right child as parameter
}

/*///////////////////////////////////////////////////////////
//preorderAux(ostream & out, int & currentCount, tNodePtr subRoot)
//To be used by preorder function
///////////////////////////////////////////////////////////*/
void BST::preorderAux(ostream & out, int & currentCount, tNodePtr subroot)
{
    //the following if statement is used for display purposes
    if(currentCount>53-subroot->getDig())   //check if the next number will be longer than the established width of the frame
    {
        for(int i=0; i<55-currentCount; i++)   //if so, for loop will finish displaying the frame
            out<<" ";   //keep displaying spaces
        out<<"//"<<endl;   //display right end of frame and wrap around to next line of display
        out<<setw(13)<<"// ";   //display left part of frame
        currentCount=0;    //reset the count to zero
    }
    out<<subroot->myData<<" ";    //display the node's data
    currentCount=currentCount+subroot->getDig()+1;    //add the number of digits of the number displayed to the current count
    if(subroot->leftChild!=NULL) //check if subroot's leftChild is pointing to NULL
        preorderAux(out, currentCount, subroot->leftChild);   //if so, recursively call preorderAux with subroot's left child as parameter
    if(subroot->rightChild!=NULL)  //check if subroot has a rightChild
        preorderAux(out, currentCount, subroot->rightChild);  //if so, recursively call function preorderAux with subroot's right child as parameter
}

/*///////////////////////////////////////////////////////////
//postorderAux(ostream & out, int & currentCount, tNodePtr subRoot)
//To be used by postorder function
///////////////////////////////////////////////////////////*/
void BST::postorderAux(ostream & out, int & currentCount, tNodePtr subroot)
{
    if(subroot->leftChild!=NULL) //check if subroot's leftChild is pointing to NULL
        postorderAux(out, currentCount, subroot->leftChild);   //if so, recursively call postorderAux with subroot's left child as parameter
    if(subroot->rightChild!=NULL)  //check if subroot has a rightChild
        postorderAux(out, currentCount, subroot->rightChild);  //if so, recursively call function postorderAux with subroot's right child as parameter

    //the following if statement is used for display purposes
    if(currentCount>53-subroot->getDig())   //check if the next number will be longer than the established width of the frame
    {
        for(int i=0; i<55-currentCount; i++) //if so, for loop will finish displaying the frame
            out<<" ";   //keep displaying spaces
        out<<"//"<<endl;   //display right end of frame and wrap around to next line of display
        out<<setw(13)<<"// ";   //display left part of frame
        currentCount=0;    //reset the count to zero
    }
    out<<subroot->myData<<" ";    //display the node's data
    currentCount=currentCount+subroot->getDig()+1;    //add the number of digits of the number displayed to the current count
}

/*///////////////////////////////////////////////////////////
//graphAux(ostream & out, int indent, tNodePtr subroot) const
//To be used by graph function
///////////////////////////////////////////////////////////*/
void BST::graphAux(ostream & out, int indent, tNodePtr subroot) const
{
    if(subroot!=NULL)  //check that subroot does not point to NULL
    {
        graphAux(out, indent + 6, subroot->rightChild);   //recursively call graphAux with subroot's right child, and increase indent parameter by 6
        if(subroot->myData==myRoot->myData)  //check if the node to be displayed is the main root
            {
                out<<"Main Root->";  //if it is, display a message to identify the root in the graph
                out<< " " << subroot->myData<<endl;  //display the data in the node
            }else
                out << setw(indent) << " " << subroot->myData << endl;  //else, display the data in the node with the proper indent
        graphAux(out, indent + 6, subroot->leftChild);  //recursively call graphAux, with subroot's left child as parameter and increase indent by 6
    }
}

/*///////////////////////////////////////////////////////////
//output operator overloading function
///////////////////////////////////////////////////////////*/
ostream & operator<<(ostream & o, BST & t)
{
    t.display(o);  //call function display on BST object t, with ostream object o as parameter
    return o;    //return ostream object o
}
