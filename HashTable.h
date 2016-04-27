#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <vector>

struct WordStruct
{
	std::string word;
	int used = 1;
	WordStruct *next;
	WordStruct *previous;
	bool solved = false;
	WordStruct()
	{
		next = NULL;
		previous = NULL;
	}
};

class HashTable
{
	public:
		HashTable();
		~HashTable();
		void printMostUsed(int number);
		void insertWord(std::string name);
		void findWord(std::string name);
		void nullhashTable();
		void printAllWords();
		void findPercentage(std::string word);
		int totalWordsUsed();
		double AverageSyllables();
		WordStruct *findWordStruct(std::string word);
	private:
		int SyllableCount(std::string x);
		void resetHash();
		std::string lowercase(std::string);
		int tableSize = 15;
		WordStruct* hashTable[15];
};

#endif // HASHTABLE_H