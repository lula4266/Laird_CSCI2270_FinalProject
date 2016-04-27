#include "HashTable.h"
#include <iostream>
#include <string>
#include <fstream>
#include <string.h>

using namespace std;
int main(int argc, char *argv[2])
{
	if(argc == 2)
	{
		string data;
		HashTable wordtable;
		ifstream inFile;
		string in_word;
		int num_words;
		char* word;
		char tempstr[20000];
		int choice = 0;
		string blank;
		inFile.open(string(argv[1]));
		string temp;
		double totsyl;
		if(inFile.good())
		{
			while(getline(inFile,data))
			{
				strcpy(tempstr,data.c_str());
				word = strtok(tempstr,",. :;!@#$&*()+=\"\?");
				if(word != NULL)
				{
					wordtable.insertWord(string(word));
				}	
				while(word != NULL)
				{
					word = strtok(nullptr,",. :;!@#$&*()+=\"\?");
					if(word != NULL)
					{
						wordtable.insertWord(string(word));
					}
				}
			}
			while(choice != 6)
			{
				cout<<"======Main Menu======"<<endl;
				cout<<"1: Find a word"<<endl;
				cout<<"2: Print top used words"<<endl;
				cout<<"3: Print all words"<<endl;
				cout<<"4: Find percentage of use for word"<<endl;
				cout<<"5: Find average syllables per word"<<endl;
				cout<<"6: Quit"<<endl;
				cin>>choice;
				getline(cin,blank);
				switch(choice)
				{
					case 1:
						cout<<"Enter word you would like to find"<<endl;
						getline(cin,in_word);
						wordtable.findWord(in_word);
					break;
					case 2:
						cout<<"How many top words would you like to find?"<<endl;
						cin>>num_words;
						getline(cin,blank);
						wordtable.printMostUsed(num_words);
					break;
					case 3:
						wordtable.printAllWords();
					break;
					case 4:
						cout<<"Enter word you would like to find"<<endl;
						getline(cin,in_word);
						wordtable.findPercentage(in_word);
					break;
					case 5:
						totsyl = wordtable.AverageSyllables();
						cout<<"On average each word has "<<totsyl<<" syllables"<<endl;
					break;
					case 6:
						cout<<"Goodbye"<<endl;
					break;
				}
			}
		}
	}
	else
	{
		cout<<"Incorrect command line arguments"<<endl;
	}
}