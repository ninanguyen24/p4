/*Author: Nina Nguyen
Filename: SpasEnum.cpp
11/13/2017
Version 1
Project: P4
CPSC 5011*/

/*
~Data structure used: Data structure used: rray to maniplute string
~Ultility Functions: ctime for random int
~Dependencies: Relies on client program to validate legal inputs. Also relies on the parent class to remain unchanged and stable
~Design: Will inherit all public and protected variables and functionalities from SequenceEnum. subString() will be added to 
		 SeqExtract to help the class generate a subsequence string if any.
		 mod() pre-condition is different from parent's. mod() can now be called when state is inactive. setWord and reset() remain
		 unchanged
~Error Response: guess() will allow for the user to guess what the modify() word is. They can only guess once. There
			    will be no statistics to hold guess data.
~Assumptions: setWord() is dependent on state so it won't violate encapsulation. It should remain protected and can only
			be called through reset().
*/

#include "SpasEnum.h"
#include <cstdlib> //for srand
#include <ctime> //for srand

SpasEnum::SpasEnum(string word) : SequenceEnum(word){
	reset(word);
}

string SpasEnum::mod() {
	subString();
	//int ConOrTrunc = ((rand() % 100) + 1) % 2; //0 for concatenate 1 for truncate
	if (isActive()) { //Concatenate if "active" or true
		cout << "The word was concatecated." << endl;
		classModWord = wordFromUser.append(subsequence);
	} else { // truncate
		cout << "The word was truncated." << endl;
		if (wordFromUser.find(subsequence) != std::string::npos) {
			string::size_type i = wordFromUser.find(subsequence);
			while (i != string::npos) {
				classModWord = wordFromUser.erase(i, subsequence.length());
				i = wordFromUser.find(subsequence, i);
			}
		}		
	}

	state = false;
	return classModWord;
}

SpasEnum::~SpasEnum()
{
}

//Helper method
string SpasEnum::subString()
{
	srand(time(NULL));
	int difference = 0;
	int begin = 0;
	int end = 0;
	while (difference < 2) {
		begin = rand() % wordFromUser.length();
		end = rand() % wordFromUser.length();
		difference = end - begin;
	}
	
	subsequence = wordFromUser.substr(begin, end);
	
	return subsequence;
}
