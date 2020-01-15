#include "data.h"

Data::Data(){
}
Data::~Data(){
   for(int i = cols.size()-1; i >= 0; i++){
      delete cols[i];
   }
}



void Col::newValue(string value){
   keys.push_back(value);
   values.push_back(1);
}


void Col::operator+=(string key){
   int index = -1;
   for(int i = 0; i < keys.size(); i++){
      if(keys[i] == key){
         index = i;
         break;
      }
   }
   if(index == -1){
      newValue(key);
   }
   else{
      values[index]++;
   }
}


int Data::getNumberOfRecords(){
   return cols.size();
}

int Data::getNumberOfAttributes(){
   return cols[0]->getNumberOfAttributes();
}

int Col::getNumberOfAttributes(){
   return values.size();
}

int Data::getColsSize(){
   return cols.size();
}

void Data::newCol(){
   cols.push_back(new Col);
}
void Data::addVal(int index, string val){
   *cols[index] += val;
}