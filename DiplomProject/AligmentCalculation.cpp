#include "AligmentCalculation.h"


AligmentCalculation::AligmentCalculation()
{
}


AligmentCalculation::~AligmentCalculation()
{
}

Aligment * AligmentCalculation::calculateTask(Task * task)
{
	Aligment * returningValue = NULL;
	std::vector<aligmentStr> * aligment;
	if (task->getAlgorithm() == NEEDLEMAN_WUNCH)
	{
		NeedlemanWunschAlgorithm algorithm;
		aligment = algorithm.alignSequences(task->getDNASequence(), task->getSearchingSequence(), task->getMatch(), task->getMissmatch(), task->getGap());
		returningValue = MessageBuilder::createAligment(aligment, "Needleman_Wunch");
	}
	delete task;
	return returningValue;
}