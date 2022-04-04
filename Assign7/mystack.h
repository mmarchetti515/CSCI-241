//************************************************
//
// mystack.h
// CSCI 241 Assignment 8
//
// Michael Marchetti z1860574
//
//************************************************

#ifndef MYSTACK_H
#define MYSTACK_H

struct node
{
    int value;
    node* next;

    node (int value, node* next = nullptr)
    {
        this->value = value;
        this->next = next;
    }
};

class mystack
{
private:

    node* stk_top = nullptr;
    size_t stk_size = 0;
    
    char* stk_array_ptr = nullptr;  // stack array pointer, needs to be changed
    size_t stk_capacity = 0;  // stack capacity
    size_t stk_size = 0;  // stack size

public:

    mystack();
    mystack(const mystack&);
    mystack& operator=(const mystack&);
    ~mystack();

    size_t size() const;
    bool empty() const;
    void clear();
    const int& top() const;
    void push(int);
    void pop();

    void clone(const mystack&);
};

#endif // MYSTACK_H