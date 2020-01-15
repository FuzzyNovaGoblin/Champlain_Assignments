#include <iostream>
#include "linkedList.h"
#include "functions.h"
#include "data.h"

using namespace std;


int main(){
   Node* head;
   Data dataSet;


   head = readData();




   Node* curser = head;
   while(curser != nullptr){
      for (int i = 0; !head->data.eof(); i++)
      {
         if(dataSet.getColsSize() < i){
            dataSet.newCol();
         }

         string val;
         head->data >> val;
         dataSet.addVal(i, val);
      }

      curser = curser->child;
   }

   deleteList(head);
}
