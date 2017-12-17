#pragma once
/*Author: Nina Nguyen
Filename: SequenceEnum.h
11/13/2017
Version 1
Project: P4
CPSC 5011*/

/*
~Description: This class is parent class of SeqExtract and SpasEnum. SeqExtract and SpasEnum both have a is-a relationship
with SequenceEnum. The class will take in a word from the user (state becomes active) and modify that word (state becomes inactive)
by repeating one of the letters in the word by a random index. The user will have a chance to guess what the modified word is.
The program will return the result of guess() along with the modified string.
Then they can reset() to reset the encapsulated word (state becomnes active) and reuse the object.

~Anticipated use: SequenceEnum is created as a base class with a virtual mod() method that any child class should override. 
Constructor calls reset(string), reset(string) in turn calls setWord() which encapsulate the word. User won't be able to call
setWord() as it is protected.

~Legal States: Active or Inactive. The object will be active when initially created, mod() will change the state to inactive, and
reset() will again turn the state active(). setWord() is a protected class and will not be available for the client.

~Legal and illegal inputs: The constructor expects a single string to be passed as an argument. The string has to be 3 letters or more,
all lower case, no numbers/spaces/punctuations. There are defensive programming in the driver but there's no error handling in the constructor. 
Results might be unexpected if anything invalid is passed into the constructor, results won't be guaranteed.

~Dependencies: Relies on the user to input a string that matches all requirements. And relies on the child classes not to violate state
when overriding.

~Assumptions:
The class is dependent on what is passed into the constructor. The class can be a parent class but can also be a standalone class. 
reset() can only be called if the current state of the object is inactive (false) since that is one of the conditions of setWord().
isActive() is used to check the current state of the object. Destructor is called when polymorphism is in used

~State Transition: From active to inactive - modify(). From inactive to active - reset(). Constructor will put the object in an initial
active state.
*/

#ifndef SEQUENCE_ENUM
#define SEQUENCE_ENUM

#include <iostream>
#include <string>
using namespace std;

class SequenceEnum {
public:

	//Description: Constructor. Takes in a word from the user and put object in initial valid state - "Active". Only a word of 3 letters
	//		       or more, all lowercase and no spaces, numbers or punctuations should be passed in.
	//Pre: None
	//Post: State becomes "active"
	SequenceEnum(string);

	//Description: This method is called to modify the word that's passed in by the user. It selects a random letter from the word and
	//insert a duplicate back into the original. "Repeat"
	//Pre: State has to be "active"
	//Post: State becomes "inactive"
	virtual string mod();

	//Description: This allow the user to guess what the modified word (classModWOrd) will be after mod() was called on the original word
	//Pre: State has to be "active"
	//Post: None
	bool guess(string);

	//Description: This allow the user to reset the word and reuse the current object instead of creating a new object.
	//Pre: State has to be "inactive"
	//Post: State resets to "active"
	void reset(string);
	
	//Description: Gets the current state of the object
	//Pre: None
	//Post: None
	bool isActive();

	//Description: Destructor
	//Pre: In an inactive state
	//Post: none
	virtual ~SequenceEnum();

	string getWord() const; //For testing purposes only

protected:

	//Description: Holds the word from user in lowercase.
	string wordFromUser;

	//Description: Holds the word after mod() is called.
	string classModWord;

	//Description: Holds the state of the object. "True" is for active, "False" is for inactive.
	bool state;

	//Description: setter - used to set the word for the object. Is protected so it can be used by the child classes. 
	//			   is called by the reset() and will only run if the current state is active (true)
	//Pre: State has to be active
	//Post: No change
	void setWord(string);

private:
//None for now
};

#endif