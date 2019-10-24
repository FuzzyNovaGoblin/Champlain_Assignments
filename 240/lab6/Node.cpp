#include "Node.h"
#include <iostream>

Node::Node(std::string title, Node *last, Node *next)
{
   parent = last;
   this->next = next;
   this->title = title;
   if (last != nullptr)
   {
      last->next = this;
   }
   if (next != nullptr)
   {
      next->parent = this;
   }
}

Node::~Node()
{
   if (parent != nullptr)
      parent->next = next;
   if (next != nullptr)
      next->parent = parent;
}