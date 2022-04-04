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

// 
int precedence(char op)
{
    //
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

string convert (const string& infix)
{
    string postfix = "";
    mystack stack;

    // 
    for (size_t i = 0; i < infix.length(); i++)
    {
        //
        if (islower(infix[i]))
        {
            // 
            postfix += infix[i];
            postfix += ' ';
        }
        //
        else if (isdigit(infix[i]))
        {
            // 
            while (i < infix.length() && isdigit(infix[i]))
            {
                //
                postfix += infix[i];
                i++;
            }
            i--;
            postfix += ' ';
        }
        //
        else if (infix[i] == '(')
        {
            //
            stack.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            // 
            while (!stack.empty() && stack.top() != '(')
            {
                postfix += stack.top();
                postfix += ' ';
                stack.pop();
            }
            if (stack.top() == '(')
            {
                stack.pop();
            }
        }
        //
        else if (infix[i] != ' ')
        {
            //
            while (!stack.empty() && precedence(infix[i]) <= precedence(stack.top()))
            {
                postfix += stack.top();
                postfix += ' ';
                stack.pop();
            }
            stack.push(infix[i]);
            
        }
    }

    // 
    while (!stack.empty())
    {
        //
        postfix += stack.top();
        postfix += ' ';
        stack.pop();
    }

    // 
    postfix.pop_back();
    return postfix;
}
