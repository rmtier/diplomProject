#pragma once
#include "AligmentAlgorithm.h"
class BlastAlgorithm
{
public:
	BlastAlgorithm();
	~BlastAlgorithm();
	std::vector<aligmentStr> * alignSequences(std::vector<char> *, std::vector<char> *, int, int, int);

};

