/* ***       Author:  Grant Hedley
     *  Last Update:  April 24, 2020
     *        Class:  CSI-281
     *     Filename:  DynamicArray.h
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my work.
     **********************************************************/

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <sstream>

	 using namespace std;

template <typename K, typename V>
struct ElementNode
{
		K mKey;
		V mValue;
		public:
		ElementNode(K key){
			mKey = key;
		}
		ElementNode(K key, V value){
			mKey = key;
			mValue = value;
		}
};

template <typename T>
class DynamicArray
{
private:
	T *mArr;
	int mCount = 0;
	int mArrayCount;

public:
	DynamicArray();
	DynamicArray(const DynamicArray &d);
	~DynamicArray();
	int size() const;
	T &operator[](int i) const;
	string getPrintInfo() const;
	void add(T item);
	void resizeArray(int newSize);
	T remove(int i);
	void clear();
};



template <typename T>
DynamicArray<T>::DynamicArray()
{
	mCount = 0;
	mArrayCount = 10;
	mArr = new T[mArrayCount];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray &d)
{
	mCount = d.mCount;
	mArrayCount = d.mArrayCount;
	mArr = new T[mArrayCount];
	for (int i = 0; i < d.mCount; i++)
	{
		mArr[i] = d.mArr[i];
	}
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
	delete[] mArr;
	mArr = nullptr;
}

template <typename T>
int DynamicArray<T>::size() const
{
	return mCount;
}

template <typename T>
T &DynamicArray<T>::operator[](int i) const
{
	if (i >= mCount || i < 0)
	{
		throw invalid_argument("index out of bounds");
	}

	return mArr[i];
}

template <typename T>
string DynamicArray<T>::getPrintInfo() const
{
	stringstream ss;
	ss << "The current capacity of the array is: " << mArrayCount;
	ss << "\nThe current size of the array is: " << mCount;
	ss << "\nArray content:\n";

	for (int i = 0; i < mCount; i++)
	{
		ss << (*this)[i] << endl;
	}

	return ss.str();
}

template <typename T>
void DynamicArray<T>::add(T item)
{
	if (mCount >= mArrayCount)
	{
		T *tmp = new T[mCount];
		for (int i = 0; i < mCount; i++)
		{
			tmp[i] = mArr[i];
		}

		mArrayCount *= 2;
		delete[] mArr;
		mArr = new T[mArrayCount];
		for (int i = 0; i < mCount; i++)
		{
			mArr[i] = tmp[i];
		}
	}
	mArr[mCount++] = item;
}

template <typename T>
void DynamicArray<T>::resizeArray(int newSize)
{
	DynamicArray tmp = DynamicArray(*this);
	delete[] mArr;
	mArrayCount = newSize;
	if (tmp.mCount > mArrayCount)
		mCount = mArrayCount;
	else
		mCount = tmp.mCount;
	mArr = new T[mArrayCount];

	for (int i = 0; i < mCount; i++)
	{
		mArr[i] = tmp.mArr[i];
	}
}

template <typename T>
T DynamicArray<T>::remove(int i)
{
	for (int i = 0; i < mArrayCount - 2;)
		mArr[i] = mArr[++i];
	mCount--;
}

template<typename T>
void DynamicArray<T>::clear(){
	mCount = 0;
}

#endif