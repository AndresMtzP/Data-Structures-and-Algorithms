/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Class TreeNode
//
// Public members:
// -TreeNode().- default constructor
// -TreeNode(treeElement n, TreeNode* L=NULL, TreeNode* R=NULL) - Explicit value constructor
// -TreeNode(const TreeNode & t) - Copy constructor
// -TreeNode & operator=(const TreeNode & righthand) - Assignment operator overloading function
// -getData() const {return myData;} - returns value of type treeElement which is int in this case
// -getDig(){return numOfDigits;} - Returns the number of digits of each of the trees ints, for display purposes
// -getLeft() const {return *leftChild;} - Returns an object of type TreeNode.
// -getRight() const {return *rightChild;} - Returns an object of type TreeNode
// -calcDig(int num) - Calculates the digits of an int, used at the cosntructor to intialize one of the private members
//
// Private members:
// -TreeElement myData.- Variable myData holds treeElement, in this case and int
// -int numOfDigits.- Holds int, the number of digits in the node's int
// -leftChild and RightChild, both are TreeNode*
//
// Program 5 BST
// COMPE 260
// Programmer: Andres Martinez Paz
// RedID: 819505668
//////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED

typedef int treeElement; //define every instance of treeElement as int

//Declaration of class TreeNode
class TreeNode
{
    friend class BST; //Make class BST a friend of this class

    //public members of class BST
    public:

        /*////////////////////////////////////////////////////////////////////////////
        //TreeNode() - default constructor
        ////////////////////////////////////////////////////////////////////////////*/
        TreeNode();

        /*////////////////////////////////////////////////////////////////////////////
        //TreeNode(treeElement n, TreeNode* L=NULL, TreeNode* R=NULL) - Explicit value
        //constructor
        ////////////////////////////////////////////////////////////////////////////*/
        TreeNode(treeElement n, TreeNode* L=NULL, TreeNode* R=NULL);

        /*////////////////////////////////////////////////////////////////////////////
        //TreeNode(const TreeNode & t) - Copy constructor
        ////////////////////////////////////////////////////////////////////////////*/
        TreeNode(const TreeNode & t);

        /*////////////////////////////////////////////////////////////////////////////
        //TreeNode & operator=(const TreeNode & righthand) - Assignment operator
        //overloading function
        ////////////////////////////////////////////////////////////////////////////*/
        TreeNode & operator=(const TreeNode & righthand);

        /*////////////////////////////////////////////////////////////////////////////
        //getData() const {return myData;} - accessor to get data in node
        ////////////////////////////////////////////////////////////////////////////*/
        treeElement getData() const {return myData;};

        /*////////////////////////////////////////////////////////////////////////////
        //getDig(){return numOfDigits;} - accessor to get number of digits of data in
        //Node
        ////////////////////////////////////////////////////////////////////////////*/
        int getDig(){return numOfDigits;};

        /*////////////////////////////////////////////////////////////////////////////
        //getLeft() const {return *leftChild;} accessor to get Node being pointed at
        //by leftChild
        ////////////////////////////////////////////////////////////////////////////*/
        TreeNode & getLeft() const {return *leftChild;};

        /*////////////////////////////////////////////////////////////////////////////
        //getRight() const {return *leftChild;} accessor to get Node being pointed at
        //by rightChild
        ////////////////////////////////////////////////////////////////////////////*/
        TreeNode & getRight() const {return *rightChild;};

        /*////////////////////////////////////////////////////////////////////////////
        //calcDig(int num) - Calculate number of digits of an int
        ////////////////////////////////////////////////////////////////////////////*/
        int calcDig(int num);

    //Private data members of class BST
    private:
        typedef TreeNode* tNodePtr;  //define every instance of tNodePtr as TreeNode*
        treeElement myData;  //myData holds treeElement, in this case an int
        int numOfDigits;     //numOfDigits holds number of digits of myData
        tNodePtr leftChild,  //leftchild and rightchild point to the node children of the node
                rightChild;
};

/*////////////////////////////////////////////////////////////////////////////
//TreeNode() - default constructor
////////////////////////////////////////////////////////////////////////////*/
inline TreeNode::TreeNode()
{
    leftChild = NULL;  //set each child to NULL
    rightChild = NULL;
}

/*////////////////////////////////////////////////////////////////////////////
//TreeNode(treeElement n, TreeNode* L=NULL, TreeNode* R=NULL) - Explicit value
//constructor
////////////////////////////////////////////////////////////////////////////*/
inline TreeNode::TreeNode(treeElement n, tNodePtr L, tNodePtr R)
                :myData(n), leftChild(L), rightChild(R), numOfDigits(calcDig(n)) //initialization of private members
{}

////////////////////////////////////////////////////////////////////////////
//TreeNode(const TreeNode & t) - Copy constructor
////////////////////////////////////////////////////////////////////////////*/
inline TreeNode::TreeNode(const TreeNode & t)
{
    myData=t.getData();   //copy the data of parameter into new object of type TreeNode
    leftChild=&(t.getLeft());
    rightChild=&(t.getRight());
    numOfDigits=calcDig(myData);
}

/*////////////////////////////////////////////////////////////////////////////
//calcDig(int num) - Calculate number of digits of an int
////////////////////////////////////////////////////////////////////////////*/
inline int TreeNode::calcDig(int num)
{
    int numD=0;  //declare and set new int variable to zero
    int i=num;   //declare and set new int variable to parameter's value
    if(i<0)   //check if i is negative
    {
        i=-i;    //if it is, set t to positive
        numD++;  //add one to the digit counter
    }

    while(i>=1)  //while loop keeps running while i is less than or equal to 1
    {
        i=i/10;  //at every cycle, divide i by ten
        numD++;  //increase the digit counter by one
    }
    return numD;  //return digit counter
}

/*////////////////////////////////////////////////////////////////////////////
//TreeNode & operator=(const TreeNode & righthand) - Assignment operator
//overloading function
////////////////////////////////////////////////////////////////////////////*/
inline TreeNode & TreeNode::operator=(const TreeNode &righthand)
{
    if(this==&righthand)  //check if both sides of assignment opertaor are the same
        return *this;    //if so, return the left hand side
    delete this;   //delete whatever is on the left hand side of operator

    return *new TreeNode(righthand);  //create new object of type TreeNode by calling copy constructor, with righthandside as argument
}

#endif // TREENODE_H_INCLUDED
