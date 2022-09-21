/*
*  File:        arrayListType.h
*  Author: 		Najlae ABARGHACHE
*  Description: Implementation of the arrayListType template class.
*
*
*  Date: 2022-05-05 20:45
*
*
*/

#include <iostream>
#include <cassert> 

using namespace std;

template <class elemType>
bool arrayListType<elemType>::isEmpty() const
{
    return (this->length == 0);
}

template <class elemType>
bool arrayListType<elemType>::isFull() const
{
    return (this->length == this->maxSize);
}

template <class elemType>
int arrayListType<elemType>::listSize() const
{
	return this->length;
}

template <class elemType>
int arrayListType<elemType>::maxListSize() const
{
	return this->maxSize;
}

template <class elemType>
void arrayListType<elemType>::print() const
{
    for (int i = 0; i < this->length; i++)
        cout << list[i] << " ";
    cout << endl;
}


template <class elemType>
bool arrayListType<elemType>::isItemAtEqual(int location, 
                                            const elemType& item)  const
{
    if (location < 0 || location >= this->length)
    {
        cout << "The location of the item to be removed "
             << "is out of range." << endl;

        return false;
    }
    else
        return (list[location] == item);
}

template <class elemType>
void arrayListType<elemType>::removeAt(int location)
{
    if (location < 0 || location >= this->length)
        cout << "The location of the item to be removed "
             << "is out of range." << endl;
    else
    {
        for (int i = location; i < this->length - 1; i++)
            list[i] = list[i + 1];

        this->length--;
    }
} //end removeAt

template <class elemType>
elemType arrayListType<elemType>::retrieveAt(int location) const
{
	// Checking if the given location is out of range
    if (location < 0 || location >= this->length){
        cout << "The location of the item to be retrieved is "
             << "out of range" << endl;
    	assert(location < 0 || location >=length);
	}
    else
        return list[location]; // Returning the retrieved element at the specified position location
} //end retrieveAt

template <class elemType>
void arrayListType<elemType>::clearList()
{
    this->length = 0;
} //end clearList

template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{
    if (size <= 0)
    {
        cout << "The array size must be positive. Creating "
             << "an array of the size 100. " << endl;

        this->maxSize = 100;
    }
    else
        this->maxSize = size;

    this->length = 0;

    list = new elemType[this->maxSize];
}

template <class elemType>
arrayListType<elemType>::~arrayListType()
{
    delete [] list;
}

template <class elemType>
arrayListType<elemType>::arrayListType(const arrayListType<elemType>& otherList)
{
    this->maxSize = otherList.maxSize;
    this->length = otherList.length;

    list = new elemType[this->maxSize]; 	//create the array

    for (int j = 0; j < this->length; j++)  //copy otherList
        list [j] = otherList.list[j];
}//end copy constructor


template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator=
                             (const arrayListType<elemType>& otherList)
{
    if (this != &otherList)    //avoid self-assignment
    {
        delete [] list;
        this->maxSize = otherList.maxSize;
        this->length = otherList.length;
 
        list = new elemType[this->maxSize];

        for (int i = 0; i < this->length; i++)
            list[i] = otherList.list[i];
    }
    return *this;
}

