// InfixToPostfixConverter.h: this is the specification file for the InfixToPostfixConverter class.
//

// Benjamin Hertzler
// CSC 223
// Evaluating Mathematical Expressions Project
//

#pragma once
#include <string>
#include <stdexcept>

// Exception Classes

// Invalid character detected
class InvalidTokenException : public std::exception 
{
public:
	explicit InvalidTokenException(const std::string& msg = "Invalid token")
		: message(msg) {
	}
	const char* what() const noexcept override { return message.c_str(); }
private:
	std::string message;
};

// Argument string is not formatted in proper infix notation
class MalformedExpressionException : public std::exception 
{
public:
	explicit MalformedExpressionException(const std::string& msg = "Malformed expression")
		: message(msg) {
	}
	const char* what() const noexcept override { return message.c_str(); }
private:
	std::string message;
};

// Converts an infix string to a postfix string.
class InfixToPostfixConverter 
{
public:
	// Default conversion function.
	// Precondition: string infix must be a valid string of whitespace separated tokens.
	// 
	void convert() throw(InvalidTokenException, MalformedExpressionException);

	// Overloaded conversion function.
	// Precondition: string infix_str must be a valid string of whitespace separated tokens.
	//
	void convert(std::string infix_str);

	// Function to set the infix string.
	// Precondition: string infix_str must be a valid string of whitespace separated tokens.
	//
	void setInfix(std::string infix_str);

	// Function to return the infix string in postfix notation
	std::string getPostfix() const { return postfix; }

	// Default Constructor
	InfixToPostfixConverter() : infix(""), postfix("") {}

	// Parameterized Constructor
	// Precondition: string infix_str must be a valid string of whitespace separated tokens.
	//
	explicit InfixToPostfixConverter(std::string infix_str) { convert(infix_str); }

private:
	int precedence(char op);		// Internal function to calculate the precedence of operations.
	std::string infix;				// Variable to store the infix string.
	std::string postfix;			// Variable to store the postfix string.
};


