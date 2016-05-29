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
	bool writeWord(std::string word);
	bool writeLine(std::string line);
private:
	std::string address;
	std::ofstream * myFileOut;
	std::ifstream * myFileIn;
};

#endif