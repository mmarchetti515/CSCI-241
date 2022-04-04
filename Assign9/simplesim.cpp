//************************************************
// simplesim.cpp
// CSCI 241 Assignment 4
//
// Created by your-name (your-z-ID).
//************************************************

#include <iostream>
#include <iomanip>

#include "sml.h"
#include "simplesim.h"

using namespace std;

/**
 * Constructor. Initializes simplesim data 
 * members.
 */
simplesim::simplesim()
{
    for (int i = 0; i < 100; i++)
        memory[i] = 7777;
}

/**
 * Reads a simplesim program and loads it into
 * memory.
 *
 * @return Returns true on successful load; 
 *         otherwise, returns false.
 */
bool simplesim::load_program()
{
    int count = 0;      // Count of words read
    int instruction;    // Word being read

    while (cin >> instruction && instruction != -99999)
    {
        if (invalid_word(instruction))
        {
            cout << "*** ABEND: pgm load: invalid word ***\n";
            return false;
        }
        // check instruction count
        if (count >= 100)
        {
            // Print error message and return false
            cout << "*** pgm load: pgm too large ***\n";
            return false;
        }
        // Copy instruction into memory and increment count
        memory[count] = instruction;
        count++;
    }
    // successful load
    return true;
}

/**
 * Executes a loaded simplesim program.
 */
void simplesim::execute_program()
{
    bool done = false;
    bool branching = false; // initialize branch to check if instruction is located on a branch
    instruction_counter = 0; // initialize instruction_counter to manage current step
    while (!done)
    {
        // Test instruction_counter; if >= 100, addressability
        if (instruction_counter >= 100)
        {
            cout << "*** ABEND: addressability error ***\n";
            return;
        }
        // instruction fetch
        instruction_register = memory[instruction_counter];
        operation_code = instruction_register / 100;
        operand = instruction_register % 100;
    
        // instruction execute
        switch (operation_code)
        {
            case READ:
                int num;
                cin >> num;
                if (invalid_word(num))
                {
                    cout << "*** invalid input ***\n";
                    return;
                }
                cout << "READ: " << showpos << setfill('0') << setw(5) << internal << num << endl;
                memory[operand] = num;
                break;

            case WRITE:
                cout << showpos << setfill('0') << setw(5) << internal << memory[operand] << endl;
                break;

            // store/ load ops
            case LOAD:
                accumulator = memory[operand];
                break;

            case STORE:
                memory[operand] = accumulator;
                break;
            
            // arithmetic ops
            case ADD:
                if(invalidNum(accumulator + memory[operand]))
                {
                    return;
                }
                else
                {
                    accumulator+= memory[operand];
                }
                break;

            case SUBTRACT:
                if(invalidNum(accumulator - memory[operand]))
                {
                    return;
                }
                else
                {
                    accumulator -= memory[operand];
                }
                break;

            case MULTIPLY:
                if(invalidNum(accumulator * memory[operand]))
                {
                    return;
                }
                else
                {
                    accumulator *= memory[operand];
                }
                break;

            case DIVIDE:
                // check for div/0
                if(memory[operand] == 0)
                {
                    cout << "*** ABEND: attempted division by 0 ***\n";
                    return;
                }
                //continue if normal
                if(invalidNum(accumulator / memory[operand]))
                {
                    return;
                }
                else
                {
                    accumulator /= memory[operand];
                }
                break;

            // move control ops
            case HALT:
                cout << "*** Simplesim execution terminated ***\n";
                done = true;
                break;

            case BRANCH:
                branching = true;
                if(accumulator <= 0)
                {
                    instruction_counter = operand;
                }
                break;
            
            case BRANCHNEG:
                branching = true;
                if(accumulator <= 0)
                {
                    instruction_counter = operand;
                }
                break;

            case BRANCHZERO:
                branching = true;
                if(accumulator == 0)
                {
                    instruction_counter = operand;
                }
                break;
        
            default:
                // Print invalid operation code error and return
                cout << "*** ABEND: invalid opcode ***\n";
        }

        if (!branching && !done)
        {
            instruction_counter++;
        }
        // initialize branching for continued loops
        branching = false;
    }
}

// check if number passed to function is within valid range
bool simplesim::invalidNum(int num) const
{
    if (num < -9999) 
    {
        cout << "*** ABEND: underflow ***\n";
        return true;
    }
    else if (num > 9999)
    {
        cout << "*** ABEND: overflow ***\n";
        return true;
    }
    return false;
}

/**
 * Dumps simplesim registers and memory.
 */
void simplesim::dump() const
{
    cout << setfill(' ');
    // Print the registers
    cout << "REGISTERS:\n";

    cout << setw(24) << left << "accumulator: " << showpos << setw(5) << setfill('0') << internal << accumulator << endl << setfill(' ');
    cout << setw(24) << left << "instruction_counter: " << noshowpos << setw(2) << setfill('0') << right << instruction_counter << endl << setfill(' ');
    cout << setw(24) << left << "instruction_register: " << showpos << setw(5) << setfill('0') << internal << instruction_register << endl << setfill(' ');
    cout << setw(24) << left << "operation_code: " << noshowpos << setw(2) << setfill('0') << right << operation_code << endl << setfill(' ');
    cout << setw(24) << left << "operand: " << setw(2) << setfill('0') << right << operand << endl << setfill(' ');

    // Print memory
    cout << "\nMEMORY:\n";

    for (int i = 0; i < 100; i++)
    {
        cout << memory[i] << endl;
    }
    
    cout << right << setw(5) << 9;

    cout << endl << right << " 0 ";
    for (int i = 0; i < 100; i++) 
    {
        cout << showpos << setw(5) << setfill('0') << internal << memory[i];
        if ((i+1) % 10 == 0 && i !=99)
        {
            cout << endl << noshowpos << (1 + i) << " ";
            cout << endl;
        }
        else if (i != 99)
        {
            cout << " ";
            cout << endl;
        }
    }
}

bool simplesim::invalid_word(int word) const
{
    if (word < -9999 || word > 9999)
        return true;
    else
        return false;
}
