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
		delete firstSequence;
	if (secondSequence != NULL)
		delete secondSequence;
	if (aligment != NULL)
		delete aligment;
}
