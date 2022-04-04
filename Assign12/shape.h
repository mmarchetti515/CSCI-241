//***************************************************************
//
//  shape.h
//  CSCI 241 Assignment 12
//
//  Michael Marchetti z1860574
//
//***************************************************************

#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>

using namespace std;

class shape
{
    private:
        // private data member
        string color;

    public:
        // default constructor
        shape() = default;

        // constructor for color
        shape(const string& color);

        // virtual destructor
        virtual ~shape();

        // virtual print fucntion
        virtual void print() const;

        // pure virtual get area function
        virtual double get_area() const = 0;

};

#endif // SHAPE_H

