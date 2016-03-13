#include "NeedlemanWunschAlgorithm.h"


NeedlemanWunschAlgorithm::NeedlemanWunschAlgorithm()
{
}


NeedlemanWunschAlgorithm::~NeedlemanWunschAlgorithm()
{
}
/*
* @param sequence of gens
* @param sequence of gens
*
* @return
* function compute aligment and return it in vector of pairs std::vector<std::pair<char, char>> 
* it is look like:
* A T G T A     A T A
* A T A T A     A T A
*/
std::vector<aligmentStr> * NeedlemanWunschAlgorithm::alignSequences(std::vector<char> * firstSequence, std::vector<char> * secondSequence, int match, int mismatch, int gap)
{
	const int sizeOfFirstSequence = firstSequence->size();
	const int sizeOfSecondSequence = secondSequence->size();
	const int sizeOfHorizontal = sizeOfFirstSequence + 1;
	const int sizeOfVertical = sizeOfSecondSequence + 1;

	int init = 0; //value constantly incremented by gap
	int horizontalValue;
	int verticalValue;
	int diagonalValue;
	int maxValue;

	matrixValue ** matrix = new matrixValue*[sizeOfVertical];

	for (int i = 0; i < sizeOfVertical; i++)
	{
		matrix[i] = new matrixValue[sizeOfHorizontal];
	}

	//init matrix with incrementaly added gaps to first horisontal and vertical row
	for (int i = 0; i < sizeOfHorizontal; i++)
	{
		matrix[0][i].ancestorDirection = NULL; //using in tracking back, end point
		matrix[0][i].value = init;
		matrix[0][i].ancestor = NULL;
		init += gap;
	}
	init = 0;
	for (int j = 0; j < sizeOfVertical; j++)
	{
		matrix[j][0].ancestorDirection = NULL; //using in tracking back, end point
		matrix[j][0].ancestor = NULL;
		matrix[j][0].value = init;
		init += gap;
	}

	//fill the matrix 
	for (int i = 1; i < sizeOfVertical; i++)
	{
		for (int j = 1; j < sizeOfHorizontal; j++)
		{
			arrow * direction = new arrow;
			verticalValue = matrix[i - 1][j].value + gap;
			horizontalValue = matrix[i][j - 1].value + gap;
			if (firstSequence->at(j-1) == secondSequence->at(i-1))
				diagonalValue = match + matrix[i - 1][j - 1].value;
			else
				diagonalValue = mismatch + matrix[i - 1][j - 1].value;

			if (horizontalValue < verticalValue)
			{
				maxValue = verticalValue;
				direction->vertical = true;
			} 
			else if (horizontalValue == verticalValue)
			{
				maxValue = verticalValue;
				direction->vertical = true;
				direction->horizontal = true;
			}
			else 
			{
				maxValue = horizontalValue;
				direction->horizontal = true;
			}
			if (diagonalValue > maxValue){
				maxValue = diagonalValue;
				direction->diagonal = true;
				direction->vertical = false;
				direction->horizontal = false;
			}
			else if (diagonalValue == maxValue)
			{
				direction->diagonal = true;
			}
			matrix[i][j].value = maxValue;
			matrix[i][j].ancestorDirection = direction;
		}
	}
	
	//trace back
	maxValue = INT_MIN;
	int i = sizeOfVertical-1;
	int j = sizeOfHorizontal-1;
	int iCoordinate = 0;
	int jCoordinate = 0;
	//finding highest value
	for (; i >= 0; i--)
	{
		for (; j >= 0; j--)
		{
			if (maxValue < matrix[i][j].value)
			{
				maxValue = matrix[i][j].value;
				iCoordinate = i;
				jCoordinate = j;
			}
		}
	}
	//making aligment
	matrixValue * last;
	std::vector<aligmentStr> * aligment = new std::vector<aligmentStr>();
	last = &matrix[iCoordinate][jCoordinate];
	jCoordinate--; iCoordinate--;
	while (last->ancestorDirection != NULL)
	{
		aligmentStr a;
		if (last->ancestorDirection->diagonal == true)
		{
			a.first = firstSequence->at(jCoordinate);
			a.second = secondSequence->at(iCoordinate);
			if (firstSequence->at(jCoordinate) == secondSequence->at(iCoordinate))
			{
				a.pipe = true;
			}
			else
			{
				a.pipe = false;
			}
			jCoordinate--;
			iCoordinate--;
		}
		else if (last->ancestorDirection->vertical == true)
		{
			a.first = '-';
			a.second = secondSequence->at(iCoordinate);
			iCoordinate--;
			a.pipe = false;
		}
		else if (last->ancestorDirection->horizontal = true)
		{
			a.first = firstSequence->at(jCoordinate);
			a.second = '-';
			jCoordinate--;
			a.pipe = false;
		}
		
		aligment->insert(aligment->begin(), a);
		last = &matrix[iCoordinate][jCoordinate];
	}
	aligmentStr a;
	if (jCoordinate == 0)	//last part of aligment
	{
		a.first = '-';
		a.second = secondSequence->at(iCoordinate);
	}
	else
	{
		a.first = firstSequence->at(jCoordinate);
		a.second = '-';
	}
	aligment->insert(aligment->begin(), a);
	return aligment;
}
