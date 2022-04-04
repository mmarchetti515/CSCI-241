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

// define struct node
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

    // data members
    node* stk_top = nullptr;
    size_t stk_size = 0;

public:

    // member functions
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
