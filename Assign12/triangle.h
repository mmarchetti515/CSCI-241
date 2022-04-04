//***************************************************************
//
//  triangle.h
//  CSCI 241 Assignment 12
//
//  Michael Marchetti z1860574
//
//***************************************************************

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include <iostream>

class triangle : public shape
{
    private:
        // private data members
        private:
        int height, base;

    public:
        // public member functions
        // default constructor
        triangle() = default;

        // constructor for color, height, and base
        triangle(const string& color, int height, int base);

        // overridden print function
        virtual void print() const;

        // overridden get_area function
        virtual double get_area() const;
};

#endif // TRIANGLE_H