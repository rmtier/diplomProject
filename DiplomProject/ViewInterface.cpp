#include "ViewInterface.h"

ViewInterface::ViewInterface()
{
}


ViewInterface::~ViewInterface()
{
}
/*
* Ask user throught console to 
* input file - file contain dna sequences 
* compare file - contain dna sequence, what will be compared with information in input file
*/
bool ViewInterface::continueComputing()
{
	char inputChar[SIZEOFINPUTARRAY];
	std::string inputFile;
	std::string compareFile;

	initConsole();
	std::cout << "Zadaj vstupny subor s vzorkami genov:";
	std::cin >> inputChar;
	if (strcmp(inputChar, "e") == 0){
		return false;
	}
	inputFile = inputChar;
	std::cout << "\nZadaj porovnavaci subor:";
	std::cin >> inputChar;
	if (strcmp(inputChar, "e") == 0){
		return false;
	}
	compareFile = inputChar;
	readFromFiles(inputFile, compareFile, "console");
	return true;
}

void ViewInterface::print(Aligment * aligment, long time, std::string algorithm)
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int l = 0;
	unsigned int index = 0;

	std::cout << "\n\n";
	std::cout << "Algorithm used for aligning: " << algorithm;
	std::cout << "\nComputing aligning time:     " << time;
	std::cout << "\nAligment:\n";
	
	while (aligment->getAligment()->size() > index)
	{
		i = 0;
		while (i < NUMBEROFROWININTERFACE && aligment->getAligment()->size() > index + i)
		{
			std::cout << aligment->getAligment()->at(index + (i++)).first;
		}
		std::cout << "\n";
		j = 0;
		while (j < NUMBEROFROWININTERFACE && aligment->getAligment()->size() > index + j)
		{
			std::cout << ((aligment->getAligment()->at(index + j++).pipe == true) ? '|' : ' ');
		}
		std::cout << "\n";
		l = 0;
		while (l < NUMBEROFROWININTERFACE && aligment->getAligment()->size() >(index + l))
		{
			std::cout << aligment->getAligment()->at(index + l++).second;
		}
		index += NUMBEROFROWININTERFACE;
		std::cout << "\n\n";
	}
}

/*
* Read input from files
* @param inputFileName - name of file that contain byte array of dna sequences
* @param compareFileName - name of File that contain aligning dna sequence(with array of dna sequences)
* @param outFileName - name of output file(default console)
*/
void ViewInterface::readFromFiles(std::string inputFileName, std::string compareFileName, std::string outFileName)
{
	std::ifstream inputFile;
	std::ifstream compareFile;
	std::ofstream outFile;
	std::string buffer;
	std::string comparingString;
	std::string data;

	try{
		inputFile.open(inputFileName);
		getline(inputFile, data);
		inputFile.close();

		compareFile.open(compareFileName);
		getline(compareFile, comparingString);
		compareFile.close();
	}
	catch (const char & e)
	{
		std::cout << e;
	}

	doListOfMessages.push_back(MessageBuilder::createTask(&data, &comparingString));

}

void ViewInterface::initConsole()
{
	clearConsole();
	std::cout << "\n[Pre skoncenie programu stlac: klavesku 'e' a nasledne ENTER\n. V pripade pokracovanie postupne vyplnujte zadanie nizsie]\n\n";
}

void ViewInterface::clearConsole() {
	// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
}

Task* ViewInterface::takeTask (){
	Task* task = doListOfMessages.back();
	doListOfMessages.pop_back();
	return task;
}