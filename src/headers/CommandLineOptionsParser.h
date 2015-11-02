//
// Created by joseph on 28/10/15.
//

#ifndef RELAXSL_COMMANDLINEOPTIONSPARSER_H
#define RELAXSL_COMMANDLINEOPTIONSPARSER_H

#include <iostream>
#include <vector>

class CommandLineOptionsParser
{
private:
	std::string xmlVersion = "1.0";
	std::string xslVersion = "1.0";
	std::string encoding = "UTF-8";
	std::string inputFile = "";

	std::vector<std::string> optionsList;

public:
	CommandLineOptionsParser(int argc, char* argv[]);

	const std::string& getXmlVersion() const;
	const std::string& getXslVersion() const;
	const std::string& getEncoding() const;
	const std::string& getInputFile() const;

private:
	void buildOptionsList(int argc, char* argv[]);
	void parseOptionsList();
	void printUsage(std::string information = "", bool exitFailure=false);
};


#endif //RELAXSL_COMMANDLINEOPTIONSPARSER_H