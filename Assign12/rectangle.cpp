//***************************************************************
//
//  rectangle.cpp
//  CSCI 241 Assignment 12
//
//  Michael Marchetti z1860574
//
//***************************************************************

#include "rectangle.h"
#include <cmath>

using namespace std;

/**
 * @brief Construct a new rectangle::rectangle object
 * 
 * @param color shape color
 * @param height shape height
 * @param width shape width 
 */
rectangle::rectangle(const string& color, int height, int width) : shape(color)
{
    this->height = height;
    this->width = width;
}

/**
 * @brief overridden print function
 */
void rectangle::print() const
{
    // call base class print
    shape::print();
    cout << " rectangle, height " << height << ", width " << width << ", area " << get_area() << endl;
}

/**
 * @brief overridden get_area computes rectangle area based on height and width
 * 
 * @return double rectangle area
 */
double rectangle::get_area() const
{
    return height * width;
}