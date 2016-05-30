#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <string.h>
#include "Const.h"
#include "Reader.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char ** argv)
{
	// Display of information
	if (DEBUG || INFO)
	{
		cout << "+---------------------------------+" << endl;
		cout << "|             CS  331             |" << endl;
		cout << "|   Sarcasm Detector Assignment   |" << endl;
		cout << "|          Behnam Saeedi          |" << endl;
		cout << "|          Due: 6/1/2016          |" << endl;
		cout << "|           Debug  Mode           |" << endl;
		cout << "+---------------------------------+" << endl;
	}
	// Testing the File class for input and output
	if (DEBUG || FILE_TEST)
	{
		cout << "**Read test: " << endl;
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
		cout << endl << "**Read all: " << endl;
		myFile->ReadAll();
		cout << endl << "**Sample output for ReadAll in the array: " << myFile->buffer[4] << endl;
		delete myFile;
		cout << endl << "**Write test: " << endl;
		File * myFileOut = new File("Output_text.txt");
		bool successful = myFileOut->writeWord("This is a word. ");
		cout << endl << "**Adding word: " << (bool)successful << endl;
		successful = myFileOut->writeLine("This is a line.");
		cout << endl << "**Adding line: " << (bool)successful << endl;
		successful = myFileOut->writeLine("This is another line.");
		cout << endl << "**adding another line: " << (bool)successful << endl;
		delete myFileOut;
	}



	return 0;
}