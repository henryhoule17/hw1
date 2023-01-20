/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/
#include <cstddef>
#include "split.h"

/* Add a prototype for a helper function here if you need */
void appendOdd(Node* in, Node*& odds);

void appendEven(Node* in, Node*& evens);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  Node* temp;
//if there's no data
  if(in == NULL)
    return;

  //if there's only one data point left
  if(in->next == NULL)
  {
    if(in->value%2 == 1)
    {
      appendOdd(in, odds);
      in = NULL;
    }
    else if(in->value%2 == 0)
    {
      appendEven(in, evens);
      in = NULL;
    }
    return;
  }

  //If input list is longer than one data point

  
  //findFirstOdds(in, odds);
  //findFirstEven(in, evens);

  else if(in->value % 2 == 1)
  {
    temp = in;
    in = in->next;
    appendOdd(temp, odds);
  }
  else if(in->value%2 == 0)
  {
    temp = in;
    in = in->next;
    appendEven(temp, evens);
  }

  split(in, odds, evens);

}

//Adds odd number to end of odds list
void appendOdd(Node* in, Node*& odds)
{
  if(odds == NULL)
  {
    odds = in;
    odds->next = NULL;
    return;
  }

  if(odds->next == NULL)
  {
    odds->next = in;
    odds->next->next = NULL;
    return;
  }
  else
    appendOdd(in, odds->next);
}

//Adds even number to end of evens list
void appendEven(Node* in, Node*& evens)
{
  if(evens == NULL)
  {
    evens = in;
    evens->next = NULL;
    return;
  }

  if(evens->next == NULL)
  {
    evens->next = in;
    evens->next->next = NULL;
    return;
  }
  else
    appendEven(in, evens->next);
}


/* If you needed a helper function, write it here */

//Finds the position for odds
/*void findFirstOdd(Node* in, Node*& odds)
{
  if(in->value&2 == 1)
  {
    odds = in;
    return;
  }
  else
    findFirstOdd(in->next, odds);
}

//find the position of first even
void findFirstEven(Node* in, Node*& evens)
{
  if(in->value&2 == 0)
  {
    odds = in;
    return;
  }
  else
    findFirstEven(in->next, evens);
}*/