# p4

Author: Nina Nguyen
CPSC 5011
Fall 2017
p4

Description:
This program demonstrates inheritance. This program will ask a user for a word (3 letters or more, all lower case, no spaces or punctuations) and will let the user choose to "Repeat", "Extract", "Concatenate/Truncate"). The driver will create the appropiate object from SequenceEnum, SeqExtract, or SpasEnum base on what the user wants to do. mod() will be called from that object which modifies the word and will allow for the user to guess what the modified word will be. Afterwards, the user have a choice reset() the word which will set a new word to reuse object. Or the user can create new objects. The current design have an array of size 3 to hold 3 SequenceEnum objects.

SequenceEnum will be the parent and SpasEnum and SpasExtract will be the child and override the necessary methods.

Built with:
Visual Studios
Vim

Acknowledgement:
p4 Seattle U
