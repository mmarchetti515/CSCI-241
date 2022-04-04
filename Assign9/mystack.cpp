//*******************************************************************
//
//  mystack.cpp
//  CSCI 241 Assignment 7
//
//  Michael Marchetti z1860574
//
//*******************************************************************

#include <iostream>
#include <cstdlib>
#include "mystack.h"

using namespace std;

// copy constructor
mystack::mystack(const mystack &x)
{
    // Size and capacity for the new object equal to the corresponding data members
    // in the new object x
    stk_size = x.stk_size;
    stk_capacity = x.stk_capacity;

    // if stack capacity is zero, set the stack array pointer to nullptr
    if (stk_capacity == 0)
    {
        stk_array_ptr = nullptr;
    }
    // Otherwise, the stack array pointer should point to an array of char with a 
    // number of elements equal to the stack capacity.
    else
    {
        stk_array_ptr = new char[x.stk_capacity];
        for (size_t i = 0; i < stk_capacity; i++)
        {
            stk_array_ptr[i] = x.stk_array_ptr[i];
        }
    }
}

// should delete the stack array
mystack::~mystack()
{
    delete[] stk_array_ptr;
}

// overloaded copy assignment operator
mystack& mystack::operator=(const mystack &x)
{
    // the object that called the member function, which is pointed to by this
    if(this != &x)
    {
        // delete the stack array
	    delete[] stk_array_ptr;

        // perform the same logic as the copy instructor above
        stk_size = x.stk_size;
        stk_capacity = x.stk_capacity;

        if (stk_capacity == 0)
        {
            stk_array_ptr = nullptr;
        }
        else
        {
            stk_array_ptr = new char[x.stk_capacity];
            for (size_t i = 0; i < stk_size; i++)
            {
                stk_array_ptr[i] = x.stk_array_ptr[i];
            }
        }
    }
    // returns pointer to this
    return *this;
}

// should return stack capacity
size_t mystack::capacity() const
{
    return stk_capacity;
}

// should return stack size
size_t mystack::size() const  
{
    return stk_size;
}

// return true if stack size 0
bool mystack::empty() const
{
    bool empty = true;
    // check if size is 0, or empty
    if(stk_size == 0)
    {
        empty = true;
    }
    else
    {
        empty = false;
    }
    // return empty when true
    return empty;
}

// set stack size back to 0
void mystack::clear()
{
    stk_size = 0;
}

// modify stack object capacity only
void mystack::reserve(size_t n) 
{
    // If n is less than the stack size or n is equal to the current stack capacity, simply return
    if(n < stk_size || n == stk_capacity)
    {
        return;
    }
    // set capacity to n
    stk_capacity = n;

    // dynamically allocate an array of char with a size equal to stack capacity
    char* temp = new char[n];
    // for loop allows for dynamic allocation
    for(size_t i = 0; i < stk_size; i++)
    {
        temp[i] = stk_array_ptr[i];
    }
    // delete the stack array
    delete[] stk_array_ptr;

    // Set the stack array pointer to the temporary array pointer.
    stk_array_ptr = temp;
}

// return the top item in the stack
const char& mystack::top() const
{
    return stk_array_ptr[stk_size - 1];
}

// push the character value onto the top of the stack
void mystack::push(char value)
{
    // check if stack size equals stack capacity
    if(stk_size == stk_capacity)
        {
            // check if the capacity is equal to zero, then reserve 1 if true
            if(stk_capacity == 0)
            {
                reserve(1);
            }
            // Otherwise, double the stack capacity
            else
            {
                reserve(stk_capacity * 2);
            }
        }
    // copy value into the stack array as the new top item in the stack
    stk_array_ptr[stk_size] = value;
    // increment stack size
    stk_size++;
}

// decrease the stack size by 1
void mystack::pop()
{
    stk_size--;
}
