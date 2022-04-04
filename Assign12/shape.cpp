//***************************************************************
//
//  shape.cpp
//  CSCI 241 Assignment 12
//
//  Michael Marchetti z1860574
//
//***************************************************************

#include "shape.h"

using namespace std;

/**
 * @brief Construct a new shape::shape object
 * 
 * @param color color of the shape
 */
shape::shape(const string& color)
{
    this->color = color;
}

/**
 * @brief Destroy the shape::shape object
 * destructor
 */
shape::~shape(){
}

/**
 * @brief Print function for color 
 */
void shape::print() const
{
    cout << color << " ";
}


