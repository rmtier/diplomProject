#include "NeedlemanWunschAlgorithm.h"
#include <stdlib.h>

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

	matrixValue ** matrix = ((matrixValue**)malloc(sizeOfVertical* sizeof(matrixValue*)));

	for (int i = 0; i < sizeOfVertical; i++)
	{
		matrix[i] = ((matrixValue*) malloc(sizeOfHorizontal * sizeof(matrixValue)));
	}

	//init matrix with incrementaly added gaps to first horisontal and vertical row
	for (int j = 0; j < sizeOfHorizontal; j++)
	{
		matrix[0][j].value = init;
		init += gap;
	}
	init = 0;
	for (int i = 0; i < sizeOfVertical; i++)
	{
		matrix[i][0].value = init;
		init += gap;
	}

	//fill the matrix 
	for (int i = 1; i < sizeOfVertical; i++)
	{
		for (int j = 1; j < sizeOfHorizontal; j++)
		{
			matrixValue direction;
			direction.diagonal = 1;	//can be faster
			direction.vertical = 1;
			direction.horizontal = 1;

			verticalValue = matrix[i - 1][j].value + gap;
			horizontalValue = matrix[i][j - 1].value + gap;
			if (firstSequence->at(j-1) == secondSequence->at(i-1))
				diagonalValue = match + matrix[i - 1][j - 1].value;
			else
				diagonalValue = mismatch + matrix[i - 1][j - 1].value;

			if (horizontalValue < verticalValue)
			{
				maxValue = verticalValue;
				direction.vertical = 0;
			} 
			else if (horizontalValue == verticalValue)
			{
				maxValue = verticalValue;
				direction.vertical = 0;
				direction.horizontal = 0;
			}
			else 
			{
				maxValue = horizontalValue;
				direction.horizontal = 0;
			}
			if (diagonalValue > maxValue){
				maxValue = diagonalValue;
				direction.diagonal = 0;
				direction.vertical = 1;
				direction.horizontal = 1;
			}
			else if (diagonalValue == maxValue)
			{
				direction.diagonal = 0;
			}
			matrix[i][j].value = maxValue;
			matrix[i][j].diagonal = direction.diagonal;	//can be faster
			matrix[i][j].vertical = direction.vertical;
			matrix[i][j].horizontal = direction.horizontal;
		}
	}
	
	//trace back
	maxValue = INT_MIN;
	int i = sizeOfVertical-1;
	int j = sizeOfHorizontal-1;
	int iCoordinate = 0;
	int jCoordinate = 0;
	//finding highest value
	//for (; i >= 0; i--)
	//{
		for (int i = 0; i < sizeOfVertical; i++)
		{
			if (maxValue < matrix[i][j].value)
			{
				maxValue = matrix[i][j].value;
				iCoordinate = i;
				jCoordinate = j;
			}
		}
	//}
	//making aligment
	matrixValue * last;
	std::vector<aligmentStr> * aligment = new std::vector<aligmentStr>();
	last = &matrix[iCoordinate][jCoordinate];
	jCoordinate--; iCoordinate--;
	while (jCoordinate >= 0 && iCoordinate >= 0)
	{
		aligmentStr * a = new aligmentStr;
		if (last->diagonal == 0)
		{
			a->first = firstSequence->at(jCoordinate);
			a->second = secondSequence->at(iCoordinate);
			if (firstSequence->at(jCoordinate) == secondSequence->at(iCoordinate))
			{
				a->pipe = true;
			}
			else
			{
				a->pipe = false;
			}
			jCoordinate--;
			iCoordinate--;
		}
		else if (last->vertical == 0)
		{
			a->first = '-';
			a->second = secondSequence->at(iCoordinate);
			iCoordinate--;
			a->pipe = false;
		}
		else if (last->horizontal == 0)
		{
			a->first = firstSequence->at(jCoordinate);
			a->second = '-';
			jCoordinate--;
			a->pipe = false;
		}
		
		aligment->insert(aligment->begin(), *a);
		last = &matrix[iCoordinate+1][jCoordinate+1];
		delete a;
	}
	aligmentStr * a = new aligmentStr;

	if (jCoordinate == 0 && iCoordinate < 0) //one of coordinate have to be zero
	{
		a->first = firstSequence->at(jCoordinate);
		a->second = '-';
		aligment->insert(aligment->begin(), *a);
	}
	else if (iCoordinate == 0 && jCoordinate < 0)
	{
		a->first = '-';
		a->second = secondSequence->at(iCoordinate);
		aligment->insert(aligment->begin(), *a);
	}

	//free malloc memory
	for (int i = 0; i < sizeOfVertical; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
	return aligment;
}
