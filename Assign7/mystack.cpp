//************************************************
//
// mystack.cpp
// CSCI 241 Assignment 8
//
// Michael Marchetti z1860574
//
//************************************************

#include <iostream>
#include <cstdlib>
#include "mystack.h"

using namespace std;

// copy constructor
mystack::mystack(const mystack &x)
{
    // set the new stack object's list to empty
    stk_top = nullptr;

    //  copy the other stack's size
    stk_size = x.stk_size;

    //copy the other stack's linked list, calls clone 
    clone();   
}

// copies the linked list from the stack x to this object
mystack::clone(const mystack& x)
{
    node *last = nullptr;
    node *ptr = x.stk_top;

    while(stk_array_ptr != nullptr)
    {
        node *new_node = new node (x.stk_size)
        new_node->value = stk_array_ptr->value;

        if(last == nullptr)
        {
            stk_top = new_node;
        }
        else
        {
            last->next = new_node;
        }
        last = new_node;
        stk_array_ptr = stk_array_ptr->next;
    }
}

// should delete the stack array
mystack::~mystack()
{
    delete[] stk_array_ptr;
}

// may need to be looked at
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
    while(stk_size > 0)
    {
        mystack.pop();
    }
}

// return the top item in the stack
const int& mystack::top() const
{
    return stk_array_ptr[stk_size - 1];
}

// push the int value onto the top of the stack
void mystack::push(int value)
{
    int * = new_node;
    
    new_node->value = value;
    new_node->next = stk_top;

    stk_top = new_node;
    stk_size++;
}

// decrease the stack size by 1
void mystack::pop()
{
    delete_node = stk_top;
    stk_top = stk_top->next;

    //delete the node
    delete_node;
    //decrement
    stk_size--;
}