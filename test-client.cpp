// test-client.cpp: this file contains the 'main' function.
//

// Benjamin Hertzler
// CSC 223
// Evaluating Mathematical Expressions Project
//

#include "InfixToPostfixConverter.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string infix;
	
	cout << "Enter Infix Expression: ";
	getline(cin, infix);

	try
	{
		string postfix = InfixToPostfixConverter(infix).getPostfix();
		cout << "Postfix Notation: " << postfix << endl;
	}
	catch (const InfixToPostfixConverter::InvalidTokenException& e)
	{
		cerr << "Error: " << e.what() << endl;
	}
	
	return 0;
}