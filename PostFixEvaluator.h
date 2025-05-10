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
	void evaluate();
	void evaluate(std::string postfix_str);
	void setPostfix(std::string postfix_str) { postfix = postfix_str; }
	double getResult() const { return result; }

	PostFixEvaluator() : postfix(""), result(0) {}
	PostFixEvaluator(std::string postfix_str) { evaluate(postfix_str); }
private:
	std::string postfix;
	double result;
};

