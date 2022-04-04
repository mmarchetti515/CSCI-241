//************************************************
// book.h
// CSCI 241 Assignment 5
//
// Michael Marchetti z1860574
//************************************************

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std;

// Declaring class
class book
{
    public:

        // Member functions
        
        book(); // Default constructor
                
        const char* get_isbn(); 
        double get_price();
        int fulfill_order(int);
        void print() const;

    private:

        // Data members

        char isbn[11]{"None"};
        char title[41]{"None"};
        double price{0};
        // double orderCost{0};
        int stockQty{0};
};

#endif // BOOK_H