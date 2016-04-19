# Laird_CSCI2270_FinalProject
Repository for Lucas Laird's Data Structures final project
Project Summary

For this project, I will read a file of any length and determine the amount of syllables in a word. This is done by counting the number of vowels that are separated by at least 1 consonant. Then each word will be stored into a hash table with their index corresponding to the number of syllables the word has. The hash table will use a linked list to store the word itself and the number of times it was used. The linked list will store the words alphabetically. The purpose of this is to allow for easy analysis of the "complexity" of a piece of writing or a speech. Storing the number of times a word is used and its syllable count lets an analyzer easily check the complexity of words given through the file. Alphabetizing is done for organization and because it speeds up the insertion of new words into the hash table. 
