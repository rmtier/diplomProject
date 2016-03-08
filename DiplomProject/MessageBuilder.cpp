#include "MessageBuilder.h"

MessageBuilder::MessageBuilder()
{
}

Task* MessageBuilder::createTask(std::string * dnaSequence, std::string * searchingDnaSequence){
	int i = 0;
	std::vector<char> * searchingDnaVector = new std::vector<char>(searchingDnaSequence->size(), '\0');
	std::vector<char> * dnaVector = new std::vector<char>(dnaSequence->size(), '\0');
	
	copy(dnaSequence, dnaVector, dnaSequence->size());
	copy(searchingDnaSequence, searchingDnaVector, searchingDnaSequence->size());

	Task* message = new Task();

	message->algorithm = NEEDLEMAN_WUNCH;
	message->dnaSequence = dnaVector;
	message->searchingDNAsequence = searchingDnaVector;
	return message;
}

void MessageBuilder::copy(std::string * str, std::vector<char> * v, int length)
{
	for (int i = 0; i < length; i++)
	{
		v->at(i) = str->at(i);
	}
}

Aligment* MessageBuilder::createAligment(std::vector<aligmentStr> * vector, std::string algorithm, std::vector<char> *str1, std::vector<char> *str2){
	Aligment * aligment = new Aligment();
	aligment->aligment = vector;
	aligment->algorithm = algorithm;
	aligment->firstSequence = str1;
	aligment->secondSequence = str2;
	return aligment;
}


MessageBuilder::~MessageBuilder()
{
}
