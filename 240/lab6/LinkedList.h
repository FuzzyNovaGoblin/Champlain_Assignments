// Author: Grant Hedley
// Class: CSI-240 - Advanced Programming
// Assignment: Module-07-Lab Assignment 6 - Linked List
// Date assigned: 10/24/19
// Due Date: 10/30/19
// Description:
// Certification of Authenticity :
// I  certify  that  this  is  entirely  my  own  work, except  where  I  have  given fully
// documented  references  to  the  work  of  others. I  understand  the
// definition and consequences of plagiarism and acknowledge that the assessor
// of this assignment may, for the purpose of assessing this assignment:
// - Reproduce  this  assignment and provide  a  copy  to  another  member  of
// academic staff; and/or
// - Communicate  a  copy  of  this  assignment  to  a  plagiarism  checking
// service(which  may  then  retain  a  copy  of  this  assignment  on  its
// database for the purpose of future plagiarism checking)

#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

class LinkedList {
	Node* head;
	Node* last;
   int size;

   void findLast();

public:
	LinkedList();
   ~LinkedList();
   void addNode(Node* node);
	void addTitle(const string title);
   void operator+(Node *node);
   void operator+(string title);
   string removeAt(int index);
   string removeLast();
   void displayList(bool count = false);
   void destroyList();
   int getSize();
};