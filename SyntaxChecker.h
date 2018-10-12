/*
Chris Galdi
2299616
galdi@chapman.edu
CPSC 350-01
Assignment 3
*/
#ifndef SYNTAXCHECKER_H
#define SYNTAXCHECKER_H
#include "GenStack.h"
#include "UserInput.h"
#include <iostream>

class SyntaxChecker: public UserInput
{
private:
  GenStack<char>*buffer;
  string input;


public:
  SyntaxChecker();
  SyntaxChecker(string s);
  ~SyntaxChecker();

  bool isGood();

  void reset(string s);

};





#endif
