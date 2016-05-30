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
	if ((DEBUG && FILE_TEST) || FILE_TEST)
	{
		cout << "**Read test: " << endl;
		File * myFileTest = new File("training_text.txt");
		string test = myFileTest->Read();
		test = myFileTest->Read();
		test = myFileTest->Read();
		test = myFileTest->Read();
		test = myFileTest->Read();
		test = myFileTest->Read();
		test = myFileTest->Read();
		test = myFileTest->Read();
		test = myFileTest->Read();
		test = myFileTest->Read();
		test = myFileTest->Read();
		test = myFileTest->Read();
		test = myFileTest->Read();
		cout << endl << "**Read all: " << endl;
		myFileTest->ReadAll();
		cout << endl << "**Sample output for ReadAll in the array: " << myFileTest->buffer[4] << endl;
		delete myFileTest;
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

	//Reading and processing the training set:
	//- Creating the File object for reading
	File * myFileRead = new File("training_text.txt");

	//- Reading the training set in a buffer
	myFileRead->ReadAll();
	if (DEBUG)
		cout << endl << "** The training set has " << myFileRead->index << " items." << endl << endl;

	//- Processing the training set:
	//- - Creating the Sarcasm array
	int * Training = new int[myFileRead->index];

	// - - Populating the Sarcasm array and Removing punctuation:
	int QC = 0;		//Counting quotation marks, if it is even and the character is a 0 or 1 , it is the sarcasm score
	for (int i = 0; i < myFileRead->index; i++)
	{
		for (int j = 0; j < myFileRead->buffer[i].size(); j++)
		{
			if (!((myFileRead->buffer[i][j] >= (char)(65) && myFileRead->buffer[i][j] <= (char)(90)) ||
				(myFileRead->buffer[i][j] >= (char)(97) && myFileRead->buffer[i][j] <= (char)(122)) ||
				(myFileRead->buffer[i][j] == ' ')))
			{
				if (myFileRead->buffer[i][j] == '"')
					QC++;
				if ((QC % 2 == 0) && (myFileRead->buffer[i][j] == '0' || myFileRead->buffer[i][j] == '1'))
				{
					if (myFileRead->buffer[i][j] == '0')
						Training[i] = 0;
					else
						Training[i] = 1;
					if (TRAINING)
						cout << endl << "** " << myFileRead->buffer[i] << " is " << Training[i] << endl;
				}
				if (DEBUG)
					cout << myFileRead->buffer[i][j] << " ";

				// - - - Deleting punctuation
				myFileRead->buffer[i][j] = '\0';
			}
		}
		if (DEBUG)
			cout << endl << myFileRead->buffer[i] << endl;
	}
	if (DEBUG)
		cout << endl;

	system("cls");
	system("clear");
	system("echo Training set is processed. ");

	//CLEANUP;
	delete myFileRead;
	return 0;
}