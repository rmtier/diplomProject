#include "BlastAlgorithm.h"

BlastAlgorithm::BlastAlgorithm()
{
}


BlastAlgorithm::~BlastAlgorithm()
{
}

std::vector<aligmentStr> * BlastAlgorithm::alignSequences(std::vector<char> * querry, std::vector<char> *subject, int wordSize, int, int)
{
	int countOfWords = querry->size() / wordSize + 1;
	int wordIndex = 0;
	int endOfQuerry = querry->size() - wordSize;
	int hashLength = pow(4, wordSize);
	char ** hashTable = new char*[hashLength];

	for (int i = 0; i < hashLength; i++)
	{
		hashTable[i] = new char[wordSize];
		int x = 4;
		int y = 1;
		for (int j = 0; j < wordSize; j++)
		{
			switch (i % x / y)
			{
			case(0) : {hashTable[i][j] = 'A'; break; }
			case(1) : {hashTable[i][j] = 'C'; break; }
			case(2) : {hashTable[i][j] = 'G'; break; }
			case(3) : {hashTable[i][j] = 'T'; break; }
			}
			x = x * 4; y = y * 4;
		}
	}
	
	return NULL;
}
