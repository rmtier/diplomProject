#pragma once
#include "AligmentAlgorithm.h"

struct matrixValue{
	int value;
	unsigned short horizontal : 1;
	unsigned short vertical : 1;
	unsigned short diagonal : 1;
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

