/*
Chris Galdi
2299616
galdi@chapman.edu
CPSC 350-01
Assignment 3
*/

#include "GenStack.h"
#include "UserInput.h"
#include "SyntaxChecker.h"


int main(int argc, char const *argv[])
{
  if (argc > 1)
  {
    SyntaxChecker checker(argv[1]);
    bool good = checker.isGood();
    while (good)
    {
      cout << "Would you like to process another file? (y/n)" << endl;
      string userInput = "";
      getline(cin, userInput);
      if (userInput == "y")
      {
        cout << "What is the name of the file?" << endl;
        getline(cin, userInput);
        checker.reset(userInput);
        cout << "Test" << endl;
        good = checker.isGood();
      }
      else if (userInput == "n")
      {
        good = false;
      }
      else
      {
        cout << "Invalid input" << endl;
      }
    }
  }
  else
  {
    cout << "Error: no arguments" << endl;
  }

  return 0;
}
