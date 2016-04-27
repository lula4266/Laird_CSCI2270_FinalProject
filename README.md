# Laird_CSCI2270_FinalProject
Repository for Lucas Laird's Data Structures final project
Project Summary

For this project, I will read a file of any length and determine the amount of syllables in a word. 
This is done by counting the number of vowels that are separated by at least 1 consonant. Then each 
word will be stored into a hash table with their index corresponding to the number of syllables the 
word has. The hash table will use a linked list to store the word itself and the number of times it 
was used. The linked list will store the words alphabetically. The purpose of this is to allow for 
easy analysis of the "complexity" of a piece of writing or a speech. Storing the number of times a 
word is used and its syllable count lets an analyzer easily check the complexity of words given 
through the file. Alphabetizing is done for organization and because it speeds up the insertion of
new words into the hash table. To meet the 10 method requirement, I will implement functions into 
the class of hashTable to analyze the complexity. Whether it be the total number of syllables or 
the average number of syllables per word. Or it could be printing out the 10 most common words and 
their syllable counts.

Project Summary

This project reads in a text file line by line and parses it for each word. It will make all letters lower
case and remove punctuation. It will organize the words by how many syllables each word has and store them
in hash table where each index is the syllable count of each word. The hash table has linked lists for 
collision cases which happen often since there are many words with the same number of syllables.
There is user functionality for
Finding a word and printing its syllables and times used
Printing the top n words where n is a user input
Printing all words used
Finding the number of times a word is used over the total
Finding the average syllables per word
The code takes the text file to be opened as a command line argument.

How to Run

To compile the code, I have included a makefile called makefile. All you have to do is go to the terminal 
and type make when you are in the directory with all the code files. This will create a file called WordAnalysis.
In the same terminal window after it is done compiling, type ./WordAnalysis and it will run the code.
An example of what you should see:
/Desktop/"folder with code"$ make
g++ -std=c++11 -c Main.cpp
g++ -std=c++11 -c HashTable.cpp
g++ -o WordAnalysis Main.o HashTable.o
/Desktop/"folder with code"$ ./WordAnalysis textfilename.txt
For textfiles, I have included a transcript of a Donald Trump speech and Bernie Sanders speech. They are called
DonaldTrump.txt and BernieSanders.txt so you can use those as the text file in the command line although the code
should work with any text.

Dependencies

There are no dependencies except that you compile using c++11 but that is taken care of with the makefile.

System Requirements

The instructions for running the code is for linux, so to follow those instructions use on linux.

Group Members

Lucas Laird

Contributors

Jake Crawford: Used a modified version of his makefile

Collaboration Recommendations

Printing the words in alphabetical order would be a beneficial feature to add. There is also one bug due 
to how I removed the punctuation. I removed it using strtok a c string function. The only issue with this
is that if there is punctuation in the middle of a word such as Com!puters. It will tokenize it into 2 separate
words, making it into com and puters. The best way would be for it to become computers without the ! but I wasn't
able to figure that out.