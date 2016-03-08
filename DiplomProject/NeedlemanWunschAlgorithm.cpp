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
	int init = 0; //value constantly incremented by gap
	int horizontalValue;
	int verticalValue;
	int diagonalValue;
	int maxValue;
	matrixValue * biggestCell;
	arrow direction;

	matrixValue ** matrix = new matrixValue*[sizeOfSecondSequence];

	for (int i = 0; i < sizeOfSecondSequence; i++)
	{
		matrix[i] = new matrixValue[sizeOfFirstSequence];
	}

	//init matrix with incrementaly added gaps to first horisontal and vertical row
	for (int i = 0; i < sizeOfSecondSequence; i++)
	{
		matrix[0][i].ancestorDirection = NO_DIRECTION; //using in tracking back, end point
		matrix[0][i].value = init;
		matrix[0][i].ancestor = NULL;
		init += gap;
	}
	init = 0;
	for (int i = 0; i < sizeOfFirstSequence; i++)
	{
		matrix[i][0].ancestorDirection = NO_DIRECTION; //using in tracking back, end point
		matrix[i][0].ancestor = NULL;
		matrix[i][0].value = init;
		init += gap;
	}

	//fill the matrix 
	for (int i = 1; i < sizeOfSecondSequence; i++)
	{
		for (int j = 1; j < sizeOfFirstSequence; j++)
		{
			horizontalValue = matrix[i - 1][j].value + gap;
			verticalValue = matrix[i][j - 1].value + gap;
			if (firstSequence->at(j) == secondSequence->at(i))
				diagonalValue = match + matrix[i - 1][j - 1].value;
			else
				diagonalValue = mismatch + matrix[i - 1][j - 1].value;

			if (horizontalValue > verticalValue)
			{
				biggestCell = &matrix[i - 1][j];
				maxValue = horizontalValue;
				direction = HORIZONTAL;
			}
			else 
			{
				biggestCell = &matrix[i][j-1];
				maxValue = verticalValue;
				direction = VERTICAL;
			}
			if (diagonalValue > maxValue){
				biggestCell = &matrix[i - 1][j - 1];
				maxValue = diagonalValue;
				direction = DIAGONAL;
			}
			matrix[i][j].value = maxValue;
			matrix[i][j].ancestorDirection = direction;
			matrix[i][j].ancestor = biggestCell;
		}
	}
	
	//trace back
	matrixValue * last;
	maxValue = INT_MIN;
	int i = sizeOfSecondSequence-1;
	int j = sizeOfFirstSequence-1;
	int iCoordinate = 0;
	int jCoordinate = 0;
	//finding highest value
	for (; i > 0; i--)
	{
		for (; j > 0; j--)
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
	std::vector<aligmentStr> * aligment = new std::vector<aligmentStr>();
	last = &matrix[iCoordinate][jCoordinate];
	while (last->ancestor != NULL)
	{
		aligmentStr a;
		a.first = firstSequence->at(jCoordinate);
		a.second = secondSequence->at(iCoordinate);
		if (last->ancestorDirection == DIAGONAL)
		{
			jCoordinate--;
			iCoordinate--;
		}
		if (last->ancestorDirection == VERTICAL)
		{
			jCoordinate--;
		}
		if (last->ancestorDirection == HORIZONTAL)
		{
			iCoordinate--;
		}
		if (firstSequence->at(jCoordinate) == secondSequence->at(iCoordinate))
		{
			a.pipe = true;
		}
		else
		{
			a.pipe = false;
		}
		aligment->insert(aligment->begin(), a);
	}
	return aligment;
}
