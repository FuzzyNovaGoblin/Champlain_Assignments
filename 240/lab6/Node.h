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


class Node
{
public:
   std::string title;
   Node *next;
   Node *parent;

   Node(std::string title, Node *last = nullptr, Node* next = nullptr);
   ~Node();
};