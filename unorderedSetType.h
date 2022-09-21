/*
*  File:        unorderedSetType.h
*  Author: 		Najlae ABARGHACHE
*  Description: Definition of the unorderedSetType template class.
*
*
*  Date: 2022-05-05 20:45
*
*/
#ifndef H_unorderedSetType
#define H_unorderedSetType
/*
*  unorderedSetType template class: represents a sub-class, or derived class, of the template
*  class unorderedArrayListType.
*  The unorderedSetType template class can access and use all the unorderedArrayListType class's public and 
*  protected attributes and methods. So there is no need to re-define and implement them. However, we need
*  to overload some methods, that are already implemented in the base class, in order to make them perform
*  the same way as sets would. 
*  A set is a list with distinct elements. In other words, a set is a specialized version of a list that
*  holds distinct elements of the same type.
*  We need to re-implement the functions insertAt and insertEnd in order to make them check whether the item
*  to be inserted was already in the list. Similarly, for the function replaceAt, it needs to check if the 
*  item to be replaced was already in the list.
*
*  The operations on sets include union and intersection. The union of two sets is a third set which 
*  contains all the elements of both sets (with no duplicates). 
*  The intersection of two sets is a third set which contains only elements that are in both sets 
*  (again with no duplicates). Implement 
*  We will be implementing these operations in our unorderedSetType template class by overloading 
*  the + operator to perform the set union operation and the – operator to perform the set intersection
*  operation. Overload these operators as member functions. 
*
*
*/
template <class elemType>
class unorderedSetType: public unorderedArrayListType <elemType>
{
 public:
 	
 	/*
    *  Checks wether the element insertItem already 
	*  exists in the array or not. If it exists, the 
	*  element insertItem is not inserted in the list
	*  and an appropriate message is displayed. 
	*  If it not, it calls the unorderedArrayListType's
	*  method insertAt and the element insertItem is 
	*    	added to the list.
	*
    * PRE:  The element insertItem isn't already in
    *	the list.
	* 		The given location isn't out of
    * 	range.
	*       The array isn't full.
    *
	* POST: The given insertItem is inserted
	* in the array at the specified position location.		 
    * 
    * EXCEPTION: If the given location is out of
    *  range or if the array is full, if the array
    *  is full, or the given item is already in the list,
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
    *  Checks wether the element insertItem already 
	*  exists in the array or not. If it exists, the 
	*  element insertItem is not inserted in the list
	*  and an appropriate message is displayed. 
	*  If it not, it calls the unorderedArrayListType's
	*  method insertEnd and the element insertItem is 
	*    	inserted at the end to the list.
	*
    * PRE:  The element insertItem isn't already in
    *	the list.
	*       The array isn't full.
    *
	* POST: The given insertItem is inserted
	* 		at the end of the array.		 
    * 
    * EXCEPTION: If the array is full, or the given
	*        item is already in the list,
	*  an appropriate message is displayed.
	*
	*  PARAM: insertItem - elemType(Generic Type)  
	*   		the item to be inserted in the array.
	* 
    */
  	void insertEnd(const elemType& insertItem);
  
 	/*
    *  Checks wether the element repItem already 
	*  exists in the array or not. If it exists, the 
	*  element at the given location in the list
	*  is not replaced with the given item repItem 
	*  and an appropriate message is displayed. 
	*  If it not, it calls the unorderedArrayListType's
	*  method replaceAt and the element at the given
	*  location in the list is replaced with the given 
	*			item repItem.
	*
    * PRE:  The element repItem isn't already in
    *	the list.
    *
	* POST: The element at the given location
	*   in the list is replaced with the given 
	*			item repItem.		 
    * 
    * EXCEPTION: If the given item repItem 
	*         is already in the list,
	*  an appropriate message is displayed.
	*
	*  PARAM: repItem - elemType(Generic Type)  
	*   		the item to be inserted in the array.
	*		  location - int the index position 
	*   		of the item to replace.
	*
    */
  	void replaceAt(int location, const elemType& repItem);
  
  	/*
    *  For each set of the two sets, the current object
	*  and the given object in parameters, 
	*  for each element item, checks if the element
	*  item exists in the array and then inserts it at 
	*  the end of the array of the unionGroup set.
	*  Inserts elements by calling the unorderedSetType's
	*  method insertEnd so there will be no duplicated
	*  		items in the returned union set.
	*
	* RETURN: A union set of items.		 
	*
	*  PARAM: rightObject - unorderedSetType<elemType>  
	*   		the set of item to create a union set
	*					with the current set.
	*
    */
  	unorderedSetType<elemType> operator+(unorderedSetType<elemType> rightObject);

  
  	/*
    *  For each set of the two sets, the current object
	*  and the given object in parameters, 
	*  for each element item, checks if the element
	*  item exists in the array of this set and then
	*  checks again if it exists in the other's set array
	*  if it does, it inserts it at the end of the array 
	*         of the intersectionGroup set.
	*  Inserts elements by calling the unorderedSetType's
	*  method insertEnd so there will be no duplicated
	*  		items in the returned union set.
	*
	* RETURN: An intersectionGroup set of items.		 
	*
	*  PARAM: rightObject - unorderedSetType<elemType>  
	* the set of item to create an intersectionGroup set
	*				with the current set.
	*
    */
  	unorderedSetType<elemType> operator-(unorderedSetType<elemType> rightObject);

	/*
    *  Parameterized constructor
    *
    *  Creates an unorderedSetType instance.
    *
    * 	Calls the constructor of the base class 
	* 		unorderedArrayListType. 
	*
	*  PARAM: size - elemType(Generic Type)  
	*  to initialize the maxSize, superClass
	*	  arrayListType's attribute.
    */
  	unorderedSetType(int size = 100);

};


#include "unorderedSetType.cpp" 

#endif
