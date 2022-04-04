//************************************************
// matrix.h
// CSCI 241 Assignment 6
//
// Michael Marchetti z1860574
//************************************************

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

// Declaring class
class matrix
{
    friend std::ostream& operator<<(std::ostream&, const matrix&);
    friend matrix operator*(int lhs, const matrix&);

    private:

        // Data members

        int array[2][2];

    public:

        // Member functions
        
        matrix();   // Default constructor - set the elements of the matrix array to the "identity matrix", 
                             // such that all the elements on the main diagonal are equal to 1 and all other elements are equal to 0
        matrix(int array_arg[][2]);   // Default constructor - Set the elements of the matrix array to the 
                                      // corresponding elements in the array passed into the constructor.

        int determinant() const;   // Performs the determinant operation on the 2x2 matrix

        matrix operator+(const matrix&) const;   // The sum A+B of two 2-by-2 matrices A and B is calculated entrywise: 
                           //(A + B)i,j = Ai,j + Bi,j, where 1 ≤ i ≤ 2 and 1 ≤ j ≤ 2

        matrix operator*(int rhs) const;   // The product Ac of a matrix A and a number c (also called a scalar in the parlance of abstract algebra)
                           // is computed by multiplying every entry of A by c: (Ac)i,j = Ai,j · c. 

        matrix operator*(const matrix&) const;   // Determines the product of two given 2x2 matrices, non communative

        bool operator==(const matrix&) const;   // Return true if all elements of the left operand are equal to the corresponding 
                             // elements of the right operand. Otherwise, the member function should return false.

        bool operator!=(const matrix&) const;   // Return false if the left operand equals the right operand. 
                        //  Otherwise, the member function should return true.

};
#endif // MATRIX_H
