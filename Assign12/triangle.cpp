//***************************************************************
//
//  triangle.cpp
//  CSCI 241 Assignment 12
//
//  Michael Marchetti z1860574
//
//***************************************************************

#include "triangle.h"
#include <cmath>

using namespace std;

/**
 * @brief Construct a new triangle::triangle object
 * 
 * @param color 
 * @param height 
 * @param base 
 */
triangle::triangle(const string& color, int height, int base) : shape(color)
{
    this->height = height;
    this->base = base;
}

/**
 * @brief overridden print function 
 */
void triangle::print() const
{
    // call base class print
    shape::print();
    cout << " triangle, height " << height << ", base " << base << ", area " << get_area() << endl;
}

/**
 * @brief overridden get_area computes triangle area based on height and base
 * 
 * @return double area of triangle
 */
double triangle::get_area() const
{
    return ((height * base) / 2);
}