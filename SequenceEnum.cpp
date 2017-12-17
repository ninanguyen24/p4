/*Author: Nina Nguyen
Filename: SequenceEnum.cpp
11/13/2017
Version 1
Project: P4
CPSC 5011
Reference: EncryptWord.cpp*/


/* 
~Data structure used: Array to maniplute string
~Ultility Functions: ctime for random int, cctypes and algorithm for transform() to turn string into lower case
~Dependencies: Relies on client program to validate legal inputs
~Design: Two protected strings will be used, one to hold the original and one to hold the word after mod() is called.
		They should remain protected.
~Error response: guess() will allow for the user to guess what the modify() word is. They can only guess once. There
			    will be no statistics to hold guess data.
~Assumption: setWord() is dependent on state so it won't violate encapsulation. It should remain protected and can only
			be called through reset().
*/

#include "SequenceEnum.h"
#include <iostream>
#include <cstdlib> //for srand
//#include <ctime> //for srand
#include <cctype> //transform
#include <algorithm> //transfrom
using namespace std;

SequenceEnum::SequenceEnum(string word) {
	reset(word);
}

string SequenceEnum::mod()//virtual
{
	if (state == true) { //can only call method when state is "true" or "active"
		string modWord = wordFromUser;
		int indexToDuplicate = 0;

		//srand(time(NULL));
		indexToDuplicate = rand() % wordFromUser.length(); // should generate a number between 0 and wordFromUser length

		char temp = wordFromUser.at(indexToDuplicate);
		string letterDup(1, temp); //char to string
		modWord.insert(indexToDuplicate, letterDup);
		state = false;
		classModWord = modWord;
		
	}
	return classModWord;
}

bool SequenceEnum::guess(string userGuess)
{
	if (userGuess == classModWord) {
		cout << "You guessed it!" << endl;
		return true;
	}
	else {
		cout << "Sorry, that's not the word." << endl;
		return false;
	}
}

void SequenceEnum::setWord(string word)
{
	if (word.length() >= 3 && state == true) {
		std::transform(word.begin(), word.end(), word.begin(), ::tolower); //reuse from EncryptWord
		wordFromUser = word;
	}
}

void SequenceEnum::reset(string resetWord)
{
	state = true;
	setWord(resetWord);
}

bool SequenceEnum::isActive()
{
	return state;
}

SequenceEnum::~SequenceEnum() //destructor
{
}

string SequenceEnum::getWord() const
{
	return wordFromUser;
}
