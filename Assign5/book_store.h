//************************************************
// book_store.h
// CSCI 241 Assignment 5
//
// Michael Marchetti z1860574
//************************************************

#ifndef BOOK_STORE_H
#define BOOK_STORE_H

#include <iostream>
#include <string>
#include "book.h"

using namespace std;

// Declaring class
class book_store
{
    private:

        // Data members

        book books[30];
        int NumBooks;
        int i{0};
        int stockQty{0};


    public:

        // Member functions
        
        book_store(); // Default constructor
        
        void read_book_data(const string);
        istream& read(char* s, streamsize n);
        void sort_isbn();
        void process_orders(const string&);
        void print() const;
        int search_isbn(const char*);
};

#endif // BOOK_STORE_H