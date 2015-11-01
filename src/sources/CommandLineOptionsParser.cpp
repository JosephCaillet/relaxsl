//
// Created by joseph on 28/10/15.
//
#include <iostream>
#include "../headers/CommandLineOptionsParser.h"

using namespace std;

CommandLineOptionsParser::CommandLineOptionsParser(int argc, char* argv[])
{
	buildOptionsList(argc, argv);
	parseOptionsList();
}

const string& CommandLineOptionsParser::getXmlVersion() const
{
	return xmlVersion;
}

const string& CommandLineOptionsParser::getXslVersion() const
{
	return xslVersion;
}

const string& CommandLineOptionsParser::getEncoding() const
{
	return encoding;
}

void CommandLineOptionsParser::buildOptionsList(int argc, char** argv)
{
	for (int i = 0; i<argc; i++)
	{
		optionsList.push_back(argv[i]);
	}
}

void CommandLineOptionsParser::parseOptionsList()
{
	for(unsigned int i=1; i<optionsList.size(); i++)
	{
		cout << "Arg: " << optionsList[i] << endl;
		if(optionsList[i] == "--xmlV" && i != optionsList.size())
		{
			xslVersion = optionsList[i+1];
			cout << "\toption xmlV found. value: " << optionsList[i+1] << endl;
			i++;
		}
	}
}

void CommandLineOptionsParser::printUsage()
{
	cout << "Usage: relaxsl filename.rsl [--xmlV \"xml version\"] [--xslV \"xslt version\"] [--enco \"file encoding\"]" << endl;
}
