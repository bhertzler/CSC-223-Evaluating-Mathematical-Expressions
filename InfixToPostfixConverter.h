// InfixToPostfixConverter.h: this is the specification file for the InfixToPostfixConverter class.
//

// Benjamin Hertzler
// CSC 223
// Evaluating Mathematical Expressions Project
//

#pragma once
#include <string>

class InfixToPostfixConverter
{
public:
	
	// Exception Classes

	class InvalidTokenException
	{
	public:
		InvalidTokenException() { message = "Invalid Token Encountered"; }
		std::string what() const { return message; }
	private:
		std::string message;
	};
	
	class MalformedExpressionException
	{
	public:
		MalformedExpressionException() { message = "Malformed Expression: The expression is not formatted in correct infix notation."; }
		std::string what() const { return message; }
	private:
		std::string message;
	};

	class DivideByZeroException
	{
	public:
		DivideByZeroException() { message = "Cannot Divide by Zero"; }
		std::string what() const { return message; }
	private:
		std::string message;
	};

	class StackOverflowException
	{
	public:
		StackOverflowException() { message = "Stack Overflow"; }
		std::string what() const { return message; }
	private:
		std::string message;
	};
	
	void convert()
		throw (InvalidTokenException);
	void convert(std::string infix_str);
	void setInfix(std::string infix_str) { infix = infix_str; }
	std::string getPostfix() const { return postfix; }

	InfixToPostfixConverter() : infix(""), postfix("") {}
	InfixToPostfixConverter(std::string infix_str) { convert(infix_str); }

private:
//	void sortOperator(char op, stack<char>& operations);
	int precedence(char op);
	std::string infix = "";
	std::string postfix = "";
};



