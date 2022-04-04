#ifndef SIMPLESIM_H
#define SIMPLESIM_H

//************************************************
// simplesim.h
// CSCI 241 Assignment 4
//
// Created by your-name (your-z-ID).
//************************************************

class simplesim
{
private:

    // Simplesim memory.
    int memory[100];
    
    // Simplesim registers.
    int accumulator = 0;
    int instruction_counter = 0;
    int instruction_register = 0;
    int operation_code = 0;
    int operand = 0;
    
    // Private utility functions.
    bool invalid_word(int) const;

public:

    simplesim();
    bool load_program();
    void execute_program();
    void dump() const;
};

#endif
