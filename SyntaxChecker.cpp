/*
Chris Galdi
2299616
galdi@chapman.edu
CPSC 350-01
Assignment 3
*/

#include "SyntaxChecker.h"
#include "Delimiter.h"

using namespace std;

SyntaxChecker::SyntaxChecker()
{

}

SyntaxChecker::SyntaxChecker(string fileName):UserInput(fileName)
{
  input = getString();
  int Delimiters = 0;
  for (int i = 0; i < input.length(); ++i)
  {
    if (input[i] == '[' || input[i] == '(' || input[i] == '{')
    {
      Delimiters++;
    }
  }
  buffer = new GenStack <char> (Delimiters);

}
SyntaxChecker::~SyntaxChecker()
{

}

bool SyntaxChecker::isGood()
{
  bool good = true;
  int line = 1;
    for (int i = 0; i < input.length(); ++i)
    {
      if (input[i] == '\n')
      {
        ++line;
      }
      if (input[i] == '[' || input[i] == '(' || input[i] == '{')
      {
        buffer -> push(input[i]);
      }
      if (input[i] == ']' || input[i] == ')' || input[i] == '}')
      {
        if (Delimiter::flip(input[i]) != buffer -> peek())
        {
          cout << "Delimiter doesn't match at line " << line << ", expected " <<
            Delimiter::flip(buffer->peek()) << "but detected " << input[i] << '.' << endl;
          return false;
        }
        else
        {
          buffer -> pop();
        }
      }
    }
    if (!buffer->isEmpty())
    {
      cout << "Reached end of file; missing " << Delimiter::flip(buffer->peek()) << '.' << endl;
      return false;
    }

    else if(myFile.is_open())
    {
      cout << "Delimiter syntax is good" << endl;
      myFile.close();
      return true;
    }
  return false;
}

void SyntaxChecker::reset(string s)
{
  delete buffer;
  fileName = "";
  userInput = "";
  fileName = s;
  setString();
  input = getString();
  int Delimiters = 0;
  for (int i = 0; i < input.length(); ++i)
  {
    if (input[i] == '[' || input[i] == '(' || input[i] == '{')
    {
      Delimiters++;
    }
  }
  buffer = new GenStack<char>(Delimiters * 2);
}
