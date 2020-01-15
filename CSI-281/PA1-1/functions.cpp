#include "functions.h"

using namespace std;

Node* readData (){
   string fileName, buffer;
   Node *head, *currentNode, *tmp;
   ifstream file;

   head = new Node("head");
   currentNode = head;

   cout << "Enter file name:\n";

   do{
      getline(cin, fileName);
      if(fileName.length() < 1){
         cout<< "That is not a valid file name\n";
      }
   } while(fileName.length() < 1);

   file.open(fileName);

   while(!file.eof()){
      getline(file, buffer);
      for(int i = 0; i < buffer.length(); i++){
         if((int)buffer[i] == 44){
            buffer[i] = ' ';
         }
      }
      currentNode->child = new Node(buffer);
      currentNode = currentNode->child;
   }
   currentNode = nullptr;

   tmp = head->child;
   delete head;
   head = nullptr;

   return tmp;
}


void deleteList(Node* head){
   Node* tmp;
   while(head != nullptr){
      tmp = head;
      head = head->child;
      delete tmp;
   }
   tmp = nullptr;
}