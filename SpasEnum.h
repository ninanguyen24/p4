#pragma once
/*Author: Nina Nguyen 
Filename: SpasEnum.h
11/13/2017
Version 1
Project: P4
CPSC 5011*/

/*
~Description: SpasEnum is a child class of SequenceEnum class, and they have a is-a relationship. SpasEnum inherits all the protected and public
variables and functionalities from SequenceEnum. It also created a helper method to create a subsequence string from the encapsulated word. 
The subsequence string that can be generated from randomly generated index base on the string length. The end index will always be larger than 
the begin index and their difference is 2 or greater. Then it uses that subsequence string to override the mod() method from the parent class. 
User can pass in a word (state becomes active), mod()
is called (state becomes inactive) and reset() can be called to reset the word and reuse the object (state goes from inactive to active). If subsequence
string is found within the original word, then it will be removed from the original string and the remaining letters will be extracted and return 
for the user.

~Legal states: Similar to SequenceEnum. The object will be active when initially created, mod() will change the state to inactive, and
reset() will again turn the state active. setWord() is a protected class and will not be available for the client.

~Legal and illegal inputs: The constructor expects a single string to be passed as an argument. The string has to be 3 letters or more,
all lower case, no numbers/spaces/punctuations. There are defensive programming in the driver but there's no error handling in the constructor. 
Results might be unexpected if anything invalid is passed into the constructor, results won't be guaranteed.

~Dependencies: The class is dependent on the user for valid word being passed into the constructor. Relies on the parent to keep all 
functionality unchanged.

~Assumptions: mod() method overrides the parent's class. mod() pre-condition can be active or inactive. Concatenate string is active and truncate string
if inactive. setWord(), guess() and reset() remain unchanged. Called in driver to demonstate. Destructor will be called to deallocate memory accordingly

~State transition: From active to inactive - modify(). From inactive to active - reset(), mod(). Constructor will put the object in an initial
active state.
*/
#ifndef SPAS_ENUM
#define SPAS_ENUM

#include "SequenceEnum.h"
#include <iostream>
#include <string>
using namespace std;

class SpasEnum : public SequenceEnum {
public:
	//Description:Constructor. Takes in a word from the user and put object in initial valid state - "Active". Only a word of 3 letters
	//		       or more, all lowercase and no spaces, numbers or punctuations should be passed in.
	//Pre: None
	//Post: State will be active
	SpasEnum(string);

	//Description: This method will override the mod() method from the parent (SequenceEnum). If active, it will concatenate and
	//			   truncate when inactive.
	//Pre: State might be active or inactive
	//Post: State will be inactive
	string mod() override;

	//Destructor
	//Pre: Object in an inactive state
	//Post: None
	~SpasEnum();

private:
	
	//Description: Helper method that gets a subSequence string. Random indexes are generated from the begin index and end index. End indexc
	//			   will always be larger than begin index and their difference is 2 or greater.
	//Pre: State can be active or inactive
	//Post: No change
	string subString();

	string subsequence; //Holds the subsequence string

};

#endif