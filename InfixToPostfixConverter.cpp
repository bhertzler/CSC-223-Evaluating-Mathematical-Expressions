// InfixToPostfixConverter.cpp: Implementation file for the InfixToPostfixConverter class.
//

// Benjamin Hertzler
// CSC 223
// Evaluating Mathematical Expressions Project
//

#include "InfixToPostfixConverter.h"
#include <string>
#include <sstream>
#include <cctype>
#include <stack>
using namespace std;

void InfixToPostfixConverter::convert()
throw (InvalidTokenException)
{
    stack<char> op_stack;
    istringstream ss(infix);
    string token;
    postfix = "";

    while (ss >> token)
    {
        
        char ch = token[0];

        // Operand (number or variable)
        if (isdigit(ch) || (isalpha(ch)) || (ch == '.' && token.length() > 1))
        {
            postfix += token + " ";
        }
        // Opening parenthesis
        else if (ch == '(')
        {
            op_stack.push(ch);
        }
        // Closing parenthesis
        else if (ch == ')')
        {
            while (!op_stack.empty() && op_stack.top() != '(')
            {
                postfix += op_stack.top();
                postfix += " ";
                op_stack.pop();
            }
            if (op_stack.empty())
                throw InvalidTokenException();  // Unmatched ')'
            op_stack.pop();  // Discard '('
        }
        // Operator
        else
        {
            int op_level = precedence(ch);
            if (op_level == -1)
                throw InvalidTokenException();  // Unknown character

            while (!op_stack.empty())
            {
                char top = op_stack.top();
                int top_level = precedence(top);

                // Check associativity: '^' is right-associative
                if ((op_level < top_level) || (op_level == top_level && ch != '^'))
                {
                    postfix += top;
                    postfix += " ";
                    op_stack.pop();
                }
                else
                {
                    break;
                }
            }
            op_stack.push(ch);
        }
    }

    // Pop any remaining operators
    while (!op_stack.empty())
    {
        if (op_stack.top() == '(')
            throw InvalidTokenException();  // Unmatched '('
        postfix += op_stack.top();
        postfix += " ";
        op_stack.pop();
    }
}

void InfixToPostfixConverter::convert(string infix_str)
{
	setInfix(infix_str);
	convert();
}

int InfixToPostfixConverter::precedence(char op)
{
	switch (op)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	default:
		return -1;
	}
}