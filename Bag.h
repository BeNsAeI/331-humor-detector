#ifndef BAG_H
#define BAG_H

#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include <fstream>
#include "Const.h"

struct Item{
	std::string word;
	int value;
};

class Bag{
public:
	Bag();
	~Bag();
	void add(std::string word, int value);
	void print();
	struct Item * item[26];
private:
	int size[26];
};

#endif