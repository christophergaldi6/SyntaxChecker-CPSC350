/**
Chris galdi
2299616
galdi@chapman.edu
CPSC 350-01
Assignment 3
*/

#include "Delimiter.h"

char Delimiter::flip(char del) //given cases, checks for its opposite counterpart
{
  switch (del)
  {
    case '[': return ']'; //https://gist.github.com/mycodeschool/7207410
    case ']': return '[';
    case '(': return ')';
    case ')': return '(';
    case '{': return '}';
    case '}': return '{';
    default: return '\0';
  }
}
