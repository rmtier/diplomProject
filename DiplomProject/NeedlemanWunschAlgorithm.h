#pragma once
#include "AligmentAlgorithm.h"
struct arrow{
	bool horizontal = false;
	bool vertical = false;
	bool diagonal = false;
};
struct matrixValue{
	int value;
	matrixValue * ancestor;
	arrow * ancestorDirection;
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

