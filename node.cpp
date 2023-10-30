#include <iostream>
#include <stdexcept>
#include "node.h"
using namespace std;

// Use to construct a sentinel node (see list.h)
Node::Node(bool sentinel)
{
    is_sentinel=true;
    next=NULL;
    prev=NULL;
}

// Use to construct a regular node
Node::Node(int v, Node *nxt, Node *prv)
{
    value=v;
    is_sentinel=false;
    next=nxt;
    prev=prv;
}

// Return whether a node is a sentinel node
// Use it to check if we are at the ends of a list
bool Node::is_sentinel_node()
{
    if(is_sentinel){
        return true;
    }
    return false;
}

// Return the value of a node
int Node::get_value()
{
    return value;
}