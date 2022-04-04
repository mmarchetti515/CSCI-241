//**************************************
//
// scc.cpp
// CSCI 241 Assignment 9
//
// Michael Marchetti z1860574
//
//**************************************

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>

#include "sml.h"
#include "inpost.h"

using namespace std;

/**
 *
 * Symbol table entry.
 *
 */

struct table_entry
{
    int symbol;
    char type;
    int location;
};

/**
 *
 * Simple compiler.
 *
 */
class scc
{
public:

    // Data members
    static const int MEMORY_SIZE = 100;
    static const int SYMBOL_TABLE_SIZE = 1000;

    // Member functions
    scc();
    void first_pass();
    void second_pass();
    void print_program() const;

private:

    // Data members
    int memory[MEMORY_SIZE];    // Program memory.
    int data[MEMORY_SIZE];      // Input data values.
    int ndata = 0;              // Number of input data values.

    table_entry symbol_table[SYMBOL_TABLE_SIZE];     // Symbol table.
    
    int flags[MEMORY_SIZE];     // Array of flags to mark partial
                                // isntructions.

    int inst_addr = 0;    // Address of next instruction.
    int next_const_or_var_addr = MEMORY_SIZE - 1;
    int next_symbol_table_idx = 0;

    // Member functions

    void check_mem() const;
    void data_check() const;
    void stack_space_check(int) const;

    /*might need more here*/ int find_location(const string&);
    int search_table(int, char) const;

    void handle_input(istringstream& ss);
    void handle_data(istringstream& ss);
    void handle_let(istringstream& ss);
    void handle_print(istringstream& ss);
    void handle_goto(istringstream& ss);
    void handle_if(istringstream& ss);
    void handle_rem(istringstream& ss);
    void handle_end();
};

/**
 * Compiles a Simple program to SML and
 * prints it to standard output.
 */
int main()
{
    scc compiler;

    compiler.first_pass();

    compiler.second_pass();

    compiler.print_program();

    return 0;
}

/**
 * Constructor - initializes memory and flags arrays.
 */
scc::scc()
{
    for (int i = 0; i < MEMORY_SIZE; i++)
    {
        memory[i] = 7777;
        flags[i] = -1;
    }
}

/**
 * Performs first pass of compilation.
 */
void scc::first_pass()
{
    string buffer1, buffer2, command;
    int linenum;

    while (getline(cin, buffer1))
    {
        buffer2 = buffer1;         // buffer2 used for 'let'
        istringstream ss(buffer1);

        ss >> linenum;

        // Add linenum to symbol table with type 'L'.
        symbol_table[next_symbol_table_idx].symbol = linenum;
        symbol_table[next_symbol_table_idx].type = 'L';
        symbol_table[next_symbol_table_idx]. location = inst_addr;
        next_symbol_table_idx++;

        ss >> command;

        if (command == "input")
        {
            // ... code to process 'input' command ...
            handle_input(ss);
        }
        else if (command == "data")
        {
            // ... code to process 'data' command ...
            handle_data(ss);
        }
        /*
        else if (command == "let")
        {
            // ... code to process 'let' command ...
            handle_let(ss);
        }
        */
        else if (command == "goto")
        {
            // ... code to process 'goto' command ...
            handle_goto(ss);
        }
        else if (command == "if")
        {
            // ... code to process 'if' command ...
            handle_if(ss);
        }
        /*
        else if (command == "print")
        {
            // ... code to process 'print' command ...
            handle_print(ss);
        }
        */
        /*
        else if (command == "rem")
        {
            // ... code to process 'rem' command ...
            handle_rem(ss);    // possibly do nothing instead
        }
        */
        else
        {
            // ... code to process 'end' command ...
            handle_end();
        }
    }
}

/**
 * Performs second pass of compilation.
 */
void scc::second_pass()
{    
    int stack_start = next_const_or_var_addr - 1;
    
    // Loop through flags and memory arrays.
    for (int i = 0; i < inst_addr; i++)
    {
        // If the instruction is marked incomplete in the flags array...
        if (flags[i] != -1)
        {
            if (flags[i] > 0)
            {
                // Line number for goto instruction.
                int index = search_table(flags[i], 'L');
                memory[i] += symbol_table[index].location;
            }
            else if (flags[i] == -2)
            {
                // Special right operand location.
                memory[i] += next_const_or_var_addr;
            }
            else if (flags[i] < -2)
            {
                // Stack location.
                int index = -3 - flags[i];
                // compute
                int location = stack_start - index;
                stack_space_check(location);

                // add value of location to memory 
                memory[i] += location;
            }
        }
    }

}

/**
 * Prints memory and data for the compiled SML program.
 */
