#pragma once
#include "NeedlemanWunschAlgorithm.h"

class SmithWatermanAlgorithm : public NeedlemanWunschAlgorithm
{
public:
	SmithWatermanAlgorithm();
	~SmithWatermanAlgorithm();
	std::vector<aligmentStr> * alignSequences(std::vector<char> *, std::vector<char> *, int, int, int);
};

