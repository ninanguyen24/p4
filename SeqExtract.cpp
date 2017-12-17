/*Author: Nina Nguyen
Filename: SeqExtract.cpp
11/13/2017
Version 1
Project: P4
CPSC 5011*/

/*
~Data structure used: rray to maniplute string
~Ultility Functions: ctime for random int
~Dependencies: Relies on client program to validate legal inputs. Also relies on the parent class to remain unchanged and stable
~Design: Will inherit all public and protected variables and functionalities from SequenceEnum. subString() will be added to 
		 SeqExtract to help the class generate a subsequence string if any.
		 State to remain consistent with parent's class.
~Error Response: guess() will allow for the user to guess what the modify() word is. They can only guess once. There
			    will be no statistics to hold guess data.
~Assumptions:  setWord() is dependent on state so it won't violate encapsulation. It should remain protected and can only
			be called through reset().

*/

#include "SeqExtract.h"
#include <cstdlib> //for srand
#include <ctime> //for srand

SeqExtract::SeqExtract(string word) : SequenceEnum(word) {
	reset(word);
}

//override from parent's class
string SeqExtract::mod()
{
	string getSub = subString();
	if (!getSub.empty()) {
		if (wordFromUser.find(getSub) != std::string::npos) {
			string::size_type i = wordFromUser.find(getSub);
			while (i != string::npos) {
				classModWord = wordFromUser.erase(i, getSub.length());
				i = wordFromUser.find(getSub, i);
			}
		}
	} else {
		classModWord = wordFromUser;
	}
	state = false;
	return classModWord;
}

SeqExtract::~SeqExtract()
{
}

//helper class
string SeqExtract::subString()
{
	srand(time(NULL));
	int end = rand() % wordFromUser.length();
	int begin = rand() % wordFromUser.length();
	int difference = end - begin; 
	string subsequence;
	int sub = ((rand() % 100) + 1) % 2;
	if (sub == 0) { //False - no subsequence generated
		subsequence = "";
	} else {
		if (begin < end && difference >= 2) { //Make sure that the substring is 2 or longer
			subsequence = wordFromUser.substr(begin, end);
		} else {
			subsequence = wordFromUser.substr(0, 2);
		}
	}
	return subsequence;
}
