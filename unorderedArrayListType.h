/*
*  File:        unorderedArrayListType.h
*  Author: 		Najlae ABARGHACHE
*  Description: Definition of the unorderedArrayListType template class.
*
*
*  Date: 2022-05-05 20:45
*
*/
#ifndef H_unorderedArrayListType
#define H_unorderedArrayListType

#include "arrayListType.h"
/*
*  unorderedArrayListType template class: represents a sub-class, or derived class, of the template base
*  class arrayListType.
*  The unorderedArrayListType template class can access and use all the arrayListType class's public and 
*  protected attributes and methods. So there is no need to re-define and implement them. However, we need to
*  implement all the pure virtual functions of the template base class arrayListType.
*
*/
template <class elemType>
class unorderedArrayListType: public arrayListType <elemType>
{
public: 

	/*
    *  Starting at the given parameter 'location',
	*  it shifts the items of the array down,
	*	and inserts the given item insertItem
	*  	at the specified position 'location'
	*  	in the array, and then increments the
	*   'length' value, which represents the
	*    number of elements in the array,
	*				 by one.
	*
    * PRE: The given location isn't out of
    * 	range, and the array isn't full.
    *
	* POST: The given insertItem is inserted
	* in the array at the specified position location.		 
    * 
    * EXCEPTION: If the given location is out of
    *  range or if the array is full,
	*  an appropriate message is displayed.
	*
	*  PARAM: insertItem - elemType(Generic Type)  
	*   		the item to be inserted in the array.
	*		  location - int the index position 
	*   		where to insert the item.
	* 
    */
    void insertAt(int location, const elemType& insertItem);
    
    /*
    *  Inserts the given item insertItem
	*  	at the end of the array, i.e where 
	*   the array's index is equal to
	*	length value, and then increments
	*   'length' value, which represents the
	*    number of elements in the array,
	*				 by one.
	*
	* POST: The given insertItem is inserted
	* 			at the end of the array.		 
    * 
    * EXCEPTION: If the array is full,
	*  an appropriate message is displayed.
	*
	*  PARAM: insertItem - elemType(Generic Type)
	*   		  the item to be inserted at the 
	*					end of the array.
	* 
    */
    void insertEnd(const elemType& insertItem);
    
    /*
    *  Replaces the item at the given position
    *  'location' in the array by the value
	* 		of the given item repItem.
	*
    * PRE: The given location isn't out of
    * 				range.
    *
	* POST: The item at the given
	* location in the array is replaced by
	* 		the given item repItem.	 
    * 
    * EXCEPTION: If the given location is out of
    * range, an appropriate message is displayed.
	*
	*  PARAM: repItem - elemType(Generic Type)  
	*   	the item to be inserted in the array.
	*		  location - int the index position 
	*   	where to insert the item.
	* 
    */
    void replaceAt(int location, const elemType& repItem);
    
	/*
    *  Searches for the index position of
	*   the first occurence of the given 
	*		item searchItem in the
	* 				array.
	*
	* PRE: The given item is found within 
	*  			the array items.
	*
	* RETURN: The index position of
	*   the the first occurence of the
	*   given item searchItem in the
	* 	 	array if it's found. 
	*  	   Otherwise, returns -1.
	*
	*  PARAM: searchItem - elemType(Generic Type) 
	*   the item to be searched for in the array.
	* 
    */
    int seqSearch(const elemType& searchItem) const;
    
	/*
    *  Removes the given item removeItem
    *  	from the array, and then decrements
	*   the'length' value, which represents
	*   the number of elements in the array,
	*				 by one.
	*
	* PRE: The given item is found within 
	* the array items, and the array isn't
	*				empty.
	*
	* POST: The given item removeItem
	* is removed from the array.	
	*	 
	*  PARAM: removeItem - elemType(Generic Type) 
	* 	 the item to be	removed from the array.
    */
    void remove(const elemType& removeItem);

	/*
    *  Parameterized constructor
    *
    *  Creates an unorderedArrayListType instance.
    *
    * 	Calls the constructor of the superClass 
	* 			arrayListType. 
	*
	*  PARAM: size - elemType(Generic Type)  
	*  to initialize the maxSize arrayListType's 
	*				attribute.
    */
    unorderedArrayListType(int size = 100);
}; 


#include "unorderedArrayListType.cpp"

#endif
