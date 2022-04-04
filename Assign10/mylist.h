//**************************************
//
// mylist.h
// CSCI 241 Assignment 10
//
// Michael Marchetti z1860574
//
//**************************************

#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <stdexcept>
#include <cstddef>

// Forward declaration of the mylist template class
template <class T>
class mylist;
        
// Forward declaration of the operator<< template function
template <class T>
std::ostream& operator<<(std::ostream&, const mylist<T>&);

template <class T>
struct node
{
    T value;
    node<T>* prev;
    node<T>* next;
    
    node(const T& value = T(), node<T>* prev = nullptr, node<T>* next = nullptr)
    {
        this->value = value;
        this->prev = prev;
        this->next = next;
    }
};

template <class T>
class mylist
{
    // friend declaration for the template function - note the special syntax
    friend std::ostream& operator<< <>(std::ostream&, const mylist<T>&);

    // private data members
private: 
    size_t l_size = 0;
    node<T> *l_back = nullptr;
    node<T> *l_front = nullptr;

    // private member function
    void clone(const mylist<T>& x);

    // public member functions
public:
    mylist() = default;
    ~mylist();
    mylist(const mylist<T>& x);
    mylist<T> &operator=(const mylist<T>& x);
    void clear();
    size_t size() const;
    bool empty() const;
    const T& front() const;
    T& front();
    const T& back() const;
    T& back();
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    bool operator==(const mylist<T>& rhs) const;
    bool operator<(const mylist<T>& rhs) const;

};
        
// Function definitions for the mylist class

template <class T>
void mylist<T>::clone(const mylist<T>& x)
{
    node<T>* cptr = x.l_front;
    while(cptr != nullptr)
    {
        push_back(cptr->value);
        cptr = cptr->next;
    }
}
/**
 * destructor that calls the clear() method
 */    
template <class T>
mylist<T>::~mylist()
{
    clear();
}

/**
 * copy constructor that traverses the list in the existing mylist object and uses push_back
 * to add each value to the back of the new mylist object
 */  
template <class T>
mylist<T>::mylist(const mylist<T>& x)
{
    clear();
    clone(x);
}

/**
 * assignment operator overload function
 */  
template <class T>
mylist<T>& mylist<T>::operator=(const mylist<T>& x)
{
    if(this != &x)
    {
        // make the left queue object empty
        clear();

        // copy the other queue's linked list
        clone(x);
    }

    return *this;
}

/**
 * clear function, sets the list back to an empty state, deleting all the nodes in the linked
 * list and setting the size back to 0
 */  
template <class T>
void mylist<T>::clear()
{
    while(!empty())
    {
        pop_back();
    }
}

/**
 * size function, returns l_size
 */  
template <class T>
size_t mylist<T>::size() const
{
    return l_size;
}

/**
 * empty function, returns true if the list size is 0; otherwise, returns false
 */  
template <class T>
bool mylist<T>::empty() const
{
    if (l_size == 0) 
    {
        return true;
    }
    else 
    {
        return false;
    }
}

/**
 * front function, returns value of the front node in the list, const
 */  
template <class T>
const T& mylist<T>::front() const
{
    if(empty())
    {
        throw std::underflow_error("underflow exception on call to back()");
    }
    else
    {
        return l_back->value;
    }
}

/**
 * front function, returns value of the front node in the list
 */  
template <class T>
T& mylist<T>::front()
{
    if(empty())
    {
        throw std::underflow_error("underflow exception on call to back()");
    }
    else
    {
    return l_front->value;
    }
}

/**
 * back function, returns value of the back node in the list, const
 */  
template <class T>
const T& mylist<T>::back() const
{
    if(empty())
    {
        throw std::underflow_error("underflow exception on call to back()");
    }
    else
    {
        return l_back->value;  
    }
}

/**
 * back function, returns value of the back node in the list
 */  
template <class T>
T& mylist<T>::back()
{
    if(empty())
    {
        throw std::underflow_error("underflow exception on call to back()");
    }

    return l_back->value;
}

/**
 * push_front function, inserts an item at the front of the list
 */  
