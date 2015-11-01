#include <iostream>

#include "headers/CommandLineOptionsParser.h"

using namespace std;

int main(int argc, char* argv[])
{
	cout << "Hello, this is a test, for this amazing (I hope) experimental project." << endl;
	CommandLineOptionsParser clop(argc, argv);

	return 0;
}