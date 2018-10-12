/*
Chris Galdi
2299616
galdi@chapman.edu
CPSC 350-01
Assignment 3
*/


#include "UserInput.h"

using namespace std;

UserInput::UserInput()
{
  fileName = " ";
  userInput = " ";
}

UserInput::UserInput(string fileName)
{
  UserInput();
  this->fileName = fileName;
  setString();
}

UserInput::~UserInput()
{
  myFile.close();
}
//saves the file name
void UserInput::addFile(string fileName)
{
  this->fileName = fileName;
  setString();
}

void UserInput::setString()
{
  myFile.open(fileName.c_str());
  string line;

  cout << "Reading file" << fileName << "..." << '\n';

  if (myFile.is_open())
  {
    while (getline (myFile,line))
    {
      userInput += line + '\n';
    }
  }
  else cout << "Unable to open file\n";
}

string UserInput::getString()
{
  return userInput;
}
