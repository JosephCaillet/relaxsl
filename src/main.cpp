#include <iostream>
#include <vector>

#include "headers/CommandLineOptionsParser.h"

using namespace std;

int main(int argc, char* argv[])
{
	cout << "Hello, this is a test, for this amazing (I hope) experimental project." << endl;
	CommandLineOptionsParser clop(argc, argv);
	vector<string> opl = clop.getOptionsList();

	for(unsigned int i=0; i<opl.size(); i++)
	{
		cout << opl[i] << endl;
	}
	return 0;
}