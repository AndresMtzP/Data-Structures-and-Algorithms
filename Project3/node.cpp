#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include "node.h"
using namespace std;

Node::Node(int d)
{
    data=d;
    next=NULL;
}

Node::~Node()
{
}

Node * Node::getN()
{
    return next;
}

void Node::display(ostream & out)
{
    out << data << " ";
    if(next!=NULL)
        next->display(out);
}

void Node::setD(int d)
{
    data = d;
}

void Node::setN(Node * n)
{
    if(n==NULL)
    {
        next=NULL;
    }else{
        next = n;
    }

}

ostream & operator<<(ostream & o, Node & n)
{
    n.display(o);
    return o;
}

bool operator==(const Node n1, const Node n2)
{
    return n1==n2;
}
