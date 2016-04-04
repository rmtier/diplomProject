#include "ViewInterface.h"
#include <sstream>

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
	std::string outFile;
	std::string algorithm;
	int match, missmatch, gap;
	int algInt;

	initConsole();
	std::cout << "Vyber si algoritmus vypoctu stlacenim klavesy:\n\n";
	std::cout << "  1. Needleman Wunch\n";
	std::cout << "  2. Smith Waterman\n";
	std::cout << "  3. Nukleotidovy Blast\n";
	std::cin >> algInt;

	switch (algInt)
	{
		case(1) : {algorithm = "NeedlemanWunch"; break; }
		case(2) : {algorithm = "SmithWaterman"; break; }
		case(3) : {algorithm = "Blast"; break; }
		default: {return false; }
	}
	std::cout << "Zadaj vstupny subor s vzorkami genov:";
	std::cin >> inputChar;
	if (strcmp(inputChar, "e") == 0){
		return false;
	}
	inputFile = inputChar;
	std::cout << "Zadaj subor s porovnavacou sekvenciou:";
	std::cin >> inputChar;
	if (strcmp(inputChar, "e") == 0){
		return false;
	}
	compareFile = inputChar;
	std::cout << "Zadaj vystupny subor (v pripade zobrazenia do konzoly zadaj \"console\"):";
	std::cin >> inputChar;
	if (strcmp(inputChar, "e") == 0){
		return false;
	}
	outFile = inputChar;
	std::cout << "Zadaj parametre algoritmu (match missmatch gap): ";
	std::cin >> match;
	std::cin >> missmatch;
	std::cin >> gap;
	readFromFiles(inputFile, compareFile, outFile, match, missmatch, gap, algorithm);
	return true;
}


void ViewInterface::print(Aligment * aligment, long time, std::string algorithm)
{
	std::ofstream of;
	std::ostream * out;

	if (outFile == "console")
	{
		out = &std::cout;
		*out << "\n\n";
		*out << "Algorithm used for aligning: " << algorithm;
		*out << "\nComputing aligning time:     " << time;
		*out << "\nAligment:\n";
		printAligment(aligment, out);
	}
	else
	{
		of.open(this->outFile);
		out = &of;
		*out << "Algorithm: " << algorithm << "; Time CPU: " << time;
		*out << "\n";
		printAligment(aligment, out);
		of.close();
	}
}

void ViewInterface::printAligment(Aligment * aligment, std::ostream * out)
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int l = 0;
	unsigned int index = 0;
	while (aligment->getAligment()->size() > index)
	{
		i = 0;
		while (i < NUMBEROFROWININTERFACE && aligment->getAligment()->size() > index + i)
		{
			*out << aligment->getAligment()->at(index + i).first; i++;
		}
		*out << "\n";
		j = 0;
		while (j < NUMBEROFROWININTERFACE && aligment->getAligment()->size() > index + j)
		{
			*out << ((aligment->getAligment()->at(index + j).pipe == true) ? '|' : ' '); j++;
		}
		*out << "\n";
		l = 0;
		while (l < NUMBEROFROWININTERFACE && aligment->getAligment()->size() >(index + l))
		{
			*out << aligment->getAligment()->at(index + l).second; l++;
		}
		index += NUMBEROFROWININTERFACE;
		*out << "\n\n";
	}
}
/*
* Read input from files
* @param inputFileName - name of file that contain byte array of dna sequences
* @param compareFileName - name of File that contain aligning dna sequence(with array of dna sequences)
* @param outFileName - name of output file(default console)
*/
void ViewInterface::readFromFiles(std::string inputFileName, std::string compareFileName, std::string outFileName, int match, int missmatch, int gap, std::string algorithm)
{
	std::ifstream inputFile;
	std::ifstream compareFile;
	std::string buffer;
	std::string comparingString;
	std::string data;
	std::stringstream inStream;
	std::stringstream inStream2;
	std::string trash;

	try{
		inputFile.open(inputFileName);
		getline(inputFile, trash);
		while (getline(inputFile, data))
		{
			inStream << data;
		}
		inputFile.close();

		compareFile.open(compareFileName);
		getline(compareFile, trash);
		while (getline(compareFile, comparingString))
		{
			inStream2 << comparingString;
		}
		compareFile.close();
		this->outFile = outFileName;
	}
	catch (const char & e)
	{
		std::cout << e;
	}
	
	doListOfMessages.push_back(MessageBuilder::createTask(&inStream.str(), &inStream2.str(), match, missmatch, gap, algorithm));
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