//***************************************************************
//
//  circle.h
//  CSCI 241 Assignment 12
//
//  Michael Marchetti z1860574
//
//***************************************************************

#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <iostream>

class circle : public shape
{
    private:
        // private data member
        int radius;

    public:
        // public member functions
        // default constructor
        circle() = default;

        // constructor for color and radius
        circle(const string& color, int radius);

        // overridden print function
        virtual void print() const;

        // overridden get_area function
        virtual double get_area() const;
};

#endif // CIRCLE_H