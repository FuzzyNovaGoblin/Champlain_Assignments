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

#include "LinkedList.h"

LinkedList::LinkedList()
{
   head = nullptr;
   last = nullptr;
   size = 0;
}
LinkedList::~LinkedList()
{
   if (head != nullptr)
      destroyList();
}

void LinkedList::addNode(Node *node)
{
   if (node == nullptr)
      return;

   size++;

   if (head == nullptr)
   {
      head = node;
      last = node;
      return;
   }
   node->parent = last;
   last->next = node;
   last = node;
}

void LinkedList::addTitle(std::string title)
{
   size++;
   if (head == nullptr)
   {
      head = new Node(title);
      last = head;
      return;
   }
   last->next = new Node(title, last);
   last = last->next;
}

void LinkedList::operator+(Node *node)
{
   addNode(node);
}
void LinkedList::operator+(string title)
{
   addTitle(title);
}

string LinkedList::removeLast()
{
   size--;
   string str = last->title;
   if (size == 0)
   {
      delete last;
      last = nullptr;
      head = nullptr;
   }
   else
   {
      last = last->parent;
      delete last->next;
   }
   return str;
}
string LinkedList::removeAt(int index)
{
   string str;
   if (head == nullptr)
      return "";

   if (index < 0)
   {
      cout << "Index out of range!\n";
      return "";
   }

   if (index == 0)
   {
      size--;
      str = head->title;
      head = head->next;
      delete head->parent;
      return str;
   }

   Node *cursor = head;
   for (int i = 0; i < index && cursor != nullptr; i++)
   {
      cursor = cursor->next;
   }
   if (cursor == nullptr)
   {
      cout << "Index out of range!\n";
      return "";
   }
   if (cursor == last)
      last = last->parent;
   size--;
   str = cursor->title;
   delete cursor;
   return str;
}

void LinkedList::displayList(bool count)
{
   Node *cursor = head;
   if (!count)
      cout << "\nList size: " << size << endl;
   int i;
   for (i = 0; cursor != nullptr; i++)
   {
      if (count)
         cout << i + 1 << ") ";
      cout << cursor->title << endl;
      cursor = cursor->next;
   }
}

void LinkedList::destroyList()
{
   last = last->parent;
   while (last != nullptr)
   {
      delete last->next;
      last = last->parent;
   }
   delete head;
   head = nullptr;
   size = 0;
}

int LinkedList::getSize()
{
   return size;
}