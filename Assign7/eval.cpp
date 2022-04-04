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
#include "inpost.cpp"

using std::string;
using std::stringstream;

int evaluate(const string& postfix)
{
    string op;
    stringstream ss(postfix);  // create a stringstream obj from the postfix string

    // Read from the stringstream as if it were standard input. The end of the string
    // will be treated as the end of input.
    mystack<int> eval_stack;

    // main logic to evaluate postfix expression
    while (ss >> op)
    {
        // need code here
        if(isdigit(op[0]))
        {
            eval_stack.push(op[0]);
        }
        else if(isalpha(op[0]))
        {
            eval_stack.push(op[0]) - 'a';
        }
        else if(op[0] == "~")
        {
            // get the top item from the eval stack
            int temp = eval_stack.top();
            // pop the stack
            eval_stack.pop();
            // apply the operator, push the result on the eval_stack
            // might need more
            eval_stack.push(temp);
        }
        else
        {
            // get the top item of the eval_stack, right operand
            int tempR = eval_stack.top();
            // pop the stack
            eval_stack.pop();
            // apply operator and push result onto eval_stack, left operand
            int tempL = eval_stack.top();
            // pop the stack
            eval_stack.pop();

            // check operator, apply when match case
            switch(op)
            {
                // given '+' operator, add the left and right operands
                case (op == "+"):
                    eval_stack.push(l + r);
                    break;

                // given '-' operator, subtract the left and right operands
                case (op == "-"):
                    eval_stack.push(l - r);
                    break;

                // given '*' operator, multiply the left and right operands
                case (op == "*"):
                    eval_stack.push(l * r);
                    break;
                
                // given '/' operator, divide the left operand by the right operand
                case (op == "/"):
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

                // given '^' operator, raise the left operand to the right operand
                case (op == "^"):
                    eval_stack.push(pow(l,r));
                    break;                
            }
        }
    }
}