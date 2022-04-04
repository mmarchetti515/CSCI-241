//************************************************
// book.cpp
// CSCI 241 Assignment 5
//
// Michael Marchetti z1860574
//************************************************

#include <iostream>
#include <iomanip>
#include <string>
#include "book.h"
#include "book_store.h"

using namespace std;

// constructor
book::book() 
{
}

// definition of get_isbn using scope resolution operator ::
const char* book::get_isbn()
{
    return isbn;
}

// definition of get_price using scope resolution operator ::
double book::get_price() 
{
    return price;
}

// definition of fulfill_order using scope resolution operator ::
int book::fulfill_order(int orderQty)
{
    int shippedQty;

    if (orderQty < 0)   // Error in order, trying to order less than zero books
    {
    cout << "Error: Requested quantity must be 0 or higher.\n";
        shippedQty = 0;
    }
    
    else if (orderQty <= stockQty)  // Valid order request with sufficient stock
    {
        // complete the order
        shippedQty = orderQty;
        stockQty = stockQty - shippedQty;
        // orderCost = orderQty
    }

    else // Valid order request with insufficient stock
    {
        shippedQty = stockQty;
        stockQty = 0;
    }
    return orderQty;
}

// definition of print using scope resolution operator ::
void book::print() const
{
    // prints data
    cout << setw(14) << setprecision(2) << fixed << left << isbn;
    cout << setw(44) << setprecision(2) << fixed << left << title;
    cout << setw(5) << setprecision(2) << fixed << right << price;
    cout << setw(6) << setprecision(2) << fixed << right << stockQty << endl;
}