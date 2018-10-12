/*
Chris Galdi
2299616
galdi@chapman.edu
CPSC 350-01
Assignment 3
*/

#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>

using namespace std;

template <class T>
class GenStack
{
private:
  int size;
  int top;
  T *myArray;

public:
  GenStack()
  {
    size = 0;
    top = -1;
  };
  GenStack(int maxSize)
  {
    myArray = new T[maxSize];
    size = maxSize;
    top = -1;
  };
  ~GenStack()
  {
    delete [] myArray;
  };

  void push(T d)
  {
    myArray[++top] = d;
  };

  T pop()
  {
    return myArray[top--];
  };

  T peek()
  {
    return myArray[top];
  };

  bool isFull()
  {
    return (size - 1 == top);
  };

  bool isEmpty()
  {
    return (top = -1);
  };
};





#endif
