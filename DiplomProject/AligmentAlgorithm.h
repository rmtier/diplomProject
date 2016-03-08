#pragma once
#include <vector>
#include <climits>
#include "MessageBuilder.h"
/*
* @file 
* @author: Rami Mtier
* @date: 28.2.2016
* @section DESCRIPTION
* Class define algorithm apperience 
*/
class AligmentAlgorithm
{
public:
	AligmentAlgorithm();
	virtual ~AligmentAlgorithm();
	std::vector<std::pair<char, char>> * alignSequences(std::vector<char> * , std::vector<char> *, int, int, int);
};

