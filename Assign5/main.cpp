#include <iostream>
#include <iomanip>
#include "book_store.h"

using namespace std;

int main() 
{
    // declare book_store object
	book_store book_store;

    // read_book_data reads the information passed from the argument bookdata
    book_store.read_book_data("bookdata");

    // prints inventory listing before order is made
    // cout prints title and column headers
    cout << "Book Inventory Listing\n\n";
    cout << setw(14) << left << "ISBN";
    cout << setw(44) << left << "Title";
    cout << setw(5) << right << "Price";
    cout << setw(6) << right << "  Qty.\n\n";

    book_store.print();

    // process_orders completes the transaction using the order information passed
    // from the argument orders.txt
    book_store.process_orders("orders.txt");

    // prints inventory listing after` order is made
    // cout prints title and column headers
    cout << "Book Inventory Listing\n\n";
    cout << setw(14) << left << "ISBN";
    cout << setw(44) << left << "Title";
    cout << setw(5) << right << "Price";
    cout << setw(6) << right << "  Qty.\n\n";

    book_store.print();    

}