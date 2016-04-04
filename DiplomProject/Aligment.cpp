#include "Aligment.h"


Aligment::Aligment()
{
	firstSequence = NULL;
	secondSequence = NULL;
	aligment = NULL;
}


Aligment::~Aligment()
{
	if (firstSequence != NULL)
	{
		delete firstSequence;
		firstSequence = NULL;
	}
	if (secondSequence != NULL)
	{
		delete secondSequence;
		secondSequence = NULL;
	}
	if (aligment != NULL)
	{
		delete aligment;
		aligment = NULL;
	}
}
