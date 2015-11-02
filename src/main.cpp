#include <iostream>

#include "headers/CommandLineOptionsParser.h"

using namespace std;

int main(int argc, char* argv[])
{
	//cout << "Hello, this is a test, for this amazing (I hope) experimental project." << endl;
	CommandLineOptionsParser clop(argc, argv);

	cout << clop.getEncoding() << endl;
	cout << clop.getXmlVersion() << endl;
	cout << clop.getXslVersion() << endl;
	cout << clop.getInputFile() << endl;

	return 0;
}