#pragma once
#include <string>
#include <vector>
enum ALGORITHM{
	NEEDLEMAN_WUNCH,
};
/*
* @author: Rami Mtier
* @description: This is only data structure and not have a computation logic. 
*				char pointer in structure are like "TGCTGCTGC"
*/
class Task
{
	friend class MessageBuilder;
public:
	Task();
	virtual ~Task();
	std::vector<char> * getDNASequence() { return dnaSequence; }
	std::vector<char> * getSearchingSequence(){ return searchingDNAsequence; }
	ALGORITHM getAlgorithm(){ return algorithm; }
	int getMatch(){ return match; }
	int getMissmatch() { return missmatch; }
	int getGap() { return gap; }
private:
	std::vector<char> * dnaSequence; //inputs string whitch is aligned with comparingString 
	std::vector<char> * searchingDNAsequence; //aligment char array
	ALGORITHM algorithm;
	int match;
	int missmatch;
	int gap;
};

