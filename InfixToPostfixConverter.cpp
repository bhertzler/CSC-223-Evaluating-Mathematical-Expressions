// InfixToPostfixConverter.cpp: Implementation file for the InfixToPostfixConverter class.
//

// Benjamin Hertzler
// CSC 223
// Evaluating Mathematical Expressions Project
//


#include "InfixToPostfixConverter.h"
#include <sstream>
#include <stack>
#include <cctype>
#include <vector>
using namespace std;

void InfixToPostfixConverter::convert()
throw(InvalidTokenException, MalformedExpressionException)
{
    stack<char> op_stack;
    istringstream ss(infix);
    string token;
    vector<string> output;
    bool operand_last = false;

    while (ss >> token) 
    {
        // Operand (number or variable)
        if (isdigit(token[0]) || isalpha(token[0]) || token[0] == '.') 
        {
            for (char c : token) 
            {
                if (!isdigit(c) && !isalpha(c) && c != '.')
                    throw InvalidTokenException("Invalid character in operand: " + token);
            }
            output.push_back(token);
            operand_last = true;
        }
        // Left parenthesis
        else if (token == "(") 
        {
            op_stack.push('(');
            operand_last = false;
        }
        // Right parenthesis
        else if (token == ")") 
        {
            while (!op_stack.empty() && op_stack.top() != '(') 
            {
                output.emplace_back(string(1, op_stack.top()));
                op_stack.pop();
            }
            if (op_stack.empty())
                throw MalformedExpressionException("Unmatched parenthesis");
            op_stack.pop(); // remove '('
            operand_last = true;
        }
        // Operator
        else if (token.length() == 1 && precedence(token[0]) != -1) 
        {
            char ch = token[0];
            int op_level = precedence(ch);

            if (!operand_last)
                throw MalformedExpressionException("Operator not preceded by operand");

            while (!op_stack.empty()) 
            {
                char top = op_stack.top();
                int top_level = precedence(top);
                if ((op_level < top_level) || (op_level == top_level && ch != '^')) 
                {
                    output.emplace_back(string(1, top));
                    op_stack.pop();
                }
                else 
                {
                    break;
                }
            }
            op_stack.push(ch);
            operand_last = false;
        }
        else 
        {
            throw InvalidTokenException("Unknown token: " + token);
        }
    }

    if (!operand_last)
        throw MalformedExpressionException("Expression ends with operator");

    while (!op_stack.empty()) 
    {
        if (op_stack.top() == '(')
            throw MalformedExpressionException("Unmatched parenthesis");
        output.emplace_back(string(1, op_stack.top()));
        op_stack.pop();
    }

    ostringstream oss;
    for (size_t i = 0; i < output.size(); ++i) 
    {
        oss << output[i];
        if (i != output.size() - 1)
            oss << " ";
    }
    postfix = oss.str();
}

void InfixToPostfixConverter::convert(string infix_str) 
{
    setInfix(infix_str);
    convert();
}

void InfixToPostfixConverter::setInfix(string infix_str) 
{
    infix = move(infix_str);
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