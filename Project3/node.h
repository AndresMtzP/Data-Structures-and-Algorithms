#include <iostream>
using namespace std;

#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node(int d);
        ~Node();
        Node * getN();
        void setD(int d);
        void setN(Node* n);
        void display(ostream & out);
    private:
        int data;
        Node *next;
};

ostream & operator<<(ostream & o, Node & n);
bool operator==(const Node n1, const Node n2);
#endif // NODE_H
