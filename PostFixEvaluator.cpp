// PostFixEvaluator.cpp: Implementation file for the PostFixEvaluator class.
//

// Benjamin Hertzler
// CSC 223
// Evaluating Mathematical Expressions Project
//

#include "PostFixEvaluator.h"
#include <string>
#include <sstream>
#include <cmath>
#include <stack>
using namespace std;

#define OPERATORS "+-*/^"

void PostFixEvaluator::evaluate() throw (InvalidExpressionException)
{
	istringstream ss(postfix);
	string token;
	stack<double> op_stack;

	while (ss >> token)
	{
		char ch = token[0];
		if (isdigit(ch) || ch == '.' || (token.length() > 1 && ch == '-' || ch == '+') && isdigit(token[1]))
		{
			try
			{
				double num = stod(token);
				op_stack.push(num);
			}
			catch (...)
			{
				throw InvalidExpressionException("Invalid Operand: " + token);
			}
		}
		else if (token.length() == 1 && string(OPERATORS).find(ch) != string::npos)
		{
			if (op_stack.size() < 2)
				throw InvalidExpressionException("Insufficient Operands for Operator: " + token);

			double k = op_stack.top();
			op_stack.pop();
			double h = op_stack.top();
			op_stack.pop();
			double ans;

			switch (ch)
			{
			case '+':
				ans = h + k;
				break;
			case '-':
				ans = h - k;
				break;
			case '*':
				ans = h * k;
				break;
			case '/':
				if (k == 0)
					throw InvalidExpressionException("Division by Zero");
				ans = h / k;
				break;
			case '^':
				ans = pow(h, k);
				break;
			default:
				throw InvalidExpressionException("Unknown Operator: " + token);
			}
			op_stack.push(ans);
		}
		else
			throw InvalidExpressionException("Unexpected Token: " + token);
	}

	if (op_stack.size() != 1)
		throw InvalidExpressionException("Malformed Expression");

	result = op_stack.top();
}

void PostFixEvaluator::evaluate(string postfix_str)
{
	setPostfix(postfix_str);
	evaluate();
}


