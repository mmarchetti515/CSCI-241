//***************************************************************
//
//  rectangle.h
//  CSCI 241 Assignment 12
//
//  Michael Marchetti z1860574
//
//***************************************************************

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include <iostream>

class rectangle : public shape
{
    private:
        // private data members
        int height, width;

    public:
        // public member functions
        // default constructor
        rectangle() = default;

        // constructor for color, height, width
        rectangle(const string& color, int height, int width);

        // overridden print function
        virtual void print() const;

        // overridden get_area function
        virtual double get_area() const;
};

#endif // RECTANGLE_H