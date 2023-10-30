#include <iostream>
#include "stack_b.h"
#include <stdexcept>
using namespace std;

Stack_B::Stack_B()
{
    try
    {
        size = 0;
        capacity = 1024;
        stk = new int[1024];
    }
    catch (bad_alloc)
    {
        throw runtime_error("Out of Memory");
    }
}

Stack_B::~Stack_B()
{
    delete [] stk;
}

void Stack_B::push(int data)
{
    try
    {
        if (size >= capacity)
        {
            int *v = new int[capacity * 2];
            for (int i = 0; i < size; i++)
            {
                v[i] = stk[i];
            }
            delete [] stk;
            stk = v;
            capacity *= 2;
        }
        stk[size] = data;
        size++;
        return;
    }
    catch (bad_alloc)
    {
        throw runtime_error("Out of Memory");
    }
}

int Stack_B::pop()
{
    try
    {
        if (size == 0)
        {
            throw runtime_error("Empty Stack");
        }
        if ((size < capacity / 4) && capacity >= 4096)
        {
            int *v = new int[capacity / 2];
            for (int i = 0; i < size; i++)
            {
                v[i] = stk[i];
            }
            delete [] stk;
            stk = v;
            capacity /= 2;
        }
        int temp = stk[size-1];
        size--;
        return temp;
    }
    catch (bad_alloc)
    {
        throw runtime_error("Out of Memory");
    }
}

int Stack_B::get_element_from_top(int idx)
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

int Stack_B::get_element_from_bottom(int idx)
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

void Stack_B::print_stack(bool top_or_bottom)
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

int Stack_B::add()
{
    try
    {
        if (size < 2)
        {
            throw runtime_error("Not Enough Arguments");
        }
        if ((size < capacity / 4) && capacity >= 4096)
        {
            int *v = new int[capacity / 2];
            for (int i = 0; i < size; i++)
            {
                v[i] = stk[i];
            }
            delete [] stk;
            stk = v;
            capacity /= 2;
        }
        int temp = stk[size - 1] + stk[size - 2];
        stk[size - 2] = temp;
        size--;
        return temp;
    }
    catch (bad_alloc)
    {
        throw runtime_error("Out of Memory");
    }
}

int Stack_B::subtract()
{
    try
    {
        if (size < 2)
        {
            throw runtime_error("Not Enough Arguments");
        }
        if ((size < capacity / 4) && capacity >= 4096)
        {
            int *v = new int[capacity / 2];
            for (int i = 0; i < size; i++)
            {
                v[i] = stk[i];
            }
            delete [] stk;
            stk = v;
            capacity /= 2;
        }
        int temp = stk[size - 2] - stk[size - 1];
        stk[size - 2] = temp;
        size--;
        return temp;
    }
    catch (bad_alloc)
    {
        throw runtime_error("Out of Memory");
    }
}

int Stack_B::multiply()
{
    try
    {
        if (size < 2)
        {
            throw runtime_error("Not Enough Arguments");
        }
        if ((size < capacity / 4) && capacity >= 4096)
        {
            int *v = new int[capacity / 2];
            for (int i = 0; i < size; i++)
            {
                v[i] = stk[i];
            }
            delete [] stk;
            stk = v;
            capacity /= 2;
        }
        int temp = (stk[size - 2]) * (stk[size - 1]);
        stk[size - 2] = temp;
        size--;
        return temp;
    }
    catch (bad_alloc)
    {
        throw runtime_error("Out of Memory");
    }
}

int Stack_B::divide()
{
    try
    {
        if (size < 2)
        {
            throw runtime_error("Not Enough Arguments");
        }
        if (stk[size - 1] == 0)
        {
            throw runtime_error("Divide by Zero Error");
        }
        if ((size < capacity / 4) && capacity >= 4096)
        {
            int *v = new int[capacity / 2];
            for (int i = 0; i < size; i++)
            {
                v[i] = stk[i];
            }
            delete [] stk;
            stk = v;
            capacity /= 2;
        }
        int temp = (stk[size - 2]) / (stk[size - 1]);
        if (((stk[size - 2]) * (stk[size - 1])) < 0 && (((stk[size - 1])*temp)!=(stk[size - 2])))
        {
            temp--;
        }
        stk[size - 2] = temp;
        size--;
        return temp;
    }
    catch (bad_alloc)
    {
        throw runtime_error("Out of Memory");
    }
}

int *Stack_B::get_stack()
{
    return stk;
}

int Stack_B::get_size()
{
    return size;
}