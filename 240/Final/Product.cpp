#include "Product.h"

Product::Product(string name, int section)
{
   this->name = name;
   this->section = section;
}

TempControlled::TempControlled(string name, int section, int temp):Product(name, section){
   this->temp = temp;
}

Meat::Meat(string name, int section, int temp = 34) : TempControlled(name, section, temp) {

}

