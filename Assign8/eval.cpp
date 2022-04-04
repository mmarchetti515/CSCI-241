//************************************************
//
// eval.cpp
// CSCI 241 Assignment 8
//
// Michael Marchetti z1860574
//
//************************************************

#include <cmath> // for pow()
#include <iostream>
#include <string>
#include <sstream>
#include "inpost.h"
#include "mystack.h"
#include "eval.h" // edit made 11.4.21

using std::string;
using std::stringstream;

int evaluate(const string& postfix)
{
    mystack eval_stack;
    string op;
    stringstream ss(postfix);  // create a stringstream obj from the postfix string

    // Read from the stringstream as if it were standard input. The end of the string
    // will be treated as the end of input

    // main logic to evaluate postfix expression
    while (ss >> op)
    {
        // check for operand
        if(isdigit(op[0]))
        {
            eval_stack.push(stoi(op));
        }
        // check for variable
        else if(isalpha(op[0]))
        {
            // assuming single letter variable name is stored in program's variable
            eval_stack.push(op[0] - 'a');
        }
        // check for '~' operator
        else if(op[0] == '~')
        {
            // get the top item from the eval stack
            int temp = eval_stack.top();
            // pop the stack
            eval_stack.pop();
            // apply the operator, push the result on the eval_stack
            eval_stack.push(-temp);
        }
        else
        {
            // get the top item of the eval_stack, right operand
            int r = eval_stack.top();
            // pop the stack
            eval_stack.pop();
            // apply operator and push result onto eval_stack, left operand
            int l = eval_stack.top();
            // pop the stack
            eval_stack.pop();

            // check operator, apply when match case
            switch(op[0])
            {
                // given '+' operator, add the left and right operands
                case '+':
                    eval_stack.push(l + r);
                    break;

                // given '-' operator, subtract the left and right operands
                case '-':
                    eval_stack.push(l - r);
                    break;

                // given '*' operator, multiply the left and right operands
                case '*':
                    eval_stack.push(l * r);
                    break;
                
                // given '/' operator, divide the left operand by the right operand
                case '/':
                    // account for divide by zero error
                    if(r == 0)
                    {
                        cout << "*** Division by 0 ***\n";
                        eval_stack.push(0);
                    }
                        // not divide by zero
                        else
                        {
                            eval_stack.push(l / r); 
                            break;
                        }
		    break;

                // given '^' operator, raise the left operand to the right operand
                case '^':
                    // initialize result
                    int result = 1;
                    // loop through right hand side operand until power is satisfied
                    for(int i = 1; i <= r; i++)
                    {
                        result *= l;
                    }
		    eval_stack.push(result);
                    break;                
            }
        }
    }
    return eval_stack.top(); // edit made 11.4.21
}
