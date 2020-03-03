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
#include <iostream>  //input/output library
#include "treenode.h"  //include header file "treenode.h"

#ifndef BST_H
#define BST_H

using namespace std;

typedef int treeElement;   //typedef every instance of treeElement as int
typedef TreeNode* tNodePtr;    //typedef every instance of tNodePtr as TreeNode*

//class BST declaration
class BST
{
    //public member functions
    public:
        /*///////////////////////////////////////////////////////////
        //BST() - Default constructor
        ///////////////////////////////////////////////////////////*/
        BST();

        /*///////////////////////////////////////////////////////////
        //~BST() - Destructor
        ///////////////////////////////////////////////////////////*/
        ~BST();

        /*///////////////////////////////////////////////////////////
        //empty() - returns true if myRoot points to NULL, false otherwise
        ///////////////////////////////////////////////////////////*/
        bool empty() const;

        /*///////////////////////////////////////////////////////////
        //insertNode(const TreeElement & data).- takes in an object
        //by reference of type TreeElement, which is int in this case,
        //as parameter. Inserts a new Node with the parameters data
        //into the tree
        ///////////////////////////////////////////////////////////*/
        void insertNode(const treeElement & data);

        /*///////////////////////////////////////////////////////////
        //deleteNode(const TreeElement & data).- takes in an object
        //by reference of type TreeElement, which is int in this case,
        //as parameter. Searches for and deletes the node with the
        //parameter's data
        ///////////////////////////////////////////////////////////*/
        void deleteNode(const treeElement & data);

        /*///////////////////////////////////////////////////////////
        //search(const treeElement & data).- takes in an object by
        //reference of type TreeElement, which is int in this case,
        //as parameter. searches for the node with the parameter's
        //data. outputs "item was found" or "item was not found"
        ///////////////////////////////////////////////////////////*/
        bool search(const treeElement & data);

        /*///////////////////////////////////////////////////////////
        //inorder(ostream & out) - Traverses the tree and outputs
        //each element in inorder fashion
        ///////////////////////////////////////////////////////////*/
        void inorder(ostream & out);

        /*///////////////////////////////////////////////////////////
        //preorder(ostream & out) - Traverses the tree and outputs
        //each element in preorder fashion
        ///////////////////////////////////////////////////////////*/
        void preorder(ostream & out);

        /*///////////////////////////////////////////////////////////
        //postorder(ostream & out) - Traverses the tree and outputs
        //each element in postorder fashion
        ///////////////////////////////////////////////////////////*/
        void postorder(ostream & out);

        /*///////////////////////////////////////////////////////////
        //display(ostream & o) - displays the elements in the BST by
        //calling function "Inorder"
        ///////////////////////////////////////////////////////////*/
        void display(ostream & out);

        /*///////////////////////////////////////////////////////////
        //graph(ostream & out) const - Displays the elements of the
        //BST in an organized manner, to show a graphical
        //representation of the Binary Search Tree
        ///////////////////////////////////////////////////////////*/
        void graph(ostream & out) const;

    //private members of BST
    private:
        //TreeNode* myRoot
        tNodePtr myRoot;

        /*///////////////////////////////////////////////////////////
        //destructAux(tNodePtr destNode) - To be used by destructor
        ///////////////////////////////////////////////////////////*/
        void destructAux(tNodePtr destNode);

        /*///////////////////////////////////////////////////////////
        //searchAux(const treeElement & data, bool & found,
        //            tNodePtr & locptr, tNodePtr & parent)
        //To be used by search function
        ///////////////////////////////////////////////////////////*/
        void searchAux(const treeElement & data, bool & found,
                        tNodePtr & locptr, tNodePtr & parent);

        /*///////////////////////////////////////////////////////////
        //inorderAux(ostream & out, int & currentCount, tNodePtr subRoot)
        //To be used by inorder function
        ///////////////////////////////////////////////////////////*/
        void inorderAux(ostream & out, int & currentCount, tNodePtr subRoot);

        /*///////////////////////////////////////////////////////////
        //preorderAux(ostream & out, int & currentCount, tNodePtr subRoot)
        //To be used by preorder function
        ///////////////////////////////////////////////////////////*/
        void preorderAux(ostream & out, int & currentCount, tNodePtr subRoot);

        /*///////////////////////////////////////////////////////////
        //postorderAux(ostream & out, int & currentCount, tNodePtr subRoot)
        //To be used by postorder function
        ///////////////////////////////////////////////////////////*/
        void postorderAux(ostream & out, int & currentCount, tNodePtr subRoot);

        /*///////////////////////////////////////////////////////////
        //graphAux(ostream & out, int indent, tNodePtr subroot) const
        //To be used by graph function
        ///////////////////////////////////////////////////////////*/
        void graphAux(ostream & out, int indent, tNodePtr subroot) const;
};

/*///////////////////////////////////////////////////////////
//output operator overloading function
///////////////////////////////////////////////////////////*/
ostream & operator<<(ostream & o, BST & t);

#endif // BST_H
