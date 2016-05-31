#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include <fstream>
#include "Const.h"
#include "Bag.h"

using std::cout;
using std::endl;

Bag::Bag()
{
	sarcasm = false;
	for (int i = 0; i < 26; i++)
	{
		item[i] = new struct Item[1024];
		size[i] = 0;
	}
}

void Bag::add(std::string word, int value)
{
	if ((int)word[0] > 95)
		word[0] = word[0] - 32;
	int letter = word[0] - 65;

	if (DEBUG)
	{
		cout << endl << "** Word: " << word << ", first letter: " << letter << endl;
	}

	bool found = false;
	int index = 0;
	for (int i = 0; i < size[letter];  i++)
	{
		if (item[letter][i].word == word)
		{
			found = true;
			index = i;
		}
	}
	if (found)
		item[letter][index].value = value;
	else
	{
		item[letter][size[letter]].word = word;
		item[letter][size[letter]].value = value;
		size[letter] = size[letter] + 1;
	}
	if (DEBUG)
	{
		cout << endl << "** Log: " << item[letter][size[letter] - 1].word << ", Value:  " << item[letter][size[letter] - 1].value << ", Size of " << letter << ": " << size[letter] << endl;
	}
}

void Bag::print()
{
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < size[i]; j++)
		{
			cout << item[i][j].word << "(" << item[i][j].value << ")";
			if (j + 1 != size[i])
				cout << ", ";
		}
		cout << endl;
	}
	if (sarcasm)
		cout << "This is sarcastic" << endl;
	else
		cout << "This is not sarcastic" << endl;
}

Bag::~Bag()
{
	for (int i = 0; i < 26; i++)
		delete item[i];
}