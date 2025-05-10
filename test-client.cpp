// test-client.cpp: this file contains the 'main' function.
//

// Benjamin Hertzler
// CSC 223
// Evaluating Mathematical Expressions Project
//

#include "PostFixEvaluator.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define FILE_NAME "RpnData.txt"

int main() 
{
	ifstream f(FILE_NAME);
	string line;

	if (f.is_open())
	{
		while (getline(f, line))
		{
			string output;
			try
			{
				double result = PostFixEvaluator(line).getResult();
				output = to_string(result);
			}
			catch (const exception& e)
			{
				output = e.what();
			}
			cout << line << " = " << output << endl;
		}
		f.close();
	}
	else
		cerr << "Invalid File" << endl;

	return 0;
}