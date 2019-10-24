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