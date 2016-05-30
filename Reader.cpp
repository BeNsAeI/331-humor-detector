#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include <fstream>
#include "Reader.h"
#include "Const.h"

using namespace std;

File::File(string address)
{
	myFileOut = new ofstream();
	myFileIn = new ifstream(address.c_str());
	myFileOut->open(address.c_str(), ios::app);
	limit = 5000;

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
	if (DEBUG)
		cout << line << endl;
	return line;
}

void File::ReadAll()
{
	index = 0;
	string line;
	if (myFileIn->is_open())
	{
		while (getline(*myFileIn, line))
		{
			if (DEBUG)
				cout << line << '\n';
			buffer[index] = line;
			index++;
		}
	}
}

File::~File()
{
	myFileOut->close();
	myFileIn->close();
}