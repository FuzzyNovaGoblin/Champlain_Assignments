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