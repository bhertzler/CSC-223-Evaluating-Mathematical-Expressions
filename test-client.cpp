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
	InfixToPostfixConverter converter;
	string infix;
	
	cout << "Enter Infix Expression: ";
	getline(cin, infix);

	try {
		converter.convert(infix);
		std::cout << converter.getPostfix() << endl;
	}
	catch (const exception& e) {
		cerr << "Error: " << e.what() << endl;
	}

	return 0;
}