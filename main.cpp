#include <iostream>
#include "Const.h"
#include "Reader.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char ** argv)
{
	if (DEBUG)
	{
		cout << "+---------------------------------+" << endl;
		cout << "|             CS  331             |" << endl;
		cout << "|   Sarcasm Detector Assignment   |" << endl;
		cout << "|          Behnam Saeedi          |" << endl;
		cout << "|          Due: 6/1/2016          |" << endl;
		cout << "|           Debug  Mode           |" << endl;
		cout << "+---------------------------------+" << endl;
	}

	if (DEBUG)
	{
		cout << "Read test: " << endl;
		File * myFile = new File("training_text.txt");
		string test = myFile->Read();
		test = myFile->Read();
		test = myFile->Read();
		test = myFile->Read();
		test = myFile->Read();
		test = myFile->Read();
		test = myFile->Read();
		test = myFile->Read();
		test = myFile->Read();
		test = myFile->Read();
		test = myFile->Read();
		test = myFile->Read();
		test = myFile->Read();
		cout << "Write test: " << endl;
		delete myFile;
		File * myFileOut = new File("Output_text.txt");
		bool successful = myFileOut->writeWord("This is a word. ");
		cout << "Adding word: " << (bool)successful << endl;
		successful = myFileOut->writeLine("This is a line.");
		cout << "Adding line: " << (bool)successful << endl;
		successful = myFileOut->writeLine("This is another line.");
		cout << "adding another line: " << (bool)successful << endl;
		delete myFileOut;
	}
	return 0;
}