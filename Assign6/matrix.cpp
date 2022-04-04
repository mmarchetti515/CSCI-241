//*******************************************************************
//
//  assign6.cpp
//  CSCI 241 Assignment 6
//
//  Michael Marchetti z1860574
//
//*******************************************************************

#include <iostream>
#include "matrix.h"

using namespace std;

// matrix class, function call for constructor, makes sets the array values
matrix::matrix()
{
    array[0][0] = 1;
    array[0][1] = 0;
    array[1][0] = 0;
    array[1][1] = 1;
}

// matrix class, matrix function that intializes the array values
// param initArray
matrix::matrix(int initArray[][2])
{
    int result;

    for (int i = 0; i < 2; i++)   // i for loop iterates through rows
    {
        for (int j = 0; j < 2; j++)   // j for loop iterates through columns
        {
            result = initArray[i][j];   // set result to initArray
            array[i][j] = result;   // set array to result
        }
    }
}

// friend function given from in class demonstration
// os << displays structure for arrays 
ostream& operator<<(ostream& os, const matrix& obj)
{
    os << "[[" << obj.array[0][0]
       << ", " << obj.array[0][1]
       << "], [" << obj.array[1][0]
       << ", " << obj.array[1][1]
       << "]]";  

    return os;
}

// matrix class, determinant function as a const
int matrix::determinant() const
{
    // store detResult as an int for the function return value
    int detResult;   

    // logic for function - calculates the determinant of the given array using array index locations
    detResult = (array[0][0]*array[1][1]) - (array[0][1]*array[1][0]);

    return detResult;
}

// matrix class, operator + function using one param, as a const, adds two arrays
matrix matrix::operator+(const matrix& rhs)  const
{
    // store sumResult as a matrix data type for the function return value
    matrix sumResult;

    for (int i = 0; i < 2; i++)  // i for loop iterates through rows of the array 
    {
        for (int j = 0; j < 2; j++)   // j for loop iterates through rows of the array
        {
            // logic for function adds the left hand side of the array and the right hand side
            // of the array and stores the result in sumResult
            sumResult.array[i][j] = this-> array[i][j] + rhs.array[i][j];
        }
    }
    return sumResult;
}

// matrix class, operator * function using one int param, as a const, multiplying an array by a scalar
matrix matrix::operator*(int rhs) const
{
    // store prodResult as a matrix data type for the function return value
    matrix prodResult;     // Declare a temporary object to hold the result

    // logic for function takes left hand side of array and multiplies it by the right hand int
    // storing the result in prodResult
    prodResult.array[0][0] = this->array[0][0] * rhs;
    prodResult.array[0][1] = this->array[0][1] * rhs;
    prodResult.array[1][0] = this->array[1][0] * rhs;
    prodResult.array[1][1] = this->array[1][1] * rhs;

    return prodResult;
}

// matrix class, operator * function using two param multiplying an array by a scalar
matrix operator*(int lhs, const matrix& rhs)
{
    // store prodResult as a matrix data type for the function return value
    matrix prodResult; 

    // logic for function takes right hand side of array and multiplies it by the left hand int
    // storing the result in prodResult
    prodResult.array[0][0] = lhs * rhs.array[0][0];
    prodResult.array[0][1] = lhs * rhs.array[0][1];
    prodResult.array[1][0] = lhs * rhs.array[1][0];
    prodResult.array[1][1] = lhs * rhs.array[1][1];

    return prodResult;
}

// matrix class, operator * function using one param, as a const, multiplying two arrays
matrix matrix::operator*(const matrix& rhs) const
{
    // store prodResult as a matrix data type for the function return value
    matrix prodResult;

    // logic for function takes left hand array, multiplies it by right hand array, and adds the product by
    // the same for the other array
    prodResult.array[0][0] = (this->array[0][0] * rhs.array[0][0]) + (this->array[0][1] * rhs.array[1][0]);
    prodResult.array[0][1] = (this->array[0][0] * rhs.array[0][1]) + (this->array[1][0] * rhs.array[1][1]);
    prodResult.array[1][0] = (this->array[1][0] * rhs.array[0][0]) + (this->array[1][1] * rhs.array[1][0]);
    prodResult.array[1][1] = (this->array[1][0] * rhs.array[0][1]) + (this->array[1][1] * rhs.array[1][1]);

    return prodResult;
}

// bool function, operator == using one const matrix param, as a const
bool matrix::operator==(const matrix& rhs) const
{
    // set bool data type equivalence equal to true
    bool equivalence = true;

    for (int i = 0; i < 2; i++)   // i for loop iterates through rows of the array 
    {
        for (int j = 0; j < 2; j++)   // j for loop iterates through rows of the array  
        {
            // if statement checks if left side array is equal to righ side array for each index position
            if(this->array[i][j] == rhs.array[i][j])
            {
                // if they are equal, set equivalence equal to true
                equivalence = true;
            }
            // else statement to cover any other cases, in this case, false
            else
            {
                // if they are not equal, set equivalence to false and return equivalence
                equivalence = false;
                return equivalence;
            }
        }
    }
    return equivalence;

}

// bool function, operator != using one const matrix param, as a const// bool function, operator == using one const matrix param, as a const
bool matrix::operator!=(const matrix& rhs) const
{
    // set bool data type equivalence equal to false
    bool equivalence = false;

    for (int i = 0; i < 2; i++)   // i for loop iterates through rows of the array 
    {
        for (int j = 0; j < 2; j++)   // j for loop iterates through rows of the array
        {
            // if statement checks if left side array is equal to righ side array for each index position
            if(this->array[i][j] == rhs.array[i][j])
            {
                // if they are equal, set equivalence equal to false
                equivalence = false;
            }
            // else statement to cover any other cases, in this case, true
            else
            {
                // if they are not equal, set equivalence to false and return equivalence
                equivalence = true;
                return equivalence;
            }
        }
    }
    return equivalence;

}
