#pragma once
#include "Task.h"
#include "Aligment.h"
#include <stdio.h>
#include <stdlib.h>
/*
* @file
* @author: Rami Mtier
* @date: 26.2. 2016
*
* @section DESCRIPTION
* Building messages, that represent data structures
*/
class MessageBuilder
{
public:
	MessageBuilder();
	virtual ~MessageBuilder();
	/*
	* Convert args and make new Message
	* first arg: vector<string> to matrix: vector<vector<char>>
	* second arg: string to vector<char>
	*/
	static Task* createTask(std::string * dnaSequence, std::string * searchingDnaSequence, int, int, int);
	static Aligment* createAligment(std::vector<aligmentStr> * vector, std::string algorithm);
	static void copy(std::string * str, std::vector<char> * v, int length);

};

