//***************************************************************
//
//  circle.cpp
//  CSCI 241 Assignment 12
//
//  Michael Marchetti z1860574
//
//***************************************************************

#include "circle.h"
#include <cmath>

using namespace std;

/**
 * @brief Construct a new circle object
 * 
 * @param color shape color
 * @param radius shape radius
 */
circle::circle(const string& color, int radius) : shape(color)
{
    this->radius = radius;
}

/**
 * @brief overridden print function  
 */
void circle::print() const
{
    // call base class print method
    shape::print();
    cout << " circle, radius " << radius << ", area " << get_area() << endl;
}

/**
 * @brief overridden get_area computes circle area based on radius
 * @return double returns the area
 */
double circle::get_area() const
{
    return M_PI * (radius * radius);
}