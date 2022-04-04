//***************************************************************
//
//  assign12.cpp
//  CSCI 241 Assignment 12
//
//  Michael Marchetti z1860574
//
//***************************************************************

#include "shape.h"      // shape base class
#include "circle.h"     // circle derived class
#include "rectangle.h"  // rectangle derived class
#include "triangle.h"   // triangle derived class

#include <vector>
#include <iomanip>

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::vector;
using std::string;

int main()
{
    // create vector shapes
    vector<shape*> shapes;

    // Dynamically create at least two circles, rectangles, and triangles. 
    shapes.push_back(new circle("orange", 5));
    shapes.push_back(new circle("green", 10));

    shapes.push_back(new rectangle("red", 8, 6));
    shapes.push_back(new rectangle("blue", 3, 7));

    shapes.push_back(new triangle("yellow", 8, 4));
    shapes.push_back(new triangle("black", 4, 10));

    cout << "Printing all shapes... \n\n";

    // loop through shapes vectory, call print() for every pointer
    for(size_t i = 0; i < shapes.size(); i++)
    {
        // print shape information
        shapes[i]->print();
    }

    cout << "\nPrinting only circles... \n\n";

    // loop through shapes vectory, call print() for every circle object
    for(size_t i = 0; i < shapes.size(); i++)
    {
        circle* p = dynamic_cast<circle*>(shapes[i]);
        // check if circle object
        if(p != nullptr)
        {
            p->print();
        }
    }    

    // loop through shapes vector, delete each object
    for(size_t i = 0; i < shapes.size(); i++)
    {
        delete shapes[i];
    }
}
