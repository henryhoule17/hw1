/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
#include <iostream>
#include <cstddef>
#include "split.h"
using namespace std;

int main(int argc, char* argv[])
{
 Node n10(11, NULL);
  Node n9(78, &n10);
  Node n8(0, &n9);
  Node n7(21, &n8);
  Node n6(4, &n7);
  Node n5(5, &n6);
  Node n4(5, &n5);
  Node n3(3, &n4);
  Node n2(2, &n3);
  Node n1(1, &n2);

  Node* head = &n1;

  Node* odds = NULL;
  Node* evens = NULL;

  split(head, odds, evens);

  Node* temp = odds;
  while(temp != NULL)
  {
    cout << temp->value << " ";
    temp = temp->next;
  }
  cout << endl;
  temp = evens;
  while(temp != NULL)
  {
    cout << temp->value << " ";
    temp = temp->next;
  }
  cout << endl;

  if(head == NULL)
    cout << "Head was properly emptied" << endl;

  return 0;
}
