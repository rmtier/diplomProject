#include "Task.h"


Task::Task()
{
	dnaSequence = NULL;
	searchingDNAsequence = NULL;
}


Task::~Task()
{
	if (dnaSequence != NULL)
		delete dnaSequence;
	if (searchingDNAsequence != NULL)
		delete searchingDNAsequence;
}
