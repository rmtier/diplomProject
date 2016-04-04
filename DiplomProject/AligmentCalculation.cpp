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
	switch (task->getAlgorithm())
	{
		case(NEEDLEMAN_WUNCH) :
		{
			NeedlemanWunschAlgorithm algorithm;
			aligment = algorithm.alignSequences(task->getDNASequence(), task->getSearchingSequence(), task->getMatch(), task->getMissmatch(), task->getGap());
			returningValue = MessageBuilder::createAligment(aligment, "Needleman_Wunch");
			break;
		}
		case (SMITH_WATERMAN) :
		{
			SmithWatermanAlgorithm algorithm;
			aligment = algorithm.alignSequences(task->getDNASequence(), task->getSearchingSequence(), task->getMatch(), task->getMissmatch(), task->getGap());
			returningValue = MessageBuilder::createAligment(aligment, "Smith_Waterman");
			break;
		}
		case (BLAST):
		{
			BlastAlgorithm algorithm;
			aligment = algorithm.alignSequences(task->getDNASequence(), task->getSearchingSequence(), task->getMatch(), task->getMissmatch(), task->getGap());
			returningValue = MessageBuilder::createAligment(aligment, "Smith_Waterman");
			break;
		}
	}
	delete task;
	return returningValue;
}