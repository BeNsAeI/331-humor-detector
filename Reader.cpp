#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include <fstream>
#include "Reader.h"

using namespace std;

File::File(string address)
{
	myFileOut = new ofstream();
	myFileIn = new ifstream(address.c_str());
	myFileOut->open(address.c_str(), ios::app);

}

bool File::writeLine(string line)
{
	line.append("\n");
	*myFileOut << line.c_str();
	return true;
}

bool File::writeWord(string word)
{
	*myFileOut << word.c_str();
	return true;
}

string File::Read()
{
	string line;
	getline(*myFileIn,line);
	cout << line << endl;
	return line;
}

File::~File()
{
	myFileOut->close();
	myFileIn->close();
}