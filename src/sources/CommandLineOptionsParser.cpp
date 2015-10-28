//
// Created by joseph on 28/10/15.
//

#include "../headers/CommandLineOptionsParser.h"

CommandLineOptionsParser::CommandLineOptionsParser(int argc, char* argv[])
{
	buildOptionsList(argc, argv);
}

const std::string& CommandLineOptionsParser::getXmlVersion() const
{
	return xmlVersion;
}

const std::string& CommandLineOptionsParser::getXslVersion() const
{
	return xslVersion;
}

const std::string& CommandLineOptionsParser::getEncoding() const
{
	return encoding;
}

void CommandLineOptionsParser::buildOptionsList(int argc, char** argv)
{
	for (int i = 0; i < argc; i++)
	{
		optionsList.push_back(argv[i]);
	}
}

void CommandLineOptionsParser::parseOptionsList()
{

}

const std::vector<std::string>& CommandLineOptionsParser::getOptionsList() const
{
	return optionsList;
}
