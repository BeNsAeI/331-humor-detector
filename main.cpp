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

	File * myFile = new File("training_text.txt");

	if (DEBUG)
	{
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
	}
	return 0;
}