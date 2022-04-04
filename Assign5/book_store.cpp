//************************************************
// book_store.cpp
// CSCI 241 Assignment 5
//
// Michael Marchetti z1860574
//************************************************

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cmath>
#include "book.h"
#include "book_store.h"

using namespace std;

// default constructor, initialize NumBooks to 0
book_store::book_store()
{
    NumBooks = 0;
}

// insertion sort used to sort book data
// pulled from pseudocode from class notes
void book_store::sort_isbn()
{
    int i, j;
    book temp;
    for (i = 1; i < NumBooks; i++)
    {
        temp = books[i];

        // using strcmp instead of relational operators
        for(j = i; j > 0 && strcmp(books[j -1].get_isbn(), temp.get_isbn()) > 0; j--)
            books[j] = books[j - 1];

        books[j] = temp;
    }
}

// function obtained from in class notes
// read_book_data opens file and reads data from binary
void book_store::read_book_data(const string file_nameA)
{
    ifstream in_fileA;

    // Open the input file and test for failure.
    in_fileA.open(file_nameA);
    if (!in_fileA)
    {
        cerr << "Error: Unable to open input file " << file_nameA << endl;
        exit(1);
    }

    // Read an entire book_store object worth of bytes into the book_store object
    // that was used to call the read_book_data() member function.
    in_fileA.read((char*) this, sizeof(book_store));

    in_fileA.close();
    // calls sort_isbn function with no parameters
    sort_isbn(); 
}

// binary search pulled from pseudocode provided from class notes
// use strcmp instead of relational operators for strings
int book_store::search_isbn(const char* search_key)
{
    int low = 0;
    int mid;
    int high = NumBooks - 1;

    while(low <= high)
    {
        mid = (low + high)/ 2;

        if(strcmp(search_key, books[mid].get_isbn()) == 0)
        {
            return mid;
        }
        if (strcmp(search_key, books[mid].get_isbn()) < 0)
        {
            high = mid - 1;
        }
            else
            {
                low = mid + 1;
            }
    }
    return -1;
}

// proccess order function will finish the order by printing book information for each
// order, and calling the fulfill_order function to update the inventory
void book_store::process_orders(const string& file_nameB)
{
    // Open the input file and test for failure
    ifstream in_fileB;
    in_fileB.open(file_nameB);
    if (!in_fileB)
    {
        cerr << "Error - unable to open input file " << file_nameB << endl;
        exit(2);
    }

    cout << "Order Listing\n\n";

    // declare variables for Order Listing
    int i;
    int orderQty;
    char orderNum[7];
    char isbn[11];

    while (in_fileB >> orderNum)
    {
        in_fileB >> orderQty;
        in_fileB >> isbn;
        
        search_isbn(isbn);
        if ((i = search_isbn(isbn)) != -1)
        {
            // could not get valid orders to print, and could not get full isbn to print
            books[i].fulfill_order(orderQty);
            cout << "Order #" << orderNum << ": ISBN " << isbn << ", " << orderQty;
            cout << " of " << stockQty << " shipped, order total "; 
        }
        else if (search_isbn(isbn) == -1)
        {
            cout << "Order # " << orderNum << ": error - ISBN " << isbn << " does not exist\n";
        }
    }
    cout << "\n"; 
}

// prints book data in a table until end of NumBooks
void book_store::print() const 
{
    for (int i = 0; i < NumBooks; i++) 
    {
        books[i].print();
    }
    cout << "\n";
}