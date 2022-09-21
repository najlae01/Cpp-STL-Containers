/*
*  File:        unorderedArrayListType.cpp
*  Author: 		Najlae ABARGHACHE
*  Description: Implementation of the unorderedArrayListType template class.
*
*
*  Date: 2022-05-05 20:45
*
*  
*
*/

#include "arrayListType.h" 

using namespace std; 

template <class elemType>
void unorderedArrayListType<elemType>::insertAt(int location,
                                         const elemType& insertItem)
{

    if (location < 0 || location >= this->maxSize)
        cout << "The position of the item to be inserted "
             << "is out of range." << endl;
    else if (this->length >= this->maxSize)  //list is full
        cout << "Cannot insert in a full list" << endl;
    else
    {
        for (int i = this->length; i > location; i--)
            this->list[i] = this->list[i - 1];	//move the elements down

        this->list[location] = insertItem; //insert the item at
        //the specified position

        this->length++;	//increment the length
    }
} //end insertAt

template <class elemType>
void unorderedArrayListType<elemType>::insertEnd
                                 (const elemType& insertItem)
{
 if (this->length >= this->maxSize)  //the list is full
        cout << "Cannot insert in a full list." << endl;
    else
    {
        this->list[this->length] = insertItem; //insert the item at the end
        this->length++; //increment the length
    }
    
} //end insertEnd

template <class elemType>
int unorderedArrayListType<elemType>::seqSearch
                            (const elemType& searchItem) const
{
    int loc;
    bool found = false;

    for (loc = 0; loc < this->length; loc++)
        if (this->list[loc] == searchItem)
        {
            found = true;
            break;
        }

    if (found)
        return loc;
    else
        return -1;
} //end seqSearch

template <class elemType>
void unorderedArrayListType<elemType>::remove
                               (const elemType& removeItem)
{
    int loc;

    if (this->length == 0)
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        loc = seqSearch(removeItem);

        if (loc != -1)
            this->removeAt(loc);
        else
            cout << "The item to be deleted is not in the list."
                 << endl;
    }
} //end remove

template <class elemType>
void unorderedArrayListType<elemType>::replaceAt(int location, 
                                       const elemType& repItem)
{
      if (location < 0 || location >= this->length)
        cout << "The location of the item to be "
             << "replaced is out of range." << endl;
    else
        this->list[location] = repItem;
} //end replaceAt


template <class elemType>
unorderedArrayListType<elemType>::unorderedArrayListType(int size)
                       : arrayListType<elemType>(size)
{
}
