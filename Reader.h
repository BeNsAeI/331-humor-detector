#ifndef READER_H
#define READER_H

#include <iostream>
#include <cstring>
#include <string.h>
#include <fstream>

class File{
public:
	File(std::string address);
	~File();
	std::string Read();
	void ReadAll();
	bool writeWord(std::string word);
	bool writeLine(std::string line);
	std::string buffer[5000];
	int index;
private:
	int limit;
	std::string address;
	std::ofstream * myFileOut;
	std::ifstream * myFileIn;
};

#endif