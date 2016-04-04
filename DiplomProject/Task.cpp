#include "Task.h"


Task::Task()
{
	dnaSequence = NULL;
	searchingDNAsequence = NULL;
}


Task::~Task()
{
	if (dnaSequence != NULL)
	{
		delete dnaSequence;
		dnaSequence = NULL;
	}
	if (searchingDNAsequence != NULL)
	{
		delete searchingDNAsequence;
		searchingDNAsequence = NULL;
	}
}
