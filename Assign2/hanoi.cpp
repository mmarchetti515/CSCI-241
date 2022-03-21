//***********************************************************************
//
//  hanoi.cpp
//  CSCI 241 Assignment 2
//
//  Michael Marchetti z1860574
//
//***********************************************************************

#include <string>
#include <cctype>
#include <cstdlib>
#include <iostream>

using namespace std;

void move(int, int, int, int);

//***********************************************************************
//
// !! Skeleton code acquired from supplemental lecture !!
//
// Program to use a recursive function to solve the Towers
// of Hanoi problem. 
// argc Number of command line arguments
// argv Array of command line arguments
// Return 0 upon succesful completion
//***********************************************************************

int main(int argc, char* argv[])
{
    int n;

    // check for the presence of a command line argument 
    // specifying the number of disks to move

    if (argc == 1)
    {
        cout << "Missing argument\n"
             << "Usage: Hanoi number-of-disks\n";
        exit(1);
    }

    // Validate the argument to make sure that it only 
    // contains numeric digits

    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            cout << "Argument must be a number\n"
                 << "Usage: Hanoi number-of-disks\n";
            exit(1);
        }
    }

    //Convert the numeric string to an integer

    n = stoi(argv[1]);

    // Make the intial call to the move() function to move
    // n from peg 1 to peg 2 using peg 3 as temporary
    // storage

    move(n, 1, 2, 3);

    return 0;
}

//***********************************************************************
// Moves n disks from the source peg to the destination peg,
// using the third peg as temporary storage.
// n Number of disks to move
// src_peg Source peg number
// dest_peg Destination peg number
// temp_peg Peg number used as temporary storage
//***********************************************************************

void move(int n, int src_peg, int dest_peg, int temp_peg)
{
    if (n >= 1 )
    {
        move(n - 1, src_peg, temp_peg, dest_peg);
        cout << n << " " << src_peg << " -> " << dest_peg << "\n";
        move(n - 1, temp_peg, dest_peg, src_peg);
    }
}
