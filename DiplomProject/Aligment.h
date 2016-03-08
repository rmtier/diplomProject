#pragma once
#include <vector>
struct aligmentStr{
	char first;
	char second;
	bool pipe;
};
/*
* @file Aligment
* @author: Rami Mtier
* @date: 28.2.2016
* 
* @section DESCRIPTION
* Data structure of aligming dvo sequences and used algorithm
*/
class Aligment
{
	friend class MessageBuilder;
private:
	std::vector<char> * firstSequence;
	std::vector<char> * secondSequence;
	std::vector<aligmentStr> * aligment; //indexes in aligment
	std::string algorithm;
public:
	std::vector<aligmentStr> * getAligment(){ return aligment; }
	std::vector<char> * getFirstSequence() { return firstSequence; };
	std::vector<char> * getSecondSequence() { return secondSequence; };
	std::string getAlgorithm() { return algorithm; }
	Aligment();
	~Aligment();
};

