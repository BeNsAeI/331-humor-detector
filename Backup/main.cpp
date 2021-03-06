#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <string>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <set>

#include "Const.h"
#include "Reader.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::remove_if;
using std::remove;

void print(const std::string& item)
{
	std::cout << item << std::endl;
}

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

				}


				// - - - Deleting punctuation
				myFileRead->buffer[i][j] = ' ';
			}
		}
	}


	system("cls");
	system("clear");
	system("echo \"Training set is processed.\" ");

	// - - truning the strings to vocabulary:
	std::set<std::string> Vocabulary;
	for (int i = 0; i < myFileRead->index; i++)
	{
		string line = myFileRead->buffer[i];
		string tmp;
		int j = 0;
		stringstream ssin(line);
		while (ssin.good()){
			ssin >> tmp;
			// Removing spaces
			for (int i = 0; i<tmp.length(); i++)
			if (tmp[i] == ' ') tmp.erase(i, 1);

			//putting it in the vocabulary
			//tmp is the word to be inserted to the vocabulary
			if (tmp[0] >= 65)
			{
				for (int k = 0; k < tmp.size(); k++)
				{
					if (tmp[k] < 97)
						tmp[k] = (char)(tmp[k] + 32);
				}
				Vocabulary.insert(tmp);
			}

			++j;
		}
		if (DEBUG)
			;// std::for_each(Vocabulary.begin(), Vocabulary.end(), &print);

	}
	system("cls");
	system("clear");
	system("echo \"Bag is built. \"");
	
	//Saving to preprocessed_train.txt
	File *myFileWrite = new File("preprocessed_train.txt");

	std::set<std::string>::iterator wordIndex;
	int *FeaturVector = new int[Vocabulary.size()];
	float *FVPYT = new float[Vocabulary.size()];
	float *FVPYF = new float[Vocabulary.size()];
	int TS = 0;
	int TNS = 0;
	for(int i = 0; i < myFileRead->index; i++)
	{
		if (bool(Training[i]))
			TS++;
		else
			TNS++;
	}
	float PY = 0;
	for (int i = 1; i < myFileRead->index; i++)
	{
		PY = PY + Training[i];
	}
	PY = PY / myFileRead->index;
	float PNY = 1 - PY;

	for (int i = 0; i < Vocabulary.size(); i++)
	{
		
			FeaturVector[i]= 0;
			FVPYT[i] = 0;
			FVPYF[i] = 0;
	}

	for (int i = 0; i < myFileRead->index; i++)
	{
		for (int i = 0; i < Vocabulary.size(); i++)
		{
			FeaturVector[i] = 0;
		}
		string line = myFileRead->buffer[i];
		string tmp;
		int j = 0;
		stringstream ssin(line);
		while (ssin.good())
		{
			ssin >> tmp;
			// Removing spaces
			for (int i = 0; i<tmp.length(); i++)
			if (tmp[i] == ' ') tmp.erase(i, 1);

			//putting it in the vocabulary
			//tmp is the word to be inserted to the vocabulary
			if (tmp[0] >= 65)
			{
				for (int k = 0; k < tmp.size(); k++)
				{
					if (tmp[k] < 97)
						tmp[k] = (char)(tmp[k] + 32);
				}
				wordIndex = Vocabulary.find(tmp);
				int distance = std::distance(Vocabulary.begin(),wordIndex);
				FeaturVector[distance] = 1;
				if (bool(Training[i]))
				{
					FVPYT[distance] = FVPYT[distance] + 1;
				}
				else
				{
					FVPYF[distance] = FVPYF[distance] + 1;
				}
			}

			++j;
		}
		FeaturVector[Vocabulary.size()] = Training[i];
		FVPYT[Vocabulary.size()] = 1;
		FVPYF[Vocabulary.size()] = 0;
		if (i>0)
		{
			for (int j = 0; j < Vocabulary.size() + 1; j++)
			{
				myFileWrite->writeWord(SSTR(FeaturVector[j]));
				if (DEBUG)
					cout << FVPYT[j];
				if (j != Vocabulary.size())
				{
					myFileWrite->writeWord(", ");
					if (DEBUG)
						cout << ", ";
				}
			}
			myFileWrite->writeWord("\n");
			if (DEBUG)
				cout << endl;
		}
	}

	for (int i = 0; i < Vocabulary.size(); i++)
	{
		FVPYT[i] = float(float(FVPYT[i]) / float(TS));
		FVPYF[i] = float(float(FVPYF[i]) / float(TNS));
	}
	delete myFileWrite;

	system("cls");
	system("clear");
	system("echo \"Saved to file\"");
	system("echo \"Pre-Process Done\"");

	//CLEANUP after Pre-process
	system("echo \"Cleaning the memory\"");
	delete myFileRead;

	//Reading in the samples
	system("echo \"Reading in the next file\"");
	string fileName;
	fileName = "test_text.txt";
	//fileName = "training_text.txt";		//Testing the accuracy on training set (gets all of it right)
	File *myFile = new File(fileName);

	myFile->ReadAll();
	string tmp;
	tmp = "Log.txt";
	//tmp = "results.txt";
	//tmp = "results_" +fileName;
	File *result = new File(tmp);
	string out = "File name : " + fileName + ":";
	result->writeLine(out);
	// cleaning the words
	QC = 0;
	int * Accuracy = new int[myFile->index];
	for (int i = 0; i < myFile->index; i++)
	{
		for (int j = 0; j < myFile->buffer[i].size(); j++)
		{
			if (!((myFile->buffer[i][j] >= (char)(65) && myFile->buffer[i][j] <= (char)(90)) ||
				(myFile->buffer[i][j] >= (char)(97) && myFile->buffer[i][j] <= (char)(122)) ||
				(myFile->buffer[i][j] == ' ')))
			{
				if (myFile->buffer[i][j] == '"')
					QC++;
				if ((QC % 2 == 0) && (myFile->buffer[i][j] == '0' || myFile->buffer[i][j] == '1'))
				{
					if (myFile->buffer[i][j] == '0')
						Accuracy[i] = 0;
					else
						Accuracy[i] = 1;

				}


				// - - - Deleting punctuation
				myFile->buffer[i][j] = ' ';
			}
		}
	}
	cout << "Processing the new wordlist." << endl;
	cout << myFile->index << endl;
	int verdict = 0;
	for (int i = 1; i < myFile->index; i++)
	{
		float PT = float(PY);
		float PF = float(PNY);
		string line = myFile->buffer[i];
		string tmp;
		int j = 0;
		stringstream ssin(line);
		while (ssin.good()){
			ssin >> tmp;
			// Removing spaces
			for (int i = 0; i < tmp.length(); i++)
			if (tmp[i] == ' ') tmp.erase(i, 1);

			// making the word lower case
			if (tmp[0] >= 65)
			{
				for (int k = 0; k < tmp.size(); k++)
				{
					if (tmp[k] < 97)
						tmp[k] = (char)(tmp[k] + 32);
				}
				// word "tmp" check here
				if (DEBUG)
					cout << tmp << endl;
				wordIndex = Vocabulary.find(tmp);
				int distance = std::distance(Vocabulary.begin(), wordIndex);
				PT = PT * float(FVPYT[distance]);
				PF = PF * float(FVPYF[distance]);
			}

			++j;
		}
		
		if (PT > PF)
		{
			if (Accuracy[i] == 1)
				verdict++;
			cout << PT << " vs " << PF << ": Sarcastic." << endl;
			string out = SSTR(PT) + " vs " + SSTR(PF) + ": Sarcastic.";
			result->writeLine(out);
		}
		else
		{
			if (Accuracy[i] == 0)
				verdict++;
			cout << PT << " vs " << PF << ": Not sarcastic." << endl;
			string out = SSTR(PT) + " vs " + SSTR(PF) + ": Not sarcastic.";
			result->writeLine(out);
		}
		if (DEBUG)
			;// std::for_each(Vocabulary.begin(), Vocabulary.end(), &print);
	}
	cout << "Accuracy is: " << (float(float(verdict) / float(myFile->index)) * float(100)) << "%." << endl;
	out = "Accuracy is: " + SSTR((float(float(verdict) / float(myFile->index)) * float(100))) + "%.";
	result->writeLine(out);

	delete myFile;
	delete result;
	
	return 0;
}