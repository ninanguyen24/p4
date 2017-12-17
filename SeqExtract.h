#pragma once
/*Author: Nina Nguyen
Filename: SeqExtract.h
11/13/2017
Version 1
Project: P4
CPSC 5011*/

/*
~Description: SeqExtract is a child class of SequenceEnum class, and they have a is-a relationship. SeqExtract inherits all the protected and public
variables and functionalities from SequenceEnum. It also created a helper method to create a subsequence string from the encapsulated word. 
The subsequence string that can be generated are from randomly generated index base on the string length. If the generated index are out of 
bound, the first two letters will be used as a subsequence. The subString() might not generate any subsequence string.
Then it uses that subsequence string to override the mod() method from the parent class. User can pass in a word (state becomes active), mod()
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

~Assumptions: Calling the seqExtract constructor will in turn call the SequenceEnum constructor so the methods will function properly.
		      Destructor will be called to deallocate memory accordingly

~State transition: From active to inactive - modify(). From inactive to active - reset(). Constructor will put the object in an initial
active state.

*/
#ifndef SEQ_EXTRACT
#define SEQ_EXTRACT

#include "SequenceEnum.h"
#include <iostream>
#include <string>
using namespace std;

class SeqExtract:public SequenceEnum {
public:
	//Description: Constructor. Takes in a word from the user and put object in initial valid state - "Active". Only a word of 3 letters
	//		       or more, all lowercase and no spaces, numbers or punctuations should be passed in.
	//Pre: None
	//Post: State becomnes active
	SeqExtract(string);

	//Description: This method is called to modify the word. subString() will be called to get a subString and it will be removed from the
	//			   original word. It might not return any subString.
	//Pre: State is "active"
	//Post: State becomes "Inactive"
	string mod() override;

	//Description: Destructor
	//Pre: In an inactive state
	//Post: NOne
	~SeqExtract();


private:
	//Description: Helper method that gets a subSequence string. Random indexes are generated from the begin index and end index. If end
	//			   index is smaller or the difference between the end index and begin index is smaller than 2, the first two letters of 
	//			   the string is used as a substring. Is called by mod() method.
	//Pre: State is active
	//Post: State unchanged
	string subString();
	
};

#endif