void scc::print_program() const
{
    cout << setfill('0') << internal << showpos;

    // Print the entire memory array.
    for (int i = 0; i < MEMORY_SIZE; i++)
        cout << setw(5) << memory[i] << endl;

    // Print the "end of instructions" sentinel value.
    cout << -99999 << endl;

    // Print the input data values.
    for (int i = 0; i < ndata; i++)
        cout << data[i] << endl;
}


/**
 * goto function
 */
void scc::handle_goto(istringstream& ss)
{
    string token;

    ss >> token;  // read token through ss

    // Perform a search for the line number appearing at the end of the line
    int index = search_table(stoi(token), 'L');

    check_mem();
    // if the line number appears in the symbol table
    if(index == -1)
    {
        memory[inst_addr] = 100 * BRANCH;  // 
        flags[inst_addr] = stoi(token);  // 
    }
    // if the line number appears outside the symbol table
    else
    {
        memory[inst_addr] = (100 * BRANCH) + symbol_table[index].location;
    }
    inst_addr++; // incrememnt after each sml instruction
}


void scc::handle_if(istringstream& ss)
{
    string relop, rop, ignored, lop;
    int lop_location, rop_location, linenum;

    // read relational operator into ss
    ss >> relop;
    // read right operator into ss
    ss >> rop;
    // read left operator into ss
    ss >> lop;
    // function to find location of lop
    lop_location = find_location(lop);
    // function to find location of lop
    rop_location = find_location(rop);
    ss >> linenum;
    // function to search symbol table
    ss >> ignored;
    // read line number into ss

    int index = search_table(linenum, 'L');

    // check for which relop is used, action accordingly
    if (relop == "==")
    {
        check_mem();
        
        memory[inst_addr] = 100 * LOAD + lop_location;
        // increment
        inst_addr++;

        // Subract
        check_mem();

        memory[inst_addr] = 100 * SUBTRACT + rop_location;
        // increment
        inst_addr++;

        // BRANCHNEG
        check_mem();

        if (index == -1)
        {
            memory[inst_addr] = 100 * BRANCHZERO;
            flags[inst_addr] = linenum;
        }
        else
        {
            memory[inst_addr] = 100 * BRANCHZERO + symbol_table[index].location;
        }
        // increment
        inst_addr++;
    }
    else if (relop == "!=")
    {
        // Load
        check_mem();

        memory[inst_addr] = 100 * LOAD + lop_location;
        // increment
        inst_addr++;

        // subract
        check_mem();

        memory[inst_addr] = 100 * SUBTRACT + rop_location;
        // increment
        inst_addr++;

        check_mem();

        memory[inst_addr] = 100 * BRANCHZERO + inst_addr + 2;
        // increment
        inst_addr++;

        // BRANCH
        check_mem();

        if (index == -1)
        {
            memory[inst_addr] = 100 * BRANCH;
            flags[inst_addr] = linenum;
        }
        else
        {
            memory[inst_addr] = 100 * BRANCH + symbol_table[index].location;
        }
        // increment
        inst_addr++;
    }
    else if (relop == "<")
    {
        // Load
        check_mem();

        memory[inst_addr] = 100 * LOAD + lop_location;
        // increment
        inst_addr++;

        // aubract
        check_mem();

        memory[inst_addr] = 100 * SUBTRACT + rop_location;
        // increment
        inst_addr++;

        // BRANCHNEG
        check_mem();

        if (index == -1)
        {
            memory[inst_addr] = 100 * BRANCHNEG;
            flags[inst_addr] = linenum;
        }
        else
        {
            memory[inst_addr] = 100 * BRANCHNEG + symbol_table[index].location;
        }
        // increment
        inst_addr++;
    }
    else if (relop == "<=")
    {
        // Load
        check_mem();

        memory[inst_addr] = 100 * LOAD + lop_location;
        // increment
        inst_addr++;

        // Subract
        check_mem();

        memory[inst_addr] = 100 * SUBTRACT + rop_location;
        // increment
        inst_addr++;

        // BRANCHNEG
        check_mem();
        if (index == -1)
        {
            memory[inst_addr] = 100 * BRANCHNEG;
            flags[inst_addr] = linenum; 

            // increment
            inst_addr++;
            check_mem();

            memory[inst_addr] = 100 * BRANCHZERO;
            flags[inst_addr] = linenum;

        }
        else
        {
            memory[inst_addr] = 100 * BRANCHNEG + symbol_table[index].location;
            inst_addr++;
            check_mem();

            memory[inst_addr] = 100 * BRANCHZERO + symbol_table[index].location;
        }
        // increment
        inst_addr++;
    }
    else if (relop == ">")
    {
        // Load
        check_mem();

        memory[inst_addr] = 100 * LOAD + rop_location;
        // increment
        inst_addr++;

        // Subract
        check_mem();

        memory[inst_addr] = 100 * SUBTRACT + lop_location;
        // increment
        inst_addr++;

        // BRANCHNEG
        check_mem();

        if (index == -1)
        {
            memory[inst_addr] = 100 * BRANCHNEG;
            flags[inst_addr] = linenum;
        }
        else
        {
            memory[inst_addr] = 100 * BRANCHNEG + symbol_table[index].location;
        }
        // increment
        inst_addr++;
    }
    else if (relop == ">=")
    {
        // load
        check_mem();

        memory[inst_addr] = 100 * LOAD + rop_location;
        // increment
        inst_addr++;

        // subtract
        check_mem();

        memory[inst_addr] = 100 * SUBTRACT + lop_location;
        // increment
        inst_addr++;

        // BRANCHNEG
        check_mem();

        if (index == -1)
        {
            memory[inst_addr] = 100 * BRANCHNEG;
            flags[inst_addr] = linenum;
            // increment
            inst_addr++;

            check_mem();

            memory[inst_addr] = 100 * BRANCHZERO;
            flags[inst_addr] = linenum;

        }
        else
        {
            memory[inst_addr] = 100 * BRANCHNEG + symbol_table[index].location;
            // increment
            inst_addr++;

            check_mem();
            memory[inst_addr] = 100 * BRANCHZERO + symbol_table[index].location;
        }
        inst_addr++;
    }
}

