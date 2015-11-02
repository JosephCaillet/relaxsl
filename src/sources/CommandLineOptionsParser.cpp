//
// Created by joseph on 28/10/15.
//
#include <iostream>
#include "../headers/CommandLineOptionsParser.h"

#define VERSION_TEXT "Relaxsl, v0.1 by Joseph Caillet"
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

const std::string& CommandLineOptionsParser::getInputFile() const
{
	return inputFile;
}

void CommandLineOptionsParser::buildOptionsList(int argc, char* argv[])
{
	for(int i=0; i<argc; i++)
	{
		optionsList.push_back(argv[i]);
	}
}

void CommandLineOptionsParser::parseOptionsList()
{
	for(unsigned int i=1; i<optionsList.size(); i++)
	{
		if(optionsList[i] == "--xmlV")
		{
			if(i < optionsList.size())
			{
				xmlVersion = optionsList[i+1];
				i++;
			}
			else
			{
				printUsage("Incorect or empty xml version.");
			}
		}
		else if(optionsList[i] == "--xslV")
		{
			if(i < optionsList.size())
			{
				xslVersion = optionsList[i+1];
				i++;
			}
			else
			{
				printUsage("Incorect or empty xslt version.");
			}
		}
		else if(optionsList[i] == "--enco")
		{
			if(i < optionsList.size())
			{
				encoding = optionsList[i+1];
				i++;
			}
			else
			{
				printUsage("Incorect or empty encoding.");
			}
		}
		else if(optionsList[i] == "-h")
		{
			printUsage("Relaxsl help:", false);
		}
		else if(optionsList[i] == "-v")
		{
			cout << VERSION_TEXT;
			exit(EXIT_SUCCESS);
		}
		else if(i == optionsList.size()-1)
		{
			cout << "Dernier elm: " << optionsList[i];
			inputFile = optionsList[i];
		}
		else
		{
			printUsage("Unknow option: " + optionsList[i]);
		}
	}

	if(inputFile.empty())
	{
		printUsage("No input filename.");
	}
}

void CommandLineOptionsParser::printUsage(string information, bool exitFailure)
{
	cout << information << endl;
	cout << "Usage: relaxsl [ [-v | -h] | [--xmlV \"xml version\"] [--xslV \"xslt version\"] [--enco \"file encoding\"] filename.rsl ]" << endl;
	if(exitFailure)
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}