template <class T>
void mylist<T>::push_front(const T& value)
{
    node<T> *new_node = new node<T>(value);  // declare new node

    new_node->next = l_front;  // Point new node's next pointer at current last node in the list
    
    if(empty())
    {
        l_front = new_node;  // Point l_front at new first node in the list
    }
    else
    {
        l_front->next = new_node;  // Point current last node's next pointer at new last node in the list
    }

    l_size++;
}

 /**
 * push_back function, inserts an item at the back of the list
 */  
template <class T>
void mylist<T>::push_back(const T& value)
{
    node<T> *new_node = new node<T>(value);  // declare new node

    new_node->prev = l_back;  // Point new node's prev pointer at current last node in the list

    if(empty())
    {
        l_front = new_node;  // Point l_front at new first node in the list
    }
    else
    {
        l_back->next = new_node;  // Point current last node's next pointer at new last node in the list
    }

    l_size++;
}

/**
 * pop_front function, removes an item from the front of the list
 */  
template <class T>
void mylist<T>::pop_front()
{
    if (empty())
    {
        throw std::underflow_error("underflow exception on call to front()");
    }

    node<T>* del_node = l_front;  // Save address of node to delete in a pointer

    l_front = del_node->prev;  // Point l_front at the new last node in the list

    if(size() == 1)
    {
        l_back = nullptr;  // If l_front == nullptr, l_back should be as well since the list is now empty
    }
    else if(size() > 1)
    {
        l_front->prev = nullptr;  // Set the new last node's prev pointer to nullptr
    }
    
    delete del_node;

    l_size--;

}

/**
 * pop_back function, removes an item from the back of the list
 */  
template <class T>
void mylist<T>::pop_back()
{
    if (empty())
    {
        throw std::underflow_error("underflow exception on call to back()");
    }
    
    node<T>* del_node = l_back;  // Save address of node to delete in a pointer

    l_back = del_node->prev;  // Point l_back at the new last node in the list

    if(size() == 1)
    {
        l_front = nullptr;  // If l_back == nullptr, l_front should be as well since the list is now empty
    }
    else if(size() > 1)
    {
        l_back->next = nullptr;  // Set the new last node's next pointer to nullptr
    }
    
    delete del_node;

    l_size--;

}

/**
 * overload equality operator function, compares two mylist objects to check for equivalence
 */  
template <class T>
bool mylist<T>::operator==(const mylist<T>& rhs) const
{
    // intiliaze lhs and rhs nodes
    node<T> *lhs = l_front;
    node<T> *rptr = rhs.l_front;
    
    // check l_size
    if (this->l_size != rhs.l_size) 
    {
        return false;
    }
    
    // traverse the list
    bool verify = false;
    while (verify == true) 
    {
        if (lhs->value == rptr->value) 
        {
            verify = true;
        }
        else 
        {
            verify = false;
            return verify;
        }
 
        lhs = lhs->next;
        rptr = rptr->next;
        
    }
    return verify;
}

/**
 * overload less than operator function, compares two mylist objects
 */  
template <class T>
bool mylist<T>::operator<(const mylist<T>& rhs) const
{

   node<T> *lhs = l_front;
   node<T> *rptr = rhs.l_front;
    
   // intitialize verify
   bool verify = true;

   while(verify == false && lhs != nullptr && rptr != nullptr) 
   {
        if (lhs->value > rptr->value) 
        {
            verify = false;
            return verify;
        }
        else if (lhs->value < rptr->value) 
        {
            verify = true;
            return verify;
        }

        // increment
        lhs = lhs->next;
        rptr = rptr->next;
   }

   // if true at first, verify array size
   if (this->l_size < rhs.l_size) 
   {
       verify = true;
   }
   return verify;
}

/**
 * overload stream insertion operator function, allows entire mylist object to be sent to standard output
 */ 
template <class T>
std::ostream& operator<<(std::ostream& os, const mylist<T>& obj)
{
    node<T>* traverse = obj.l_front;

    while (traverse != nullptr)
    {
        os << traverse->value << " ";
        traverse = traverse->next;
    }
    return os;
}


#endif // MYSTACK_H

