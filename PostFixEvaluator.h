// PostFixEvaluator.h: this is the specification file for the PostFixEvaluator class.
//

// Benjamin Hertzler
// CSC 223
// Evaluating Mathematical Expressions Project
//

#pragma once
#include <string>
#include <stdexcept>

// Exception Classes

// Malformed Postfix Expression
class InvalidExpressionException : public std::exception
{
public:
	explicit InvalidExpressionException(const std::string& msg = "Invalid Expression")
		: message(msg) {}
	const char* what() const noexcept override { return message.c_str(); }
private:
	std::string message;
};

// Object Class

class PostFixEvaluator
{
public:
	// Default evaluator function.
	// Precondition: string postfix must be a valid postfix expression.
	// Postcondition: the solution to the expression will be stored in double result
	//
	void evaluate() throw (InvalidExpressionException);

	// Overloaded evaluator function.
	// Precondition: string postfix_str must be a valid postfix expression.
	// Postcondition: the solution to the expression will be stored in double result
	//
	void evaluate(std::string postfix_str);

	// Function to set the postfix expression
	// Precondition: string postfix_str must be a valid postfix expression.
	//
	void setPostfix(std::string postfix_str) { postfix = postfix_str; }

	// Function to retrieve the result of the expression as a double.
	double getResult() const { return result; }

	// Default constructor
	PostFixEvaluator() : postfix(""), result(0) {}

	// Parameterized constructor
	// Precondition: string postfix_str must be a valid postfix expression.
	// Postcondition: the solution to the expression will be stored in double result.
	//
	PostFixEvaluator(std::string postfix_str) { evaluate(postfix_str); }

private:
	std::string postfix;	// string to store the postfix expression.
	double result;			// double to store the solution to the expression.
};

