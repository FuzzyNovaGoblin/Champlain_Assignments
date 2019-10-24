#pragma once
#include <iostream>


class Node
{
public:
   std::string title;
   Node *next;
   Node *parent;

   Node(std::string title, Node *last = nullptr, Node* next = nullptr);
   ~Node();
};