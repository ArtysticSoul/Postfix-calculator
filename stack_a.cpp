#include <iostream>
#include "stack_a.h"
#include <stdexcept>
using namespace std;

Stack_A::Stack_A()
{
    size = 0;
}

void Stack_A::push(int data)
{
    if (size >= 1024)
    {
        throw runtime_error("Stack Full");
    }
    else
    {
        stk[size] = data;
        size++;
    }
    return;
}

int Stack_A::pop()
{
    if (size == 0)
    {
        throw runtime_error("Empty Stack");
    }
    else
    {
        int temp = stk[size-1];
        size--;
        return temp;
    }
}

int Stack_A::get_element_from_top(int idx)
{
    if (idx >= size)
    {
        throw runtime_error("Index out of range");
    }
    else
    {
        return stk[size - idx - 1];
    }
}

int Stack_A::get_element_from_bottom(int idx)
{
    if (idx >= size)
    {
        throw runtime_error("Index out of range");
    }
    else
    {
        return stk[idx];
    }
}

void Stack_A::print_stack(bool top_or_bottom)
{
    if (size == 0)
    {
        return;
    }
    if (top_or_bottom)
    {
        for (int i = 0; i < size; i++)
        {
            cout << stk[i] << endl;
        }
        return;
    }
    for (int i = 0; i < size; i++)
    {
        cout << stk[size - i - 1] << endl;
    }
    return;
}

int Stack_A::add()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int temp = stk[size - 1] + stk[size - 2];
        stk[size - 2] = temp;
        size--;
        return temp;
    }
}

int Stack_A::subtract()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int temp = stk[size - 2] - stk[size - 1];
        stk[size - 2] = temp;
        size--;
        return temp;
    }
}

int Stack_A::multiply()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int temp = (stk[size - 2]) * (stk[size - 1]);
        stk[size - 2] = temp;
        size--;
        return temp;
    }
}

int Stack_A::divide()
{
    if (size < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        if (stk[size - 1] == 0)
        {
            throw runtime_error("Divide by Zero Error");
        }
        int temp = (stk[size - 2]) / (stk[size - 1]);
        if(((stk[size - 2]) * (stk[size - 1]))<0 && (((stk[size - 1])*temp)!=(stk[size - 2]))){
            temp--;
        }
        stk[size - 2] = temp;
        size--;
        return temp;
    }
}

int *Stack_A::get_stack()
{
    return stk;
}

int Stack_A::get_size()
{
    return size;
}