//*******************************************************************
//
//  inpost.cpp
//  CSCI 241 Assignment 7
//
//  Michael Marchetti z1860574
//
//*******************************************************************

#include <iostream>
#include <string>
#include <stack>
#include "inpost.h"
#include "mystack.h"

using namespace std;

// function that defines precedence of operators 
int precedence(char op)
{
    // switch statement to define the precedence of operators, descending order
    switch(op)
    {
        case '~':
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return -1;
    }
}
// function to convert an infix expression into an equivalent postfix expression
string convert (const string& infix)
{
    string postfix = "";
    mystack stack;

    // increment through the infix expression
    for (size_t i = 0; i < infix.length(); i++)
    {
        // check if lowercase
        if (islower(infix[i]))
        {
            // add space 
            postfix += infix[i];
            postfix += ' ';
        }
        // check if digit
        else if (isdigit(infix[i]))
        {
            // while length is greater than i, and infix is a digit 
	    // This will run for a num
            while (i < infix.length() && isdigit(infix[i]))
            {
                // append as postfix and increment
                postfix += infix[i];
                i++;
            }
	    // decrement and add space postfix
            i--;
            postfix += ' ';
        }
        // check if infix is a left parenthese
        else if (infix[i] == '(')
        {
            // push value
            stack.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            // while mystack is not empty and the top is not a left parenthese
	    // convert what is inside the parantheses
            while (!stack.empty() && stack.top() != '(')
            {
		// empty the stack
                postfix += stack.top();
                postfix += ' ';
                stack.pop();
            }
	    // check if top is a left parenthese
            if (stack.top() == '(')
            {
                stack.pop();
            }
        }
        // check if infix is not a space
        else if (infix[i] != ' ')
        {
            // while stack is not empty and the precedence for the current index is
	    // less than the precedence for the top, this will be an op
            while (!stack.empty() && precedence(infix[i]) <= precedence(stack.top()))
            {
		// empty the stack
                postfix += stack.top();
                postfix += ' ';
                stack.pop();
            }
	    // push
            stack.push(infix[i]);
            
        }
    }

    // while stack is not empty
    while (!stack.empty())
    {
        // empty the rest of the stack
        postfix += stack.top();
        postfix += ' ';
        stack.pop();
    }

    // clear any whitespace
    postfix.pop_back();
    return postfix;
}
