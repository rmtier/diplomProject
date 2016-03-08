#pragma once
#include "AligmentAlgorithm.h"
enum arrow{
	HORIZONTAL, VERTICAL, DIAGONAL, NO_DIRECTION
};
struct matrixValue{
	int value;
	matrixValue * ancestor;
	arrow ancestorDirection;
};

/*
* @file NeedlemanWunchAlgorithm
* @author: Rami Mtier
* @date: 28.2.2016
* @section DESCRIPTION 
* NeedlemanWunch algorithm for aligning sequences
*/
class NeedlemanWunschAlgorithm: public AligmentAlgorithm
{
public:
	NeedlemanWunschAlgorithm();
	virtual ~NeedlemanWunschAlgorithm();
	std::vector<aligmentStr> * alignSequences(std::vector<char> *, std::vector<char> *, int, int, int);
};

