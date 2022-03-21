//***********************************************************************
//
//  queens.cpp
//  CSCI 241 Assignment 2
//
//  Michael Marchetti z1860574
//
//***********************************************************************
#include <iostream>

using namespace std;

#define N 8

class queen_solver
{
private:

    bool board[N][N] = {{false}};

public:

    queen_solver() = default;
    bool place_queens();
    bool place_queen_in_row(int);
    bool is_safe(int, int) const;
    void print_solution() const;
};


int main()
{
    queen_solver q;

    if (q.place_queens())
        q.print_solution();
    else
        cout << "Error - no solution found\n";

    return 0;
}

bool queen_solver::place_queens()
{
    return place_queen_in_row(0);
}

//***********************************************************************
//
// !! Skeleton code acquired from supplemental lecture !!
//
// Program to use nested for loops to place queens on array of bools
// searching above placed queens to test if placement will not create
// any conflicts where other queens could attack the placed queen
// Return true upon completion
//***********************************************************************

bool queen_solver::place_queen_in_row(int row)
{
    // Base case #1 - All queens have been placed successfully.
    if (row >= 8)
        return true;

    for (int col = 0; col < N; col++)
    {
        if (is_safe(row, col))
        {
            // Put a queen at board[row][col]
            board[row][col] = true;

            if (place_queen_in_row(row + 1))
                // Base case #2 - All queens in rows below this one
                // have been successfully placed.
                return true;
            
            board[row][col] = false;      // Remove the queen at board[row][col]
        }
    }

    return false;
}

// Nested for loops test for validity of placement of queen
// by checking all spaces directly horizontally, then when that 
// returns true, it moves to checking the left upwards diagonal,
// doing the same, then the right upwards diagonal, doing 
// the same. 
bool queen_solver::is_safe(int row, int col) const
{
    for(int r = row; r>=0; r--)
    {
        if(board[r][col])
            return false;
    }

    for(int r = row, c = col; r >= 0 && c >= 0; r--, c--)
    {
        if(board[r][c])
            return false;
    }

    for(int r = row, c = col; r >= 0 && c < 8; r--, c++)
    {
        if(board[r][c])
            return false;
    }

    return true;
}

// function prints the array to prepare for placement of queens
void queen_solver::print_solution() const
{
   for(int r = 0; r < N; r++)
    {
        for(int c=0; c < N; c++)
        	cout << board[r][c] << " "; 
        {
            cout << "\n";
        }
    }
}   