/**
 * Checks whether there is room in the memory array to add
 * another instruction.
 */
void scc::check_mem() const
{
    if (inst_addr >= MEMORY_SIZE || 
        inst_addr > next_const_or_var_addr)
    {
        cout << "*** ERROR: ran out of Simplesim memory ***\n";
        exit(1);
    }
}

/**
 * Checks whether there is room in the data array to add
 * another data item.
 */
void scc::data_check() const
{
    if (ndata >= MEMORY_SIZE)
    {
        cout << "*** ERROR: too many data lines ***\n";
        exit(1);
    }
}

/**
 * Checks whether the top of the stack has crossed into
 * the region of the memory array that contains instructions.
 *
 * @param location Location of the top of the stack.
 */
void scc::stack_space_check(int location) const
{
    // If top of the stack has hit the instructions...
    if (location < inst_addr)
    {
        cout << "*** ERROR: insufficient stack space ***\n";
        exit(1);
    }
}

/**
 * Gets the location of a constant or variable, adding it
 * to the symbol table and memory if necessary.
 *
 * @param token The symbol to locate.
 *
 * @return The symbol's location.
 */
int scc::find_location(const string& token)
{
    int location, symbol;
    char type;

    if (islower(token[0]))
    {
        // This is a variable.
        symbol = token[0];
        type = 'V';
    }
    else
    {
        // This is an integer constant.
        symbol = stoi(token);
        type = 'C';
    }

    int index = search_table(symbol, type);

    if (index == -1)
    {
        // This symbol is not in the symbol table yet.
        
        // Add this symbol to the symbol table and memory.
        location = next_const_or_var_addr;

        // Add symbol to symbol table.
        symbol_table[next_symbol_table_idx].symbol = symbol;
        symbol_table[next_symbol_table_idx].type = type;
        symbol_table[next_symbol_table_idx].location = location;
        next_symbol_table_idx++;

        // Add this constant or variable to memory.
        check_mem();
        if (type == 'V')
            memory[location] = 0;
        else
            memory[location] = symbol;

        next_const_or_var_addr--;
    }
    else
    {
        // This symbol is in the symbol table at element
        // index.
        location = symbol_table[index].location;
    }

    return location;
}

/**
 * Searches the symbol table for a symbol with a particular
 * type.
 *
 * @param symbol The symbol to search for.
 * @param type The type of the symbol to search for.
 *
 * @return The location of the symbol or -1 if the search
 *         failed.
 *
 * @note Uses the linear search algorithm.
 */
int scc::search_table(int symbol, char type) const
{
    for (int i = 0; i < next_symbol_table_idx; i++)
    {
        if (symbol == symbol_table[i].symbol && type ==
            symbol_table[i].type)
            return i;
    }

    return -1;
}

/**
 * Generates code for a "input" instruction.
 *
 * @param ss Input string stream from which to read.
 */
void scc::handle_input(istringstream& ss)
{
    string token;

    ss >> token;

    int location = find_location(token);

    check_mem();
    memory[inst_addr] = READ * 100 + location;
    inst_addr++;
}

/**
 * Generates code for a "data" instruction.
 *
 * @param ss Input string stream from which to read.
 */
void scc::handle_data(istringstream& ss)
{
    int number;

    ss >> number;
    data_check();
    data[ndata] = number;
    ndata++;
}

/**
 * Generates code for an "end" instruction.
 */
void scc::handle_end()
{
    check_mem();
    memory[inst_addr] = HALT * 100;
    inst_addr++;
}
