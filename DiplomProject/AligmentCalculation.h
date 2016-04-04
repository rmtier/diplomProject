#pragma once
#include "SmithWatermanAlgorithm.h"
#include "BlastAlgorithm.h"
#include "Aligment.h"
#include "MessageBuilder.h"
/*
* @file
* @author: Rami Mtier
* @date: 28.2.2016
* @section DESCRIPTION
* Used for calculate tasks
*/
class AligmentCalculation
{
public:
	AligmentCalculation();
	~AligmentCalculation();
	Aligment * calculateTask(Task * task);
};

