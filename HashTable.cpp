#include "HashTable.h"
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>

using namespace std;

HashTable::HashTable()
{
	for(int i = 0; i<tableSize; i++)
	{
		hashTable[i] = NULL;
	}
}
HashTable::~HashTable()
{

}
int HashTable::SyllableCount(string word)
{
	int syllables = 0;
	string vowels = "aeiouyAEIOUY";
	for(int i = 0; i<word.size(); i++)
	{
		for(int j = 0; j<vowels.size(); j++)
		{
			if(word[i] == vowels[j])
			{
				if(word[i+1] == 'a' || word[i+1] == 'e' || word[i+1] == 'i' || word[i+1] == 'o' || word[i+1] == 'u' || word[i+1] == 'A' || 
					word[i+1] == 'E' || word[i+1] == 'I' || word[i+1] == 'O' || word[i+1] == 'U' || word[i+1] == 'y' || word[i+1] == 'Y')
				{
					i++;
					syllables++;
					break;
				}
				syllables++;
			}
		}
		if(syllables >= 2)
		{
			if(i == word.size()-1)
			{
				if(word[i] == 'e' || word[i] == 'E')
				{
					syllables--;
				}
			}
		}
	}
	return syllables;
}
void HashTable::insertWord(string in_word)
{
	string word = lowercase(in_word);
	int syllables = SyllableCount(word);
	WordStruct *newWord = new WordStruct();
	newWord->used = 1;
	newWord->word = word;
	WordStruct *current = NULL;
	if(hashTable[syllables] == NULL)
	{
		hashTable[syllables] = newWord;
	}
	else
	{
		current = hashTable[syllables];
		while(current->next != NULL && current->word != newWord->word)
		{
			current = current->next;
		}
		if(current->word == newWord->word)
		{
			current->used = current->used + 1;
		}
		else if(current->next == NULL)
		{
			current->next = newWord;
			newWord->previous = current;
		}
	}
}
WordStruct * HashTable::findWordStruct(string word)
{
	int syllables = SyllableCount(word);
	WordStruct *current = hashTable[syllables];
	while(current != NULL)
	{
		if(current->word == word)
		{
			break;
		}
		current = current->next;
	}
	return current;
}
void HashTable::findWord(string word)
{
	WordStruct * current = findWordStruct(word);
	int syllables = SyllableCount(word);
	if(current != NULL)
	{
		cout<<current->word<<" Used: "<<current->used<<" Syllables: "<<syllables<<endl;
	}
	else
	{
		cout<<"Word not found"<<endl;
	}
}
void HashTable::printMostUsed(int x)
{
	vector<WordStruct*> wordlist;
	WordStruct *current;
	WordStruct *Solved;
	int n = 0;
	for(int j = 0; j<x; j++)
	{
		for(int i = 1; i<tableSize; i++)
		{
			current = hashTable[i];
			while(current != NULL)
			{
				if(!current->solved)
				{
					if(n < current->used)
					{
						n = current->used;
						Solved = current;
					}
				}
				current = current->next;
			}
		}
		wordlist.push_back(Solved);
		Solved->solved = true;
		n = 0;
	}
	for(int i = 0; i<wordlist.size(); i++)
	{
		cout<<wordlist[i]->word<<" Used: "<<wordlist[i]->used<<endl;
	}
	resetHash();
}
void HashTable::resetHash()
{
	WordStruct *current = NULL;
	for(int i = 0; i<tableSize; i++)
	{
		current = hashTable[i];
		while(current != NULL)
		{
			current->solved = false;
			current = current->next;
		}
	}
}
void HashTable::printAllWords()
{
	for(int i = 1; i<tableSize; i++)
	{
		WordStruct *current = hashTable[i];
		while(current != NULL)
		{
			cout<<current->word<<" "<<current->used<<"-> ";
			current= current->next;
		}
		cout<<endl;
	}
}
int HashTable::totalWordsUsed()
{
	int totalUsed = 0;
	WordStruct *current = NULL;
	for(int i = 1; i<tableSize; i++)
	{
		current = hashTable[i];
		while(current != NULL)
		{
			totalUsed = totalUsed + current->used;
			current = current->next;
		}
	}
	return totalUsed;
}
void HashTable::findPercentage(string word)
{
	int totalUsed = totalWordsUsed();
	WordStruct *current = findWordStruct(word);
	cout<<current->word<<" "<<current->used<<"/"<<totalUsed<<endl;
}
string HashTable::lowercase(string word)
{
	for(int i = 0; i<word.size(); i++)
	{
		word[i] = tolower(word[i]);
	}
	return word;
}
double HashTable::AverageSyllables()
{
	int totalUsed = totalWordsUsed();
	double dUsed = totalUsed;
	WordStruct *current = NULL;
	int syllables;
	int totsyl = 0;
	for(int i = 1; i<tableSize; i++)
	{
		current = hashTable[i];
		while(current != NULL)
		{
			syllables = SyllableCount(current->word);
			totsyl = totsyl + syllables *current->used;
			current = current->next;
		}
	}
	double dSyl = totsyl;
	dSyl = dSyl/dUsed;
	return dSyl;
}