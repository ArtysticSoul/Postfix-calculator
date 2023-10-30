#include <iostream>
#include <stdexcept>
#include "stack_c.h"
using namespace std;

// Constructor
Stack_C::Stack_C()
{
    try
    {
        stk = new List();
    }
    catch (bad_alloc)
    {
        throw runtime_error("Out of Memory");
    }
}

// Destructor
Stack_C::~Stack_C()
{
    delete stk;
}

void Stack_C::push(int data)
{
    stk->insert(data);
}

int Stack_C::pop()
{
    return stk->delete_tail();
}

int Stack_C::get_element_from_top(int idx)
{
    int sz = stk->get_size();
    if (idx >= sz)
    {
        throw runtime_error("Index out of range");
    }
    else
    {
        int i = sz;
        Node *temp = stk->get_head();
        while (i > idx)
        {
            temp = temp->next;
            i--;
        }
        return temp->get_value();
    }
}

int Stack_C::get_element_from_bottom(int idx)
{
    int sz = stk->get_size();
    if (idx >= sz)
    {
        throw runtime_error("Index out of range");
    }
    else
    {
        int i = 0;
        Node *temp = stk->get_head();
        while (i < idx)
        {
            temp = temp->next;
            i++;
        }
        return temp->next->get_value();
    }
}

void Stack_C::print_stack(bool top_or_bottom)
{
    int sz = stk->get_size();
    if (sz == 0)
    {
        return;
    }
    if (top_or_bottom)
    {
        int i = 0;
        Node *temp = (stk->get_head())->next;
        while (i < sz)
        {
            int result = temp->get_value();
            cout << result << endl;
            temp = temp->next;
            i++;
        }
        return;
    }
    else
    {
        Node *temp = (stk->get_head())->next;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        while (temp->prev != NULL)
        {
            temp = temp->prev;
            if (temp->prev != NULL)
            {
                int result = temp->get_value();
                cout << result << endl;
            }
        }
        return;
    }
}

int Stack_C::add()
{
    int sz = stk->get_size();
    if (sz < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int e1=stk->delete_tail();
        int e2=stk->delete_tail();
        int result = e1+e2;
        stk->insert(result);
        return result;
    }
}

int Stack_C::subtract()
{
    int sz = stk->get_size();
    if (sz < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int e1=stk->delete_tail();
        int e2=stk->delete_tail();
        int result = e2-e1;
        stk->insert(result);
        return result;
    }
}

int Stack_C::multiply()
{
    int sz = stk->get_size();
    if (sz < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int e1=stk->delete_tail();
        int e2=stk->delete_tail();
        int result = e1*e2;
        stk->insert(result);
        return result;
    }
}

int Stack_C::divide()
{
    int sz = stk->get_size();
    if (sz < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int e1=stk->delete_tail();
        int e2=stk->delete_tail();
        if (e1 == 0)
        {
            stk->insert(e2);
            stk->insert(e1);
            throw runtime_error("Divide by Zero Error");
        }
        int result =e2/e1;
        if((e2 * e1)<0 && ((e1*result)!=e2)){
            result--;
        }
        stk->insert(result);
        return result;
    }
}

List *Stack_C::get_stack()
{
    return stk;
} // Get a pointer to the linked list representing the stack

int Stack_C::get_size()
{
    return stk->get_size();
} // Get the size of the stack