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

// default constructor
mystack::mystack()
{
    // set stack size to 0
    stk_size = 0;
    // set stack top to the null pointer
    stk_top = nullptr;
}

// copy constructor
mystack::mystack(const mystack &x)
{
    // set the new stack object's list to empty
    stk_top = nullptr;

    //  copy the other stack's size
    stk_size = x.stk_size;

    // copy the other stack's linked list, calls clone with parameter x
    clone(x);   
}

// copies the linked list from the stack x to this object
void mystack::clone(const mystack& x)
{
    // set ptr to last to the nullptr
    node *last = nullptr;
    // set stack array ptr to the 
    node *ptr = x.stk_top;

    // code obtained from lecture notes
    // checking for the stack array pointer to not be equal to the nullptr
    while(ptr != nullptr)
    {
        // allocate new stack node
        node *new_node = new node (ptr->value);

        //  checking for the last value to be equal to nullptr
        if(last == nullptr)
        {
            stk_top = new_node;
        }
        // otherwise have last node point to next and set to new node
        else
        {
            last->next = new_node;
        }
        // set the last node to new node point to next
        last = new_node;
        ptr = ptr->next;
    }
}

// delete the stack array
mystack::~mystack()
{
    clear();
}

// overloaded copy assignment operator
mystack& mystack::operator=(const mystack& x)
{
    if(this != &x)
    {
        // make the left stack object empty
        clear();

        // copy the other stack's size
        stk_size = x.stk_size;

        // copy the other stack's linked list
        clone(x);
    }
    return *this;
}

// return stack size
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
    // loops through pop function until the stack size is 0x
    while(stk_size > 0)
    {
        pop();
    }
}

// return the top item in the stack
const int& mystack::top() const
{
    return stk_top->value;
}

// push the int value onto the top of the stack
void mystack::push(int value)
{
    // allocate a new stack node
    node* new_node = new node(value, stk_top);
    // set stack top to new node
    stk_top = new_node;
    // increment stack size
    stk_size++;
}

// decrease the stack size by 1
void mystack::pop()
{
    // define the top stack node to delete the top stack node
    node *delete_node;
    delete_node = stk_top;
    stk_top = stk_top->next;
    //delete the node
    delete delete_node;
    // decrement the stack size
    stk_size--;
}
