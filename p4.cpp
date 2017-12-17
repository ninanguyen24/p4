/*Author: Nina Nguyen
Filename: p4.cpp
11/13/2017
Version 1
Project: P4
CPSC 5011*/

/*
~Description: This program will ask a user for a word (3 letters or more, all lower case, no spaces or punctuations) and will let the user 
choose to "Repeat", "Extract", "Concatenate/Truncate"). The driver will create the appropiate object from SequenceEnum, SeqExtract, or SpasEnum
base on what the user wants to do. mod() will be called from that object which modifies the word and will allow for the user to guess what the
modified word will be. Afterwards, the user have a choice reset() the word which will set a new word to reuse object. Or the user can create 
new objects. The current design have an array of size 3 to hold 3 SequenceEnum objects. 

~Format restrictions: Current driver uses an array of 3 to hold SequenceEnum types or objects. Vector can be used to hold sequenceEnum objects.

~Source of input and output: Cin and cout. No files used.

~Value Ranges: The array size is set to 3. It can be change to hold more objects or change to a vector.

~Size of input: String provided by the user should be 3 letters or more, in all lowercase, no numbers, punctuations or spaces.
				Other interactive inputs should be input as requested by the menu. In all lowercase and one single string. I.E "yes" or "no"

~Error handling: There are some defensive programming in placed, which will response like when the user is saying "no". But the user is expected
				to follow the prompt as asked. Program will not act accordingly if input entered are invalid.

~Classes used: SequenceEnum (parent), SeqExtract(child), SpasEnum(child)

~Functionality exercised: From each class - the constructor, mod(), guess(), reset(), isActive(). SpasEnum mod() will concatenate the word to change
state to active and will call truncate right after to demonstate it's functionality. It will only truncate when inactive. State will be inactive
after mod() is called.

*/

#include "SeqExtract.h"
#include "SequenceEnum.h"
#include "SpasEnum.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

void intro() {
	cout << "This program will ask you for a word and allows you to \n";
	cout << "\"Repeat\", \"Extract a subsequence\", or \"Concatenate/Truncate\". \n";
	cout << "You can guess what the word will be after it was modify! \n";
	cout << "Please make sure the word has 3 or more letters, entered in all lowercase \n";
	cout << "with no punctuations/spaces \n";
	cout << "Let's begin!" << endl;
	cout << endl;
}

/*Reuse from EncryptWord (p1) with few modifications.*/
string validWord() {
	string userWord;

	cout << "Please enter a word? (All lower case, no spaces or punctuations, \nand at least 3 letters or more): ";
	getline(cin, userWord);
	int i = 0;

	while (userWord.size() < 3) {
		cout << "Please input a word with at least 3 characters: ";
		getline(cin, userWord);
	}

	while (userWord[i]) {
		if (ispunct(userWord[i]) || isspace(userWord[i])) {
			cout << "Please don't include punctuations or spaces. Try again: ";
			getline(cin, userWord);
			i = 0;
		}
		i++;
	}
	return userWord;
}



int main() {
	intro();
	SequenceEnum* obj[3];
	int i = 0;
	bool keepPlaying = true;

	while (keepPlaying) {
		string wordToUse = validWord();
		string userInput;
		string guessWord;
		string modWord;
		string classCalled;

		cout << "What do you want to do with the word? Input the corresponding number." << endl;
		cout << " 1. Repeat \n 2. Extract \n 3. Concatenate/truncate " << endl;
		cin >> classCalled;
		
		if (classCalled == "1") {
			obj[i] = new SequenceEnum(wordToUse);
		} else if (classCalled == "2") {
			obj[i] = new SeqExtract(wordToUse);
		} else if (classCalled == "3") {
			obj[i] = new SpasEnum(wordToUse);
		} else {
			cout << "Invalid input. Please close the program and try again.";
		}
	
		bool innerReset = true;
		while (innerReset) { //allow resets
			cout << "State before modify (True = active, False = inactive): " << boolalpha << obj[i]->isActive() << endl;
			modWord = obj[i]->mod();
			cout << "State after modify (True = active, False = inactive): " << boolalpha << obj[i]->isActive() << endl;
			cout << "Guess the word after it's modified: ";
			cin >> guessWord;
			obj[i]->guess(guessWord);

			cout << "The modified word is: " << modWord << endl;

			if (classCalled == "3") { //called to truncate because state is inactive
				modWord = obj[i]->mod();
				cout << "Word after truncate: " << modWord << endl;
			}

			cout << "Do you want to go again? (\"yes\" or \"no\")" << endl;
			cin >> userInput;
			if (userInput == "yes") {
				wordToUse = validWord();
				obj[i]->reset(wordToUse);
				cout << "State has been reset." << endl;
				innerReset = true;
			} else if (userInput == "no") {
				innerReset = false;
			} else {
				cout << "Invalid input. The program will continue." << endl;
				innerReset = false;
			}
		}

		cout << "Do you want to restart? This will allow you to \"Repeat, Extract, Concatenate/truncate\"." << endl;;
		cout << "Enter \"yes\" or \"no\": ";
		cin >> userInput;
		if (userInput == "yes") { //create new object
			keepPlaying = true;
		} else if (userInput == "no") {
			cout << "Okay, bye!" << endl;
			keepPlaying = false;
		} else {
			cout << "Invalid input. The program will exit. " << endl;;
			keepPlaying = false;
		}
		delete obj[i];
		i++;
	}
	
}