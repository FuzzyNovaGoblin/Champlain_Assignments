#pragma once

#include <string>
#include <sstream>

struct Node
{
   Node* child = nullptr;
   std::stringstream data;

   Node(std::string str){
      data = std::stringstream(str);
   }
};
