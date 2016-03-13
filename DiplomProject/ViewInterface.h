#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "MessageBuilder.h" 
/**
* @file
* @author Rami Mtier
* 
* @section DESCRIPTION
* Class is interface to the console
*/
#define SIZEOFINPUTARRAY 100
#define SIZEOFGENBUFFER 1000
#define NUMBEROFROWININTERFACE 50
class ViewInterface
{
public:
	ViewInterface();
	~ViewInterface();
	bool continueComputing();
	/**
	* take a message, that represent task to do
	* @return Task to do
	*/
	Task* takeTask();
	void print(Aligment * , long , std::string);

private:
	std::vector<Task*> doListOfMessages; ///<Thinks to do>
	void initConsole();
	void clearConsole();
	void readFromFiles(std::string inputFileName, std::string compareFileName, std::string outFileName);

};


