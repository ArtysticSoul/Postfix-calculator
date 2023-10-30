#include <iostream>
#include <stdexcept>
#include "list.h"
using namespace std;

List::List()
{
    try
    {
        sentinel_head = new Node();
        sentinel_tail = new Node();
        size = 0;
        sentinel_head->next = sentinel_tail;
        sentinel_tail->prev = sentinel_head;
    }
    catch (bad_alloc)
    {
        throw runtime_error("Out of Memory");
    }
}

List::~List()
{
    while (sentinel_head->next != sentinel_tail)
    {
        Node*temp=sentinel_head->next;
        sentinel_head->next=temp->next;
        temp->next->prev=sentinel_head;
        temp->prev=NULL;
        temp->next=NULL;
        delete temp;
    }
    delete sentinel_head;
    delete sentinel_tail;
}

// Insert an element at the tail of the linked list
void List::insert(int v)
{
    try
    {
        Node* temp = new Node(v, NULL, NULL);
        sentinel_tail->prev->next=temp;
        temp->prev=sentinel_tail->prev;
        sentinel_tail->prev=temp;
        temp->next=sentinel_tail;
        size++;
    }
    catch (bad_alloc)
    {
        throw runtime_error("Out of Memory");
    }
}

// Delete the tail of the linked list and return the value
// You need to delete the valid tail element, not the sentinel
int List::delete_tail()
{
    if(size>0){
        Node* temp=sentinel_tail->prev;
        int result=temp->get_value();
        sentinel_tail->prev=temp->prev;
        temp->prev->next=sentinel_tail;
        temp->prev=NULL;
        temp->next=NULL;
        delete temp;
        size--;
        return result;
    }
    throw runtime_error("Empty Stack");
}

// Return the size of the linked list
// Do not count the sentinel elements
int List::get_size()
{
    return size;
}

// Return a pointer to the sentinel head of the linked list
Node *List::get_head()
{
    return sentinel_head;
}