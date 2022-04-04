//************************************************
//
// mystack.h
// CSCI 241 Assignment 7
//
// Michael Marchetti z1860574
//
//************************************************

#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <cstddef>
#include <stack>

// Declaring class
class mystack
{
    private:

        // Data members

        char* stk_array_ptr = nullptr;  // stack array pointer, needs to be changed
        size_t stk_capacity = 0;  // stack capacity
        size_t stk_size = 0;  // stack size

    public:
        // Member functions
        
        mystack() = default;  // default constructor
        mystack(const mystack&);  // copy constructor

        ~mystack();  // should delete the stack array (use pop in a for loop?)
        mystack& operator=(const mystack &x);  // 
        size_t capacity() const;  // should return stack capacity
        size_t size() const;  // should return stack size
        bool empty() const;  // return true if stack size 0
        void clear();  // set stack size back to 0
        void reserve(size_t n);  // modify stack object capacity only
        const char& top() const;  // return the top item in the stack
        void push(char value);  // push the character value onto the top of the stack
        void pop();  // decrease the stack size by 1

};
#endif // MYSTACK_H
