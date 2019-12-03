// Author: Grant Hedley
// Class: CSI-240 - Advanced Programming
// Assignment: 240 Final
// Description: write a dynamic array class and read in words from a file to fill the array, also the user can set the size of the array
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
#include "Product.h"
#include "dynamicArray.h"
#include "Log.h"

#ifndef functions
#define functions


const int END_VALUE = 6;

template <class T>
void addItem(T item, DynamicArray<Product *> &arr)
{
   arr.add(item);
   if (is_same<T, DryFood *>::value)
      log("Dry food added to products");
   else if (is_same<T, Meat *>::value)
      log("Meat added to products");
   else if (is_same<T, Produce *>::value)
      log("Produce added to products");
   else if (is_same<T, TempControlled *>::value)
      log("TempControlled added to products");
   else if (is_same<T, Product *>::value)
      log("Product added to products");
}

int displayMenu();

void printInfo(DynamicArray<Product *> products, bool pre = false);

void createProduct(DynamicArray<Product *> *products);

void adjustCount(DynamicArray<Product *>* products);

void saveData(DynamicArray<Product *> *products);

void readData(DynamicArray<Product *> *products);

#endif