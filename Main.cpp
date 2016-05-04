#include "HashTable.h"
#include <iostream>
#include <string>
#include <fstream>
#include <string.h>

using namespace std;
int main()
{
	
	int choice = 0;
	int choice2 = 0;
	string data;
	HashTable wordtable;
	ifstream inFile;
	string in_word;
	int num_words;
	char* word;
	char tempstr[20000];
	string blank;
	string temp;
	double totsyl;
	bool hasChosen = false;
	
	while(choice != 7)
	{
		cout<<"======Main Menu======"<<endl;
		cout<<"1: Choose a .txt file"<<endl;
		cout<<"2: Find a word"<<endl;
		cout<<"3: Print top used words"<<endl;
		cout<<"4: Print all words"<<endl;
		cout<<"5: Find percentage of use for word"<<endl;
		cout<<"6: Find average syllables per word"<<endl;
		cout<<"7: Quit"<<endl;
		cin>>choice;
		getline(cin,blank);
		switch(choice)
		{
			case 1:
				choice2 = 0;
				while(choice2 != 3){
				
					cout<<"1: Bernie Sanders"<<endl;
					cout<<"2: Donald Trump"<<endl;
					cout<<"3: Go Back"<<endl;
					cin>>choice2;
					getline(cin,blank);
					switch(choice2){
					
						case 1:
							hasChosen = true;
							
							inFile.open("BernieSanders.txt");
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
							}
						choice2 = 3;	
						
						case 2:
							hasChosen = true;
							
							inFile.open("DonaldTrump.txt");
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
							}
						choice2 = 3;
						
						case 3:
						break;
					}
					
				}
				
			break;	
			case 2:
				if(hasChosen){
					cout<<"Enter word you would like to find"<<endl;
					getline(cin,in_word);
					wordtable.findWord(in_word);
				} else {
					cout << "Please Choose a .txt file first" << endl;
				}
			break;
			case 3:
				if(hasChosen){
					cout<<"How many top words would you like to find?"<<endl;
					cin>>num_words;
					getline(cin,blank);
					wordtable.printMostUsed(num_words);
				} else {
					cout << "Please Choose a .txt file first" << endl;
				}
			break;
			case 4:
				if(hasChosen){
					wordtable.printAllWords();
				} else {
					cout << "Please Choose a .txt file first" << endl;
				}
			break;
			case 5:
				if(hasChosen){
					cout<<"Enter word you would like to find"<<endl;
					getline(cin,in_word);
					wordtable.findPercentage(in_word);
				} else {
					cout << "Please Choose a .txt file first" << endl;
				}
			break;
			case 6:
				if(hasChosen){
					totsyl = wordtable.AverageSyllables();
					cout<<"On average each word has "<<totsyl<<" syllables"<<endl;
				} else {
					cout << "Please Choose a .txt file first" << endl;
				}
			break;
			case 7:
				cout<<"Goodbye"<<endl;
			break;
		}
	}
}

